/**
 * @file Ficheiro que contem a funçao principal
 * 
 */
#include "parser3.h"
#include "parser2.h"
#include "stack3.h"
#include <stdio.h>

/**
 * \brief funçao principal do programa 
 * @param fgets funçao que lê uma seq de chars ate "\n"
 * @returns o valor 0 
 */

int main() {
  STACK *p = create_stack();
  char buf[BUFSIZ];           
  char *s =fgets(buf, BUFSIZ, stdin);      
  parse3(s,p);
  return 0;
}