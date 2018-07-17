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
#include <stdio.h>

void stdin_rd_cb(struct ev_loop *loop, ev_io *w, int revents)
{
    int ret;
    char buff[1024] = {0};
    ret = read(0, buff, 1024);
    printf("read from stdin: %d bytes\n", ret);
    printf("%s", buff);
    //ev_io_stop(loop, w);
}

int main(int argc, char **argv)
{
    struct ev_loop *loop = EV_DEFAULT;

    ev_io io_w;
    ev_io_init(&io_w, stdin_rd_cb, 0, EV_READ);
    ev_io_start(loop, &io_w);

    ev_run(loop, 0);

    return 0;
}

