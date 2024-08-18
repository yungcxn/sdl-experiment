CC = gcc
CFLAGS_COMMON = -DDEBUG_GAME -std=c99 -I./include
CFLAGS_NORMAL = $(CFLAGS_COMMON) -O3 -g3 -Wall -Wextra -Wshadow 
CFLAGS_LARGE = $(CFLAGS_COMMON) -flarge-source-files -fno-diagnostics-show-caret -ftrack-macro-expansion=0

LIBS = -lSDL2 -lSDL2_mixer
SRCS := $(shell find . -name '*.c')
OBJS := $(SRCS:.c=.o)
EXEC = experiment

.PHONY: all clean clean-obj

all: $(EXEC)

$(EXEC): $(OBJS)
	@$(CC) $(CFLAGS_COMMON) -o $@ $^ $(LIBS)

# Rule for building object files in src/resource with different flags
src/resource/%.o: src/resource/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS_LARGE) -c $< -o $@

# Rule for building object files elsewhere with the normal flags
%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS_NORMAL) -c $< -o $@

clean-obj:
	@find . -name '*.o' -type f -delete

clean:
	@find . -name '*.o' -type f -delete
	@rm -rf $(EXEC)

print-%:
	@echo '$*=$($*)'