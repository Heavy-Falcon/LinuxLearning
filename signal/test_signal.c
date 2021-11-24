#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void f(int signal_no) {
	printf("got a signal: %d\n", signal_no);
}

int main(int argc, char *argv[]) {
	while (1) {
		signal(2, f);		// 注册2号信号的捕捉方式为执行函数f
		sleep(1);
	}
	return 0;
}
