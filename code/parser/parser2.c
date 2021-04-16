/**
 * @file ficheiro que contem o parse
 * 
 */
#include "stack2.h"
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
      } else if (strcmp(token, "+")== 0 )  { 
         SUM(s);
      } else if (strcmp(token, "-")== 0 ) {
         SUBTRACT(s);
      } else if (strcmp(token, "*")== 0 ) {
         MULTIPLY(s);
      } else if (strcmp(token, "/")== 0 ) {
         DIVISION(s);
      } else if (strcmp(token, "(")== 0 ) { 
         DECREMENT(s);
      } else if (strcmp(token, ")")== 0 ) { 
         INCREMENT(s);                          
      } else if (strcmp(token, "%")== 0 ) { 
         MODULE(s);                          
      } else if (strcmp(token, "#")== 0 ) { 
         EXPO(s); 
      } else if (strcmp(token, "&")== 0 ) { 
         AMPERSAND(s); 
      } else if (strcmp(token, "^")== 0 ) { 
         XOR(s); 
      } else if (strcmp(token, "~")== 0 ) { 
         NOT(s); 
      } else if (strcmp(token, "|")== 0 ) { 
         OR(s); 
      } else if(strcmp(token, "_")== 0 )  { 
         UNDERSCORE(s);
      } else if(strcmp(token, ";")== 0 )  { 
         SEMICOLON(s);
      } else if(strcmp(token, "\\")== 0 ) {
         BACK_SLASH(s);
      } else if(strcmp(token, "@")== 0 ) {
         AT_SIGN(s);
      } else if(strcmp(token, "$")== 0 ) { 
         COPY(s);
      } else if(strcmp(token, "l")== 0 ) {
         read(s);
      } else if(strcmp(token, "i")== 0 ) {
         toInt(s);
      } else if(strcmp(token, "f")== 0 ) { 
         toDouble(s);
      } else if (strcmp(token, "c")== 0 ) {
         toChar(s);
      }
    }
    print_stack(s); 
}
