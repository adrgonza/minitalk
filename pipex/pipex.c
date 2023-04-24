# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>

void    pipex(int f1, int f2, char **argv)
{
	int end[2];
	pid_t parent;

	pipe(end);
	parent = fork();
	if (parent == 0)
		child_process(f1, cmd1);
	else
		parent_process(f2, cmd2);
}

int main (int argc, char ** argv, char **envp)
{
	if (argc != 5)
		return 0;
	pipex(open(argv[1], O_RDONLY), open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644), argv);
}
