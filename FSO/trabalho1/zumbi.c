#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

volatile sig_atomic_t stage = 0;
pid_t zombie_pid = -1;

void handler(int sig) {
    if (stage == 0) {
        pid_t pid = fork();
        if (pid == 0) {
            exit(0);
        } else if (pid > 0) {
            zombie_pid = pid;
        }
        stage = 1;
    } 
    else if (stage == 1) {
        if (zombie_pid > 0) {
            waitpid(zombie_pid, NULL, 0);
            zombie_pid = -1;
        }
        stage = 2;
    } 
    else if (stage == 2) {
        exit(0);
    }
}

int main(void) {
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while (1) {
        pause(); 
    }

    return 0;
}