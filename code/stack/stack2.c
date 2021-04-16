/**
 * @file Ficheiro que contem a stack 
 */
#include "stack2.h"
#include <stdio.h>
#include <stdlib.h>
/**
 *  \brief Funçao que verifica o tipo do token 
 *  @param elem - numero que é passado como parametro
 *  @param mask - mascara para os tipos (long,double,char,string)
 *  @returns retorna verdadeiro quando elem.type e mask têm o mesmo tipo   
 */
int has_type(DATA elem, int mask) {
  return (elem.type & mask) != 0;     
}

/**
 *  \brief Funçao que cria a stack  
 *  @returns retorna a stack 
 */

STACK *create_stack() { 
  STACK *s = (STACK *) calloc(1, sizeof(STACK));     
  s->size = 100;        
  s->stack = (DATA *) calloc(s->size, sizeof(DATA));
  return s;
}
/**
 *  \brief empilha valores na stack
 *  @param elem - numero que é passado como parametro
 *  @param s - passagem de stack como parametro 
 */

void push(STACK *s, DATA elem) {
  if(s->size == s->n_elems) {      // aumentar o tamanho da stack 
    s->size += 100;
    s->stack = (DATA *) realloc(s->stack, s->size * sizeof(DATA));   // attempts to resize the memory block pointed to by ptr duma calloc
  }
  s->stack[s->n_elems] = elem;
  s->n_elems++;
}
/**
 *  \brief retira valores na stack
 *  @param s - passagem de stack como parametro 
 *  @returns retorna o valor para o qual o stack pointer aponta
 */
DATA pop(STACK *s) {
  s->n_elems--;
  return s->stack[s->n_elems];
}
/**
 *  \brief funçao que retorna o n-ésimo elemento a partir do topo da stack
 *  @param s - passagem de stack como parametro 
 *  @param n - n-ésimo elemento 
 *  @returns retorna n-ésimo elemento
 */
