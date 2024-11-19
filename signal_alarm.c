/**
 * File: signal_alarm.c
 * Modified by: Connor Albrecht
 * gcc signal_alarm.c -o signal_alarm
 * 
 * Brief summary of program: Schedules an alarm to trigger SIGALRM after 5 seconds and handles the signal.
 */

/**
 * @file signal_alarm.c
 * @brief Schedules an alarm to trigger SIGALRM after 5 seconds and handles the signal.
 */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>


void handle_alarm(int signal) {
    if (signal == SIGALRM) {
        printf("Alarm signal received!\n");
    }
}

int main() {

    if (signal(SIGALRM, handle_alarm) == SIG_ERR) {
        perror("Error registering signal handler");
        return 1;
    }


    printf("Scheduling an alarm for 5 seconds...\n");
    alarm(5);


    while (1) {
        pause(); 
    }

    return 0;
}
