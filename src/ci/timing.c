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
#include "./include/time_utils.h"

time_t start_time_init(void) {
    time_t t = time(NULL);
    if (t == ((time_t)-1)) {
        printf("Error getting startup time.\n");
    }
    return t;
}

double get_elapsed_seconds(time_t start_time) {
    time_t now = time(NULL);
    return difftime(now, start_time);
}

void print_elapsed_time(double elapsed) {
    int hours = (int)elapsed / 3600;
    int minutes = ((int)elapsed % 3600) / 60;
    int seconds = (int)elapsed % 60;
    printf("Elapsed time: %02d:%02d:%02d\n", hours, minutes, seconds);
}