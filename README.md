# bruteforce-password-simulator-c
C program simulating a brute-force attack on short lowercase passwords

## Project goal

This project was created to practice C programming and basic cybersecurity concepts by simulating a brute-force attack on a short password.

The program generates all possible combinations from a defined character set and compares each guess to a target password.

## Features

- written in C
- brute-force simulation on short passwords
- configurable character set
- progressive search from length 1 up to a user-defined maximum
- input validation for unsupported characters
- display of attempts and elapsed time

## Technologies used

- C
- standard libraries: `stdio.h`, `string.h`, `time.h`, `stdint.h`

## How to compile

```bash
gcc bruteforce.c -o bruteforce
