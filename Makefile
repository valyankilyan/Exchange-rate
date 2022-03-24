CC = g++
# FLAGS = -Wextra -Wall -g -c
FLAGS = -lcurl -Wall -g -c
DIR = src
MODULES = Rate.o OnePrimeAPI.o CurrentExchangeUnit.o

all: modules er clean

er: main.o
	$(CC) $(MODULES) main.o -lcurl -o er

main.o: modules
	$(CC) $(FLAGS) $(DIR)/main.cpp

modules: $(MODULES)
	@echo "Modules compiled"

CurrentExchangeUnit.o:
	@echo "CurrentExchangeUnit.o"
	$(CC) $(FLAGS) $(DIR)/CurrentExchangeUnit.cpp

OnePrimeAPI.o:
	@echo "OnePrimeAPI.o"
	$(CC) $(FLAGS) $(DIR)/OnePrimeAPI.cpp

Rate.o:
	@echo "Rate.o"
	$(CC) $(FLAGS) $(DIR)/Rate.cpp


clean:
	rm -f $(MODULES) main.o