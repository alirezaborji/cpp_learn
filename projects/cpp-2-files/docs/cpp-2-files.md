# cpp-2-files

## 📝 Writing and Reading Text

A file stream connects a C++ program to a file. `std::ofstream` writes, `std::ifstream` reads, and `std::fstream` supports both according to its open mode.

The text-stream exercise writes `myFile.md`, closes the output stream, then reads the file line by line. This compact version shows the same flow:

```cpp
{
    std::ofstream output("myFile.md");
    if (!output) {
        return 1;
    }
    output << "First line\nSecond line\n";
} // The stream closes before reading begins.

std::ifstream input("myFile.md");
if (!input) {
    return 1;
}

std::string line;
while (std::getline(input, line)) {
    std::cout << line << '\n';
}
if (!input.eof()) {
    return 1;
}
```

`getline()` preserves spaces and consumes the newline without storing it. Testing the read in the loop prevents printing an extra line after a failed read. The full `examples/text-streams.cpp` also checks the completed write.

```mermaid
flowchart LR
    A["Open output"] --> B["Write text"]
    B --> C["Close and check output"]
    C --> D["Open input"]
    D --> E["Read with getline"]
```

### 🔧 Stream Modes

| Mode | Purpose |
|---|---|
| `std::ios::in` | Read |
| `std::ios::out` | Write; by itself normally truncates an existing file |
| `std::ios::app` | Append each write at the end |
| `std::ios::trunc` | Discard existing contents when opening for output |
| `std::ios::binary` | Disable text-mode translations; it does not serialize objects for you |

Combine modes using `|`. An `ofstream` defaults to output, an `ifstream` to input, and an `fstream` to input plus output. A default `fstream` therefore normally requires the file to exist.

> ⚠️ **Run file exercises from their build directory.**
>
> Paths are relative to the process's current working directory. These examples can overwrite `myFile.md`, `myFile.txt`, or `meFile.bin`; use disposable practice files there.

## 🔎 Searching Text and Checking Streams

`is_open()` checks whether a stream opened a file. Later reads and writes can still fail, so also check the operation's result or the stream state.

`std::string::find()` returns a position, or `std::string::npos` when there is no match:

```cpp
if (line.find("school") != std::string::npos) {
    std::cout << "Found a match\n";
}
```

A match at the beginning has position `0`; a match in the middle has a positive position. Store the result with `auto` when needed rather than narrowing it to `int`.

The historical `examples/notes-practice.cpp` preserves the menu exercise: add, display, search, clear, and an unfinished delimiter operation. Its `if (!found)` only detects a match at position zero, delimiter removal is incomplete, and input EOF is not handled. Enter `6` to exit normally.

## 📦 Binary Files and Packed Structures

The main exercise saves a packed `School` structure to `meFile.bin`, resets the fields in memory, and reads the saved bytes back.

```cpp
#pragma pack(push, 1)
struct School {
    int amountOfChildrens;
    int amountOfClasses;
    int amountOfTeachers;
    char headQuarterName[50];
};
#pragma pack(pop)
```

Packing requests reduced alignment and padding on compilers that support this pragma. `push` saves the previous packing setting; `pop` restores it for later types.

```cpp
outStream.write(reinterpret_cast<const char*>(&school), sizeof school);
inStream.read(reinterpret_cast<char*>(&school), sizeof school);
```

The cast provides a byte-oriented pointer to the object. The count is `sizeof school` bytes; `read()` fills that existing object's storage.

```mermaid
flowchart LR
    A["School object in RAM"] -->|"write object bytes"| F["meFile.bin"]
    F -->|"read into existing object"| B["School object in RAM"]
```

If `sizeof(int) == 4` and packing removes all padding, this layout occupies `3 × 4 + 50 = 62` bytes. The binary example uses C++20 designated initializers to name each member when constructing the object.

> ⚠️ **Raw object bytes are a native-layout exercise.**
>
> Integer width, byte order, and packing can differ across targets. Packed members may be unaligned, which matters on embedded hardware. Types such as `std::string` also contain implementation-managed state and cannot be saved this way as a portable format.
>
> The restored binary program lacks stream-error checks. Adding checks for a complete write/read is a practice task before using the result as reliable data.

## 🧪 Interview Q&A

**Q1:** Why use `while (getline(stream, line))`?

**Q2:** How do you distinguish no match from a match at index zero?

**Q3:** Does `std::ios::binary` make a packed structure portable?

> [!answer]- 📋 Answers
>
> **A1:** It processes a line only when the read succeeds, rather than guessing whether the next read will reach EOF.
>
> **A2:** Compare the result with `std::string::npos`. Zero is a valid position.
>
> **A3:** No. Binary mode controls stream translations; the structure still uses the target's native representation.

## 🔨 Hands-On Practice

1. Run `files_text_streams` from its build directory and inspect `myFile.md`.

    ✅ Its lines are printed twice: once through `ifstream`, then through `fstream`.

2. In the notes-menu exercise, search for text at the start and middle of a line. Replace the boolean position check with a comparison against `npos`.

    ✅ Both positions should be recognized.

3. Add stream checks to the binary exercise and compare `sizeof(School)` with the generated file size. Try a truncated practice file when checking reads.

    ✅ A short read must be reported rather than treated as a complete record.

### 📋 Quick Reference

| Operation | Syntax |
|---|---|
| Append text | `std::ofstream out(path, std::ios::app);` |
| Read lines | `while (std::getline(in, line))` |
| Search a line | `line.find(text) != std::string::npos` |
| Write bytes | `out.write(pointer, count);` |
| Read bytes | `in.read(pointer, count);` |
| Check failure | `if (!stream) { /* handle failure */ }` |

### 🧠 Things to Remember

- Relative paths use the working directory, not the source directory.
- An open file can still encounter read/write failures.
- `app` preserves existing content; truncation discards it.
- Packing affects layout and alignment, not byte order.

### 💡 Pro Tips

- Close and check output before opening the same file for reading; destructors handle ordinary scope cleanup.
- Keep the text, menu, and binary exercises in separate targets so each can keep its own `main()`.
- For data shared between embedded targets, define field sizes and byte order explicitly instead of relying on packed native structs.

### 🔗 Related Topics

- [[cpp-1-exceptions]]
- [[cpp-012-vectors]]
