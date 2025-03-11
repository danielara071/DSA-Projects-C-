#include <iostream>
#include "DoublyNode.h"
using namespace std;


template <class T>
class DoublyLinkedList{
    private:
        DoublyNode<T>  *head;
        int size;
    public:

    DoublyLinkedList(){
        head = nullptr;
        size = 0;
    }

    string getline(int index) {
        DoublyNode<T> *curr = head;
        for (int i=0;i<index;i++) {
            curr = curr ->next;
        }
        return curr->line;
    }

    int getData(int index){
        DoublyNode<T> *curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->data;
    }


    void swap(int index1, int index2) {
        if (index1 >= size || index2 >= size) {
            cout << "No fue posible el swap";
        }

        DoublyNode<T> *curr1 = head;
        DoublyNode<T> *curr2 = head;

        for (int i = 0; i < index1; i++) {
            curr1 = curr1->next;
        }
        for (int j = 0; j < index2; j++) {
            curr2 = curr2->next;
        }


        T buffer = curr1->data;
        curr1->data = curr2->data;
        curr2->data = buffer;


        string bufferline = curr1->line;
        curr1->line=curr2->line;
        curr2->line=bufferline;
    }

    int par(int l, int r) {

        DoublyNode<T>* nodeL = head;
        for (int i = 0; i < l; i++) {
            nodeL = nodeL->next;
        }

        int x = nodeL->data;

        int i = l + 1;


        for (int j = i; j <= r; j++) {
            DoublyNode<T>* curr = head;

            for (int k=0; k<j ; k++) {
                curr = curr->next;
            }

            if((curr->data)<x){
                swap(i, j);
                i = i + 1;
            }

        }

        swap(l, i - 1);
        return i - 1;
    }

    void quickSort(int l, int r) {
        if(l < r){
            int p = par(l,r);
            quickSort(l, p-1);
            quickSort(p + 1, r);
        }
    }


    void addFirst( T value, string line){
        DoublyNode<T> *newNode = new DoublyNode<T>(value, line);
        DoublyNode<T> *curr;
        curr = head;
        newNode -> next = curr;
        head = newNode;
        if (size > 0){
            curr -> prev = newNode;
        }
        size++;
    }

    void addLast(T value){
        
        if (head == nullptr){
            addFirst(value);
        }
        else{
            DoublyNode<T> *newNode = new DoublyNode<T>(value);
            DoublyNode<T> *curr;
            curr = head;
            while (curr -> next != nullptr){
                curr = curr -> next;
            }
            curr -> next = newNode;
            newNode -> prev = curr;
            size++;
        }
        
    }

    bool addAtIndex(T value, int index){
        if (index > size){
            return false;
        }
        if(index == 0){
            addFirst(value);
        }
        else if (index ==  size){
            addLast(value);
        }
        else{
            DoublyNode<T> *newNode = new DoublyNode<T>(value);
            DoublyNode<T> *curr;
            curr = head;
            for (int i = 0; i < index; i++){
                curr = curr -> next;
            }
            newNode -> prev = curr;
            newNode -> next = curr -> next;
            newNode -> next->prev = newNode;
            curr -> next = newNode;
            size++;
        }
        return true;
        
    }

    bool setAtIndex(int index, float value){
        
        if (index > size){
            return false;
        }
        else{
            DoublyNode<T> *curr;
            DoublyNode<T> *newNode = new DoublyNode<T>(value);
            curr = head;
            if(index == 0){
                curr ->data = newNode -> data;
                delete newNode;
                return true;
            }
            for (int i = 1; i <= index; i++){
                curr = curr -> next;
            }
            curr -> data = newNode -> data;
            delete newNode;
        }  
        return true;
    }


    bool deleteFirst(){
        DoublyNode<T> *del;
        del = head;
        if (head == nullptr){
            return false;
        }
        else if(head -> next == nullptr){
            head = nullptr;
        }
        else{
            head = head -> next;
            //head -> prev = nullptr;
        }
        delete del;
        size--;
        return true;
        
    }

    bool deleteLast(){
        DoublyNode<T> *curr, *before;
        curr = head;
        if ( head == nullptr){
            return false;
        }
        else if(head -> next == nullptr){
            head = nullptr;
        }
        else{
            while(curr -> next != nullptr){
                curr = curr -> next;
            }
            before = curr -> prev;
            before -> next = nullptr;
        }
        delete curr;
        size--;
        return true;
    }

    bool deleteAtIndex(int index){
        if (index >= size){
            return false;
        }
        if(index == 0){
            deleteFirst();
        }
        else if ( index == size -1){
            deleteLast();
        }
        else{
            DoublyNode<T> *curr, *before;
            curr = head;
            for(int i = 1; i <= index; i++){
                curr = curr -> next;
            }
            before = curr -> prev;
            before -> next = curr -> next;
            curr ->next -> prev = before;
            delete curr;
            size--;
        }
        return true;

    }

    void deleteAll(){
        DoublyNode <T> *curr;
        while(head != nullptr){
            curr = head -> next;
            delete head;
            size--;
            head = curr;
        }
    }


    

    int getIndex(float value){
        DoublyNode<T> *curr;
        curr = head;
        int index = 0;
        while(curr != nullptr){
            if(curr ->data == value){
                return index;
            }
            index++;
        }
        return -1;
    }

    int getSize(){
        return size;
    }

    void print(){
        DoublyNode<T> *curr;
        curr = head;

        if (size > 0){
            while ( curr != nullptr){
                cout << curr->line << " "<<endl;
                curr = curr->next;
            }
        }
        else{
            cout << "Empty List! " << endl;
        }
    }

    void printReverse(){
        DoublyNode<T> *curr;
        curr = head;
        if (size > 0){
            while ( curr -> next != nullptr){
                curr = curr -> next;
            }
            cout << curr-> data << " ";
            curr = curr -> prev;
            while(curr != nullptr){
                cout << curr ->data << " ";
                curr = curr -> prev;
            }
            cout << endl;
        }else{
            cout << "Empty List!" << endl;
        }
    }
};