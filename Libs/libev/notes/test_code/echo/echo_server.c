/*
 * =====================================================================================
 *
 *       Filename:  echo_server.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2018年07月16日 20时03分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <sys/stat.h>

#include <ev.h>

void echo_rd_cb(struct ev_loop *loop, ev_io *w, int revents)
{
    char buff[1024];
    int ret = read(w->fd, buff, sizeof(buff));
    if(ret > 0) {
        if(write(w->fd, buff, ret) < 0) {
            perror("write()");
        }
        return;
    }
    else if(ret == 0) {
        printf("client offline\n");
    }
    else {
        perror("read()");
    }
    close(w->fd);
    ev_io_stop(loop, w);
    free(w);
}

void listen_cb(struct ev_loop *loop, ev_io *w, int revents)
{
    struct sockaddr_in peer;
    memset(&peer, 0, sizeof(peer));
    socklen_t len = sizeof(peer);
    
    int fd = accept(w->fd, (struct sockaddr *)&peer, &len);
    if(fd < 0) {
        perror("accept()");
    }
    else {
        printf("client %s:%d online\n", inet_ntoa(peer.sin_addr), ntohs(peer.sin_port));
        ev_io *io_w = (ev_io *)calloc(1, sizeof(*io_w));
        if(NULL == io_w) {
            perror("calloc");
        }
        else {
            ev_io_init(io_w, echo_rd_cb, fd, EV_READ);
            ev_io_start(loop, io_w);
        }
    }
}

int main(int argc, char **argv)
{
    if(argc != 3) {
        printf("Usage: %s ip port\n", argv[0]);
        return 0;
    }
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd < 0) {
        perror("socket()");
        exit(0);
    }
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &(server_addr.sin_addr));
    server_addr.sin_port = htons(atoi(argv[2]));

    if(bind(fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind()");
        close(fd);
        exit(0);
    }

    if(listen(fd, 100) < 0) {
        perror("listen()");
        close(fd);
        exit(0);
    }

    struct ev_loop *loop = EV_DEFAULT;
    ev_io listen_watcher;
    ev_io_init(&listen_watcher, listen_cb, fd, EV_READ);
    ev_io_start(loop, &listen_watcher);
    ev_run(loop, 0);


    return 0;
}

