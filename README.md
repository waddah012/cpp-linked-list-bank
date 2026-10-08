# Linked List Account Manager

A singly linked list supporting account insertion, lookup, removal, deposits, and withdrawals.

An educational C++ example developed from coursework, organized as a standalone project.

## Build and run

Requires a C++17 compiler and Make. Smoke checks also require Python 3.

```sh
make
make run
make check
```

To choose a compiler: `make CXX=clang++` or `make CXX=g++`. Run `make clean` to remove build outputs.

## Example

Use the numbered menu to manage in-memory example accounts; choose 0 to exit.

## Structure

- `src/`: source code and headers.
- `tests/smoke.py`: representative console checks with execution timeouts.
- `Makefile`: builds the source files together into `build/example`.

## Scope

Data exists only during execution. Account identifiers are not enforced as unique, and menu input validation is limited.

The source retains the original exercise logic and explanatory comments. Build outputs, submission documents, and course materials are not part of this repository.
