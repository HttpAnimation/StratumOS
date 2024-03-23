#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1024]; // Buffer to store user input

    // Display the initial prompt
    printf("/ ");

    // Continuously read user input and execute commands
    while (fgets(input, sizeof(input), stdin) != NULL) {
        // Remove the newline character at the end of the input
        input[strcspn(input, "\n")] = '\0';

        // Check if the input is empty
        if (strlen(input) == 0) {
            // Display the prompt again
            printf("/ ");
            continue;
        }

        // Check if the input starts with '/'
        if (input[0] == '/') {
            // Execute the command within the program
            system(input + 1); // Skip the first character '/'
        } else {
            // Execute the command directly
            system(input);
        }

        // Display the prompt again
        printf("/ ");
    }

    return 0;
}
