OBJS=testmain.o rbtree.o
CC=gcc
DEPS=rbtree.h
EXE=testmain

#由o文件产生可执行文件
$(EXE):$(OBJS)
	$(CC) -o $@ $^

#有c文件生成o文件
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $<

clean:
	rm $(OBJS) $(EXE)
