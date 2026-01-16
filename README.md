# Building C Runtime from Scratch

This repository demonstrates how a C runtime is built from scratch on Linux,
starting from `crt0` without using libc.

It shows how the Linux kernel transfers control to user space, how `argc` and
`argv` are extracted from the initial process stack, how `main()` is invoked,
and how system calls like `write` and `exit` are implemented manually.

## How to Build and Run

This project targets **32-bit Linux** and does not use libc and is tested on WSL(Ubuntu).

### Build

```bash
gcc -m32 -nostdlib -no-pie crt0.s main.c write.c read.c -o bare32

```

### To Run

```bash
./bare32 hello world test
```

### Check exit code

```
echo $?
```
