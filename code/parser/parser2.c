/**
 * @file ficheiro que contem o parse
 * 
 */
#include "stack3.h"
#include "fmaths.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 * \brief funçao que faz com que o conteúdo de uma linha seja lido (parse) 
 *  @param line a linha que foi lida e da qual vai se fazer o parse 
 *  @param strtol converte strings em long int 
 *  @param strtod converte strings em double
 *  @param strtok parte a string sempre que encontra uma delimitaçao 
 *  @param strcmp compara duas strings
 *  @param strlen indica o tamanho duma string 
 */
void parse(char *line, STACK *s) {
    char *delims = " \t\n";  

      for(char *token = strtok(line, delims); token != NULL; token = strtok(NULL, delims)) {
        char *sobra1;
        char *sobra2;                   
        long val_l = strtol(token, &sobra1, 10);           
        double val_d = strtod(token, &sobra2);              
      if(strlen(sobra1) == 0) { 
         push_LONG(s, val_l); 
      } else if(strlen(sobra2) == 0) { 
         push_DOUBLE(s, val_d);
      } else if(!verificaChar(token[0]) || strlen(token) != 1)  {
        if(strlen(token)==1) {
         push_CHAR(s,token[0]);
      } else {
         push_STRING(s, token);
      } 
      } 
       switch (*token) { 
         case '+':
          SUM(s);
           break;
          case '-':
          SUBTRACT(s);
           break;
          case '*':
          MULTIPLY (s);
           break;
          case '/':
          DIVISION (s);
           break;
          case '(':
          DECREMENT(s);
           break;
          case ')':
          INCREMENT(s);
           break;
          case '%':
          MODULE(s);
           break;
          case '#':
          EXPO(s);
           break;
          case '&':
          AMPERSAND(s);
           break;
          case '^':
          XOR(s);
           break;
          case '~':
          NOT(s);
           break;
          case '|':
          OR(s);
           break;
          case '_':
          UNDERSCORE(s);
           break;
          case ';':
          SEMICOLON(s);
           break;
          case '\\':
          BACK_SLASH(s);
           break;
          case '$':
          AT_SIGN(s);
           break;
          case 'l':
          read(s);
           break;
          case 'i':
          toInt(s);
           break;
          case 'f':
          toDouble(s);
           break;
          case 'c':
          toChar(s);
           break;
         }
      }
   print_stack(s); 
}
