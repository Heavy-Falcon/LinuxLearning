#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
	int pipe_id[2];
	pipe(pipe_id);
	pid_t pid = fork();
	if (pid) {
		// father, read
		close(pipe_id[1]);
		char buffer[32];
		int cnt = 100;
		while (1) {
			ssize_t l = read(pipe_id[0], buffer, sizeof buffer - 1);
			if (l) {
				buffer[l] = 0;
				printf("father gets: %s", buffer);
			}
			if (cnt -- == 0) {
				close(pipe_id[0]);
				break;
			}
		}
		int sta;
		waitpid(pid, &sta, 0);
		printf("the signal that child gets: %d\n", sta & 0x7f);
	} else if (!pid) {
		// child, write
		close(pipe_id[0]);
		char *buf = "I am a child...\n";
		while (1) {
			write(pipe_id[1], buf, strlen(buf));
			sleep(1);
		}
	}
	return 0;	
}
