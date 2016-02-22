check: test
	./test

test: test.o list.o
	cc -std=gnu99 -o $@ $^

clean:
	rm *.o
	rm test
