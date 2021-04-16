#include "stack22.h"
#include "stack22.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void read(STACK *s) {                           
    char line[10240];                          
    assert(fgets(line,10240,stdin)!=NULL);     
    assert(line[strlen(line)-1]=='\n');        
    push_STRING(s,line);                  
}


void toInt (STACK *s) {             
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

void toDouble (STACK *s) {                                         
   if(has_type(top(s),LONG)) {   
      long x = pop_LONG(s);               
      push_DOUBLE(s, (double)x); 

   } else if(has_type(top(s),CHAR)) {
      char x = pop_CHAR(s);
      push_DOUBLE(s, (double)x); 
   } 
}     

void toChar(STACK *s) {             
   if(has_type(top(s),LONG)) {   
      long x = pop_LONG(s);               
      push_CHAR(s, (char)x); 

   } else if(has_type(top(s),DOUBLE)) {
      double x = pop_DOUBLE(s);
      push_CHAR(s, (char)x); 
   } 
}     

       
void UNDERSCORE(STACK *s) {          
   DATA X = pop(s);             
   push(s,X);                   
   push(s,X);  
}                  

void SEMICOLON(STACK *s) {
   DATA Y = pop(s); 
}            
            
void BACK_SLASH(STACK *s) {         
   DATA X = pop(s);             
   DATA Z = pop(s);             
   push(s,X);                   
   push(s,Z);                    
}

void AT_SIGN(STACK *s) {             
   DATA X = pop(s);             
   DATA Z = pop(s);             
   DATA W = pop(s);             
   push(s,Z);                   
   push(s,X);                   
   push(s,W);  
}          
                                            
void COPY(STACK *s){        
    int x = pop_LONG(s);
    push(s, enesimo(s, x)); 
}
