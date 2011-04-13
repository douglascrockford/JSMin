all: clean jsmin

jsmin: jsmin.c
	cc -O3 jsmin.c -o jsmin

clean:
	rm -f jsmin *.o
