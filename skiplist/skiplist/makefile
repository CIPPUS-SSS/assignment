OBJS=testmain.o skiplist.o
CC=gcc
DEPS=skiplist.h
EXE=testmain

$(EXE):$(OBJS)
	$(CC) -o $@ $^

%.o:%.c $(DEPS)
	$(CC) -c -o $@ $<

clean:
	rm $(OBJS) $(EXE)
