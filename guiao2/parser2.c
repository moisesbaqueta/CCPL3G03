#include "fmaths.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void parse1(char *line) {
    char *delims = " \t\n";

    STACK *s = create_stack();       

    for(char *token = strtok(line, delims); token != NULL; token = strtok(NULL, delims)) {
        char *sobra1;
        char *sobra2;
                                
        long val_l = strtol(token, &sobra1, 10);            // string -> long   ; 10 é a base 
        double val_d = strtod(token, &sobra2);              // string -> double 

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
      }else if (strcmp(token, "-")== 0 ) {
        SUBTRACT(s);
      }else if (strcmp(token, "*")== 0 ) {
        MULTIPLY(s);
      }else if (strcmp(token, "/")== 0 ) {
        DIVISION(s);
      }else if (strcmp(token, "(")== 0 ) { 
        DECREMENT(s);
      }else if (strcmp(token, ")")== 0 ) { 
        INCREMENT(s);                          
      }else if (strcmp(token, "%")== 0 ) { 
        MODULE(s);                          
      }else if (strcmp(token, "#")== 0 ) { 
        EXPO(s); 
      }else if (strcmp(token, "&")== 0 ) { 
        AMPERSAND(s); 
      }else if (strcmp(token, "^")== 0 ) { 
        XOR(s); 
      }else if (strcmp(token, "~")== 0 ) { 
        NOT(s); 
      }else if (strcmp(token, "|")== 0 ) { 
        OR(s); 
      }
    }
    print_stack(s); 
}