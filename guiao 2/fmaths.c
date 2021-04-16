#include "stack2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 


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

void EXPO(STACK *s) {                                
    DATA x = pop(s);                               
    DATA y = pop(s);                               
    DATA res;                                           
 if(has_type(x, LONG) && has_type(y, LONG)) {           
    res.type = LONG;                                    
    res.LONG = pow(y.LONG,x.LONG);  }                   
  else if (has_type(x, DOUBLE) && has_type(y, LONG)) {  
    res.type = DOUBLE;                                  
    res.DOUBLE = pow(y.LONG,x.DOUBLE);  }               
  else if (has_type(x, DOUBLE) && has_type(y, DOUBLE)) {
    res.type = DOUBLE;                                  
    res.DOUBLE = pow(y.DOUBLE,x.DOUBLE);    }           
  else if (has_type(x, LONG) && has_type(y, DOUBLE)) {  
    res.type = DOUBLE;                                  
    res.DOUBLE = pow(y.DOUBLE,x.LONG) ;    }            
  else if (has_type(x, CHAR) && has_type(y, LONG)) {    
    res.type = LONG;                                    
    res.LONG = pow(y.LONG,x.CHAR);  }                   
  else if (has_type(x, LONG) && has_type(y, CHAR)) {    
    res.type = LONG;                                    
    res.LONG = pow(y.CHAR,x.LONG);  }                   
  else if (has_type(x, CHAR) && has_type(y, DOUBLE)) {  
    res.type = DOUBLE;                                    
    res.DOUBLE = pow(y.DOUBLE,x.CHAR);  }                 
 else if (has_type(x, DOUBLE) && has_type(y, CHAR)) {   
    res.type = DOUBLE;                                    
    res.DOUBLE = pow(y.CHAR,x.DOUBLE);  }                 
 else if (has_type(x, CHAR) && has_type(y, CHAR)) {     
    res.type = LONG;                                    
    res.LONG = pow(y.CHAR,x.CHAR);  }               
 push(s,res);
}

void AMPERSAND(STACK *s) {                              
    DATA x = pop(s);                                
    DATA y = pop(s);                                
    DATA res;                                            
 if(has_type(x, LONG) && has_type(y, LONG)) {            
    res.type = LONG;                                     
    res.LONG = x.LONG & y.LONG;  }                       
  else if (has_type(x, CHAR) && has_type(y, LONG)) {     
    res.type = LONG;                                     
    res.LONG = x.CHAR & y.LONG;  }                       
  else if (has_type(x, LONG) && has_type(y, CHAR)) {     
    res.type = LONG;                                     
    res.LONG = x.LONG & y.CHAR;  }                       
 else if (has_type(x, CHAR) && has_type(y, CHAR)) {      
    res.type = CHAR;                                     
    res.CHAR = x.CHAR & y.CHAR;  }                       
 push(s,res);
}

void XOR(STACK *s)  {                                   
    DATA x = pop(s);                                
    DATA y = pop(s);                                
    DATA res;                                            
 if(has_type(x, LONG) && has_type(y, LONG)) {            
    res.type = LONG;                                     
    res.LONG = x.LONG ^ y.LONG;  }                       
  else if (has_type(x, CHAR) && has_type(y, LONG)) {     
    res.type = LONG;                                     
    res.LONG = x.CHAR ^ y.LONG;  }                       
  else if (has_type(x, LONG) && has_type(y, CHAR)) {     
    res.type = LONG;                                     
    res.LONG = x.LONG ^ y.CHAR;  }                       
 else if (has_type(x, CHAR) && has_type(y, CHAR)) {      
    res.type = LONG;                                     
    res.LONG = x.CHAR ^ y.CHAR;  }                       
 push(s,res);
}

void NOT(STACK *s)   {                                   
    DATA x = pop(s);                                
    DATA res;                                            
 if(has_type(x, LONG)) {                                 
    res.type = LONG;                                     
    res.LONG = ~(x.LONG);  }                             
  else if (has_type(x, CHAR)) {                          
    res.type = CHAR;                                     
    res.CHAR = ~(x.CHAR);  }                             
 push(s,res);
}

void OR(STACK *s)    {                                   
    DATA x = pop(s);                                
    DATA y = pop(s);                                
    DATA res;                                            
 if(has_type(x, LONG) && has_type(y, LONG)) {            
    res.type = LONG;                                     
    res.LONG = (x.LONG | y.LONG);  }                     
  else if (has_type(x, CHAR) && has_type(y, LONG)) {     
    res.type = LONG;                                     
    res.LONG = (x.CHAR | y.LONG);  }                     
  else if (has_type(x, LONG) && has_type(y, CHAR)) {     
    res.type = LONG;                                     
    res.LONG = (x.LONG | y.CHAR);  }                     
 else if (has_type(x, CHAR) && has_type(y, CHAR)) {      
    res.type = LONG;                                     
    res.LONG = (x.CHAR | y.CHAR);  }                     
 push(s,res);
}

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
   pop(s); 
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
