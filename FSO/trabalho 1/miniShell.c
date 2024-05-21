#include <time.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	char script[255], arg[255];
	float tempor, tempototal = 0.0;
	struct timespec inicio, para;
	int returnvalor;
	while (scanf("%s %s", script, arg) != EOF)
	{
		fflush(stdout);
		timespec_get(&inicio, TIME_UTC);
		if (!fork())
		{
			execl(script, script, arg, (char *)NULL);
			printf("> Erro: %s\n", strerror(errno));
			returnvalor = errno;
			fclose(stdin);
			exit(errno);
		}
		else
		{
			wait(&returnvalor);
			timespec_get(&para, TIME_UTC);
			tempor = (para.tv_sec - inicio.tv_sec) + (para.tv_nsec - inicio.tv_nsec) / 1e9;
			printf("> Demorou %.1f segundos, retornou %d\n", tempor, WEXITSTATUS(returnvalor));
			tempototal += tempor;
		}
	}
	printf(">> O tempo total foi de %.1f segundos\n", tempototal);
	return 0;
}