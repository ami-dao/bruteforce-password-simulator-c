# Brute Force Password Simulator in C

C program simulating a brute-force attack on short passwords using lowercase letters.

## Project goal

This project was created to practice C programming and basic cybersecurity concepts by simulating a brute-force attack on a simple password.

The program generates all possible combinations of lowercase letters and compares each guess to a target password until it finds a match.

## Features

- written in C
- brute-force simulation on short passwords
- generation of all combinations of lowercase letters
- configurable maximum password length
- password comparison using string functions
- display of attempts and elapsed time

## Charset

The program uses the following character set:

abcdefghijklmnopqrstuvwxyz

Maximum supported password length:

3

This limitation allows the brute-force search to complete quickly for demonstration purposes.

## Technologies used

- C
- standard libraries:
  - stdio.h
  - string.h
  - time.h
  - stdint.h

## How to compile

gcc bruteforce.c -o bruteforce

## How to run

./bruteforce

Example workflow
	1.	Enter a target password (only lowercase letters)
	2.	Choose the maximum length to try
	3.	The program generates all possible combinations until the password is found

Example output

Password found:   cat
Length matched:   3
Attempts:         1372
Elapsed time:     0.000012 seconds

Learning objectives

This project helped practice:
	•	C syntax
	•	arrays and null-terminated strings
	•	string comparison
	•	iterative generation of combinations
	•	brute-force logic
	•	basic algorithmic thinking
