#include "stack3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 * \brief funçao que converte para LONG o topo da stack  
 * @param x - passagem de um elemento como parametro 
 * @returns retorna o elemento ja convertido 
 */
DATA transformaLONG(long x){
   DATA y;
   y.LONG = x;
   y.type = LONG;
   return y;
}
/**
 * \brief funçao que converte para DOUBLE o topo da stack  
 * @param x - passagem de um elemento como parametro 
 * @returns retorna o elemento ja convertido 
 */
DATA transformaDOUBLE(double x){
   DATA y;
   y.DOUBLE = x;
   y.type = DOUBLE;
   return y;
}
/**
 * \brief funçao que converte para CHAR o topo da stack  
 * @param x - passagem de um elemento como parametro 
 * @returns retorna o elemento ja convertido 
 */
DATA transformaCHAR(char x){
   DATA y;
   y.CHAR = x;
   y.type = CHAR;
   return y;
}
/**
 * \brief funçao que vai a certa posição do array e exibe o valor por omissão 
 * @param s - passagem da stack como parametro  
 */
void new_stack(STACK *s){
  s->array[0] = transformaLONG(10);
  s->array[1] = transformaLONG(11); 
  s->array[2] = transformaLONG(12); 
  s->array[3] = transformaLONG(13); 
  s->array[4] = transformaLONG(14);
  s->array[5] = transformaLONG(15);
  s->array[13] = transformaCHAR('\n');  
  s->array[18] = transformaCHAR(' ');  
  s->array[23] = transformaLONG(0);  
  s->array[24] = transformaLONG(1);  
  s->array[25] = transformaLONG(2);  
}
/**
 * \brief funçao que coloca no topo da stack o conteúdo da variável que é passado como parametro
 * @param s - passagem da stack como parametro 
 * @param letra -  passagem da variavel como elemento 
 */
void letras(STACK *s, char letra){
   long pos = letra;
   DATA y = s->array[pos-65];
   if(has_type(y,LONG)) {
      push_LONG(s,y.LONG);
   } else if(has_type(y,DOUBLE)) {
      push_DOUBLE(s,y.DOUBLE);
   } else if(has_type(y,CHAR)) {
      push_CHAR(s,y.CHAR);
   } else if(has_type(y,STRING)) {
      push_STRING(s,y.STRING);
   } 
}
/**
 * \brief funçao que copia o que está no topo da stack para a variável
 * @param s - passagem da stack como parametro  
 * @param letra -  passagem da variavel como parametro
 */
// copia o topo da stack para a variavel 
void doisPontosLetra(STACK *s, char letra) {
   DATA z = top(s); 
   long x = letra;
//   DATA y = (s->array[x-65]);    // vai a tal posiçao do array 
   if(has_type(z,LONG)) {
      (s->array[x-65]) = transformaLONG(z.LONG);
   } else if(has_type(z,DOUBLE)) {
      (s->array[x-65]) = transformaDOUBLE(z.DOUBLE);
   } else if(has_type(z,CHAR)) {
      (s->array[x-65]) = transformaCHAR(z.CHAR);
   }
}

