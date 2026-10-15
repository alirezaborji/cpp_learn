# cpp-012-vectors

Practice string insertion, indexed access, postfix iterator increment, and vector size/capacity reuse. The source preserves the current working exercise; `resize()` is explained in the notes for further practice.

From this directory, with CMake 3.20+ and a C++20 compiler:

```bash
cmake -S . -B build
cmake --build build
./build/cpp_012_vectors
```

The program prints `Hi again`, the values `1`, `2`, `3`, and three size/capacity pairs. Capacity is at least `5`; its exact value is implementation dependent.

Read [[cpp-012-vectors]] in Obsidian or open [the lesson note](docs/cpp-012-vectors.md).
