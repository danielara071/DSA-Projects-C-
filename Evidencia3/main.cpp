#include <iostream>
#include <fstream>
#include "AVL.h"
using namespace std;


string getIp(string archivo) {
    ifstream file(archivo);
    string first_line;

    if (file.is_open()) {
        getline(file, first_line);
        string clave = "";
        int i = 0;
        for(int j = 0; j < 30; j++){
            if(first_line[j]== ' '){
                i++;
            }
            if(i == 3){//despues de 3 char blancos encontrado si agregan las ip
                if(first_line[j] != '.' && first_line[j] != ' '){
                    if(first_line[j] == ':') break;
                    clave += first_line[j];
                }
            }

        }//for
        return clave;
    }

}


void leer(string archivo, AVL<int> &structure) {

    ifstream file(archivo);
    if (file.is_open()) {
        string clave, line, current;
        int count = 0;
        int count_ip=0;
        string first_ip=getIp("bitacora.txt");
        current = first_ip;

        while (getline(file, line)) {
            clave = "";
            int i = 0; // variable que indica cuantas veces se ha encontrado un char en blanco, sirve para capturar las ip
            for(int j = 0; j < 30; j++){
                if(line[j]== ' '){
                    i++;
                }
                if(i == 3){//despues de 3 char blancos encontrado si agregan las ip
                    if(line[j] != '.' && line[j] != ' '){
                        if(line[j] == ':') break;
                        clave += line[j];
                    }
                }

            }//for


            if(current == clave){
                count++;
            }

            if(current != clave || file.eof()){
                structure.insert(count, current);
                count = 1;
            }

            current = clave;


        }//while

        file.close();
    }//if

}

int main(){
    AVL <int> myAVL;
    cout<<"Top 5 ips mas accesos"<<endl;
     leer("bitacora.txt", myAVL);
     myAVL.inorder();

    return 0;
}
