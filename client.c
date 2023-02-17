#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char **argv)
{
	int pid;
    int i;

    if(argc != 3)
        return(write(1, "\033[31mError:\nTry: ./.. 'pid' 'str'", 34));
    i = 0;
    while(argv[1][i])
        if(argv[1][i++] < '0' || argv[1][i] > '9')
            return(write(1, "\033[31mError: Invalid Pid...\n", 28));
    pid = atoi(argv[1]);
    while (*argv[2])
    {
        i = 8;
	    while (i--)
	    {
		    if (*argv[2] >> i & 1)
			    kill(pid, SIGUSR1);
		    else
			    kill(pid, SIGUSR2);
		    usleep(200);
	    }
        argv[2]++;
    }
}