#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

#define MAX_TOKENS 64
#define DELIM " \t\r\n\a"

void parse_and_execute(char *input) {
    char *tokens[MAX_TOKENS];
    char *token;
    int position = 0;

    // Tokenize the input string
    token = strtok(input, DELIM);
    while (token != NULL) {
        tokens[position] = token;
        position++;
        token = strtok(NULL, DELIM);
    }
    tokens[position] = NULL; // Null-terminate the token array

    // Simulate execution by printing the tokens
    if (position > 0) {
        printf("Parsed command: \n");
        for (int i = 0; i < position; i++) {
            printf("Token %d: %s\n", i, tokens[i]);
        }
    }
}

int main() {
    char *input;
    char prompt[] = "myshell> ";

    while (1) {
        // Read input from user
        input = readline(prompt);

        // Add command to history
        if (input && *input) {
            add_history(input);
        }

        // Exit condition for "exit" command
        if (strcmp(input, "exit") == 0) {
            free(input);
            break;
        }

        // Parse and execute the command
        parse_and_execute(input);

        // Free the input buffer
        free(input);
    }

    return 0;
}
