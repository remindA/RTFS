/*
 * =====================================================================================
 *
 *       Filename:  ev.h.note.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2018年07月15日 10时49分48秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

/*
 * active:
 * pending:
 * priority:
 * *data:
 * *cb: WATCHER对应的回调函数
 */
#define EV_WATCHER(type)    \
    int active;             \
    int pending;            \
    int priority;            \
    void *data;             \
    void (*cb)(struct ev_loop *loop, struct type *w, int revents);

/* 回调函数形如
 * void cb(struct ev_loop *loop, struct ev_io *w, int revents);
 * void cb(struct ev_loop *loop, struct ev_timer *w, int revents);
 * void cb(struct ev_loop *loop, struct ev_signal *w, int revents);
 */

#define EV_WATCHER_LIST(type) \
    int active;             \
    int pending;            \
    int priority;            \
    void *data;             \
    void (*cb)(struct ev_loop *loop, struct type *w, int revents); \
    struct ev_watcher_list *next;

#define EV_WATCHER_TIME(type) \
    int active;             \
    int pending;            \
    int priority;            \
    void *data;             \
    void (*cb)(struct ev_loop *loop, struct type *w, int revents); \
    ev_tstamp at;

typedef struct ev_watcher{
    int active;
    int pending;
    int priority;
    void *data;
    void (*cb)(struct ev_loop *loop, struct ev_watcher *w, int revents);
}ev_watcher;

/* 单链表:存放ev_watcher链 */
typedef struct ev_watcher_list {
    int active;
    int pending;
    int priority;
    void *data;
    void (*cb)(struct ev_loop *loop, struct ev_watcher_list *w, int revents);
    /* above exist as one whole */

    struct ev_watcher_list *next;
}ev_watcher_list;

typedef struct ev_watcher_time {
    int active;
    int pending;
    int priority;
    void *data;
    void (*cb)(struct ev_loop *loop, struct ev_watcher_time *w, int revents);
    /* above exist as one whole */

    ev_tstamp at;
}

typedef struct ev_io {
    int active;
    int pending;
    int priority;
    void *data;
    void (*cb)(struct ev_loop *loop, struct ev_io *w, int revents);
    struct ev_watcher_list *next;
    /* above exist as one whole */

    int fd;
    int events;
}

typedef struct ev_timer {
    int active;
    int pending;
    int priority;
    void *data;
    void (*cb)(struct ev_loop *loop, struct ev_timer *w, int revents);
    /* above exist as one whole */
    
    ev_tstamp at;
    ev_tstamp repeat;
}ev_timer;

typedef struct ev_signal {
    int active;
    int pending;
    int priority;
    void *data;
    void (*cb)(struct ev_loop *loop, struct ev_signal *w, int revents);
    /* above exist as one whole */

    struct ev_watcher_list *next;
    int signum;
}ev_signal;

/*
 * en_init(ev, cb_)宏
 */

#define ev_init(ev, cb_) \
    do { \
        ((ev_watcher *)(void *)(ev))->active = 0;\
        ((ev_watcher *)(void *)(ev))->pending = 0;\
    }while(0)\
    \
    /* ev_set_priority(ev, 0); 展开 */\
    ((ev_watcher *)(void  *)(ev))->priority = (0); \
    \
    /* ev_set_cb(ev, cb_); 展开 */\
    ((ev)->cb = (cb_), memmove(&((ev_watcher *)(void *)(ev))->cb, &(ev)->cb, sizeof((ev)->cb)) );



#define ev_set_priority(ev, pri) \
   ((ev_watcher *)(void *)(ev))->priority = (pri)


/*
 * ev_set_cb(ev, cb_)
 * 这个宏就是一个赋值
 * 等号右边，一个逗号前的(cb_)有什么用处?
 */
#define ev_set_cb(ev, cb_) \
    ((ev)->cb = (cb_), memmove(&((ev_watcher *)(void *)(ev)->cb), &(ev)->cb, sizeof(&(ev)->cb)) )
    

