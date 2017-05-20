/*******************************************************
*                                                      *
*   Criado em: sex 19/mai/2017,  19:56 hs              *
*   Instituicao: Universidade Federal do Ceará         *
*   Autor: Robert Cabral                               *
*   email: robertcabral@alu.ufc.br                     *
*                                                      *
********************************************************/
#include "arquivo.h"
#include <fstream>

using namespace std;

Arquivo::Arquivo(string nomeIn, string nomeOut):
    myfile("data/"+nomeIn),outFile("data/"+nomeOut)
{
    this->fileIn = nomeIn;
    this->fileOut = nomeOut;
}

string Arquivo::getFileIn(){
    return this->fileIn;
}

string Arquivo::getFileOut(){
    return this->fileOut;
}

bool Arquivo::isEnd(){
    return myfile.eof();
}

string Arquivo::getLine(){
    string line;
    if(myfile.is_open())
    {
        getline(myfile,line);
        return line;
        myfile.close();
    }
    return "\0";
}

void Arquivo::writeLine(int value){
    for (int i = 15; i >= 0; i--)
        ((value >> i) & 1) ? outFile.put('1') : outFile.put('0');
    outFile.put('\n');
}
