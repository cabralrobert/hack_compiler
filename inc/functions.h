/*******************************************************
*                                                      *
*   Criado em: sex 19/mai/2017,  19:53 hs              *
*   Instituicao: Universidade Federal do Ceará         *
*   Autor: Robert Cabral                               *
*   email: robertcabral@alu.ufc.br                     *
*                                                      *
********************************************************/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>

using namespace std;

#define isDigit(a) (a >= '0' && a <= '9' ? true : false)
#define isValid(a) (a[0] == '@' || a[1] == '=' || a[1] == ';' || a[0] == '(') ? true : false
#define isTypeA(a) (a[0] == '@' ? true : false)
#define isTypeC(a) (a[1] == '=' || a[1] == ';' ? true : false)
#define isTypeLabel(a) (a[0] == '(') ? true : false
#define setBit(x,y) (x |= 1<<y)

void rmTab(string &line);
void rmComment(string &line);

static int pc = 0;

#endif
