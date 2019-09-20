#include <unistd.h>
#include <stdio.h>

#define MSGSIZE  16
#define A_ASCII  64
#define a_ASCII  97

main()
{  char inbuf[MSGSIZE];

   int p[2], j;

   /* open pipe */

   if(pipe(p) == -1)
   {    perror("pipe call error");
        exit(1);
   }
  
   /* write down pipe */
   for (;;)
   {
        int size = read(0, inbuf, 1);
        if (inbuf[0] >= A_ASCII && inbuf[0] < a_ASCII)
        {
            inbuf[0] = tolower(inbuf[0]);
		    write(1, inbuf, 1);
        }
        else if (inbuf[0] > a_ASCII || inbuf[0] == ' ')  
            write(1, inbuf, 1);
   }
   exit(0);
}

