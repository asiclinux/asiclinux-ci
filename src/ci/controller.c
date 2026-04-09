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


#include "./include/controller.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define LOG_ERROR(fmt, ...) fprintf(stderr, "[ERROR] " fmt "\n", ##__VA_ARGS__)
#define LOG_INFO(fmt, ...)  fprintf(stdout, "[INFO] " fmt "\n", ##__VA_ARGS__)

int controller_id[] = {1, 2, 3};
const int controller_id_count = sizeof(controller_id) / sizeof(controller_id[0]);

static pthread_mutex_t controller_mutex = PTHREAD_MUTEX_INITIALIZER;

static int controllers_initialized[sizeof(controller_id) / sizeof(controller_id[0])] = {0};

/**
 * Initialize a controller by its ID.
 * Thread-safe and idempotent: re-initializing an already initialized controller is safe.
 */
int controller_init(int id) {
    int found = 0;
    int index = -1;

    // Find controller index
    for (int i = 0; i < controller_id_count; i++) {
        if (controller_id[i] == id) {
            found = 1;
            index = i;
            break;
        }
    }

    if (!found) {
        LOG_ERROR("Controller ID %d not found", id);
        return -1;
    }

    // Thread-safe initialization
    pthread_mutex_lock(&controller_mutex);

    if (controllers_initialized[index]) {
        LOG_INFO("Controller ID %d already initialized", id);
        pthread_mutex_unlock(&controller_mutex);
        return 0;  // Already initialized
    }

    // TODO: Add real initialization logic here
    LOG_INFO("Initializing controller ID %d...", id);
    controllers_initialized[index] = 1;

    pthread_mutex_unlock(&controller_mutex);
    LOG_INFO("Controller ID %d initialized successfully", id);

    return 0;
}
