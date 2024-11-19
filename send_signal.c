/**
 * File: send_signal.c
 * Modified by: Connor Albrecht
 * gcc -o send_signal send_signal.c
 * 
 * Brief summary of program: Sends SIGUSR1 with a custom integer value to a specified process.
 */


#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <receiver_pid>\n", argv[0]);
        return EXIT_FAILURE;
    }

    pid_t receiver_pid = atoi(argv[1]);

    srand(time(NULL));

    int random_value = rand() % 100;

    union sigval value;
    value.sival_int = random_value;

    if (sigqueue(receiver_pid, SIGUSR1, value) == -1) {
        perror("Error sending signal");
        return EXIT_FAILURE;
    }

    printf("Sent SIGUSR1 to process %d with value: %d\n", receiver_pid, random_value);

    return 0;
}

