#include <iostream>
using namespace std;

class Registro {
private:
    string data;
    int clave;

public:
    Registro(int key, string line) : clave(key), data(line) {}


    int getClave() const {
        return clave;
    }

    string getData() const {
        return data;
    }

    void setClave(int key) {
        clave = key;
    }

    void setData(string line) {
        data = line;
    }

    void dump() {
        cout << data;
    }
};