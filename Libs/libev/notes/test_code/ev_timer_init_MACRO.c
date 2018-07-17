
static void timeout_cb(struct ev_loop *loop, ev_timer *w, int revents)
{
    puts("timeout");



}

int main()
{
    struct ev_loop *loop = ev_default_loop (0);
    /* ev_timer_init begin */
    do { 
        /* ev_init begin */
        do { 
            ((ev_watcher *)(void *)((&timeout_watcher)))->active = ((ev_watcher *)(void *)((&timeout_watcher)))->pending = 0; 
            ( (ev_watcher *)(void *)(((&timeout_watcher))))->priority = (0); 
            ((((&timeout_watcher)))->cb = ((timeout_cb)), memmove (&((ev_watcher *)(((&timeout_watcher))))->cb, &(((&timeout_watcher)))->cb, sizeof ((((&timeout_watcher)))->cb)));
        } 
        while (0); 
        /* ev_init end */

        /* ev_timer_set begin */
        do { 
            ((ev_watcher_time *)((&timeout_watcher)))->at = ((1)); 
            ((&timeout_watcher))->repeat = ((2)); 
        } 
        while (0); 
        /* ev_timer_set end */
    }
    while (0);

    /* ev_timer_init end */
    ev_timer_start(loop, &timeout_watcher);

    ev_run(loop, 0);

    return 0;
}
