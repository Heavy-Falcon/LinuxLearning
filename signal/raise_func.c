#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void f(int signal_no) {
	printf("got a signal: %d\n", signal_no);
}

int main(int argc, char *argv[]) {
	signal(9, f);		// 其实9号信号是不能被捕捉的，所以后面仍然会退出
	while (1) {
		raise(9);		// 自举，自己给自己发信号
		sleep(1);
	}
	return 0;
}
