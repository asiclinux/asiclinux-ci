/*
 * AsicLinux - Linux on Apple M-series Macs
 * Copyright (C) 2026 AsicLinux Team
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */


#include "./include/conf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_ERROR(fmt, ...) fprintf(stderr, "[ERROR] " fmt "\n", ##__VA_ARGS__)
#define LOG_INFO(fmt, ...)  fprintf(stdout, "[INFO] " fmt "\n", ##__VA_ARGS__)

/**
 * load_config - Reads a key-value configuration file into memory
 * @filename: Path to the configuration file
 * @entries: Array of ConfigEntry structures to populate
 * @max_entries: Maximum number of entries to read
 *
 * Returns the number of entries successfully loaded,
 * or -1 on error.
 */
int load_config(const char *filename, ConfigEntry *entries, int max_entries) {
    if (!filename || !entries || max_entries <= 0) {
        LOG_ERROR("Invalid input parameters");
        return -1;
    }

    FILE *file = fopen(filename, "r");
    if (!file) {
        LOG_ERROR("Unable to open config file: %s", filename);
        return -1;
    }

    char line[CONFIG_MAX_LINE];
    int count = 0;

    while (fgets(line, sizeof(line), file) && count < max_entries) {
        // Skip comments and empty lines
        if (line[0] == '#' || line[0] == '\n') continue;

        // Remove trailing newline
        line[strcspn(line, "\r\n")] = '\0';

        // Split line into key and value
        char *eq = strchr(line, '=');
        if (!eq) {
            LOG_ERROR("Malformed config line: '%s'", line);
            continue;
        }

        *eq = '\0';
        char *key = line;
        char *value = eq + 1;

        // Trim whitespace from key and value
        while (*key == ' ' || *key == '\t') key++;
        while (*value == ' ' || *value == '\t') value++;

        // Copy key and value safely into struct
        strncpy(entries[count].key, key, CONFIG_MAX_KEY - 1);
        entries[count].key[CONFIG_MAX_KEY - 1] = '\0';

        strncpy(entries[count].value, value, CONFIG_MAX_VALUE - 1);
        entries[count].value[CONFIG_MAX_VALUE - 1] = '\0';

        LOG_INFO("Loaded config: %s=%s", entries[count].key, entries[count].value);

        count++;
    }

    fclose(file);
    return count;
}