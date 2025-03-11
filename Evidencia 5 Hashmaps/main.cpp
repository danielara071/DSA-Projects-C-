#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;


string extractIP( string& ipS) {
    size_t pos = ipS.find(':');
    if (pos != string::npos) {
        return ipS.substr(0, pos);
    }
    return ipS;
}

int main() {
    unordered_map<string, int> hashTable;  
    ifstream file("sorted_bitacora_EV5.txt");

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string mes, dia, time, ipS, description;
        
        ss >> mes >> dia >> time >> ipS;
        getline(ss, description);  

        
        string ip = extractIP(ipS);
        hashTable[ip]++;
    }
    file.close();

    
    string ipconsultar;
    cout << "Ingrese una IP para consultar los accesos: ";
    cin >> ipconsultar;
    if (hashTable.find(ipconsultar) != hashTable.end()) {
        cout << "IP: " << ipconsultar << "\n Accesos: " << hashTable[ipconsultar] << endl;
    } else {
        cout << "IP: " << ipconsultar << "\n Accesos: 0 bro" << endl;
    }

    return 0;
}
