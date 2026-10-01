#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LEN 256

char doc[MAX_LINES][MAX_LEN];
int line_count = 0;

void display_doc() {
    if (line_count == 0) {
        printf("[Document is empty]\n");
        return;
    }
    printf("\n--- DOCUMENT START ---\n");
    for (int i = 0; i < line_count; i++) {
        printf("%3d | %s\n", i + 1, doc[i]);
    }
    printf("--- DOCUMENT END ---\n\n");
}

void insert_line(int pos, const char *text) {
    if (line_count >= MAX_LINES) {
        printf("Error: Document is full (max %d lines).\n", MAX_LINES);
        return;
    }
    if (pos < 1 || pos > line_count + 1) {
        printf("Error: Line number out of range. Valid range: [1, %d]\n", line_count + 1);
        return;
    }

    int idx = pos - 1;
    for (int i = line_count; i > idx; i--) {
        strcpy(doc[i], doc[i - 1]);
    }
    strncpy(doc[idx], text, MAX_LEN - 1);
    doc[idx][MAX_LEN - 1] = '\0'; // Ensure null-termination
    line_count++;
    printf("Line inserted at position %d.\n", pos);
}

void delete_line(int pos) {
    if (line_count == 0) {
        printf("Error: Document is empty.\n");
        return;
    }
    if (pos < 1 || pos > line_count) {
        printf("Error: Line number out of range. Valid range: [1, %d]\n", line_count);
        return;
    }

    int idx = pos - 1;
    for (int i = idx; i < line_count - 1; i++) {
        strcpy(doc[i], doc[i + 1]);
    }
    line_count--;
    printf("Line %d deleted.\n", pos);
}

int main() {
    char input[MAX_LEN + 50];

    printf("=======================================\n");
    printf("     Simple Command-Line Line Editor   \n");
    printf("=======================================\n");
    printf("Commands:\n");
    printf("  PRINT                    - Display document\n");
    printf("  INSERT <line_num> <text> - Insert line at position\n");
    printf("  DELETE <line_num>        - Delete line at position\n");
    printf("  EXIT                     - Quit editor\n");
    printf("=======================================\n\n");

    while (1) {
        printf("editor> ");
        if (!fgets(input, sizeof(input), stdin)) break;

        // Remove trailing newline
        input[strcspn(input, "\n")] = '\0';

        // Ignore empty lines
        if (strlen(input) == 0) continue;

        if (strcmp(input, "PRINT") == 0) {
            display_doc();
        } else if (strncmp(input, "INSERT ", 7) == 0) {
            int pos;
            char text[MAX_LEN];
            // Parse line number and remaining text space
            if (sscanf(input + 7, "%d %[^\n]", &pos, text) == 2) {
                insert_line(pos, text);
            } else {
                printf("Usage: INSERT <line_num> <text>\n");
            }
        } else if (strncmp(input, "DELETE ", 7) == 0) {
            int pos;
            if (sscanf(input + 7, "%d", &pos) == 1) {
                delete_line(pos);
            } else {
                printf("Usage: DELETE <line_num>\n");
            }
        } else if (strcmp(input, "EXIT") == 0) {
            printf("Exiting editor. Goodbye!\n");
            break;
        } else {
            printf("Unknown command. Available commands: PRINT, INSERT, DELETE, EXIT\n");
        }
    }

    return 0;
}