all: stzr

stzr: stzr.c
	gcc -o stzr stzr.c -l ncurses

clean:
	rm -f stzr
