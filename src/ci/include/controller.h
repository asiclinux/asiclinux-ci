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

#ifndef ASICLINUX_CONTROLLER_H
#define ASICLINUX_CONTROLLER_H

#ifdef __cplusplus
extern "C" {
#endif

// Controller IDs (extern declaration only)
extern int controller_id[];        // Defined in a corresponding .c file
extern const int controller_id_count; // Number of controller IDs

/**
 * Initialize a controller by its ID.
 * @param controller_id The ID of the controller to initialize.
 * @return 0 on success, negative on error.
 */
int controller_init(int controller_id);

#ifdef __cplusplus
}
#endif

#endif // ASICLINUX_CONTROLLER_H