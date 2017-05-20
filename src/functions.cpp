/*******************************************************
*                                                      *
*   Criado em: sex 19/mai/2017,  20:01 hs              *
*   Instituicao: Universidade Federal do Ceará         *
*   Autor: Robert Cabral                               *
*   email: robertcabral@alu.ufc.br                     *
*                                                      *
********************************************************/
//#include "functions.h"
#include <string>

using namespace std;

//para linhas que tem o [tab]
void rmTab(string &line){
    while(line[0] == '\t')
        line.erase(0,1);
}

void rmComment(string &line){
    for(int i = 0; line[i] != '\0'; i++){
        if(line[i] == '\t'){
            line = line.substr(0,i);
        }
    }
}
