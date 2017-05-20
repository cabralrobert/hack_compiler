/*******************************************************
*                                                      *
*   Criado em: sex 19/mai/2017,  19:58 hs              *
*   Instituicao: Universidade Federal do Ceará         *
*   Autor: Robert Cabral                               *
*   email: robertcabral@alu.ufc.br                     *
*                                                      *
********************************************************/

#include "typeC.h"
#include "arquivo.h"
#include <map>
#include "functions.h"

using namespace std;


C::C(){
    values["0"] = 0xA80;	//6<<101010
    values["1"] = 0xFC0;	//6<<111111
    values["-1"] = 0xE80;	//6<<111010
    values["D"] = 0x300;	//6<<001100
    values["A"] = 0xC00;	//6<<110000
    values["M"] = 0x1C00;	//6<<110000
    values["!D"] = 0x340;	//6<<001101
    values["!A"] = 0xC40;	//6<<110001
    values["!M"] = 0x1C40;	//6<<110001
    values["-D"] = 0x3C0;	//6<<001111
    values["-A"] = 0xCC0;	//6<<110011
    values["-M"] = 0x1CC0;	//6<<110011
    values["D+1"] = 0x7C0;	//6<<011111
    values["A+1"] = 0xDC0;	//6<<110111
    values["M+1"] = 0x1DC0;	//6<<110111
    values["D-1"] = 0x380;	//6<<001110
    values["A-1"] = 0xC80;	//6<<110010
    values["M-1"] = 0x1C80;	//6<<110010
    values["D+A"] = 0x80;	//6<<000010
    values["D+M"] = 0x1080;	//6<<000010
    values["D-A"] =	0x4C0;	//6<<010011
    values["D-M"] =	0x14C0;	//6<<010011
    values["A-D"] = 0x1C0;	//6<<000111
    values["A-M"] = 0x11C0;	//6<<000111
    values["D&A"] = 0x0;	//6<<000000
    values["D&M"] = 0x1000;	//6<<000000
    values["D|A"] = 0x540;	//6<<010101
    values["D|M"] = 0x1540;	//6<<010101

    jmp[""] = 0x0;
    jmp["JGT"] = 0x1;
    jmp["JEQ"] = 0x2;
    jmp["JGE"] = 0x3;
    jmp["JLT"] = 0x4;
    jmp["JNE"] = 0x5;
    jmp["JLE"] = 0x6;
    jmp["JMP"] = 0x7;
}


void C::decoder(Arquivo &arquivo, string instruction){
    int value = 0;

    setBit(value,13);
    setBit(value,14);
    setBit(value,15);

    if(instruction[1] == '='){
        //Instruções tipo dest=valor (operação) valor2
        switch(instruction[0]){
        case 'D':
            setBit(value,4);
            break;

        case 'A':
            setBit(value,5);
            break;

        case 'M':
            setBit(value,3);
            break;

        default:
            break;
        }

        instruction.erase(0,2);

        auto p = values.find(instruction);
        if(p != values.end())
            value |= p->second;

        arquivo.writeLine(value);

    }else if(instruction[1] == ';'){
        while(instruction[2] == ' ')
            instruction.erase(2,1);

        //Instruções Jump
        string pos1;
        pos1.push_back(instruction[0]);

        if(values.find(pos1) != values.end())
            value |= values.find(pos1)->second;

        instruction.erase(0,2);
        if(jmp.find(instruction) != jmp.end())
            value |= jmp.find(instruction)->second;

        arquivo.writeLine(value);
    }
}
