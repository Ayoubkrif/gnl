test : 
	cc -Wall -Wextra -Werror *.c && ./a.out
vtest : 
	cc -Wall -Wextra -Werror *.c && valgrind ./a.out
