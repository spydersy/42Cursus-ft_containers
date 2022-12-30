
BINS=	map.out vector.out stack.out

CPPFLAGS= -Wall -Werror -Wextra -std=c++98
DEFINE_FLAG= -D NAMESPACE=

all:  TEST00 TEST01

TEST00:
		clang++ $(CPPFLAGS) ./TESTS/TEST-00/Map_tests.cpp -o map.out       && clear && ./map.out
		clang++ $(CPPFLAGS) ./TESTS/TEST-00/Vector_tests.cpp -o vector.out && clear && ./vector.out
		clang++ $(CPPFLAGS) ./TESTS/TEST-00/Stack_tests.cpp  -o stack.out  && clear && ./stack.out

TEST01:
		cd TESTS/TEST-01/ && clear && ./start.sh -st
		cd TESTS/TEST-01/ && ./start.sh -v
		cd TESTS/TEST-01/ && ./start.sh -m

VECTOR:
		clang++ $(CPPFLAGS) ./TESTS/TEST-00/Vector_tests.cpp -o vector.out && ./vector.out
		cd TESTS/TEST-01/ && ./start.sh -v
STACK:
		clang++ $(CPPFLAGS) ./TESTS/TEST-00/Stack_tests.cpp -o stack.out && ./stack.out
		cd TESTS/TEST-01/ && ./start.sh -st
MAP:
		clang++ $(CPPFLAGS) ./TESTS/TEST-00/Map_tests.cpp -o map.out && ./map.out
		cd TESTS/TEST-01/ && ./start.sh --map

clean:
		rm -rf $(BINS)
		rm -rf *.out
		rm -rf *.dSYM

fclean:	clean

re : fclean all
