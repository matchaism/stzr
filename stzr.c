/*====================**
About license
This is a homage to sl(https://github.com/mtoyoda/sl).
--- License of "sl" from here
Copyright 1993,1998,2014 Toyoda Masashi (mtoyoda@acm.org)

Everyone is permitted to do anything on this program including copying,
modifying, and improving, unless you try to pretend that you wrote it.
i.e., the above copyright notice has to appear in all copies.
THE AUTHOR DISCLAIMS ANY RESPONSIBILITY WITH REGARD TO THIS SOFTWARE.
--- License of "sl" ends here
**====================*/


#include <ncurses.h>
#include <unistd.h>
#include "AA.h"

int ArtWidth = 19, ArtHeight = 17;
int LABEL = 0;
int PULLTAB = 0;
int LONG = 0;
int SS = 0;
int ROCKET = 0;

void option(char *op);
void normal();
void spaceshuttle();
void rocket();


void option(char *op){
  extern int LABEL, PULLTAB, SS, ROCKET;

  while(*op != '\0'){
    switch (*op++) { // evaluate *op and ++
      case 'F': LABEL = 1; break;
      case 'L': LABEL = 2; break;
      case 'A': LABEL = 3; break;
      case 'O': LABEL = 4; break;
      case 'Y': LABEL = 5; break;
      case 'U': LABEL = 6; break;
      case 'C': LABEL = 7; break;
      case 'B': LABEL = 8; break;
      case 'P': LABEL = 9; break;
      case 'G': LABEL = 10; break;
      case 'D': LABEL = 11; break;
      case 'M': LABEL = 12; break;
      case 'R': LABEL = 13; break;
      case 'I': LABEL = 14; break;
      case 'K': LABEL = 15; break;
      case 'p': PULLTAB = 1; break;
      case 'l': LONG = 1; ArtWidth = 19; ArtHeight = 21; break;
      case 's': SS = 1; ArtWidth = 27; ArtHeight = 20; break;
      case 'r': ROCKET = 1; ArtWidth = 25; ArtHeight = 23; break;
      default: break;
    }
  }
}


int main(int argc, char *argv[]){
  //----- OPTION -----//
  for(int i = 1; i < argc; i++){
    if(*argv[i] == '-') option(argv[i] + 1);
  }

  //----- PLAY -----//
  initscr();
  noecho();
  curs_set(0);
  scrollok(stdscr, FALSE);

  if(SS == 1){
    spaceshuttle();
    endwin();
    return 0;
  }

  if(ROCKET == 1){
    rocket();
    endwin();
    return 0;
  }

  normal();
  endwin();
  return 0;
}


void normal(){
  //----- DEFINE -----//
  int H, W; getmaxyx(stdscr, H, W);
  int h = (H - ArtHeight + 1) / 2, w = (W - ArtWidth + 1) / 2;

  //----- -----//
  if(LONG == 0){
    for(int i = 0; i < ArtHeight - 3; i++){
      mvaddstr(h + 3 + i, w, ArtS[i]);
      if(i == 6) mvaddstr(h + 9, w, label[LABEL]);
    }
  }else{
    for(int i = 0; i < ArtHeight - 3; i++){
      mvaddstr(h + 3 + i, w, ArtL[i]);
      if(i == 8) mvaddstr(h + 11, w, label[LABEL]);
    }
  }
  refresh(); sleep(1);
  if(PULLTAB == 1) getch();

  mvaddstr(h + 0, w, Art02[0]); mvaddstr(h + 1, w, Art02[1]); mvaddstr(h + 2, w, Art02[2]);
  refresh(); usleep(380000);

  mvaddstr(h + 0, w, Art00[0]); mvaddstr(h + 1, w, Art00[1]); mvaddstr(h + 2, w, Art01[2]);
  refresh(); usleep(100000);

  mvaddstr(h + 1, w, Art01[1]); mvaddstr(h + 2, w, Art00[2]);
  refresh(); usleep(200000);

  mvaddstr(h + 0, w, Art01[0]); mvaddstr(h + 1, w, Art00[1]);
  refresh(); usleep(200000);

  mvaddstr(h + 0, w, Art00[0]);
  refresh(); sleep(1);
}


void spaceshuttle(){
  //----- DEFINE -----//
  int H, W; getmaxyx(stdscr, H, W);
  int FireHeight = 8, FontHeight = 8, FontWidth = 72;
  int h = (H - ArtHeight + 1) / 2, w = (W - ArtWidth + 1) / 2, hf = (H - FontHeight + 1) / 2, wf = (W - FontWidth + 1) / 2;

  //----- -----//
  for(int i = 0; i < ArtHeight; i++){
    mvaddstr(h - 2 + i, w, Art10[i]);
    if(i == 12) mvaddstr(h + 10, w + 4, label[LABEL]);
  }
  refresh(); sleep(1);

  for(int i = 0; i < 6; i++){
    mvaddstr(h + 10 + i, w, Art11[i]);
    if(i == 0) mvaddstr(h + 10, w + 4, label[LABEL]);
  }
  refresh(); usleep(100000);

  for(int i = 0; i < 6; i++){
    mvaddstr(h + 10 + i, w, Art12[i]);
    if(i == 0) mvaddstr(h + 10, w + 4, label[LABEL]);
  }
  refresh(); usleep(100000);

  for(int i = 0; i < 6; i++){
    mvaddstr(h + 10 + i, w, Art13[i]);
    if(i == 0) mvaddstr(h + 10, w + 4, label[LABEL]);
  }
  refresh(); usleep(100000);

  for(int i = 0; i < 6; i++){
    mvaddstr(h + 10 + i, w, Art14[i]);
    if(i == 0) mvaddstr(h + 10, w + 4, label[LABEL]);
  }
  refresh(); sleep(1);

  for(int i = 0; i < 6; i++){
    for(int j = 0; j <= i; j++) mvaddstr(h + 3 - i + j, w, Art15[j]);
    refresh(); usleep(100000);
  }
  sleep(1);


  //----- Ignition -----//
  for(int i = 0; i < FontHeight; i++) mvaddstr(hf + i, wf, Ignition[i]);
  refresh(); usleep(500000);

  for(int i = 0; i < FireHeight; i++) mvaddstr(h + 18 + i, w, SSFire[i]);
  refresh(); sleep(1);

  //----- -----//
  clear();
  for(int i = 0; i < ArtHeight; i++){
    mvaddstr(h - 2 + i, w, SpaceShuttle[i]);
    if(i == 12) mvaddstr(h + 10, w + 4, label[LABEL]);
  }
  for(int i = 0; i < FireHeight; i++) mvaddstr(h + 18 + i, w, SSFire[i]);
  refresh(); usleep(500000);

  //----- -----//
  for(int i = 0, k = h + ArtHeight + FireHeight; k >= 0; i++, k--){
    clear();
    for(int j = 0; j < ArtHeight; j++){
      mvaddstr(h - 3 - i + j, w, SpaceShuttle[j]);
      if(j == 12) mvaddstr(h + 9 - i, w + 4, label[LABEL]);
    }
    for(int j = 0; j < FireHeight; j++) mvaddstr(h + 17 - i + j, w, SSFire[j]);
    refresh(); usleep(5000 * (h + ArtHeight + FireHeight + 3) - i * 5000);
  }
}


void rocket(){
  //----- DEFINE -----//
  int H, W; getmaxyx(stdscr, H, W);
  int FireHeight = 5, FontHeight = 8, FontWidth = 72;
  int h = (H - ArtHeight + 1) / 2, w = (W - ArtWidth + 1) / 2, hf = (H - FontHeight + 1) / 2, wf = (W - FontWidth + 1) / 2;

  //----- -----//
  for(int i = 0; i < ArtHeight; i++) mvaddstr(h + i, w, Rocket[i]);
  refresh(); sleep(1);

  //----- Count -----//
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 4; j++) mvaddstr(h + 16 + j, w + 7, Count[i][j]);
    if(i == 6){
      mvaddstr(h + 21, w, Art20[0]); mvaddstr(h + 22, w, Art20[1]);
    }
    refresh(); sleep(1);
  }

  //----- Ignition -----//
  for(int i = 0; i < FontHeight; i++) mvaddstr(hf + i, wf, Ignition[i]);
  refresh(); sleep(1);

  //----- Take off -----//
  for(int i = 0, k = h + ArtHeight + FireHeight; k >= 0; i++, k--){
    clear();
    for(int j = 0; j < ArtHeight + FireHeight; j++) mvaddstr(h + j - i, w, RocketIgnited[j]);
    refresh(); usleep(5000 * (h + ArtHeight + FireHeight + 3) - i * 5000);
  }
  refresh(); sleep(1);
}


/*====================**
Coded by macchanism
https://github.com/macchanism/stzr
**====================*/
