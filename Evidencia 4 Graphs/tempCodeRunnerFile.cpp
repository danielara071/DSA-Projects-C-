
        // Leer las IPs
        for (int i = 0; i < numNodos; ++i) {
            string ip;
            getline(file, ip);
            grafo.agregarNodo(ip);
        }


        for (int i = 0; i < numAristas; ++i) {
            string mes, dia, hora, ipOrigen, ipDestino, razon;
            file >> mes >> dia >> hora >> ipOrigen >> ipDestino;
            getline(file, razon);
            grafo.agregarArista(ipOrigen, ipDestino);
        }

        file.close();
    } else {
        cerr << " No se pudo abrir el archivo " << archivo << endl;
    }
}

int main() {

    string bitacora = "bitacora_EV4.txt";
    Grafo grafo;

    leer(bitacora, grafo);

    cout << "Grafo:" << endl;
    grafo.imprimirGrafo();

    vector<string> nodosBotMaster = grafo.nodosConMayorFanOut();

    cout << "Nodos con mayor fan-out:" << endl;
    for (const string& nodo : nodosBotMaster) {
        cout << nodo << " fan-out de: " << grafo.obtenerFanOut(nodo) << endl;
    }

    return 0;
}