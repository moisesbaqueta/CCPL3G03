#ifndef ___STACK_H___
#define ___STACK_H___
#include <assert.h>
/**
 *  \brief struct que enumera os tipos e vai aplica-los na structdata 
 */
typedef enum {LONG = 1, DOUBLE = 2, CHAR = 4, STRING = 8} TYPE;

#define INTEGER  (LONG | CHAR)
#define NUMBER   (INTEGER | DOUBLE)
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
