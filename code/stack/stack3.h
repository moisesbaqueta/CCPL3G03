#ifndef ___STACK_H___
#define ___STACK_H___
#include <assert.h>
/**
 *  Struct que enumera os tipos e vai aplica-los na structdata 
 */
typedef enum {
  LONG = 1,    /**< Tipo Long com o valor 1 (2⁰) associado */
  DOUBLE = 2,  /**< Tipo Double com o valor 2 (2¹) associado */
  CHAR = 4,    /**< Tipo Char com o valor 4 (2²) associado */
  STRING = 8   /**< Tipo String com o valor 8 (2³) associado */
} TYPE;

/**
 *  Struct que contem os varios tipos de dados 
 */
typedef struct data {
  TYPE type;      /**< tipos de dados vindos do enum TYPE */
  long LONG;      /**< Tipo long */
  double DOUBLE;  /**< Tipo double */
  char CHAR;      /**< Tipo char */
  char *STRING;   /**< Tipo string */
} DATA;
/**
 *  Struct que define um array com 26 elementos que representam as letras do abecedário e estrutura da stack , com uma variavel que dá o tamanho e o numero de elementos 
 */
typedef struct stack {
  DATA array[26]; /**< Array das letras */
  DATA *stack;    /**< Tipo da stack */
  int size;       /**< Tamanho da stack */
  int n_elems;    /**< Numero de elementos ao momento na stack */
} STACK;

int has_type(DATA elem, int mask);
STACK *create_stack();

void push(STACK *s, DATA elem);
DATA pop(STACK *s);
DATA top(STACK *s);
DATA enesimo(STACK *s, int n);
void print_stack(STACK *s);
/**
 *  Macro macro que faz a substituiçao de acordo com o stack operation correspondente para podermos ter uma forma rapida de um push e pop para cada tipo 
 */
#define STACK_OPERATION_PROTO(_type, _name)   \
  void push_##_name(STACK *s, _type val);     \
  _type pop_##_name(STACK *s);

STACK_OPERATION_PROTO(long, LONG)
STACK_OPERATION_PROTO(double, DOUBLE)
STACK_OPERATION_PROTO(char, CHAR)
STACK_OPERATION_PROTO(char *, STRING)

#endif
