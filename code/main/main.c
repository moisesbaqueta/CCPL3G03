/**
 * @file Ficheiro que contem a funçao principal
 * 
 */


#include "parser-1.h"
#include <assert.h>

/**
 * \brief funçao principal do programa 
 * @param fgets funçao que lê uma seq de chars ate "\n"
 * @param strlen indica o tamanho duma string 
 * @returns o valor 0 
 */

int main (){
    char line[10240];
    
    assert(fgets(line,10240,stdin) != NULL);    
    assert(line[strlen(line)-1] == '\n');      
    parse(line);
    return 0 ;
}
