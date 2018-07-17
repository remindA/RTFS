
BIN = echo_server
OBJS = echo_server.o
CFLAGS = -Wall -Os
INCS = -I. -I./include
LIBS = -lev

all:$(BIN)

$(BIN):$(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LIBS) -o $(BIN)
%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(INCS)

clean:
	rm -rf $(BIN) $(OBJS)
