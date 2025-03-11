#include <iostream>
using namespace std;

template <class T>
class DoublyNode{
public:
    T data;
    string line;
    DoublyNode<T> *next;
    DoublyNode<T> *prev;
    DoublyNode(T value, string liney){
        next = nullptr;
        prev = nullptr;
        data = value;
        line = liney;
    }
};
