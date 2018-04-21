
    #include <stdio.h>
    #include <stdlib.h>
 double mycount = 0;

    int main()
    {
        int begin = 1;
        float charpos = 1 ; 
        int c ; 
        c = getchar();
        while( c != EOF )
        {
           //if ( begin == 1 )  printf( "%.0f: ", charpos++);
           // putchar( c );
           begin = 0;
           if ( c == '\n' ) 
           { begin = 1; mycount++; }
           c = getchar();
        }
        printf( "Count: %g\n" , mycount );
	return 0;
    }


