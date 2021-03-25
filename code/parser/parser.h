/**
 * @file ficheiro que contem o parse 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "stack.h"

/**
 * \brief funçao que faz com que o conteúdo de uma linha seja lido (parse) 
 *  @param line a linha que foi lida e da qual vai se fazer o parse 
 *  @param strtol converte strings em long int 
 *  @param  strtok parte a string sempre que encontra uma delimitaçao 
 */

void parse (char *line){
    STACK s = criar_stack();
    char *delims = " \t\n";

    for(char *token = strtok(line,delims); token != NULL ; token = strtok(NULL,delims)){    
        char *sobra;
        long val_i = strtol(token, &sobra, 10);      
        if(strlen(sobra)==0){                                             
            PUSH(s,val_i); 
        /**
        * soma dois valores 
        */
        }else if (strcmp(token, "+")== 0 ){         //strcmp compara duas strings 
            long Y = POP (s);
            long X = POP (s);
            PUSH(s,X + Y);
        /**
        * subtrai dois valores 
        */
        }else if (strcmp(token, "-")== 0 ){
            long Y = POP (s);
            long X = POP (s);
            PUSH(s, X - Y);
        /**
        * multiplica dois valores 
        */
        }else if (strcmp(token, "*")== 0 ){
            long Y = POP (s);
            long X = POP (s);
            PUSH(s, X * Y);
        /**
        * divide dois valores 
        */
        }else if(strcmp(token, "/")== 0 ){
            long Y = POP (s);
            long X = POP (s);
            PUSH(s, X / Y);
         /**
        * exponencialização
        */
        }else if (strcmp(token, "#")== 0 ){
            long Y = POP (s);
            long X = POP (s);
            PUSH(s, pow(X,Y));
        /**
        * incrementa uma unidade 
        */
        }else if (strcmp(token, ")")== 0 ){
            long Y = POP (s);
            PUSH(s, ++Y);
        /**
        * decrementa uma unidade
        */
        }else if (strcmp(token, "(")== 0 ){
            long Y = POP (s);
            PUSH(s, --Y);
        /**
        * resto de uma divisao inteira
        */
        }else if (strcmp(token, "%")== 0 ){
            long Y = POP (s);
            long X = POP (s);
            PUSH(s, X % Y);
        /**
        * bits em comum
        */
        }else if (strcmp(token, "&")== 0 ){
            long Y = POP (s);
            long X = POP (s);
            PUSH(s, Y & X );
        /**
        * coloca a zero todos os bits em comum e a 1 os bits diferentes 
        */
        }else if (strcmp(token, "^")== 0 ){
            long Y = POP (s);
            long X = POP (s);
            PUSH(s, Y ^ X);
        /**
        * troca os bits de um nr binario
        */
        }else if (strcmp(token, "~")== 0 ){
            long Y = POP (s);
            PUSH(s,(~Y));
        /**
        *  uniao de bits entre dois nr binarios 
        */
        }else if (strcmp(token, "|")== 0 ){
            long Y = POP (s);
            long X = POP (s);
            PUSH(s, Y | X ); 
        }   
    }
    print_stack(s); 
}
     
