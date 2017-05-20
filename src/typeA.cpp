/*******************************************************
*                                                      *
*   Criado em: sex 19/mai/2017,  19:57 hs              *
*   Instituicao: Universidade Federal do Ceará         *
*   Autor: Robert Cabral                               *
*   email: robertcabral@alu.ufc.br                     *
*                                                      *
********************************************************/
#include "typeA.h"
#include "arquivo.h"
#include <string>
#include <map>
#include "functions.h"
#include <iostream>

using namespace std;

A::A() : count(16){}

void A::decoder(Arquivo &arquivo, string instruction){
    if(isDigit(instruction[1])){
        instruction.erase(0,1);
        int value = atoi(instruction.c_str());
        arquivo.writeLine(value);
    }else if(isTypeLabel(instruction)){
        for(int i = 0; instruction[i] != '\0'; i++){
            if(instruction[i] == '(' || instruction[i] == ')'){
                instruction.erase(i,i+1);
            }
        }
        //cout << instruction << " " << pc << endl;
        variables[instruction] = pc;
    }
    else{
        //abre outro arquivo, procura em todo o arquivo criado e se achar o instruction, pega o pc e escreve no arquivo antigo
        instruction.erase(0,1);

        Arquivo auxArquivo(arquivo.getFileIn(), arquivo.getFileOut());
        int pc1 = 0;

        while(!auxArquivo.isEnd()){
            string line = auxArquivo.getLine();
            rmTab(line);

            if(isValid(line)){
                rmComment(line);

                if(isTypeA(line)){
                    pc1++;
                }
                else if(isTypeC(line)){
                    pc1++;
                }
                else if(isTypeLabel(line)){
                    for(int i = 0; line[i] != '\0'; i++){
                        if(line[i] == '(' || line[i] == ')'){
                            line.erase(i,i+1);
                        }
                    }

                    if(line == instruction){
                        if(pc1 >= pc){
                            arquivo.writeLine(pc1);
                            return;
                        }
                    }
                }
            }
        }
        pc1 = 0;

        auto pos = variables.find(instruction);
        if(variables.find(instruction) == variables.end()){
            if(instruction == "SCREEN"){
                arquivo.writeLine(0x4000);
            }else{
                variables[instruction] = count;
                arquivo.writeLine(count);
                count++;
            }
        }else
            arquivo.writeLine(pos->second);
    }
}

