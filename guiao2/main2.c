#include "funcoes2.c"
#include "parser2.c"
#include <stdio.h>
#include <string.h>


int main() {
  char buf[BUFSIZ];           //  BUFSIZ should normally be 256 KB, 512 KB or 4096 KB
  char *s =fgets(buf, BUFSIZ, stdin);     // le uma linha from the specified stream and stores it into the string pointed to by str. 
  parse1(s);
  parse2(s);
  return 0;
}
