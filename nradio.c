

////////////////////////////////////////////////////////////////////////////////////
// Author: Spartrekus
////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////
//////////////////////////////////////////
//////////////////////////////////////////
#include <stdio.h>
#if defined(__linux__)
#define MYOS 1
#elif defined(_WIN32)
#define PATH_MAX 2500
#define MYOS 2
#elif defined(_WIN64)
#define PATH_MAX 2500
#define MYOS 3
#elif defined(__unix__)
#define MYOS 4
#define PATH_MAX 2500
#else
#define MYOS 0
#endif


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h> 
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

#include <ncurses.h>

void quit(void)
{
  endwin();
}


void colornorm(void)
{
    attroff(  A_REVERSE );
    attroff( A_BOLD );
    attroff( A_BLINK );
    attroff( A_UNDERLINE );
    color_set( 7, NULL ); 
}


////////////////////////////////
void nruncmd( char *thecmd   )
{
       char cmdi[PATH_MAX];
       def_prog_mode();
       endwin();
       strncpy( cmdi , "  " , PATH_MAX );
       strncat( cmdi , thecmd , PATH_MAX - strlen( cmdi ) -1 );
       strncat( cmdi , " " , PATH_MAX - strlen( cmdi ) -1 );
       system( cmdi );
       reset_prog_mode();
}




int main(void)
{
  int ch ; 

  initscr();			
  curs_set( 0 );
  start_color();
  init_pair(0, COLOR_BLACK, COLOR_BLACK);
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_BLUE, COLOR_BLACK);
  init_pair(4, COLOR_YELLOW, COLOR_BLACK);
  init_pair(5, COLOR_CYAN, COLOR_BLACK);
  init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(7, COLOR_WHITE, COLOR_BLACK);
  init_pair(8, COLOR_BLACK, COLOR_YELLOW);

  int x = 5; int i = 1;
  int nc_gameover = 0;

  int rows, cols;
  int foo;

  while( nc_gameover == 0 )
  {
   erase();
   getmaxyx( stdscr, rows , cols);
   x = 5; i = 1;
   colornorm(); 
   color_set( 4 , NULL );
   attroff( A_REVERSE );
   attron( A_BOLD );


   mvprintw( 3,3, "1: FM Nord " );
   mvprintw( 5,3, "2: FM Mylene  " );

   attroff( A_REVERSE );

   color_set( 7, NULL ); mvprintw( 12, 3 , "<Press Key>" );

   color_set( 5, NULL ); 
   for( foo = 0 ; foo <= cols-1 ; foo++) 
   {
      mvaddch( 0      , foo , ACS_HLINE );
      mvaddch( rows-1 , foo , ACS_HLINE );
   }

   color_set( 4 , NULL );
   attroff( A_REVERSE );
   attron( A_BOLD );
   mvprintw( 0, cols/2-4 , " NRADIO " );

   refresh();

   ch = getch(); 
   if      ( ch == '1' ) nruncmd( "  mplayer   http://listen.radionomy.com/FranceBleuNord947FM" );

   else if ( ch == '2' ) nruncmd( "  mplayer   "  );
   else if ( ch == 'q' ) nc_gameover = 1;
   else if ( ch ==  27 ) nc_gameover = 1;
  }

  curs_set( 1 );
  endwin();			/* End curses mode		  */
  return(0);
}

