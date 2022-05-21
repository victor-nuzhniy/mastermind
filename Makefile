my_mastermind: main.c my_mastermind.c
	gcc -Wall -Wextra -Werror -c main.c -o main.o
	gcc -Wall -Wextra -Werror -c my_mastermind.c -o my_mastermind.o
	gcc -Wall -Wextra -Werror main.o my_mastermind.o -o my_mastermind
