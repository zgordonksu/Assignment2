#include <stdio.h>
#include <string.h>
#include "convert.h"

int main() {
    
    // Create variables to store the total tests and passed tests
    int total = 0;
    int passes = 0;
    // Variable to hold each line
    char line[256];

    // Open the file
    FILE *fp = fopen("a2_test.txt", "r");

    // Check to see if the file was opened
    if (fp == NULL) {
        printf("Failed to open the file\n");
        return 1;
    }
    // Read each line
    while (fgets(line, sizeof(line), fp)) {
        // Remove the newline that was causing some cases to be tested multiple times
        line[strcspn(line, "\r\n")] = '\0';

        // Check to see if the line is a comment or is empty
        if (line[0] == '#' || line[0] == '\0') {
            continue;
        }

        // Check which method is being tested
        char method[32];
        sscanf(line, "%s", method);

        if (strcmp(method, "oct_to_bin") == 0 || strcmp(method, "oct_to_hex") == 0 || strcmp(method, "hex_to_bin") == 0) {
            char number[64];
            char expected[100];

            // Scan the number and expected result
            sscanf(line, "%*s %s %s", number, expected);

            char out[100];
            // Run the correct method
            if (strcmp(method, "oct_to_bin") == 0) {
                oct_to_bin(number, out);
            }
            else if (strcmp(method, "oct_to_hex") == 0) {
                oct_to_hex(number, out);
            }
            else {
                hex_to_bin(number, out);
            }

            // Check to see if the values match
            if (strcmp(out, expected) == 0) {
                // The test passed
                total++;
                passes++;

                printf("Test %d: %s(%s) -> Expected: \"%s\", Got: \"%s\" [PASS]\n",
                total, method, number, expected, out);
            }
            else {
                // The test failed
                total++;

                printf("Test %d: %s(%s) -> Expected: \"%s\", Got: \"%s\" [FAIL]\n",
                total, method, number, expected, out);
            }
        }
        else {
            // The method is to_sign_magnitude, to_ones_complement, or to_twos_complement
            char number[64];
            char expected[100];

            // Scan the number and expected result
            sscanf(line, "%*s %s %s", number, expected);

            int n = atoi(number);
            char out[100];

            // Run the correct method
            if (strcmp(method, "to_sign_magnitude") == 0) {
                to_sign_magnitude(n, out);
            }
            else if (strcmp(method, "to_ones_complement") == 0) {
                to_ones_complement(n, out);
            }
            else {
                to_twos_complement(n, out);
            }

            // Check to see if the values match
            if (strcmp(out, expected) == 0) {
                // The test passed
                total++;
                passes++;

                printf("Test %d: %s(%s) -> Expected: \"%s\", Got: \"%s\" [PASS]\n",
                total, method, number, expected, out);
            }
            else {
                // The test failed
                total++;

                printf("Test %d: %s(%s) -> Expected: \"%s\", Got: \"%s\" [FAIL]\n",
                total, method, number, expected, out);
            }
        }
    }
    // Show the summary
    printf("Summary: %d/%d tests passed\n", passes, total);

    // Close the file
    fclose(fp);
    return 0;
}