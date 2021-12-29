
#include "uv.h"


#include <stdio.h>


uv_loop_t* loop;

void timer_cb1(uv_timer_t* timer, int status) {
	printf("timer_cb1 %d\n", status);
}

void timer_cb2(uv_timer_t* timer, int status) {
	printf("timer_cb2 %d\n", status);
}

int main() {
	loop = uv_default_loop();

	uv_timer_t timer1;
	uv_timer_init(loop, &timer1);
	uv_timer_start(&timer1, (uv_timer_cb)&timer_cb1, 1000, 1000);

	uv_timer_t timer2;
	uv_timer_init(loop, &timer2);
	uv_timer_start(&timer2, (uv_timer_cb)&timer_cb2, 500, 1000);

	uv_run(loop, UV_RUN_DEFAULT);
	return 0;
}