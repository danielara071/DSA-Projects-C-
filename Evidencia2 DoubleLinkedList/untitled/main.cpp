#include <iostream>
#include <fstream>
#include "DoublyLinkedList.h"

using namespace std;

// Fabricio Banda Hernandez A00839916
// Daniel Lara A01711690
/* Este programa lee un archivo de texto con diversas fechas de acciones las cuales se van a ordenar de acuerdo de una clave generada
por su mes y dia para posteriormente ordenarlas y mostrarlas en el rango de fechas definido por el usuario para su consulta */


void leer(string archivo, DoublyLinkedList<int> &structure) {
    ifstream file(archivo);
    if (file.is_open()) {
        string clave, line;
        while (getline(file, line)) {
            clave = "";
            int i = 0; // variable que indica cuantas veces se ha encontrado un char en blanco, sirve para capturar las ip
            int dotcount =0; // variable para calcular cantidad de puntos encontrados
            for(int j = 0; j < 25; j++){
                if(line[j]== ' '){
                    i++;
                }
                if(i == 3){ //despues de 3 char blancos encontrado si agregan las ip
                    string bitTwo = ""; // para almacenar segunda parte despues del punto
                    string bitTres=""; // para almacenar tercera partde despues del segundo punto
                    for(j; j <= 25; j++){
                        if(line[j] == '.'){
                            dotcount++;
                        }
                        if(dotcount > 2){
                            break;
                        }
                        if(line[j] != '.' && dotcount < 1){
                            clave += line[j];
                        }
                        if(line[j] != '.' && dotcount == 1){
                            bitTwo += line[j];
                        }
                        if(line[j] != '.' && dotcount == 2){
                            bitTres += line[j];
                        }



                    }
                    if(stoi(bitTwo) <= 9){
                        string firstZero = "0";
                        clave += firstZero +bitTwo;
                    }

                    if(stoi(bitTres) <= 9){
                        string firstZero = "0";
                        clave += firstZero +bitTres;
                    }

                    if(stoi(bitTres)>100 && stoi(bitTres)<=10){
                        string firstZero = "0";
                        clave += firstZero +bitTres;
                    }

                    else{
                        clave += bitTwo + bitTres;
                    }


                    break;
                }

            }

            structure.addFirst(stoi(clave), line);

        }
        file.close();
    } else {
        cout << "Archivo inexistente" << endl;
    }
}

string convertirclave(string ip) {
    string clave ="";
    string bitTwo="";
    string bitTres="";

    int dotcount=0;

    for (int i=0;i<25;i++) {

        if (ip[i]=='.') {
            dotcount++;
        }

            if(dotcount > 2){
                break;
            }

            if(ip[i] != '.' && dotcount < 1){
                clave += ip[i];
            }

            if(ip[i] != '.' && dotcount == 1){
                bitTwo += ip[i];
            }

            if(ip[i] != '.' && dotcount == 2){
            bitTres += ip[i];

        }




    }

        if(stoi(bitTwo) <= 9){
         string firstZero = "0";
         clave += firstZero + bitTwo;
     }

    if(stoi(bitTres) <= 9){
        string firstZero = "0";
        clave += firstZero +bitTres;
    }

    if(stoi(bitTres)>100 && stoi(bitTres)<=10){
        string firstZero = "0";
        clave += firstZero +bitTres;
    }

    else{
        clave += bitTwo + bitTres;
    }

    return clave;

}


void insertIps(  DoublyLinkedList<int> &structure, string ipinicio, string ipfin) {

    int ip_inicio = stoi(convertirclave(ipinicio));
    int ip_fin = stoi(convertirclave(ipfin));

    ofstream texto("bitacoraNueva.txt");

    for (int i = 0; i < structure.getSize(); i++) {
        int clave_actual = structure.getData(i);

        if (clave_actual >= ip_inicio && clave_actual <= ip_fin) {
            cout<<structure.getline(i)<<endl;
            texto<<structure.getline(i)<<endl;
        }
    }


}

int main() {

    DoublyLinkedList<int> structure;
    leer("bitacora.txt", structure);
    int n = structure.getSize();
    string ip1,ip2;
    structure.quickSort(0,n-1);
    structure.print();
    //insertTxt(n,structure);
    //cout<<convertirclave("423.2.230.77:6166");
    cout<<"---------Buscador Direcciones Ip---------"<<endl;
    cout<<"Ip de Inicio: ";cin>>ip1;
    cout<<endl<<"Ip Final: ";cin>>ip2;
    cout<<"Lista de ips ordenada: "<<endl;
    insertIps(structure,ip1,ip2);


    return 0;
}