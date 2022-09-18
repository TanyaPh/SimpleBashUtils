CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11

all: s21_cat

s21_cat: s21_cat.o
	$(CC) $(CFLAGS) s21_cat.o -o s21_cat
	@./s21_cat

s21_cat.o: s21_cat.c
	$(CC) $(CFLAGS) -c s21_cat.c -o s21_cat.o

re: clean all

clean: 
	@rm -rf *.o s21_cat

leak:
	CK_FORK=no leaks -atExit -- ./s21_cat

cpp:
	python3 ../../materials/linters/cpplint.py *.h
	python3 ../../materials/linters/cpplint.py *.c
	cppcheck s21_cat.c

valgrind:
	CK_FORK=no valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -s ./s21_cat
	# valgrind --leak-check=full --track-origins=yes --trace-children=yes -s ./s21_cat

