/*====================**
About license of strz.c

Some ideas are from sl(https://github.com/mtoyoda/sl).:
Copyright 1993,1998,2014-2015 Toyoda Masashi (mtoyoda@acm.org)

license of "sl" from here
Everyone is permitted to do anything on this program including copying,
modifying, and improving, unless you try to pretend that you wrote it.
i.e., the above copyright notice has to appear in all copies.
THE AUTHOR DISCLAIMS ANY RESPONSIBILITY WITH REGARD TO THIS SOFTWARE.
license of "sl" to here
**====================*/

#include <ncurses.h>
#include <unistd.h>
#include "AA.h"

int ArtWidth = 19;
int ArtHeight = 17;
int LABEL = 0;
int PULLTAB = 0;
int LONG = 0;

void option(char *op);
void normal();


void option(char *op){
  extern int LABEL, PULLTAB;

  while(*op != '\0'){
    switch (*op++) { // evaluate *op and ++
      case 'F': LABEL = 1; break;
      case 'L': LABEL = 2; break;
      case 'A': LABEL = 3; break;
      case 'O': LABEL = 4; break;
      case 'Y': LABEL = 5; break;
      case 'K': LABEL = 6; break;
      case 'C': LABEL = 7; break;
      case 'B': LABEL = 8; break;
      case 'P': LABEL = 9; break;
      case 'G': LABEL = 10; break;
      case 'D': LABEL = 11; break;
      case 'p': PULLTAB = 1; break;
      case 'l':
        LONG = 1;
        ArtWidth = 19;
        ArtHeight = 21;
        break;
      default: break;
    }
  }
}


int main(int argc, char *argv[]){
  //----- DEFINE -----//


  //----- OPTION -----//
  for(int i = 1; i < argc; i++){
    if(*argv[i] == '-') option(argv[i] + 1);
  }


  //----- PLAY -----//
  initscr();
  noecho();
  curs_set(0);
  scrollok(stdscr, FALSE);

  normal();

  //getch();
  endwin();

  return 0;
}


void normal(){
  int H, W, h, w;

  getmaxyx(stdscr, H, W);
  h = (H - ArtHeight + 1) / 2;
  w = (W - ArtWidth + 1) / 2;

  if(LONG == 0){
    for(int i = 0; i < ArtHeight-3; i++){
      mvaddstr(h + 3 + i, w, ArtS[i]);
      if(i == 6) mvaddstr(h + 3 + i, w, label[LABEL]);
    }
  }else{
    for(int i = 0; i < ArtHeight-3; i++){
      mvaddstr(h + 3 + i, w, ArtL[i]);
      if(i == 8) mvaddstr(h + 3 + i, w, label[LABEL]);
    }
  }

  refresh();
  sleep(1);
  if(PULLTAB == 1) getch();

  mvaddstr(h + 0, w, Art2[0]);
  mvaddstr(h + 1, w, Art2[1]);
  mvaddstr(h + 2, w, Art2[2]);
  refresh();
  usleep(380000);

  mvaddstr(h + 0, w, Art0[0]);
  mvaddstr(h + 1, w, Art0[1]);
  mvaddstr(h + 2, w, Art1[2]);
  refresh();
  usleep(100000);

  mvaddstr(h + 1, w, Art1[1]);
  mvaddstr(h + 2, w, Art0[2]);
  refresh();
  usleep(200000);

  mvaddstr(h + 0, w, Art1[0]);
  mvaddstr(h + 1, w, Art0[1]);
  refresh();
  usleep(200000);

  mvaddstr(h + 0, w, Art0[0]);
  refresh();
  sleep(1);
}
