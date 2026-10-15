# cpp-1-exceptions

Practice `throw`, `try`, `catch`, and a custom `std::exception` subclass. The final example separates declarations in `include/exceptions.h` from definitions in `src/exceptions.cpp`.

From this directory, with CMake 3.20+ and a C++20 compiler:

```bash
cmake -S . -B build
cmake --build build
./build/cpp_1_exceptions
./build/exceptions_basic
```

| Target | Source | Expected output |
|---|---|---|
| `cpp_1_exceptions` | `src/main.cpp`, library in `src/exceptions.cpp` | `Hi what()` |
| `exceptions_basic` | `examples/basic-throw.cpp` | `10` |

Read [[cpp-1-exceptions]] in Obsidian or open [the lesson note](docs/cpp-1-exceptions.md).
