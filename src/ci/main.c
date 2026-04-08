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

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "./include/app.h"
#include "./include/meta.h"




int main() {
    time_t start_time, current_time;
    double elapsed;

    start_time = time(NULL);
    if (start_time == ((time_t)-1)) {
        printf("Error getting startup time.\n");
    }

    printf("System Started...\n");
    printf("Author: %s\n", AUTHOR);
    printf("TODO: %s\n", VERSION);

    // Simple simulation
    for (int i = 0; i < 5; i++) {
        sleep(1);
        current_time = time(NULL);
        elapsed = difftime(current_time, start_time);
        printf("Elapsed time: %.0f seconds\n", elapsed);
    }

    current_time = time(NULL);
    elapsed = difftime(current_time, start_time);
    printf("System shutting down. Total uptime: %.0f seconds\n", elapsed);
}