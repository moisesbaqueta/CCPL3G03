/**
 * @file Ficheiro que contem a stack 
 */

#include <stdio.h>
#define SIZE  10240

/**
 *  \brief Funçao que cria e inicializa a stack 
 * 
 * @returns ao valor de s, a stack 
 */

typedef struct {
  long array[SIZE];    // Array que armazena os elementos da stack
  int pos;            // Nº de elementos na stack (e indiretamente a sua posição)
} 
  STACK;

STACK criar_stack() {
  STACK s;
  s.pos = 0;
  return s;
}
/**
 * \brief empilha valores na stack
 */ 
#define PUSH(s, val)  s.array[s.pos++] = val;

/**
 * \brief retira o elemento do topo da stack
 */ 
#define POP(s)  s.array[--s.pos]

/**
 * \brief funçao que imprime a stack
 */  
void print_stack(STACK s) {
  for(int k = 0; k < s.pos; k++)
   printf("%ld", s.array[k]);
  printf("\n"); 
}



