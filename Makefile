CC = gcc
CFLAGS = -g3 -DDEBUG_GAME -Wall -Wextra -Wshadow -g -std=c99 -I./include -O3
LIBS = -lSDL2 -lSDL2_mixer
SRCS := $(shell find . -name '*.c')
OBJS := $(SRCS:.c=.o)
EXEC = experiment

.PHONY: all clean clean-obj

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# Rule for building object files
%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean-obj:
	find . -name '*.o' -type f -delete

clean:
	find . -name '*.o' -type f -delete
	rm -rf $(EXEC)

print-%:
	@echo '$*=$($*)'