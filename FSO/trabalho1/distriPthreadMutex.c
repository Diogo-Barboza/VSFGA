#include <stdio.h>
#include <pthread.h>

int count;
pthread_mutex_t mut;

struct thread_arg
{
    int vezes;
};

int work(int id);

void *thread_func(void *arg)
{
    struct thread_arg *tArg = (struct thread_arg *)arg;
    for (int i = 0; i < tArg->vezes; i++)
    {
        int id;
        pthread_mutex_lock(&mut);
        id = count;
        count++;
        pthread_mutex_unlock(&mut);

        work(id);
    }
    return NULL;
}