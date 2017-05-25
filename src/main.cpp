#include <iostream>
#include <string>
#include <map>
#include "functions.h"
#include "arquivo.h"
#include "typeA.h"
#include "typeC.h"

using namespace std;

int main(int argc, char *argv[])
{        
    if(argc < 3){
        cout << "Você esqueceu de digitar o nome dos arquivos!!!" << endl;
    }else if(argc > 3){
        cout << "Digite somente o arquivo de entrada e o de saida respectivamente." << endl;
    }else{
        Arquivo arquivo(argv[1], argv[2]);
        string line = arquivo.getLine();
        A typeA;
        C typeC;

        if(arquivo.isOpened()){

            while(!arquivo.isEnd()){

                rmTab(line);

                if(isValid(line)){
                    if(line == "\0"){
                        line = "0";
                    }
                    rmComment(line);

                    if(isTypeA(line)){
                        pc++;
                        typeA.decoder(arquivo,line);
                    }
                    else if(isTypeC(line)){
                        pc++;
                        typeC.decoder(arquivo,line);
                    }
                    else if(isTypeLabel(line)){
                        typeA.decoder(arquivo,line);
                    }
                }
                line = arquivo.getLine();
            }
        }else{
            cout << "Digite um arquivo valido." << endl;
        }
    }


    return 0;
}
