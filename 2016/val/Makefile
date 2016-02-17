CC=g++
CPPFLAGS=-W -Wall -pedantic -std=c++11
LDFLAGS=-lm
EXEC=hashcode.out
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	@echo "Generate \"$(EXEC)\" launcher"
	@echo "Usage : ./hashcode.out [input filename] [output filename]"
	@$(CC) -o $@ $^ $(LDFLAGS)	

%.o: %.cpp
	@echo "Compile \"$<\""
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean: 
	@echo "Delete object files"
	@rm -rf *.o

mrproper: clean
	@echo "Delete \"$(EXEC)\" launcher"
	@rm -rf $(EXEC)

run : $(EXEC)
	@echo "Launch of $(EXEC)"
	@./$(EXEC)

valgrind: 
	@echo "Memory check"
	@valgrind --tool=memcheck ./$(EXEC)
