/**
 * @file ficheiro que contem o parse
 * 
 */
#include "stack3.h"
#include "logic.h"
#include "variaveis.h"
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

void parse3(char *line, STACK *s)
{
   new_stack(s);
   char *delims = " \t\n";
   for (char *token = strtok(line, delims); token != NULL; token = strtok(NULL, delims))
   {
      char *sobra1;
      char *sobra2;
      long val_l = strtol(token, &sobra1, 10);
      double val_d = strtod(token, &sobra2);
      if (strlen(sobra1) == 0)
      {
         push_LONG(s, val_l);
      }
      else if (strlen(sobra2) == 0)
      {
         push_DOUBLE(s, val_d);
      }
      else if (strlen(token) != 2 && strlen(token) != 1)
      {
         if (strlen(token) == 1)
         {
            push_CHAR(s, token[0]);
         }
         else if (strlen(token) == 2)
         {
            push_STRING(s, token);
         }
      }
      switch (*token) {
      case 'e':
         switch (token[1])
         {
         case '<':
            EMENOR(s);
            break;
         case '>':
            EMAIOR(s);
            break;
         case '&':
            eShortcout(s);
            break;
         case '|':
            ouShortcout(s);
            break;
         }
         break;
      case '<':
         SMALLER(s);
         break;
      case '>':
         BIGGER(s);
         break;
      case '=':
         EQUAL(s);
         break;
      case '!':
         NAO(s);
         break;
      case '?':
         ifThenElse(s);
         break;
      case 'A':
         letras(s, 'A');
         break;
      case 'B':
         letras(s, 'B');
         break;
      case 'C':
         letras(s, 'C');
         break;
      case 'D':
         letras(s, 'D');
         break;
      case 'E':
         letras(s, 'E');
         break;
      case 'F':
         letras(s, 'F');
         break;
      case 'G':
         letras(s, 'G');
         break;
      case 'H':
         letras(s, 'H');
         break;
      case 'I':
         letras(s, 'I');
         break;
      case 'J':
         letras(s, 'J');
         break;
      case 'K':
         letras(s, 'K');
         break;
      case 'L':
         letras(s, 'L');
         break;
      case 'M':
         letras(s, 'M');
         break;
      case 'N':
         letras(s, 'N');
         break;
      case 'O':
         letras(s, 'O');
         break;
      case 'P':
         letras(s, 'P');
         break;
      case 'Q':
         letras(s, 'Q');
         break;
      case 'R':
         letras(s, 'R');
         break;
      case 'S':
         letras(s, 'S');
         break;
      case 'T':
         letras(s, 'T');
         break;
      case 'U':
         letras(s, 'U');
         break;
      case 'V':
         letras(s, 'V');
         break;
      case 'W':
         letras(s, 'W');
         break;
      case 'X':
         letras(s, 'X');
         break;
      case 'Y':
         letras(s, 'Y');
         break;
      case 'Z':
         letras(s, 'Z');
         break;
      case ':':
         switch (token[1]) {
            case 'A':
            doisPontosLetra(s, 'A');
         break; 
            case 'B':
            doisPontosLetra(s, 'B');
         break;
            case 'C':
            doisPontosLetra(s, 'C');
         break;
            case 'D':
            doisPontosLetra(s, 'D');
         break;
            case 'E':
            doisPontosLetra(s, 'E');
         break;
            case 'F':
            doisPontosLetra(s, 'F');
         break;
         case 'G':
            doisPontosLetra(s, 'G');
         break;
         case 'H':
            doisPontosLetra(s, 'H');
         break;
         case 'I':
            doisPontosLetra(s, 'I');
         break;
         case 'J':
            doisPontosLetra(s, 'J');
         break;
         case 'K':
            doisPontosLetra(s, 'K');
         break;
         case 'L':
            doisPontosLetra(s, 'L');
         break;
         case 'M':
            doisPontosLetra(s, 'M');
         break;
         case 'N':
            doisPontosLetra(s, 'N');
         break;
         case 'O':
            doisPontosLetra(s, 'O');
         break;
         case 'P':
            doisPontosLetra(s, 'P');
         break;
         case 'Q':
            doisPontosLetra(s, 'Q');
         break;
         case 'R':
            doisPontosLetra(s, 'R');
         break;
         case 'S':
            doisPontosLetra(s, 'S');
         break;
         case 'T':
            doisPontosLetra(s, 'T');
         break;
         case 'U':
            doisPontosLetra(s, 'U');
         break;
         case 'W':
            doisPontosLetra(s, 'W');
         break;
         case 'X':
            doisPontosLetra(s, 'X');
         break;
         case 'Y':
            doisPontosLetra(s, 'Y');
         break;
         case 'Z':
            doisPontosLetra(s, 'Z');
         break;}
      break;
      case '+':
         SUM(s);
         break;
      case '-':
         SUBTRACT(s);
         break;
      case '*':
         MULTIPLY(s);
         break;
      case '/':
         DIVISION(s);
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
