#include <ncurses.h>
#include <unistd.h>

int main(){
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
    "|                 |",
    "|   GRAPEFRUIT    |",
    "|      LEMON      |",
    "|      APPLE      |",
    "|     ORANGE      |",
    "|      YUZU       |",
    "|   KANJUKU-UME   |",
    "| CITRUS DEPRESSA |",
    "|  BITTER  LEMON  |",
    "|      PEACH      |",
    "|      GRAPE      |",
    "|       DRY       |"};

  int H, W, h, w;


  initscr();
  noecho();
  curs_set(0);
  scrollok(stdscr, FALSE);

  getmaxyx(stdscr, H, W);
  h = H/2 - 9;
  w = (W - 9) / 2;

  for(int i = 0; i < 14; i++){
    mvaddstr(h + 3 + i, w, art[i]);
    if(i == 6) mvaddstr(h + 3 + i, w, label[1]);
  }
  refresh();
  //getch();
  sleep(1);

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
  usleep(500000);

  //getch();
  endwin();

  return 0;
}
