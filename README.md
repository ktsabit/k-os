#  kOS

Welcome to kOS! This is a hobby operating system project that is currently in its early stages of development.

## Introduction

kOS is a hobby OS developed as a learning project to gain a deeper understanding of operating system concepts and low-level programming. The goal is to create a simple, minimalistic operating system that can run on i386 architecture (for now).

## Features

For now, kOS can only boot and print some string.

## Roadmap

- [x] boots
- [x] GDT
- [ ] IDT
- [ ] libc
- [ ] terminal
- [ ] VGA driver
- [ ] file system
- [ ] etc

## Getting Started

Run

1. Change tools variable in makefile with your cross-compilation tool path
2. run `make` to compile and run or `make debug` to debug with GDB

Currently kOS is still in very early development stage, will be expand the guide later.  

## Contributing

Contributions to kOS are welcome! If you would like to contribute, please follow the guidelines outlined in the CONTRIBUTING.md file.

## License

kOS is open-source software licensed under the [MIT License](LICENSE).

## Contact

If you have any questions or suggestions regarding kOS, feel free to reach out to me at [ktsabit@gmail.com](mailto:ktsabit@gmail.com).
