CC = g++
# FLAGS = -Wextra -Wall -g -c
FLAGS = -lcurl -Wall -g -c
DIR = src
MODULES = OnePrimeAPI.o main.o

all: modules er clean

er: main.o
	$(CC) $(MODULES) -lcurl -o er

main.o: modules
	$(CC) $(FLAGS) $(DIR)/main.cpp

modules: $(MODULES)
	@echo "Modules compiled"

ExchangeUnit.o:
	@echo "ExchangeUnit.o"
	$(CC) $(FLAGS) $(DIR)/ExchangeUnit.cpp

OnePrimeAPI.o:
	@echo "OnePrimeAPI.o"
	$(CC) $(FLAGS) $(DIR)/OnePrimeAPI.cpp

clean:
	rm -f $(MODULES)