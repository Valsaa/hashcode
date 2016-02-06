CC=gcc
CFLAGS=-W -Wall -std=c99 -pedantic
LDFLAGS=-lm
EXEC=hashcode.out
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	@echo "Generate \"$(EXEC)\" launcher"
	@echo "Usage : ./hashcode.out [input filename] [output filename]"
	@$(CC) -o $@ $^ $(LDFLAGS)	

%.o: %.c
	@echo "Compile \"$<\""
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean: 
	@echo "Delete object files"
	@rm -rf *.o

mrproper: clean
	@echo "Delete \"$(EXEC)\" launcher"
	@rm -rf $(EXEC)
