/**
 * @file ficheiro que contem as expressoes matematicas
 * 
 */
#include "stack2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 

/**
 * \brief funçao que verifica se o char está no array 
 * @param recebe o char  
 * @returns retorna 1 se for o char estiver no array, zero se nao estiver  
 */
int verificaChar (char s) {
   int i,r=0;
   char vogais[23] = "+-*/()%#&|^~_;\\@$lifc";

	for (i=0; i<23; i++) {
		if (s == vogais[i]) {
         r=1;
      }
	}   
  return r; 
}
/**
 * \brief funçao que lê uma linha 
 * @param s - passagem de stack como parametro   
 */
void read(STACK *s) {                           
    char line[10240];                          
    assert(fgets(line,10240,stdin)!=NULL);     
    assert(line[strlen(line)-1]=='\n');        
    push_STRING(s,line);                  
}
/**
 * \brief funçao que converte para inteiro 
 * @param s - passagem de stack como parametro   
 */
void toInt(STACK *s) {             
   DATA x = pop(s);                              
   if(has_type(x,DOUBLE)) {                  
     push_LONG(s,x.DOUBLE);  
   } else if(has_type(x,CHAR)) {              
      push_LONG(s,x.CHAR); 
   } else if(has_type(x,STRING)) { 
      long y = atol(x.STRING);      
      push_LONG(s,y); 
   } else 
     push(s,x);    
}
/**
 * \brief funçao que converte para double
 * @param s - passagem de stack como parametro   
 */
void toDouble(STACK *s) {             
   DATA x = pop(s);                              
   if(has_type(x,LONG)) {              
      push_DOUBLE(s,x.LONG);  
   } else if(has_type(x,CHAR)) {               
      push_DOUBLE(s,x.CHAR); 
   } else if(has_type(x,STRING)) {
      double y = atof(x.STRING);      
      push_DOUBLE(s,y);
   } else              
      push(s,x); 
} 
/**
 * \brief funçao que converte para char
 * @param s - passagem de stack como parametro   
 */
void toChar(STACK *s) {             
   DATA x = pop(s);                            
   if(has_type(x,LONG)) {                       
      push_CHAR(s,x.LONG); }        
   else if(has_type(x,DOUBLE)) {            
      push_CHAR(s,x.DOUBLE); } 
   else 
      push(s,x); 
}     
/**
 * \brief funçao que imprime duas vezes o topo da stack 
 * @param s - passagem de stack como parametro   
 */       
void UNDERSCORE(STACK *s) {          
   DATA X = pop(s);             
   push(s,X);                   
   push(s,X);  
}                  
/**
 * \brief funçao retira o topo da stack
 * @param s - passagem de stack como parametro   
 */
void SEMICOLON(STACK *s) {
   pop(s); 
}            
/**
 * \brief funçao que troca o topo e o penultimo elemento da stack
 * @param s - passagem de stack como parametro   
 */            
void BACK_SLASH(STACK *s) {         
   DATA X = pop(s);             
   DATA Z = pop(s);             
   push(s,X);                   
   push(s,Z);                    
}
/**
 * \brief funçao que roda os 3 elementos do topo da stack 
 * @param s - passagem de stack como parametro   
 */
void AT_SIGN(STACK *s) {             
   DATA X = pop(s);             
   DATA Z = pop(s);             
   DATA W = pop(s);             
   push(s,Z);                   
   push(s,X);                   
   push(s,W);  
}          
