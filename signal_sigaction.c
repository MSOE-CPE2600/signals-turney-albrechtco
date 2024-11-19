/**
 * File: signal_sigaction.c
 * Modified by: Connor Albrecht
 * gcc signal_sigaction.c -o signal_sigaction
 * 
 * Brief summary of program:
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void handle_sigusr1(int sig, siginfo_t *info, void *context) {

    printf("Received SIGUSR1 from process with PID: %d\n", info->si_pid);
}

int main() {
    struct sigaction sa;

    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO; 
    sa.sa_sigaction = handle_sigusr1; 

    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("Error registering sigaction");
        return EXIT_FAILURE;
    }


    printf("Program running with PID: %d\n", getpid());
    printf("Waiting for SIGUSR1 signal...\n");


    while (1) {
        pause(); 
    }

    return 0;
}

