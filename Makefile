CC = g++
FLAGS = -Wextra -Wall -g -c
DIR = src
MODULES = ExchangeUnit.o

all: modules er clean

er: main.o
	$(CC) $(MODULES) -o er

modules: ExchangeUnit.o
	@echo "Modules compiled"

ExchangeUnit.o:
	@echo "ExchangeUnit.o"
	$(CC) $(FLAGS) $(DIR)/ExchangeUnit.cpp

clean:
	rm -f $(MODULES)