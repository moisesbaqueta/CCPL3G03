#include "parser2.h"
#include <stdio.h>


int main() {
  STACK *p = create_stack();
  char buf[BUFSIZ];           
  char *s =fgets(buf, BUFSIZ, stdin);      
  parse(s,p);
  return 0;
}