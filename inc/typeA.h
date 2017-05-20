/*******************************************************
*                                                      *
*   Criado em: sex 19/mai/2017,  19:57 hs              *
*   Instituicao: Universidade Federal do Ceará         *
*   Autor: Robert Cabral                               *
*   email: robertcabral@alu.ufc.br                     *
*                                                      *
********************************************************/
#ifndef TYPEA_H_
#define TYPEA_H_

#include "arquivo.h"
#include <map>

using namespace std;

class A{

public:
    A();
    void decoder(Arquivo &arquivo, string instruction);

private:
    map<string, int> variables;
    int count;

};

#endif
