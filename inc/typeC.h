/*******************************************************
*                                                      *
*   Criado em: sex 19/mai/2017,  19:58 hs              *
*   Instituicao: Universidade Federal do Ceará         *
*   Autor: Robert Cabral                               *
*   email: robertcabral@alu.ufc.br                     *
*                                                      *
********************************************************/

#ifndef TYPEC_H_
#define TYPEC_H_

#include "arquivo.h"
#include <string>
#include <map>

using namespace std;

class C{

public:
    C();
    void decoder(Arquivo &arquivo, string instruction);

private:
    map<string,int> values;
    map<string,int> jmp;
    map<string,int> variable;

};

#endif
