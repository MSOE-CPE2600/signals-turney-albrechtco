/**
 * File:   recv_signal.c  
 * Modified by: Connor Albrecht
 * gcc -o recv_signal recv_signal.c
 * 
 * Brief summary of program:  Receives SIGUSR1 and prints the custom integer value sent with the signal.
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void handle_sigusr1(int sig, siginfo_t *info, void *context) {
    printf("Received SIGUSR1 from process %d with value: %d\n", info->si_pid, info->si_value.sival_int);
}

int main() {
    // Set up sigaction
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO; 
    sa.sa_sigaction = handle_sigusr1; 

    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("Error setting up sigaction");
        return EXIT_FAILURE;
    }


    printf("Receiver running with PID: %d\n", getpid());
    printf("Waiting for SIGUSR1...\n");


    while (1) {
        pause(); 
    }

    return 0;
}
