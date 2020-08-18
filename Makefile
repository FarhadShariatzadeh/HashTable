all: test anagram

test: gen_ht.c gen_ht.h test_case.c
	gcc gen_ht.c gen_ht.h test_case.c -o test

anagram: gen_ht.c gen_ht.h main.c
	gcc gen_ht.c gen_ht.h main.c -o anagram

run_test: test
	./test

run: anagram
	./anagram
