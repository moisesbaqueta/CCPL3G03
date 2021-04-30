#include "stack3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 * \brief funçao que coloca no topo da stack o maior entre os dois elementos do topo da stack   
 * @param s - passagem de stack como parametro  
 */
void EMAIOR(STACK *s) {                                      
    DATA x = pop(s);                                     
    DATA y = pop(s);                                                                              
if(has_type(x, LONG) && has_type(y, LONG)) {            
    if(x.LONG >= y.LONG){
        push(s,x);
    }else push(s,y); }     
else if (has_type(x, DOUBLE) && has_type(y, LONG)) {   
    if(x.DOUBLE >= y.LONG){
        push(s,x);
    }else push(s,y); }                   
else if (has_type(x, DOUBLE) && has_type(y, DOUBLE)) { 
    if(x.DOUBLE >= y.DOUBLE){
        push(s,x);
    }else push(s,y); }                 
else if (has_type(x, LONG) && has_type(y, DOUBLE)) {   
    if(x.LONG >= y.DOUBLE){
        push(s,x);
    }else push(s,y); }                  
else if (has_type(x, CHAR) && has_type(y, LONG)) { 
    if(x.CHAR >= y.LONG){
        push(s,x);
    }else push(s,y); }                      
else if (has_type(x, LONG) && has_type(y, CHAR)) {  
    if(x.LONG >= y.CHAR){
        push(s,x);
    }else push(s,y); }                      
else if (has_type(x, CHAR) && has_type(y, DOUBLE)) {   
    if(x.CHAR >= y.DOUBLE){
        push(s,x);
    }else push(s,y); }                
else if (has_type(x, DOUBLE) && has_type(y, CHAR)) {    
    if(x.DOUBLE >= y.CHAR){
        push(s,x);
    }else push(s,y); }
else if (has_type(x, CHAR) && has_type(y, CHAR)) {      
    if(x.CHAR >= y.CHAR){
        push(s,x);
    }else push(s,y); }                        
}
/**
 * \brief funçao que coloca no topo da stack o menor entre os dois elementos do topo da stack  
 * @param s - passagem de stack como parametro  
 */
void EMENOR(STACK *s) {                                      
    DATA x = pop(s);                                     
    DATA y = pop(s);                                                                                
if(has_type(x, LONG) && has_type(y, LONG)) {            
    if(x.LONG <= y.LONG){
        push(s,x);
    }else push(s,y);}     
else if (has_type(x, DOUBLE) && has_type(y, LONG)) {   
    if(x.DOUBLE <= y.LONG){
        push(s,x);
    }else push(s,y);}                   
else if (has_type(x, DOUBLE) && has_type(y, DOUBLE)) { 
    if(x.DOUBLE <= y.DOUBLE){
        push(s,x);
    }else push(s,y);}                 
else if (has_type(x, LONG) && has_type(y, DOUBLE)) {   
    if(x.LONG <= y.DOUBLE){
        push(s,x);
    }else push(s,y);}                  
else if (has_type(x, CHAR) && has_type(y, LONG)) { 
    if(x.CHAR <= y.LONG){
        push(s,x);
    }else push(s,y);}                      
else if (has_type(x, LONG) && has_type(y, CHAR)) {  
    if(x.LONG <= y.CHAR){
        push(s,x);
    }else push(s,y);}                      
else if (has_type(x, CHAR) && has_type(y, DOUBLE)) {   
    if(x.CHAR <= y.DOUBLE){
        push(s,x);
    }else push(s,y);}                
else if (has_type(x, DOUBLE) && has_type(y, CHAR)) {    
    if(x.DOUBLE <= y.CHAR){
        push(s,x);
    }else push(s,y);}
else if (has_type(x, CHAR) && has_type(y, CHAR)) {      
    if(x.CHAR <= y.CHAR){
        push(s,x);
    }else push(s,y);}                        
}
/**
 * \brief funçao que coloca no topo da stack 1 (verdadeiro) se o topo for inferior ao penultimo elemento e 0 (falso) se for superior 
 * @param s - passagem de stack como parametro  
 */
void BIGGER(STACK *s) {                                      
    DATA x = pop(s);                                     
    DATA y = pop(s);
    DATA r;  
    r.type= LONG;                                                                              
if(has_type(x, LONG) && has_type(y, LONG)) {            
    if(x.LONG > y.LONG){
        r.LONG = 0 ;  
    }else{ 
        r.LONG = 1; }    
}else if (has_type(x, DOUBLE) && has_type(y, LONG)) {   
    if(x.DOUBLE > y.LONG){
        r.LONG = 0;  
    }else{ 
        r.LONG = 1; }
}else if (has_type(x, DOUBLE) && has_type(y, DOUBLE)) { 
    if(x.DOUBLE > y.DOUBLE){
        r.LONG = 0;  
    }else{ 
        r.LONG = 1; }
}else if (has_type(x, LONG) && has_type(y, DOUBLE)) {   
    if(x.LONG > y.DOUBLE){
        r.LONG = 0 ;  
    }else{ 
        r.LONG = 1; }
}else if (has_type(x, CHAR) && has_type(y, LONG)) { 
    if(x.CHAR > y.LONG){
        r.LONG = 0 ;  
    }else{ 
        r.LONG = 1; }
   }else if (has_type(x, LONG) && has_type(y, CHAR)) {  
    if(x.LONG > y.CHAR){
        r.LONG = 0 ;  
    }else{ 
        r.LONG = 1; }
}else if (has_type(x, CHAR) && has_type(y, DOUBLE)) {   
    if(x.CHAR > y.DOUBLE){
        r.LONG = 0 ;  
    }else{ 
        r.LONG = 1; }
} else if (has_type(x, DOUBLE) && has_type(y, CHAR)) {    
    if(x.DOUBLE > y.CHAR){
        r.LONG = 0 ;  
    }else{ 
        r.LONG = 1; }

} else if (has_type(x, CHAR) && has_type(y, CHAR)) {      
   if(x.CHAR > y.CHAR){
        r.LONG = 0 ;  
    }else{ 
        r.LONG = 1; }
    } 
 push(s,r); 
}
/**
 * \brief funçao que coloca no topo da stack 0 (falso) se o topo for inferior ao penultimo elemento e 1 (verdadeiro) se for superior 
 * @param s - passagem de stack como parametro  
 */
void SMALLER(STACK *s) {                                      
    DATA x = pop(s);                                     
    DATA y = pop(s);
    DATA r;  
    r.type = LONG;                                                                              
if(has_type(x, LONG) && has_type(y, LONG)) {            
    if(x.LONG < y.LONG){
        r.LONG = 0 ;  
    }else{ 
        r.LONG = 1; }    
} else if (has_type(x, DOUBLE) && has_type(y, LONG)) {   
    if(x.DOUBLE < y.LONG){
        r.LONG = 0 ;  
    }else{ 
        r.LONG = 1; } 
} else if (has_type(x, DOUBLE) && has_type(y, DOUBLE)) { 
    if(x.DOUBLE < y.DOUBLE){
        r.LONG = 0 ;  
    }else{ 
        r.LONG = 1; } 
} else if (has_type(x, LONG) && has_type(y, DOUBLE)) {   
    if(x.LONG < y.DOUBLE){
        r.LONG = 0 ;  
    }else{ 
        r.LONG = 1; } 
} else if (has_type(x, CHAR) && has_type(y, LONG)) { 
    if(x.CHAR < y.LONG){
        r.LONG = 0 ;  
    }else{ 
        r.LONG = 1; } 
} else if (has_type(x, LONG) && has_type(y, CHAR)) {  
    if(x.LONG < y.CHAR){
        r.LONG = 0 ;  
    }else{ 
        r.LONG = 1; }  
} else if (has_type(x, CHAR) && has_type(y, DOUBLE)) {   
    if(x.CHAR < y.DOUBLE){
        r.LONG = 0 ;  
    }else{ 
        r.LONG = 1; } 
} else if (has_type(x, DOUBLE) && has_type(y, CHAR)) {    
    if(x.DOUBLE < y.CHAR){
        r.LONG = 0 ;  
    }else{ 
        r.LONG = 1; } 
}else if (has_type(x, CHAR) && has_type(y, CHAR)) {      
    if(x.CHAR < y.CHAR){
        r.LONG = 0 ;  
    }else{ 
        r.LONG = 1; }
    } 
 push(s,r); 
}
/**
 * \brief funçao que coloca no topo da stack 1 (verdadeiro) se o topo e o penultimo forem iguais e 0 (falso) se forem diferentes 
 * @param s - passagem de stack como parametro  
 */
void EQUAL(STACK *s) {                                      
    DATA x = pop(s);                                     
    DATA y = pop(s);
    DATA r;
    r.type = LONG;                                                                                
if(has_type(x, LONG) && has_type(y, LONG)) {            
    if(x.LONG == y.LONG){
        r.LONG = 1 ;  
    }else{ 
        r.LONG = 0; }    
} else if (has_type(x, DOUBLE) && has_type(y, LONG)) {   
    if(x.DOUBLE == y.LONG){
        r.LONG = 1 ;  
    }else{ 
        r.LONG = 0; }
}else if (has_type(x, DOUBLE) && has_type(y, DOUBLE)) { 
    if(x.DOUBLE == y.DOUBLE){
        r.LONG = 1 ;  
    }else{ 
        r.LONG = 0; }
} else if (has_type(x, LONG) && has_type(y, DOUBLE)) {   
    if(x.LONG == y.DOUBLE){
        r.LONG = 1 ;  
    }else{ 
        r.LONG = 0; }
}else if (has_type(x, CHAR) && has_type(y, LONG)) { 
    if(x.CHAR == y.LONG){
        r.LONG = 1 ;  
    }else{ 
        r.LONG = 0; }
} else if (has_type(x, LONG) && has_type(y, CHAR)) {  
    if(x.LONG == y.CHAR){
        r.LONG = 1 ;  
    }else{ 
        r.LONG = 0; }  
} else if (has_type(x, CHAR) && has_type(y, DOUBLE)) {   
    if(x.CHAR == y.DOUBLE){
        r.LONG = 1 ;  
    }else{ 
        r.LONG = 0; }
    } else if (has_type(x, DOUBLE) && has_type(y, CHAR)) {    
    if(x.DOUBLE == y.CHAR){
        r.LONG = 1 ;  
    }else{ 
        r.LONG = 0; }
} else if (has_type(x, CHAR) && has_type(y, CHAR)) {      
    if(x.CHAR == y.CHAR){
        r.LONG = 1 ;  
    }else{ 
        r.LONG = 0; }
    }
 push(s,r); 
}
/**
 * \brief funçao que coloca no topo da stack 1 (verdadeiro) se o topo for zero e 0 se o topo da stack for qualquer elemento exceto o zero  
 * @param s - passagem de stack como parametro  
 */
void NAO(STACK *s) {                                      
    DATA x = pop(s);
    DATA r;    
    r.type = LONG;                                                                           
 if(has_type(x, LONG)) {            
    if(x.LONG == 0 ){
        r.LONG = 1;
    }else{
         r.LONG = 0;
    }
} else if(has_type(x, DOUBLE)) {            
    if(x.DOUBLE == 0 ){
        r.LONG = 1;
    }else{
         r.LONG = 0;
    }
} else if(has_type(x, CHAR)) {            
    if(x.CHAR == 0 ){
        r.LONG = 1;
    }else{
         r.LONG = 0;
    }
} if(has_type(x, STRING)) {            
    if(x.STRING == 0 ){
        r.LONG = 1;
    }else{
         r.LONG = 0;
    }
}
push(s,r);
}
/**
 * \brief funçao que coloca no topo da stack 0 se um dos dois ultimos elementos é zero, caso contrario retorna o topo da stack 
 * @param s - passagem de stack como parametro  
 */
void eShortcout(STACK *s) {
    DATA x = pop(s);   
    DATA y = pop(s);   
    DATA r; 
    if(has_type(x, LONG) && has_type(y, LONG)) {
        if(x.LONG == 0 || y.LONG == 0) {
           r.type = LONG;
           r.LONG = 0;
           push(s,r);
        } else {                          
           push(s,x); 
        }
    } else if(has_type(x, LONG) && has_type(y, DOUBLE)) {
        if(x.LONG == 0 || y.DOUBLE== 0) { 
           r.type = LONG;
           r.LONG = 0;
        } else {
           r.type = LONG; 
           r.LONG = x.LONG;                     
        }
        push(s,r);
    } else if(has_type(x, DOUBLE) && has_type(y, LONG)) {
        if(x.DOUBLE == 0 || y.LONG == 0) { 
           r.type = LONG;
           r.LONG = 0;
        } else {
           r.type = DOUBLE; 
           r.DOUBLE = x.DOUBLE;                     
        }
        push(s,r); 
    } else if(has_type(x, DOUBLE) && has_type(y, DOUBLE)) {    // 0.0 nao funciona 
        if(x.DOUBLE == 0 || y.DOUBLE == 0) { 
           r.type = LONG;
           r.LONG = 0;
        } else {
           r.type = DOUBLE; 
           r.DOUBLE = x.DOUBLE;                     
        }
        push(s,r);
    } else if(has_type(x, CHAR) && has_type(y, LONG)) {
        if(y.LONG == 0 || x.CHAR == 0) { 
           r.type = LONG;
           r.LONG = 0;
        } else {
           r.type = CHAR; 
           r.CHAR = x.CHAR;                     
        }
        push(s,r);
    } else if(has_type(x, LONG) && has_type(y, CHAR)) {
        if(x.LONG == 0 || y.CHAR == 0) {
           r.LONG = 0;
           push(s,r);
        } else {                          
           push(s,x); 
        }
    } else if(has_type(x, CHAR) && has_type(y, CHAR)) {
        if(x.CHAR == 0 || y.CHAR == 0) {
           r.LONG = 0;
           push(s,r);
        } else {
           r.type = CHAR; 
           r.CHAR = x.CHAR;                     
        }
        push(s,r);
    } else if(has_type(x, DOUBLE) && has_type(y, CHAR)) {
        if(x.DOUBLE == 0 || y.CHAR == 0) { 
           r.type = LONG;
           r.LONG = 0;
        } else {
           r.type = DOUBLE; 
           r.DOUBLE = x.DOUBLE;                     
        }
        push(s,r);
    } else if(has_type(x, CHAR) && has_type(y, DOUBLE)) {
        if(x.CHAR == 0 || y.DOUBLE == 0) { 
r.type = LONG;
           r.LONG = 0;
        } else {
           r.type = CHAR; 
           r.CHAR = x.CHAR;                     
        }
        push(s,r);
    }
}

/**
 * \brief funçao que coloca no topo da stack 0 se os dois ultimos elementos da stack forem zero , caso contrario retorna o penultimo elemento
 * @param s - passagem de stack como parametro  
 */
// escolhe o que está em ultimo  FUNCIONA
void ouShortcout(STACK *s) {
    DATA x = pop(s);   
    DATA y = pop(s);   
    DATA r; 
    if(has_type(x, LONG) && has_type(y, LONG)) {
        if(x.LONG == 0 && y.LONG == 0) {
           r.LONG = 0;
           push(s,r);
        } else if (x.LONG != 0 && y.LONG ==0) {                          
           push(s,x); 
        } else {
           push(s,y);
        }
    } else if(has_type(x, LONG) && has_type(y, DOUBLE)) {
        if(x.LONG == 0 && y.DOUBLE == 0) {
           r.LONG = 0;
           push(s,r);
        } else if (x.LONG != 0 && y.DOUBLE ==0) {                          
           push(s,x); 
        } else {
           push(s,y);
        }
    } else if(has_type(x, DOUBLE) && has_type(y, LONG)) {
        if(x.DOUBLE == 0 && y.DOUBLE == 0) {
           r.LONG = 0;
           push(s,r);
        } else if (x.DOUBLE != 0 && y.LONG ==0) {                          
           push(s,x); 
        } else {
           push(s,y);
        }
    } else if(has_type(x, DOUBLE) && has_type(y, DOUBLE)) {     
        if(x.DOUBLE == 0 && y.DOUBLE == 0) {
           r.LONG = 0;
           push(s,r);
        } else if (x.DOUBLE != 0 && y.DOUBLE ==0) {                          
           push(s,x); 
        } else {
           push(s,y);
        }
    } else if(has_type(x, CHAR) && has_type(y, LONG)) {
        if(x.CHAR == 0 && y.LONG == 0) {
           r.LONG = 0;
           push(s,r);
        } else if (x.CHAR != 0 && y.LONG ==0) {                          
           push(s,x); 
        } else {
           push(s,y);
        }
    } else if(has_type(x, LONG) && has_type(y, CHAR)) {
        if(x.LONG == 0 && y.CHAR == 0) {
           r.LONG = 0;
           push(s,r);
        } else if (x.LONG != 0 && y.CHAR == 0) {                          
           push(s,x); 
        } else {
           push(s,y);
        }
    } else if(has_type(x, CHAR) && has_type(y, CHAR)) {
        if(x.CHAR == 0 && y.CHAR == 0) {
           r.LONG = 0;
           push(s,r);
        } else if (x.CHAR != 0 && y.CHAR ==0) {                      
           push(s,x); 
        } else {
           push(s,y);
        }
    } else if(has_type(x, DOUBLE) && has_type(y, CHAR)) {
        if(x.DOUBLE == 0 && y.CHAR == 0) {
           r.LONG = 0;
           push(s,r);
        } else if (x.DOUBLE != 0 && y.CHAR ==0) {                          
           push(s,x); 
        } else {
           push(s,y);
        }
    } else if(has_type(x, CHAR) && has_type(y, DOUBLE)) {
        if(x.CHAR == 0 && y.DOUBLE == 0) {
           r.LONG = 0;
           push(s,r);
        } else if (x.CHAR != 0 && y.DOUBLE ==0) {                          
           push(s,x); 
        } else {
           push(s,y);
        }
    }
}
/**
 * \brief se o topo da stack for verdadeiro, ou seja, qualquer elemento exceto o zero, a funçao coloca no topo da stack o penultimo elemento, caso contrario coloca o antepenultimo 
 * @param s - passagem de stack como parametro  
 */
void ifThenElse(STACK *s) {
    DATA x = pop(s);          
    DATA y = pop(s);        
    DATA z = pop(s);        
    if(has_type(z, LONG)) {
      if(z.LONG !=0) {
       push(s,y); 
      } else {
       push(s,x); 
      }
    } else if(has_type(z, DOUBLE)) {
      if(z.DOUBLE !=0) {
       push(s,y); 
      } else {
       push(s,x); 
      }
    } else if(has_type(z, CHAR)) {
      if(z.CHAR !=0) {
       push(s,y); 
      } else {
       push(s,x); 
      }
    }  
}
