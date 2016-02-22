check: test
	./test

test: test.o list.o
	cc -std=gnu99 -o $@ $^

%.o: %.c
	cc -std=gnu99 -c -o $@ $^

clean:
	rm *.o
	rm test
