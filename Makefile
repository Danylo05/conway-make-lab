CC      = gcc
CFLAGS  = -Wall -Wextra -O2
TARGET  = conway
PREFIX ?= $(HOME)/.local
BINDIR  = $(PREFIX)/bin

SRCS = main.c conway.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c conway.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

install: $(TARGET)
	install -d $(DESTDIR)$(BINDIR)
	install -m 0755 $(TARGET) $(DESTDIR)$(BINDIR)/$(TARGET)

.PHONY: all clean install
