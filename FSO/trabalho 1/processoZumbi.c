#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

void prevent(int s) { }

int main()
{
    signal(SIGUSR1, prevent);
    signal(SIGUSR2, prevent);
    pause();

    if (fork()==0)
        exit(0);    
    pause();
    wait(0);
    pause();

    return 0;
}