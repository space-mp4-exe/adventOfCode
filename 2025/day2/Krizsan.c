#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>

bool is_invalid(uint64_t num) {
    char buf[11];
    snprintf(buf, sizeof(buf), "%lu", num);
    if (strlen(buf) % 2 != 0) return false;
    int half_len = strlen(buf) / 2;
    char *half1 = malloc(half_len + 1);
    char *half2 = malloc(half_len + 1);
    memcpy(half1, buf, half_len);
    memcpy(half2, buf + half_len, half_len);
    half1[half_len] = '\0';
    half2[half_len] = '\0';
    bool invalid = strcmp(half1, half2) == 0;
    free(half1);
    free(half2);
    if (invalid) {
        printf("invalid id: %s%s\n");
        return true;
    }
    else return false;
}

int main(void) {
    FILE *f = fopen("input", "r");
    if (f == NULL) {
        printf("Failed to open input file.");
        return 1;
    }
    struct stat st;
    stat("input", &st);
    char *input = malloc(st.st_size + 1);
    char *current = input;
    fscanf(f, "%s", input);
    uint64_t counter = 0;
    char *sep = NULL;
    while (1) {
        sep = strchr(current, ',');
        if (sep == NULL) sep = input + strlen(input);
        char *buffer = malloc(sep - current + 1);
        strncpy(buffer, current, sep - current);
        buffer[sep - current] = '\0';
        uint64_t start;
        uint64_t end;
        sscanf(buffer, "%lu-%lu", &start, &end);
        for (uint64_t i = start; i < end + 1; i++) {
            if (is_invalid(i)) counter += i;
        }
        free(buffer);
        if (sep == input + strlen(input)) break;
        current = sep + 1;
    }
    free(input);
    fclose(f);
    printf("The answer is: %lu.", counter);
}
