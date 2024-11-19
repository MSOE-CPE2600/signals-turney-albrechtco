/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Connor ALbrecht 
 * gcc signal_segfault.c -o signal_segfault
 * 
 */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

/**
 * @brief Signal handler for SIGSEGV
 */
void handle_segfault(int signal) {
    if (signal == SIGSEGV) {
        printf("Segmentation fault caught! Dereferencing NULL pointer.\n");
        exit(1); // Exit the program gracefully after handling the signal
    }
}

int main(int argc, char* argv[]) {
    // Register the signal handler for SIGSEGV
    if (signal(SIGSEGV, handle_segfault) == SIG_ERR) {
        perror("Error registering signal handler");
        return 1;
    }

    // Declare a null pointer
    int* i = NULL;

    // Intentionally cause a segmentation fault
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}