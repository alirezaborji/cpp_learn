# cpp-2-files

Practice text streams, a notes menu, and reading/writing a packed `School` structure. Historical exercises have separate executable targets so each keeps its own `main()`.

From this directory, with CMake 3.20+ and a C++20 compiler:

```bash
cmake -S . -B build
cmake --build build
cd build
./cpp_2_files
```

| Target | Source | Files in the working directory |
|---|---|---|
| `cpp_2_files` | `src/main.cpp` | Creates/overwrites `meFile.bin` |
| `files_text_streams` | `examples/text-streams.cpp` | Creates/overwrites `myFile.md` |
| `files_notes_practice` | `examples/notes-practice.cpp` | Reads/writes `myFile.txt`; menu operations can overwrite it |

Run the other exercises from the build directory using `./files_text_streams` or `./files_notes_practice`.

The historical notes-menu program is unfinished: search only recognizes a match at position zero, delimiter removal is incomplete, and input EOF is not handled. Enter `6` to exit normally. The binary example also lacks stream-error checks and writes native object bytes; use it as an exercise, not a portable storage format.

Read [[cpp-2-files]] in Obsidian or open [the lesson note](docs/cpp-2-files.md).
