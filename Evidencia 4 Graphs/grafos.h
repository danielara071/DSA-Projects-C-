#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Grafo {
private:
    unordered_map<string, unordered_set<string>> adjList;
    unordered_map<string, int> fanOut;

    string limpiarIp(string ipConPuerto) {
        size_t pos = ipConPuerto.find(':');
        return (pos == string::npos) ? ipConPuerto : ipConPuerto.substr(0, pos);
    }

public:

    Grafo() = default;

    void agregarNodo(string nodo) {
        string nodoLimpio = limpiarIp(nodo);
        if (adjList.find(nodoLimpio) == adjList.end()) {
            adjList[nodoLimpio] = {};
        }
    }

    void agregarArista(string origen, string destino) {
        string origenLimpio = limpiarIp(origen);
        string destinoLimpio = limpiarIp(destino);
        agregarNodo(origenLimpio);
        agregarNodo(destinoLimpio);

        if (adjList[origenLimpio].insert(destinoLimpio).second) {
            fanOut[origenLimpio]++;
        }
    }

    int obtenerFanOut(string nodo) {
        string nodoLimpio = limpiarIp(nodo);
        if (fanOut.find(nodoLimpio) != fanOut.end()) {
            return fanOut.at(nodoLimpio);
        }
        return 0;
    }

    vector<string> nodosConMayorFanOut() {
        int maxFanOut = 0;
        vector<string> resultado;
        for (auto& [nodo, count] : fanOut) {
            if (count > maxFanOut) {
                maxFanOut = count;
                resultado = { nodo };
            } else if (count == maxFanOut) {
                resultado.push_back(nodo);
            }
        }
        return resultado;
    }

    void imprimirGrafo() {
        for (auto& [nodo, destinos] : adjList) {
            cout << nodo << " -> ";
            for (auto& destino : destinos) {
                cout << destino << " ";
            }
            cout << endl;
        }
    }
};