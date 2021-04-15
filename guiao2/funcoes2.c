#include "stack2.h"
#include "stack2.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int verificaChar (char s) {
   int i,r=0;
   char vogais[10] = "_;\\@$lifc";

	for (i=0; i<10; i++) {
		if (s == vogais[i]) {
         r=1;
      }
	}   
  return r; 
}

void ler(STACK *s) {                           
    char line[10240];                          
    assert(fgets(line,10240,stdin)!=NULL);     
    assert(line[strlen(line)-1]=='\n');        
    push_STRING(s,line);                  
}


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

void toChar(STACK *s) {             
   DATA x = pop(s);                            
   if(has_type(x,LONG)) {                       
      push_CHAR(s,x.LONG); }        
   else if(has_type(x,DOUBLE)) {            
      push_CHAR(s,x.DOUBLE); } 
   else 
      push(s,x); 
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
                                            
void COPY(STACK *s,int n) {              
   STACK *p = create_stack();        
   int i;                            
   for(i=0; i<n; i++) {              
      DATA X = pop(s);          
      push(p,X);                     
   }                                 
   DATA Y = top(s);              
   for(i=0; i<n; i++) {               
     DATA P = pop(p);                
     push(s,P);                 
   }                                  
   push(s,Y);                 
}

void parse2(char *line, STACK *s) {
   char *delims = " \t\n";
   int x; 

   for(char *token = strtok(line, delims); token != NULL; token = strtok(NULL, delims)) {
      char *sobra1;
      char *sobra2;
                             
      long val_l = strtol(token, &sobra1, 10);            // string -> long 
      double val_d = strtod(token, &sobra2);              // string -> double 

      if(strlen(sobra1) == 0) { 
         push_LONG(s, val_l); 
      } else if(strlen(sobra2) == 0) { 
         push_DOUBLE(s, val_d);
      } else if(!verificaChar(token[0]) || strlen(token) != 1)  {
      if(strlen(token)==1) {
         push_CHAR(s,token[0]);
      } else {
         push_STRING(s, token);
      }
      } else if(strcmp(token, "_")== 0 )  { 
         UNDERSCORE(s);
      } else if(strcmp(token, ";")== 0 )  { 
         SEMICOLON(s);
      } else if(strcmp(token, "\\")== 0 ) {
         BACK_SLASH(s);
      } else if(strcmp(token, "@")== 0 ) {
         AT_SIGN(s);
      } else if(strcmp(token, "$")== 0 ) { 
         (scanf("%d", &x)); 
         COPY(s,x);
      } else if(strcmp(token, "l")== 0 ) {
         ler(s);
         // parse2(pop(s).STRING,s);
      } else if(strcmp(token, "i")== 0 ) {
         toInt(s);
      } else if(strcmp(token, "f")== 0 ) { 
         toDouble(s);
      } else if (strcmp(token, "c")== 0 ) {
         toChar(s);
      }
   }
   print_stack(s); 
}

int main() {
  STACK *p = create_stack();
  char buf[BUFSIZ];
  char *s =fgets(buf, BUFSIZ, stdin);   
  parse2(s,p);
  return 0;
}
