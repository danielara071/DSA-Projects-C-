#include <iostream>
#include <vector>
using namespace std;

template <class T>
class BinaryNode{
    public:
        T data;
        BinaryNode<T> * left;
        BinaryNode <T> * right;
        int height;
        vector <string> ip;
        void add(string);
        void print();
        BinaryNode(T value, string address){
            ip.push_back(address);
            data = value;
            left = nullptr;
            right = nullptr;
            height  = 1;
        }
    

};
template <class T>
void BinaryNode<T> :: add(string ipAddress){
    ip.push_back(ipAddress);
}

template <class T>
void BinaryNode<T> :: print(){
    for(int i=0; i < ip.size(); i++){
        cout << ip[i] << " ";
    }
    cout << endl;
}