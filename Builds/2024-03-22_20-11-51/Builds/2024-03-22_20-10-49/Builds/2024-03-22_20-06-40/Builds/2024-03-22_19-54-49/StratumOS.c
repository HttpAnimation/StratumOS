#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check if there are enough arguments
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    // Form the command to be executed
    char command[1024] = "host ";
    for (int i = 1; i < argc; ++i) {
        strcat(command, argv[i]);
        strcat(command, " ");
    }

    // Execute the command based on the platform
    #ifdef _WIN32
        system(command);
    #elif __APPLE__
        // For macOS, you can use the `system()` function as well
        system(command);
    #else
        // For Linux, you may need to use the `popen()` function
        FILE *fp = popen(command, "r");
        if (fp == NULL) {
            perror("Error executing command");
            return 1;
        }
        char buffer[1024];
        while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            printf("%s", buffer);
        }
        pclose(fp);
    #endif

    return 0;
}
