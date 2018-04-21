


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char *argv[])
{


    ////////////////////////////////////////////////////////
    if ( argc == 2)
      if ( strcmp( argv[1] , "--mine" ) ==  0 ) 
      {
         system( " mplayer  -vo null -ao alsa:device=hw=1,0  * " );
         return 0;
      }


    ////////////////////////////////////////////////////////
    if ( argc == 2)
      if ( ( strcmp( argv[1] , "-hw1" ) ==  0 )
      || ( strcmp( argv[1] , "--hw1" ) ==  0 ) )
      {
         system( " mpg123 -a hw:1,0  \"http://listen.radionomy.com/mylenefarmerwebradio\" " );
         return 0;
      }

      ////////////////////////////////////////////////////////
      if ( argc == 2)
      if ( strcmp( argv[1] , "--all" ) ==  0 ) 
      {
         system( " mpg123 -a hw:1,0  *   " );
         return 0;
      }


      ////////////////////////////////////////////////////////
      if ( argc == 2)
      if ( strcmp( argv[1] , "--all-hw0" ) ==  0 ) 
      {
         system( " mpg123 -a hw:0,0  *   " );
         return 0;
      }

    system( "  alsamixer " ); 
    return 0;
}



