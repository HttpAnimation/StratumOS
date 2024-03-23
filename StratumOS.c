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

        // Execute the command
        #ifdef _WIN32
            system(input);
        #elif __APPLE__
            system(input);
        #else
            // For Linux, you may need to use the `popen()` function
            FILE *fp = popen(input, "r");
            if (fp == NULL) {
                perror("Error executing command");
            } else {
                char buffer[1024];
                while (fgets(buffer, sizeof(buffer), fp) != NULL) {
                    printf("%s", buffer);
                }
                pclose(fp);
            }
        #endif

        // Display the prompt again
        printf("/ ");
    }

    return 0;
}
