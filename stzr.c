#include <ncurses.h>
#include <unistd.h>

int LABEL = 0;
int PULLTAB = 0;


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
      default: break;
    }
  }
}


int main(int argc, char *argv[]){
  //----- DEFINE -----//
  char art0[3][20] = {
    "        ___        ",
    "       '___'       ",
    "       |   |       "};

  char art1[3][20] = {
    "        ___   ...  ",
    "       '___' ...   ",
    "       |   |///    "};

  char art2[3][20] = {
    "                   ",
    "        ___        ",
    "       /---\\       "};

  char art[14][20] = {
    " x---------------x ",
    "/    MOON-TORY    \\",
    "|                 |",
    "|   STR0NG        |",
    "|   ZER0 77.15K   |",
    "|_________________|",
    "|                 |",
    "|-----------------|",
    "|       ___       |",
    "|      // \\\\      |",
    "|  ALC ``-// o/o  |",
    "|        //       |",
    "\\                 /",
    " '---------------' "};

  char label[12][20] = {
    "|                 |", //0
    "|   GRAPEFRUIT    |", //1,F
    "|      LEMON      |", //2,L
    "|      APPLE      |", //3,A
    "|     ORANGE      |", //4,O
    "|      YUZU       |", //5,Y
    "|   KANJUKU-UME   |", //6,K
    "| CITRUS DEPRESSA |", //7,C
    "|  BITTER  LEMON  |", //8,B
    "|      PEACH      |", //9,P
    "|      GRAPE      |", //10,G
    "|       DRY       |"}; //11,D

  int H, W, h, w;


  //----- OPTION -----//
  for(int i = 1; i < argc; i++){
    if(*argv[i] == '-') option(argv[i] + 1);
  }


  //----- PLAY -----//
  initscr();
  noecho();
  curs_set(0);
  scrollok(stdscr, FALSE);

  getmaxyx(stdscr, H, W);
  h = H / 2 - 9;
  w = (W - 9) / 2;

  for(int i = 0; i < 14; i++){
    mvaddstr(h + 3 + i, w, art[i]);
    if(i == 6) mvaddstr(h + 3 + i, w, label[LABEL]);
  }
  refresh();
  sleep(1);
  if(PULLTAB == 1) getch();

  mvaddstr(h + 0, w, art2[0]);
  mvaddstr(h + 1, w, art2[1]);
  mvaddstr(h + 2, w, art2[2]);
  refresh();
  usleep(380000);

  mvaddstr(h + 0, w, art0[0]);
  mvaddstr(h + 1, w, art0[1]);
  mvaddstr(h + 2, w, art1[2]);
  refresh();
  usleep(100000);

  mvaddstr(h + 1, w, art1[1]);
  mvaddstr(h + 2, w, art0[2]);
  refresh();
  usleep(200000);

  mvaddstr(h + 0, w, art1[0]);
  mvaddstr(h + 1, w, art0[1]);
  refresh();
  usleep(200000);

  mvaddstr(h + 0, w, art0[0]);
  refresh();
  sleep(1);

  //getch();
  endwin();

  return 0;
}
