CC = gcc
CFLAGS = -Wall -I./include -L./lib 
SRCDIR = src
OBJDIR = obj
LIBS = -lm

SRCS = $(wildcard $(SRCDIR)/*.c)

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

.PHONY =  all lib clean

all: testradix

lib/libtests.a: $(OBJS)
	@mkdir -p lib
	ar rcs lib/libtests.a $^
	ranlib lib/libtests.a
	
testradix: test/testradix.c lib/libtests.a
	$(CC) $(CFLAGS)  $< -o $@ -ltests $(LIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $< -c -o $@
clean:
	@rm -rf testradix  lib $(OBJDIR)
