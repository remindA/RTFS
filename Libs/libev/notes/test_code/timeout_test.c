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

ev_timer timeout_watcher;

static void timeout_cb(EV_P_  ev_timer *w, int revents)
{
    puts("timeout");

    /* cause the inner most ev_run to stop iterating */
    //ev_break(EV_A_  EVBREAK_CANCEL);
}

int main()
{
    struct ev_loop *loop = EV_DEFAULT;
    ev_timer_init(&timeout_watcher, timeout_cb, 1, 2);
    ev_timer_start(loop, &timeout_watcher);

    ev_run(loop, 0);

    return 0;
}

