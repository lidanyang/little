CC=gcc
CFLAG=-g -c
LDFLAGS=
SOURCES=$(foreach d,.,$(wildcard $(addprefix ./*,.c)))
#HEADERS=$(foreach d,.,$(wildcard $(addprefix ./*,.h)))
OBJS=$(addsuffix .o, $(basename $(SOURCES)))
#OBJS=*.o
#BIN=$(patsubst %.c,%,$(wildcard *.c))

.PHONY:all 

all:$(OBJS) 
	$(CC) $(LDFLAGS) $^ -o main

.c.o: 
	$(CC) $(CFLAG) $(LDFLAGS) $< -o $@

tags:
	ctags -R 

cscope:
	cscope -Rbq


clean:
	rm -rf *.o a.out $(BIN) tags cscope.*
