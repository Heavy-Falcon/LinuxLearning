#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void f(int signal_no) {
	printf("got a signal: %d\n", signal_no);
}

// for test

int main(int argc, char *argv[]) {
	while (1) {
		signal(2, f);		// 将收到2号信号后的动作改为执行函数f，而不是终止进程
		sleep(1);
	}
	return 0;
}
