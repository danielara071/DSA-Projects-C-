#include <iostream>
#include <fstream>
#include <vector>
#include "Registro.h"

using namespace std;

// Fabricio Banda Hernandez A00839916
// Daniel Lara A01711690
/* Este programa lee un archivo de texto con diversas fechas de acciones las cuales se van a ordenar de acuerdo de una clave generada
por su mes y dia para posteriormente ordenarlas y mostrarlas en el rango de fechas definido por el usuario para su consulta */

string mesToNumber(string month) {
    if (month == "Jan") return "1";
    if (month == "Feb") return "2";
    if (month == "Mar") return "3";
    if (month == "Apr") return "4";
    if (month == "May") return "5";
    if (month == "Jun") return "6";
    if (month == "Jul") return "7";
    if (month == "Aug") return "8";
    if (month == "Sep") return "9";
    if (month == "Oct") return "10";
    if (month == "Nov") return "11";
    if (month == "Dec") return "12";
    return "-1"; // Si el mes no es válido
}

void leer(string archivo, vector<Registro> &vector) {
    ifstream file(archivo);
    if (file.is_open()) {
        string clave, line;
        while (getline(file, line)) {
            clave = "";
            for (int i = 0; i < 3; i++) {
                clave += line[i];
            }

            clave = mesToNumber(clave);

            string dia = "";
            for (int i = 4; i <= 5; i++) {
                dia += line[i];
            }

            if (dia[1] != ' ') {
                clave += dia;
            } else {
                dia.pop_back();
                clave += "0" + dia;
            }

            vector.push_back(Registro(stoi(clave), line));  // Creamos el registro y lo añadimos al vector
        }
        file.close();
    } else {
        cout << "Archivo inexistente" << endl;
    }
}

string convertir_a_clave(string fecha) {
    string clave = "";


    for (int i = 0; i < 3; i++) {
        clave += fecha[i];
    }

    clave = mesToNumber(clave);

    // Extraer el día

    string dia = "";
    for (int i = 4; i <= 5; i++) {
        dia += fecha[i];
    }

    if (stoi(dia)>=10) {
        clave += dia;
    } else {
        dia.pop_back();
        clave += "0" + dia;
    }

    return clave;
}



void printFechas(vector<Registro> &a, string fecha_inicio, string fecha_fin) {
    int clave_inicio = stoi(convertir_a_clave(fecha_inicio));
    int clave_fin = stoi(convertir_a_clave(fecha_fin));

    for (int i = 0; i < a.size(); i++) {
        int clave_actual = a[i].getClave();
        if (clave_actual >= clave_inicio && clave_actual <= clave_fin) {
            cout << a[i].getData() << endl;
        }
    }
}


void print(const vector<Registro> &a, int n) {
    for (int i = 0; i < n && i < a.size(); i++) {
        cout <<a[i].getClave()<<' '<< a[i].getData()<< endl;
    }
}


void swap(vector <Registro> &arreglo, int i, int j ){
    Registro buffer = arreglo[i];
    arreglo[i] = arreglo[j];
    arreglo[j] = buffer;
}

void bubbleSortFlag(vector <Registro> &arreglo ,int n ) {
    for (int i=0;i<=n-1;i++) {
        bool flag = false;
        for (int j=0;j<n-i;j++) {
            if(arreglo[j].getClave()>arreglo[j+1].getClave()) {
                swap(arreglo,j,j+1);
                flag=true;
            }
        }
        if (flag==false) {
            break;
        }
    }
}

int main() {
    vector<Registro> vector;
    string fecha_inicio;
    string fecha_termino;
    leer("bitacora.txt", vector);
    cout<<"Fecha inicio: ";getline(cin,fecha_inicio);
    cout<<endl<<"Fecha Termino: "; getline(cin,fecha_termino);

    bubbleSortFlag(vector,vector.size());
    printFechas(vector,fecha_inicio,fecha_termino);



    return 0;
}