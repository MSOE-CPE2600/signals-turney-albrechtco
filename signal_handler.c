/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and then continues running.
 */

/**
 * Modified by: Connor Albrecht
 * 
 * gcc signal_handler.c -o signal_handler
 * 
 * Brief summary of modifications:
 * - Modified the signal handler to prevent the program from exiting after handling SIGINT.
 */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// Counter for the number of SIGINT signals received
int sigint_count = 0;


void handle_signal(int signal) {
    sigint_count++;
    printf("Received SIGINT %d time(s)\n", sigint_count);
}

int main() {

    printf("Program running with PID: %d\n", getpid());

    // Register the signal handler for SIGINT
    if (signal(SIGINT, handle_signal) == SIG_ERR) {
        perror("Error registering signal handler");
        exit(EXIT_FAILURE);
    }

    // Loop indefinitely, printing a message and sleeping
    while (1) {
        printf("Sleeping\n");
        sleep(1);
    }

    return 0;
}
