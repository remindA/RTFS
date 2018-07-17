/*
 * =====================================================================================
 *
 *       Filename:  man_example.c
 *
 *    Description:  man 3 ev的例子
 *
 *        Version:  1.0
 *        Created:  2018年07月14日 16时48分24秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <ev.h>
#include <stdio.h>

ev_io stdin_watcher;
ev_timer timeout_watcher;

static void stdin_cb(EV_P_ ev_io *w, int revents)
{
    puts("stdin ready");
    /* for one shot event, must manually stop the watcher */
    ev_io_stop(EV_A_  w);

    /* cause all nested ev_run()s to stop iterating */
    ev_break(EV_A_  EVBREAK_ALL);
}

static void timeout_cb(EV_P_  ev_timer *w, int revents)
{
    puts("timeout");

    /* cause the inner most ev_run to stop iterating */
    ev_break(EV_A_  EVBREAK_ONE);
}

int main()
{
    struct ev_loop *loop = EV_DEFAULT;
#if 0
    ev_io_init(&stdin_watcher, stdin_cb, 0, EV_READ);
    ev_io_start(loop, &stdin_watcher);
#endif

    ev_timer_init(&timeout_watcher, timeout_cb, 2, 0);
    ev_timer_start(loop, &timeout_watcher);

    ev_run(loop, 0);

    return 0;
}

