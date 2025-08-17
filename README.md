# Heap & Hash File Database Example

Georgios Papaioannou
Michail Aretakis

This project demonstrates a simple database system using heap files and hash table files, built on top of a block file (BF) library.

## Structure

- `src/` — Core source files (`hp_file.c`, `ht_table.c`, `record.c`)
- `include/` — Header files
- `examples/` — Example programs (`bf_main.c`, `hp_main.c`, `ht_main.c`)
- `lib/` — Precompiled BF library (`libbf.so`)
- `build/` — Compiled executables
- `data.db` — Example database file

## Build

```sh
make bf    # Block file example
make hp    # Heap file example
make ht    # Hash table example
```

## Run

```sh
./build/bf_main   # Demonstrates block file usage
./build/hp_main   # Demonstrates heap file operations
./build/ht_main   # Demonstrates hash table operations
```

## Features

- Heap file creation, insertion, and search ([src/hp_file.c](src/hp_file.c))
- Hash table file creation, insertion, and search ([src/ht_table.c](src/ht_table.c))
- Random record generation ([src/record.c](src/record.c))
- Uses BF library for block management ([include/bf.h](include/bf.h))
