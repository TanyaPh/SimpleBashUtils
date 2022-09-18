CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -g

all: s21_grep

s21_grep: s21_grep.o
	$(CC) $(CFLAGS) s21_grep.o -o s21_grep
	@./s21_grep

s21_grep.o: s21_grep.c
	$(CC) $(CFLAGS) -c s21_grep.c -o s21_grep.o

re: clean all

clean: 
	@rm -rf *.o s21_grep

leak:
	CK_FORK=no leaks -atExit -- ./s21_grep -e dream text.txt

cpp:
	python3 ../../materials/linters/cpplint.py *.c
	python3 ../../materials/linters/cpplint.py *.h
	cppcheck s21_grep.c

valgrind:
	CK_FORK=no valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -s ./s21_grep -e dream text.txt
    # valgrind --leak-check=full --track-origins=yes --trace-children=yes -s ./s21_grep

test1:
	make
	./s21_grep -f text.txt s21_grep.c -s > res1
	grep -f text.txt s21_grep.c > res2
	diff res1 res2
test7:
	make
	./s21_grep -f text.txt s21_grep.c s21_grep.h -v -s > res1
	grep -f text.txt s21_grep.c s21_grep.h -v > res2
	diff res1 res2
