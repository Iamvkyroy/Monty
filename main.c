#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

int main(int argc, char *argv[]) {
    char *content = NULL;
    FILE *file;
    size_t size = 0;
    ssize_t read_line = 1;
    stack_t *stack = NULL;
    unsigned int counter = 0;

    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    bus.file = file;
    if (!file) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read_line = getline(&content, &size, file)) != -1) {
        if (read_line > 0) {
            bus.content = content;
            counter++;
            execute(content, &stack, counter, file);
        }
        free(content); // Free allocated memory
        content = NULL; // Reset pointer
    }

    free_stack(stack); // Free remaining stack elements
    fclose(file);
    return (0);
}
