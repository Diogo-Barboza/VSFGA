#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/time.h>
#include <errno.h>
#include <string.h>

int error_flag = 0;

void handle_sinal(int signal) {
    if (signal == SIGUSR1) {
        error_flag = 1;
    }
}

double time_difference(struct timeval *start, struct timeval *end) {
    return (end->tv_sec - start->tv_sec) + 1e-6 * (end->tv_usec - start->tv_usec);
}

void proc_pai() {
    int child_status;
    struct timeval start, end;

    gettimeofday(&start, NULL);

    wait(&child_status);
    gettimeofday(&end, NULL);

    if (error_flag == 1) {
        printf("> Erro: %s\n", strerror(WEXITSTATUS(child_status)));
    }

    printf("> Demorou %0.1lf segundos, retornou %d\n", time_difference(&start, &end), WEXITSTATUS(child_status));
    fflush(stdout);
}

void proc_filho(const char *path, const char *args) {
    execl(path, path, args, NULL);

    kill(getppid(), SIGUSR1);
    _exit(errno);
}

int main(void) {
    char path[256], args[256];
    struct timeval initial_total_time, final_total_time;

    signal(SIGUSR1, handle_sinal);

    gettimeofday(&initial_total_time, NULL);

    while (scanf("%255s %255[^\n]", path, args) == 2) {
        error_flag = 0;
        pid_t pid = fork();

        if (pid == 0) {
            proc_filho(path, args);
        } else if (pid > 0) {
            proc_pai();
        } else {
            perror("fork");
        }
    }

    gettimeofday(&final_total_time, NULL);

    printf(">> O tempo total foi de %0.1lf segundos\n\n", time_difference(&initial_total_time, &final_total_time));
    return 0;
}