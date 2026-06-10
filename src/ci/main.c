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
#include "./include/app.h"
#include "./include/ci.h"
#include "./include/conf.h"
#include "./include/meta.h"
#include "./include/time_utils.h"
#include <stdio.h>
#include <unistd.h>

int main() {
  // Initialize uptime
  // time_t start_time = start_time_init();

  // ConfigEntry entries[100];
  // int n = load_config("../../config.cfg", entries, 100);

  // if (n < 0) {
  //   printf("Failed to load config\n");
  //   return 1;   
  // }

  // for (int i = 0; i < n; i++) {
  //   printf("%s = %s\n", entries[i].key, entries[i].value);
  // }

  // return 0;

    ci_run();

//   printf("System Started...\n");
//   printf("Author: %s\n", AUTHOR);
//   printf("Version: %s\n", VERSION);
//   ci_run();

//   // Simple simulation
//   for (int i = 0; i < 5; i++) {
//     sleep(1);
//     double elapsed = get_elapsed_seconds(start_time);
//     print_elapsed_time(elapsed);
//   }

//   // On shutdown
//   double elapsed = get_elapsed_seconds(start_time);
//   printf("System shutting down. Total uptime: ");
//   print_elapsed_time(elapsed);

//   return 0;
}