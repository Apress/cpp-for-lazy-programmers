/* 
Program to test sprintf, sscanf, fgets, fputs 
        -- from _C++ for Lazy Programmers_
*/

#include <stdio.h>

/*Disable a warning about scanf, etc., in Visual Studio */
#ifdef _MSC_VER
#pragma warning (disable:4996) 
#endif

int main ()
{
    while (1)                  /* forever, or until break... */
    {
        enum {MAXLINE=256};    /* array size for line        */
        char line [MAXLINE];   /* a line of text             */
        enum {MAXSTR = 80};    /* array size for word        */
        char word [MAXSTR];    /* your word                  */
        int  number;           /* a number to read in        */
        
        /* get an entire line with fgets; on EOF quit        */
        printf("Enter a line with 1 word & 1 number, EOF to quit: ");
        if (! fgets  (line, MAXSTR, stdin)) break;

        /* repeat line with fputs                            */
        printf("You entered:  "); 
        fputs (line, stdout);

        /* Use char array as source for 2 arguments          */
        if (sscanf (line, "%s %i", word, &number) != 2)
            fputs ("That wasn't a word and a number!\n", stdout);
        else
        {
            /* Print using sprintf and puts                  */
            sprintf(line, "The name was %s and the number was %i.\n", 
                    word, number);
            fputs  (line, stdout);
            /* 
            If this weren't a demo of new functions, I'd have said:
              printf ("The name was %s and the number was %f.\n", 
                      name, number);
            */
        }
        fputs ("\n", stdout);  /* add blank line to separate */
    }

    fputs ("\n\nBye!\n", stdout);
    
    return 0;
}
