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
