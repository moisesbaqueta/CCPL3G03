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




void parse3(char *line, STACK *s) {
   new_stack(s);
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
   } else if(strlen(token) != 2 && strlen(token) !=1)  {  
      if(strlen(token)==1) {
         push_CHAR(s,token[0]);
      } 
      else if(strlen(token)==2){
         push_STRING(s,token);
      }
   } 
   else if (strcmp(token, "e<")== 0 ) {  
      EMENOR(s);
   } else if (strcmp(token, "e>")== 0 ) {  
      EMAIOR(s);
   } else if (strcmp(token, "<")== 0 )  { 
      SMALLER(s);
   } else if (strcmp(token, ">")== 0 )  { 
      BIGGER(s);
   } else if (strcmp(token, "=")== 0 )  { 
      EQUAL(s);
   } else if (strcmp(token, "!")== 0 )  { 
      NAO(s);
   } else if (strcmp(token, "e&")== 0 ) {  
      eShortcout(s);
   } else if (strcmp(token, "?")== 0 )  { 
      ifThenElse(s);
   } else if (strcmp(token, "e|")== 0 ) {  
      ouShortcout(s);
   } else if(strcmp(token, "A")== 0 )  {
      letras(s,'A');
   } else if(strcmp(token, "B")== 0 )  {
      letras(s,'B');
   } else if(strcmp(token, "C")== 0 )  {
      letras(s,'C');
   } else if(strcmp(token, "D")== 0 )  {
      letras(s,'D');
   } else if(strcmp(token, "E")== 0 )  {
      letras(s,'E');
   } else if(strcmp(token, "F")== 0 )  {
      letras(s,'F');
   } else if(strcmp(token, "G")== 0 )  {
      letras(s,'G');
   } else if(strcmp(token, "H")== 0 )  {
      letras(s,'H');
   } else if(strcmp(token, "I")== 0 )  {
      letras(s,'I');
   } else if(strcmp(token, "J")== 0 )  {
      letras(s,'J');
   } else if(strcmp(token, "K")== 0 )  {
      letras(s,'K');
   } else if(strcmp(token, "L")== 0 )  {
      letras(s,'L');
   } else if(strcmp(token, "M")== 0 )  {
      letras(s,'M');
   } else if(strcmp(token, "N")== 0 )  {  
      letras(s,'N');
   } else if(strcmp(token, "O")== 0 )  {  
      letras(s,'O');
   } else if(strcmp(token, "P")== 0 )  {
      letras(s,'P');
   } else if(strcmp(token, "Q")== 0 )  {
      letras(s,'Q');
   } else if(strcmp(token, "R")== 0 )  { 
      letras(s,'R');
   } else if(strcmp(token, "S")== 0 )  {   
      letras(s,'S');
   } else if(strcmp(token, "T")== 0 )  {  
      letras(s,'T');
   } else if(strcmp(token, "U")== 0 )  {
      letras(s,'U');
   } else if(strcmp(token, "V")== 0 )  {
      letras(s,'V');
   } else if(strcmp(token, "W")== 0 )  {
      letras(s,'W');
   } else if(strcmp(token, "X")== 0 )  { // 23
      letras(s,'X');
   } else if(strcmp(token, "Y")== 0 )  {
      letras(s,'Y');
   } else if(strcmp(token, "Z")== 0 )  {
      letras(s,'Z');
   } else if(strcmp(token, ":A")== 0 )  {
      doisPontosLetra(s,'A');
   } else if(strcmp(token, ":B")== 0 )  {
      doisPontosLetra(s,'B');
   } else if(strcmp(token, ":C")== 0 )  {
      doisPontosLetra(s,'C');
   } else if(strcmp(token, ":D")== 0 )  {
      doisPontosLetra(s,'D');
   } else if(strcmp(token, ":E")== 0 )  {
      doisPontosLetra(s,'E');
   } else if(strcmp(token, ":F")== 0 )  {
      doisPontosLetra(s,'F');
   } else if(strcmp(token, ":G")== 0 )  {
      doisPontosLetra(s,'G');
   } else if(strcmp(token, ":H")== 0 )  {
      doisPontosLetra(s,'H');
   } else if(strcmp(token, ":I")== 0 )  {
      doisPontosLetra(s,'I');
   } else if(strcmp(token, ":J")== 0 )  {
      doisPontosLetra(s,'J');
   } else if(strcmp(token, ":K")== 0 )  {
      doisPontosLetra(s,'K');
   } else if(strcmp(token, ":L")== 0 )  {
      doisPontosLetra(s,'L');
   } else if(strcmp(token, ":M")== 0 )  {
      doisPontosLetra(s,'M');
   } else if(strcmp(token, ":N")== 0 )  {
      doisPontosLetra(s,'N');
   } else if(strcmp(token, ":O")== 0 )  {
      doisPontosLetra(s,'O');
   } else if(strcmp(token, ":P")== 0 )  {
      doisPontosLetra(s,'P');
   } else if(strcmp(token, ":Q")== 0 )  {
      doisPontosLetra(s,'Q');
   } else if(strcmp(token, ":R")== 0 )  {
      doisPontosLetra(s,'R');
   } else if(strcmp(token, ":S")== 0 )  {
      doisPontosLetra(s,'S');
   } else if(strcmp(token, ":T")== 0 )  {
      doisPontosLetra(s,'T');
   } else if(strcmp(token, ":U")== 0 )  {
      doisPontosLetra(s,'U');
   } else if(strcmp(token, ":V")== 0 )  {
      doisPontosLetra(s,'V');
   } else if(strcmp(token, ":W")== 0 )  {
      doisPontosLetra(s,'W');
   }else if(strcmp(token, ":X")== 0 )  {
      doisPontosLetra(s,'X');
   } else if(strcmp(token, ":Y")== 0 )  {
      doisPontosLetra(s,'Y');
   } else if(strcmp(token, ":Z")== 0 )  {
      doisPontosLetra(s,'Z');
   }  else if (strcmp(token, "+")== 0 )  { 
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
   } else {
      push_STRING(s, token);
   }
   }
   print_stack(s);
}
