#include "./include/conf.h"
#include <stdio.h>
#include <string.h>

int load_config(const char *filename, ConfigEntry *entries, int max_entries) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open config file");
        return -1;
    }

    char line[CONFIG_MAX_LINE];
    int count = 0;

    while (fgets(line, sizeof(line), file) && count < max_entries) {
        if (line[0] == '#' || line[0] == '\n') continue;

        line[strcspn(line, "\n")] = '\0';

        // Split at '='
        char *eq = strchr(line, '=');
        if (!eq) continue; 

        *eq = '\0';
        char *key = line;
        char *value = eq + 1;

        // Copy key and value into struct
        strncpy(entries[count].key, key, CONFIG_MAX_KEY - 1);
        entries[count].key[CONFIG_MAX_KEY - 1] = '\0';

        strncpy(entries[count].value, value, CONFIG_MAX_VALUE - 1);
        entries[count].value[CONFIG_MAX_VALUE - 1] = '\0';

        count++;
    }

    fclose(file);
    return count;
}