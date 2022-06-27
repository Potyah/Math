.PHONY: all clean test s21_math.a
CC=gcc
FILES= s21_math.c\

LDFLAGS= -Wall -Wextra -Werror -std=c11
OS := $(shell uname -s)

ifeq ($(OS), Darwin)
	CC += -D OS_MAC
else
	CC += -D OS_LINUX
endif

default: all

all: clean s21_math.a

test: s21_math.a
ifeq ($(OS), Darwin)
	$(CC) s21_math_tests.c s21_math.a -o test $(LCHECK)
else
	$(CC) s21_math_tests.c s21_math.a -o test -lcheck -lsubunit -lrt -lpthread -lm
endif
	./test

clean:
	rm -rf test *.a *.o *.cfg *.gcda *.gcno *.html *.info report

s21_math.a:
	$(CC) -c $(FILES)
	ar rcs s21_math.a *.o
	ranlib $@
	cp $@ lib$@
