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
/**
 * \brief funçao que copia o n-esimo elemento para o topo da stack
 * @param s - passagem de stack como parametro   
 * @param n - n-esimo elemento 
 */  
void COPY(STACK *s){        
    int x = pop_LONG(s);
    push(s, enesimo(s, x));   
}  
/**
 * \brief funçao que soma os tipos  
 * @param s - passagem de stack como parametro  
 */
void SUM(STACK *s) {                                      
    DATA x = pop(s);                                     
    DATA y = pop(s);                                     
    DATA res;                                            
 if(has_type(x, LONG) && has_type(y, LONG)) {            
    res.type = LONG;                                     
    res.LONG = x.LONG + y.LONG;  }                       
  else if (has_type(x, DOUBLE) && has_type(y, LONG)) {   
    res.type = DOUBLE;                                   
    res.DOUBLE = x.DOUBLE + y.LONG;  }                   
  else if (has_type(x, DOUBLE) && has_type(y, DOUBLE)) { 
    res.type = DOUBLE;                                   
    res.DOUBLE = x.DOUBLE + y.DOUBLE;  }                 
  else if (has_type(x, LONG) && has_type(y, DOUBLE)) {   
    res.type = DOUBLE;                                   
    res.DOUBLE = x.LONG + y.DOUBLE;  }                   
  else if (has_type(x, CHAR) && has_type(y, LONG)) { 
    res.type = LONG;                                     
    res.LONG = x.CHAR + y.LONG;   }                       
  else if (has_type(x, LONG) && has_type(y, CHAR)) {  
    res.type = LONG;                                     
    res.LONG = x.LONG + y.CHAR;  }                       
  else if (has_type(x, CHAR) && has_type(y, DOUBLE)) {   
    res.type = DOUBLE;                                   
    res.DOUBLE = x.CHAR + y.DOUBLE;  }                 
 else if (has_type(x, DOUBLE) && has_type(y, CHAR)) {    
    res.type = DOUBLE;                                   
    res.DOUBLE = x.DOUBLE + y.CHAR;  }                 
 else if (has_type(x, CHAR) && has_type(y, CHAR)) {      
    res.type = LONG;                                     
    res.LONG = x.CHAR + y.CHAR;  }                       
 push(s,res); 
}

/**
 * \brief funçao que subtrai os tipos  
 * @param s - passagem de stack como parametro  
 */
void SUBTRACT(STACK *s) {                                      
    DATA x = pop(s);                                     
    DATA y = pop(s);                                     
    DATA res;                                            
 if(has_type(x, LONG) && has_type(y, LONG)) {             
    res.type = LONG;                                     
    res.LONG = y.LONG - x.LONG;  }                       
  else if (has_type(x, DOUBLE) && has_type(y, LONG)) {   
    res.type = DOUBLE;                                   
    res.DOUBLE = y.LONG - x.DOUBLE;  }                   
  else if (has_type(x, DOUBLE) && has_type(y, DOUBLE)) { 
    res.type = DOUBLE;                                   
    res.DOUBLE = y.DOUBLE - x.DOUBLE;  }                 
  else if (has_type(x, LONG) && has_type(y, DOUBLE)) {   
    res.type = DOUBLE;                                   
    res.DOUBLE = y.DOUBLE + x.LONG;  }                   
  else if (has_type(x, CHAR) && has_type(y, LONG)) { 
    res.type = LONG;                                     
    res.LONG = y.LONG - x.CHAR;   }                       
  else if (has_type(x, LONG) && has_type(y, CHAR)) {  
    res.type = LONG;                                     
    res.LONG = y.CHAR - x.LONG;  }                       
  else if (has_type(x, CHAR) && has_type(y, DOUBLE)) {   
    res.type = DOUBLE;                                   
    res.DOUBLE = y.DOUBLE - x.CHAR;  }                 
 else if (has_type(x, DOUBLE) && has_type(y, CHAR)) {    
    res.type = DOUBLE;                                   
    res.DOUBLE = y.CHAR - x.DOUBLE ;  }                 
 else if (has_type(x, CHAR) && has_type(y, CHAR)) {      
    res.type = LONG;                                     
    res.LONG = y.CHAR - x.CHAR;  }                       
 push(s,res); 
}
/**
 * \brief funçao que multiplica os tipos  
 * @param s - passagem de stack como parametro  
 */
void MULTIPLY(STACK *s) {                                      
    DATA x = pop(s);                                     
    DATA y = pop(s);                                     
    DATA res;                                            
 if(has_type(x, LONG) && has_type(y, LONG)) {           
    res.type = LONG;                                     
    res.LONG = x.LONG * y.LONG;  }                       
  else if (has_type(x, DOUBLE) && has_type(y, LONG)) {   
    res.type = DOUBLE;                                   
    res.DOUBLE = x.DOUBLE * y.LONG;  }                   
  else if (has_type(x, DOUBLE) && has_type(y, DOUBLE)) { 
    res.type = DOUBLE;                                   
    res.DOUBLE = x.DOUBLE * y.DOUBLE;  }                 
  else if (has_type(x, LONG) && has_type(y, DOUBLE)) {   
    res.type = DOUBLE;                                   
    res.DOUBLE = x.LONG * y.DOUBLE;  }                   
  else if (has_type(x, CHAR) && has_type(y, LONG)) { 
    res.type = LONG;                                     
    res.LONG = x.CHAR * y.LONG;   }                       
  else if (has_type(x, LONG) && has_type(y, CHAR)) {  
    res.type = LONG;                                     
    res.LONG = x.LONG * y.CHAR;  }                       
  else if (has_type(x, CHAR) && has_type(y, DOUBLE)) {   
    res.type = DOUBLE;                                   
    res.DOUBLE = x.CHAR * y.DOUBLE;  }                 
 else if (has_type(x, DOUBLE) && has_type(y, CHAR)) {    
    res.type = DOUBLE;                                   
    res.DOUBLE = x.DOUBLE * y.CHAR;  }                 
 else if (has_type(x, CHAR) && has_type(y, CHAR)) {      
    res.type = LONG;                                     
    res.LONG = x.CHAR * y.CHAR;  }                       
 push(s,res); 
}
/**
 * \brief funçao que divide os tipos  
 * @param s - passagem de stack como parametro  
 */
void DIVISION(STACK *s) {                                      
    DATA x = pop(s);                                     
    DATA y = pop(s);                                     
    DATA res;                                            
 if(has_type(x, LONG) && has_type(y, LONG)) {             
    res.type = LONG;                                     
    res.LONG = y.LONG / x.LONG;  }                       
  else if (has_type(x, DOUBLE) && has_type(y, LONG)) {   
    res.type = DOUBLE;                                   
    res.DOUBLE = y.LONG / x.DOUBLE;  }                   
  else if (has_type(x, DOUBLE) && has_type(y, DOUBLE)) { 
    res.type = DOUBLE;                                   
    res.DOUBLE = y.DOUBLE / x.DOUBLE;  }                 
  else if (has_type(x, LONG) && has_type(y, DOUBLE)) {   
    res.type = DOUBLE;                                   
    res.DOUBLE = y.DOUBLE / x.LONG;  }                   
  else if (has_type(x, CHAR) && has_type(y, LONG)) { 
    res.type = LONG;                                     
    res.LONG = y.LONG / x.CHAR;   }                       
  else if (has_type(x, LONG) && has_type(y, CHAR)) {  
    res.type = LONG;                                     
    res.LONG = y.CHAR / x.LONG;  }                       
  else if (has_type(x, CHAR) && has_type(y, DOUBLE)) {   
    res.type = DOUBLE;                                   
    res.DOUBLE = y.DOUBLE / x.CHAR;  }                 
 else if (has_type(x, DOUBLE) && has_type(y, CHAR)) {    
    res.type = DOUBLE;                                   
    res.DOUBLE = y.CHAR / x.DOUBLE ;  }                 
 else if (has_type(x, CHAR) && has_type(y, CHAR)) {      
    res.type = LONG;                                     
    res.LONG = y.CHAR / x.CHAR;  }                       
 push(s,res); 
}
/**
 * \brief funçao que decrementa um  
 * @param s - passagem de stack como parametro  
 */
void DECREMENT(STACK *s) {                             
    DATA x = pop(s);                                
    DATA res;                                            
 if(has_type(x, LONG)) {                                 
    res.type = LONG;                                     
    res.LONG = x.LONG-1;  }                              
  else if (has_type(x, DOUBLE)) {                        
    res.type = DOUBLE;                                   
    res.DOUBLE = x.DOUBLE-1;  }                          
  else if (has_type(x, CHAR) ) {                         
    res.type = CHAR;                                     
    res.CHAR = x.CHAR-1;  }                             
 push(s,res);
}
/**
 * \brief funçao que incrementa um
 * @param s - passagem de stack como parametro  
 */
void INCREMENT(STACK *s) {                               
    DATA x = pop(s);                                
    DATA res;                                            
  if(has_type(x, LONG)) {                                
    res.type = LONG;                                     
    res.LONG = x.LONG+1;  }                              
  else if (has_type(x, DOUBLE)) {                        
    res.type = DOUBLE;                                   
    res.DOUBLE = x.DOUBLE+1;  }                          
  else if (has_type(x, CHAR) ) {                         
    res.type = CHAR;                                     
    res.CHAR = x.CHAR+1;  }                              
 push(s,res);
}
/**
 * \brief funçao que determina o resto de uma divisao inteira
 * @param s - passagem de stack como parametro  
 */
void MODULE(STACK *s) {                                 
    DATA x = pop(s);                                
    DATA y = pop(s);                                
    DATA res;                                            
 if(has_type(x, LONG) && has_type(y, LONG)) {            
    res.type = LONG;                                     
    res.LONG = y.LONG % x.LONG;  }                       
  else if (has_type(x, CHAR) && has_type(y, LONG)) {     
    res.type = LONG;                                     
    res.LONG = y.LONG % x.CHAR;  }                       
  else if (has_type(x, LONG) && has_type(y, CHAR)) {     
    res.type = LONG;                                     
    res.LONG = y.CHAR % x.LONG;  }                       
 else if (has_type(x, CHAR) && has_type(y, CHAR)) {      
    res.type = CHAR;                                     
    res.CHAR = y.CHAR % x.CHAR;  }                       
 push(s,res);
}
/**
 * \brief exponencialização
 * @param s - passagem de stack como parametro  
 */
