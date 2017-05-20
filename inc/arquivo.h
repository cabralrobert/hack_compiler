/*******************************************************
*                                                      *
*   Criado em: sex 19/mai/2017,  19:56 hs              *
*   Instituicao: Universidade Federal do Ceará         *
*   Autor: Robert Cabral                               *
*   email: robertcabral@alu.ufc.br                     *
*                                                      *
********************************************************/

#ifndef ARQUIVO_H_
#define ARQUIVO_H_

#include <string>
#include <fstream>

using namespace std;

class Arquivo{

public:
    Arquivo(string nomeIn, string nomeOut);
    string getFileIn();
    string getFileOut();
    bool isEnd();
    string getLine();
    void writeLine(int value);

private:
    string fileIn, fileOut;
    ofstream outFile;
    ifstream myfile;

};

#endif
