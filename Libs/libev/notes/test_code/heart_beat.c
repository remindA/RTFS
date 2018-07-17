/*
 * =====================================================================================
 *
 *       Filename:  read_stdin.c
 *
 *    Description:  从stdin读取，然后printf
 *
 *        Version:  1.0
 *        Created:  2018年07月15日 15时41分03秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <ev.h>
#include <time.h>
#include <stdio.h>
#include <sys/time.h>

void hb_cb(struct ev_loop *loop, ev_timer *w, int revents)
{
    printf("heart beat %ld\n", time(NULL));
    //ev_io_stop(loop, w);
}

int main(int argc, char **argv)
{
    struct ev_loop *loop = EV_DEFAULT;

    ev_timer timer_hb_w;
    ev_timer_init(&timer_hb_w, hb_cb, 1., 0.);
    ev_timer_start(loop, &timer_hb_w);

    ev_run(loop, 0);

    return 0;
}

