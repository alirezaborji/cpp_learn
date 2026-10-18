# CPP Learn

Four independent C++20 learning projects share one Git repository. Each project owns its source, CMake build, and Obsidian notes.

| Project | Main target | Notes |
|---|---|---|
| [Exceptions](projects/cpp-1-exceptions/README.md) | `cpp_1_exceptions` | [Exceptions lesson](projects/cpp-1-exceptions/docs/cpp-1-exceptions.md) |
| [Files](projects/cpp-2-files/README.md) | `cpp_2_files` | [Files lesson](projects/cpp-2-files/docs/cpp-2-files.md) |
| [Vectors](projects/cpp-012-vectors/README.md) | `cpp_012_vectors` | [Vectors lesson](projects/cpp-012-vectors/docs/cpp-012-vectors.md) |
| [2D Vectors](projects/cpp-014-vectors-2D/README.md) | `cpp_014_vectors_2d` | In progress |

## Build from the repository root

Requires CMake 3.20 or newer and a compiler supporting C++20.

```bash
cmake -S . -B build
cmake --build build
```

Build and run just one lesson:

```bash
cmake --build build --target cpp_012_vectors
./build/projects/cpp-012-vectors/cpp_012_vectors
```

Build and run the 2D vectors lesson:

```bash
cmake --build build --target cpp_014_vectors_2d
./build/projects/cpp-014-vectors-2D/cpp_014_vectors_2d
```

File examples write relative to the process's current working directory. Run them from the ignored build folder to keep generated files out of source:

```bash
cd build/projects/cpp-2-files
./cpp_2_files
```

## Build a project independently

Each project can be opened directly in a CMake IDE or built without the root CMake file:

```bash
cmake -S projects/cpp-1-exceptions -B projects/cpp-1-exceptions/build
cmake --build projects/cpp-1-exceptions/build
./projects/cpp-1-exceptions/build/cpp_1_exceptions
```

Project READMEs list their targets and working-directory requirements. Build output is ignored; the existing tracked IDE settings are retained.

## Project layout and notes

- `projects/<lesson>/CMakeLists.txt`: standalone project and explicit source targets.
- `projects/<lesson>/src/`: the lesson's main program and implementations.
- `projects/<lesson>/include/`: headers exposed by a lesson library, when needed.
- `projects/<lesson>/examples/`: earlier exercises with their own executable targets.
- `projects/<lesson>/docs/`: concise lesson notes with Mermaid diagrams and Obsidian links.
- [docs/AI-Prompt-Notes.md](docs/AI-Prompt-Notes.md): shared note-writing instructions.
- [docs/AI-Prompts-For-Git-Commits.md](docs/AI-Prompts-For-Git-Commits.md): commit-message instructions.

Open the repository root as an Obsidian vault to browse all lessons together. Project notes use unique lesson names for cross-links.

The exceptions project preserves the basic throw example and final custom-exception library. The files project preserves the text-stream exercise, unfinished notes-menu practice, and packed binary-struct exercise. The vectors project contains the current string, iterator, and capacity practice. The 2D vectors project is an empty starter for the next lesson; add its `main()` implementation before building it.

Keep future edits inside the relevant project. Commit from the repository root and use a short subject such as `feat(vectors): practice resize` or `docs(files): explain stream modes`.
