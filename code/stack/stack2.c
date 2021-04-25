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
DATA enesimo(STACK *s, int n){
    return s->stack[s->n_elems - n - 1];
}
/**
 *  \brief topo da stack
 *  @param s - passagem de stack como parametro 
 *  @returns retorna o valor que está no topo da stack
 */
DATA top(STACK *s) {
  return s->stack[s->n_elems - 1];
}
/**
 *  \brief funçao que imprime a stack 
 *  @param s - passagem de stack como parametro 
 */
void print_stack(STACK *s) {
  for(int K = 0; K < s->n_elems; K++) {
    DATA elem = s->stack[K];
    TYPE type = elem.type;
    switch(type) {
      case LONG:
        printf("""%ld", elem.LONG); break;
      case DOUBLE:
        printf("""%g", elem.DOUBLE); break;
      case CHAR:
        printf("""%c", elem.CHAR); break;
      case STRING:
        printf("""%s", elem.STRING); break;
    }
  }
  printf("\n");
}
/**
 *  Macro macro que faz a substituiçao de acordo com o stack operation correspondente para podermos ter uma forma rapida de um push e pop para cada tipo 
 */
#define STACK_OPERATION(_type, _name)         \
  void push_##_name(STACK *s, _type val) {    \
    DATA elem;                                \
    elem.type = _name;                        \
    elem._name = val;                         \
    push(s, elem);                            \
  }                                           \
  _type pop_##_name(STACK *s) {               \
    DATA elem = pop(s);                       \
    assert(elem.type == _name);               \
    return elem._name;                        \
  }
/**
 *  \brief prototipos para a macro
 */
STACK_OPERATION(long, LONG)
STACK_OPERATION(double, DOUBLE)
STACK_OPERATION(char, CHAR)
STACK_OPERATION(char *, STRING)
