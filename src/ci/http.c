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
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "./include/http.h"

struct Server server_Constructor(int domain, int port, int service, int protocol, int backlog, u_long interface, void (*launch)(struct Server *server)) {
    struct Server server;

    server.domain = domain;
    server.service = service;
    server.port = port;
    server.protocol = protocol;
    server.backlog = backlog;

    server.address.sin_family = domain;
    server.address.sin_port = htons(port);
    server.address.sin_addr.s_addr = htonl(interface);

    server.socket = socket(domain, service, protocol);
    if (server.socket < 0) {
        perror("Failed to initialize/connect to socket...\n");
        exit(EXIT_FAILURE);
    }

    if (bind(server.socket, (struct sockaddr*)&server.address, sizeof(server.address)) < 0) {
        perror("Failed to bind socket...\n");
        exit(EXIT_FAILURE);
    }

    if (listen(server.socket, server.backlog) < 0) {
        perror("Failed to start listening...\n");
        exit(EXIT_FAILURE);
    }

    server.launch = launch;
    return server;
}

void launch(struct Server *server) {
    char buffer[BUFFER_SIZE];
    while (1) {
        printf("=== WAITING FOR CONNECTION === \n");
        int addrlen = sizeof(server->address);
        int new_socket = accept(server->socket, (struct sockaddr*)&server->address, (socklen_t*)&addrlen);
        ssize_t bytesRead = read(new_socket, buffer, BUFFER_SIZE - 1);
        if (bytesRead >= 0) {
            buffer[bytesRead] = '\0';  // Null terminate the string
            puts(buffer);
        } else {
            perror("Error reading buffer...\n");
        }
        char *response = "HTTP/1.1 200 OK\r\n"
                         "Content-Type: text/html; charset=UTF-8\r\n\r\n"
                         "<!DOCTYPE html>\r\n"
                         "<html>\r\n"
                         "<head>\r\n"
                         "<title>AsicLinux - CI/CD</title>\r\n"
                         "</head>\r\n"
                         "<body>\r\n"
                         "Hello, Server!\r\n"
                         "</body>\r\n"
                         "</html>\r\n";
        write(new_socket, response, strlen(response));
        close(new_socket);
    }
}
