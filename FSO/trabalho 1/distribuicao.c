#include <stdio.h>
#include <pthread.h>

int count = 0;
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

struct thread_arg
{
    int vezes
};

void *thread_func(void *arg)
{
    int id = 0;
    struct thread_arg *auxiliar = arg;

    for (int i = 0; i < auxiliar->vezes; i++)
    {
        pthread_mutex_lock(&mut);
        count++;
        id = count;
        pthread_mutex_unlock(&mut);
        work(id);
    }
}
