#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

void oct_to_bin(const char *oct, char *out) {

    // // Handle the zero case
    // if (strcmp(oct, "0") == 0) {
    //     strcpy(out, "0");
    //     return;
    // }
    
    uint32_t pos = 0;

    // Create the Octal to Binary Mapping Table
    const char *table[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};

    // Get the length of the oct string
    int length = strlen(oct);

    // Loop through the oct string
    for (int i = 0; i < length; i++) {
        // Convert the digit to binary and add it to the output
        uint32_t number = (uint32_t)(oct[i] - '0');
        const char *temp = table[number];
        
        out[pos++] = temp[0];
        out[pos++] = temp[1];
        out[pos++] = temp[2];
    }

    // Add the null terminator
    out[pos] = '\0';
}

void oct_to_hex(const char *oct, char *out) {
    // Handle the zero case
    if (strlen(oct) == 1 && oct[0] == '0') {
        strcpy(out, "0");
        return;
    }

    // Convert to binary using the method above
    char binary[50];
    oct_to_bin(oct, binary);

    // Group by 4 part
    int bin_length = strlen(binary);

    // Figure out the amount of extra 0's that are needed
    int padding = 4 - (bin_length % 4);
    // Do it 1 more time for the cases where the length is evenly divisible by 4
    padding %= 4;

    // Add the extra 0's
    // Move the null terminator
    binary[bin_length + padding] = '\0';

    // Shift over the existing numbers
    for (int i = bin_length - 1; i >= 0; i--) {
        binary[i + padding] = binary[i];
    }

    // Add the extra 0's
    for (int i = 0; i < padding; i++) {
        binary[i] = '0';
    }

    // Converting to hex
    // Table for simplicity
    const char table[] = "0123456789ABCDEF";
    
    // Update the length
    bin_length += padding;
    uint32_t pos = 0;
    int value = 0;

    for (int i = 0; i < bin_length; i += 4) {
        // Calculate the value of each group of 4
        value += (binary[i] - '0') * 8;
        value += (binary[i + 1] - '0') * 4;
        value += (binary[i + 2] - '0') * 2;
        value += binary[i + 3] - '0';

        // Add it to the string
        out[pos++] = table[value];

        // Reset value
        value = 0;
    }

    // Add the null terminator
    out[pos] = '\0';

    // Get rid of the 0's at the beginning that are causing me to fail test cases
    if (out[0] == '0') {
        int temp = 0;

        // Search for the index of the first nonzero character
        while (out[temp] == '0') {
            temp++;
        }

        // Shift everything to the left by the amount of temp
        int i = 0;
        while (out[temp] != '\0') {
            out[i++] = out[temp++];
        }
        // Add back the null terminator
        out[i] = '\0';
    }
}

void hex_to_bin(const char *hex, char *out) {
    // Handle the zero case
    if (strlen(hex) == 1 && hex[0] == '0') {
        strcpy(out, "0000");
        return;
    }

    int hex_length = strlen(hex);
    uint32_t pos = 0;

    // Table for simplicity
    const char *table[16] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};

    for (int i = 0; i < hex_length; i++) {
        // Convert each number to decimal
        int decimal = 0;
        if (hex[i] <= '9') {
            decimal = hex[i] - '0';
        }
        else if (hex[i] <= 'F') {
            decimal = hex[i] - 'A' + 10;
        }
        else {
            decimal = hex[i] - 'a' + 10;
        }

        // Look up the value
        const char *temp = table[decimal];
        out[pos++] = temp[0];
        out[pos++] = temp[1];
        out[pos++] = temp[2];
        out[pos++] = temp[3];
    }

    // Add the null terminator
    out[pos] = '\0';
}

void to_sign_magnitude(int n, char *out) {
    // Decide the leading bit
    if (n >= 0) {
        out[0] = '0';
    }
    else {
        out[0] = '1';
        // Convert the negative to positive
        n = abs(n);
    }

    // The other numbers
    // Noticed I can do this from 3.3 Quick Reference
    for (int i = 30; i >= 0; i--) {
        // Shift i bits to the right and do AND with 1 to get the bit 
        out[31 - i] = ((n >> i) & 1) + '0';
    }

    // Add the null terminator
    out[32] = '\0';
}

void to_ones_complement(int n, char *out) {
    if (n >= 0) {
        // No need to rewrite the exact same thing as to_sign_magnitude
        to_sign_magnitude(n, out);
        return;
    }
    else {
        // Make it positive
        uint32_t magnitude = (uint32_t)(-n);

        // Found this inside of the bitwise operators link from Assignment 1 after I coded my own version
        uint32_t flipped = ~magnitude;
        // Do the same thing as to_sign_magnitude
        for (int i = 32; i >= 0; i--) {
            int temp = (flipped >> i) & 1;
            out[31 - i] = temp + '0';
        }
    }

    // Add the null terminator
    out[32] = '\0';
}

void to_twos_complement(int n, char *out) {
    if (n >= 0) {
        // No need to rewrite the exact same thing as to_sign_magnitude
        to_sign_magnitude(n, out);
        return;
    }
    else {
        // Make it positive
        uint32_t magnitude = (uint32_t)(-n);

        // Flip every bit and add 1
        uint32_t flipped = ~magnitude + 1;

        // Add the bits to output
        for (int i = 32; i >= 0; i--) {
            int temp = (flipped >> i) & 1;
            out[31 - i] = temp + '0';
        }
    }

    // Add the null terminator
    out[32] = '\0';
}