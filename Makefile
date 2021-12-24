all: stzr

stzr: stzr.c AA.h
	gcc -o stzr stzr.c -l ncurses

clean:
	rm -f stzr


##############################
# Coded by macchanism
# https://github.com/macchanism/stzr
##############################
