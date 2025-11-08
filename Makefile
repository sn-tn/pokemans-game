PROGRAMS=battle_main

CXXFLAGS=-std=c++20 -O2 -g -Wall -Werror -pedantic-errors
LDFLAGS=-std=c++20

all: $(PROGRAMS)

battle_main: battle_main.o Monster.o
	g++ $(LDFLAGS) $^ -o $@

clean:
	rm -rf $(PROGRAMS) *.o