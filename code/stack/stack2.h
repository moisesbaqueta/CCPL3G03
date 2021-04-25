#ifndef ___STACK_H___
#define ___STACK_H___
#include <assert.h>
/**
 *  \brief struct que enumera os tipos e vai aplica-los na structdata 
 */
typedef enum {LONG = 1, DOUBLE = 2, CHAR = 4, STRING = 8} TYPE;

/**
 *  \brief struct que contem os varios tipos de dados 
 */
typedef struct data {
  TYPE type;
  long LONG;
  double DOUBLE;
  char CHAR;
  char *STRING;
} DATA;
/**
 *  \brief struct que define a estrutura da stack , com uma variavel que dá o tamanho e o numero de elementos 
 */
typedef struct stack {
  DATA *stack;
  int size;
  int n_elems;
} STACK;

int has_type(DATA elem, int mask);
STACK *create_stack();

void push(STACK *s, DATA elem);
DATA pop(STACK *s);
DATA top(STACK *s);
DATA enesimo(STACK *s, int n);
void print_stack(STACK *s);

#define STACK_OPERATION_PROTO(_type, _name)   \
  void push_##_name(STACK *s, _type val);     \
  _type pop_##_name(STACK *s);

STACK_OPERATION_PROTO(long, LONG)
STACK_OPERATION_PROTO(double, DOUBLE)
STACK_OPERATION_PROTO(char, CHAR)
STACK_OPERATION_PROTO(char *, STRING)

#endif
