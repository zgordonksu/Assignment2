# CS 3503 Assignment 2 - Data Representation and Mapping

## Author
Zachary GOrdon

## Description
Advanced data representation functions for Owl Tech's CPU design team.

## What's New
- Direct mapping functions (oct/hex/bin)
- Signed number representations
- Reused test framework from A1

## Build/Run Notes
- Tested on Windows 11 using the GCC compiler

## Build Instructions
```powershell
gcc main.c convert.c -o program
.\program.exe
```

## Test Results
Test 1: oct_to_bin(725) -> Expected: "111010101", Got: "111010101" [PASS]
Test 2: oct_to_bin(345) -> Expected: "011100101", Got: "011100101" [PASS]
Test 3: oct_to_bin(777) -> Expected: "111111111", Got: "111111111" [PASS]
Test 4: oct_to_bin(0) -> Expected: "0", Got: "0" [PASS]
Test 5: oct_to_bin(1) -> Expected: "001", Got: "001" [PASS]
Test 6: oct_to_bin(7) -> Expected: "111", Got: "111" [PASS]
Test 7: oct_to_bin(10) -> Expected: "001000", Got: "001000" [PASS]
Test 8: oct_to_bin(100) -> Expected: "001000000", Got: "001000000" [PASS]
Test 9: oct_to_bin(377) -> Expected: "011111111", Got: "011111111" [PASS]
Test 10: oct_to_hex(345) -> Expected: "E5", Got: "E5" [PASS]
Test 11: oct_to_hex(777) -> Expected: "1FF", Got: "1FF" [PASS]
Test 12: oct_to_hex(100) -> Expected: "40", Got: "40" [PASS]
Test 13: oct_to_hex(0) -> Expected: "0", Got: "0" [PASS]
Test 14: oct_to_hex(1) -> Expected: "1", Got: "1" [PASS]
Test 15: oct_to_hex(7) -> Expected: "7", Got: "7" [PASS]
Test 16: oct_to_hex(1234) -> Expected: "29C", Got: "29C" [PASS]
Test 17: oct_to_hex(7654) -> Expected: "FAC", Got: "FAC" [PASS]
Test 18: hex_to_bin(A3) -> Expected: "10100011", Got: "10100011" [PASS]
Test 19: hex_to_bin(FF) -> Expected: "11111111", Got: "11111111" [PASS]
Test 20: hex_to_bin(1A) -> Expected: "00011010", Got: "00011010" [PASS]
Test 21: hex_to_bin(a3) -> Expected: "10100011", Got: "10100011" [PASS]
Test 22: hex_to_bin(Ff) -> Expected: "11111111", Got: "11111111" [PASS]
Test 23: hex_to_bin(aC) -> Expected: "10101100", Got: "10101100" [PASS]
Test 24: hex_to_bin(0) -> Expected: "0000", Got: "0000" [PASS]
Test 25: hex_to_bin(1) -> Expected: "0001", Got: "0001" [PASS]
Test 26: hex_to_bin(F) -> Expected: "1111", Got: "1111" [PASS]
Test 27: hex_to_bin(CAFE) -> Expected: "1100101011111110", Got: "1100101011111110" [PASS]
Test 28: hex_to_bin(1234) -> Expected: "0001001000110100", Got: "0001001000110100" [PASS]
Test 29: to_sign_magnitude(5) -> Expected: "00000000000000000000000000000101", Got: "00000000000000000000000000000101" [PASS]
Test 30: to_sign_magnitude(1) -> Expected: "00000000000000000000000000000001", Got: "00000000000000000000000000000001" [PASS]
Test 31: to_sign_magnitude(255) -> Expected: "00000000000000000000000011111111", Got: "00000000000000000000000011111111" [PASS]
Test 32: to_sign_magnitude(-5) -> Expected: "10000000000000000000000000000101", Got: "10000000000000000000000000000101" [PASS]
Test 33: to_sign_magnitude(-1) -> Expected: "10000000000000000000000000000001", Got: "10000000000000000000000000000001" [PASS]
Test 34: to_sign_magnitude(-255) -> Expected: "10000000000000000000000011111111", Got: "10000000000000000000000011111111" [PASS]
Test 35: to_sign_magnitude(0) -> Expected: "00000000000000000000000000000000", Got: "00000000000000000000000000000000" [PASS]
Test 36: to_ones_complement(5) -> Expected: "00000000000000000000000000000101", Got: "00000000000000000000000000000101" [PASS]
Test 37: to_ones_complement(1) -> Expected: "00000000000000000000000000000001", Got: "00000000000000000000000000000001" [PASS]
Test 38: to_ones_complement(255) -> Expected: "00000000000000000000000011111111", Got: "00000000000000000000000011111111" [PASS]
Test 39: to_ones_complement(-5) -> Expected: "11111111111111111111111111111010", Got: "11111111111111111111111111111010" [PASS]
Test 40: to_ones_complement(-1) -> Expected: "11111111111111111111111111111110", Got: "11111111111111111111111111111110" [PASS]
Test 41: to_ones_complement(-255) -> Expected: "11111111111111111111111100000000", Got: "11111111111111111111111100000000" [PASS]
Test 42: to_ones_complement(0) -> Expected: "00000000000000000000000000000000", Got: "00000000000000000000000000000000" [PASS]
Test 43: to_twos_complement(5) -> Expected: "00000000000000000000000000000101", Got: "00000000000000000000000000000101" [PASS]
Test 44: to_twos_complement(1) -> Expected: "00000000000000000000000000000001", Got: "00000000000000000000000000000001" [PASS]
Test 45: to_twos_complement(255) -> Expected: "00000000000000000000000011111111", Got: "00000000000000000000000011111111" [PASS]
Test 46: to_twos_complement(-5) -> Expected: "11111111111111111111111111111011", Got: "11111111111111111111111111111011" [PASS]
Test 47: to_twos_complement(-1) -> Expected: "11111111111111111111111111111111", Got: "11111111111111111111111111111111" [PASS]
Test 48: to_twos_complement(-255) -> Expected: "11111111111111111111111100000001", Got: "11111111111111111111111100000001" [PASS]
Test 49: to_twos_complement(0) -> Expected: "00000000000000000000000000000000", Got: "00000000000000000000000000000000" [PASS]
Test 50: to_twos_complement(2147483647) -> Expected: "01111111111111111111111111111111", Got: "01111111111111111111111111111111" [PASS]
Test 51: to_twos_complement(-2147483648) -> Expected: "10000000000000000000000000000000", Got: "10000000000000000000000000000000" [PASS]
Summary: 51/51 tests passed
