check: test
	./test

test: test.o list.o
	cc -o $@ $^

clean:
	rm *.o
	rm test
