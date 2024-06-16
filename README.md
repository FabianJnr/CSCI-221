# CSCI-221
Computer Science 221: Projects and Assignments

This repository contains the assignments and projects completed during my second computer science class at . Reed College. The projects are written in C, C++, and Assembly.

Table of Contents
Introduction

1. Setup
2. Usage
3. Contributing
4. Contact
5. Introduction

This repository showcases my work from a computer science class focused on systems programming and low-level programming languages. The projects and assignments here cover a range of topics and demonstrate my proficiency in C, C++, and assembly language.

Setup

To run the code in this repository, you will need a C/C++ compiler and an assembler. Here are the steps to set up your environment:

Install GCC and G++:

sh
Copy code
sudo apt-get update sudo apt-get install build-essential

Install NASM for Assembly:

sh
Copy code
sudo apt-get install nasm
Usage

Each project and assignment folder contains a README with specific instructions on how to compile and run the programs. Here are general instructions:

Compiling C Programs
sh
Copy code
gcc -o output_filename source_filename.c ./output_filename
Compiling C++ Programs
sh
Copy code
g++ -o output_filename source_filename.cpp ./output_filename
Assembling and Running Assembly Programs

If you want to run and see the results of assembly codes, you can also use QtSpim.

sh
Copy code
nasm -f elf64 -o output_filename.o source_filename.asm ld -o output_filename output_filename.o ./output_filename
Contributing

Contributions are welcome! If you have any improvements or suggestions, please fork the repository, create a new branch, and submit a pull request.

Contact

If you have any questions or feedback, feel free to reach out:

Email: andohmintahf@gmail.com
GitHub: FabianJnr
