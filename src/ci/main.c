#include <stdio.h>
#include <unistd.h>
#include "./include/app.h"
#include "./include/meta.h"
#include "./include/time_utils.h"
#include "./include/ci.h"

int main() {
    // Initialize uptime
    time_t start_time = start_time_init();

    printf("System Started...\n");
    printf("Author: %s\n", AUTHOR);
    printf("Version: %s\n", VERSION);
    ci_run();

    // Simple simulation
    for (int i = 0; i < 5; i++) {
        sleep(1);
        double elapsed = get_elapsed_seconds(start_time);
        print_elapsed_time(elapsed);
    }

    // On shutdown
    double elapsed = get_elapsed_seconds(start_time);
    printf("System shutting down. Total uptime: ");
    print_elapsed_time(elapsed);

    return 0;
}