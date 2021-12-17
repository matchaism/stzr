all: stzr

stzr: stzr.c AA.h
	gcc -o stzr stzr.c -l ncurses

clean:
	rm -f stzr
