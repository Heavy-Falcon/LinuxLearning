#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

long long cnt = 0;

void f(int signal_no) {
	printf("%lld\n", cnt);
	exit(0);
}

int main(int argc, char *argv[]) {
	signal(14, f);	// 注册14号信号
	alarm(1);		// 1秒后给自己发送14号信号，SIGALRM
	while (1) cnt ++ ;
	return 0;
}
