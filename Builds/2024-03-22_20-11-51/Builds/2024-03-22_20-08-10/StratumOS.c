#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1000

void execute_command(const char *command) {
    system(command);
}

int main() {
    char input[MAX_COMMAND_LENGTH];

    printf("Welcome to Custom OS Terminal!\n");
    printf("Type 'exit' to quit.\n");

    while (1) {
        system("clear");
        printf(">> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // remove trailing newline
        
        if (strcmp(input, "exit") == 0) {
            printf("Exiting...\n");
            break;
        } else if (strncmp(input, "/host ", 6) == 0) {
            // Extract the command after '/host' keyword
            const char *host_command = input + 6;
            execute_command(host_command);
        } else {
            printf("Unknown command: %s\n", input);
        }
    }

    return 0;
}

