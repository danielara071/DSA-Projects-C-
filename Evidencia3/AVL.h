#include <iostream>
#include "BinaryNode.h"
using namespace std;

template <class T>
class AVL{
    private:
        BinaryNode<T> *root;

        int getHeight(BinaryNode<T> *node){
            if (node == nullptr){
                return 0;
            }
            return node -> height;
        }
        int getBalance(BinaryNode<T> *node){
            if (node == nullptr){
                return 0;
            }
            return getHeight(node -> right) - getHeight(node ->left);
        }

        int updateHeight(BinaryNode<T> *node){
            return 1 + max(getHeight(node -> right ), getHeight(node -> left));
        }

        BinaryNode<T> *rightRotate(BinaryNode<T> *parent){
            BinaryNode<T> *leftChild =  parent -> left;
            BinaryNode<T> *leftRightGrandChild = leftChild -> right;
            parent -> left = leftRightGrandChild;
            leftChild -> right = parent;
            parent -> height = updateHeight(parent);
            leftChild -> height = updateHeight(leftChild);
            return leftChild;

        }

        BinaryNode<T> *leftRotate(BinaryNode<T> *parent){
            BinaryNode<T> *rightChild = parent -> right;
            BinaryNode<T> *rightLeftGrandChild = rightChild ->left;
            parent -> right = rightLeftGrandChild;
            rightChild -> left = parent;
            parent -> height = updateHeight(parent);
            rightChild -> height = updateHeight(rightChild);
            return rightChild;
        }

        BinaryNode<T>* searchRecursive(BinaryNode<T> * parent, T value){
            if(parent == nullptr){
                return nullptr;
            } else{
                if (value < parent-> data){
                     return searchRecursive(parent->left, value);
                } else if(value > parent->data){
                     return searchRecursive(parent->right, value);
                } else {
                    return parent;
                }
            }
        }

        BinaryNode<T> *insertRecursive(BinaryNode<T> *parent, T value, string address){
            if (parent == nullptr){
                parent = new BinaryNode<T>(value, address);
            } else {
                if(value < parent -> data){
                    parent -> left = insertRecursive(parent->left, value, address);
                } else if (value > parent->data){
                    parent->right = insertRecursive(parent -> right, value, address);
                } else{

                    parent->add(address);
                    return parent;
                }
            }
            parent -> height = updateHeight(parent);
            int balance = getBalance(parent);

            if (balance > 1 && getBalance(parent -> right) > 0){
                return leftRotate(parent);
            }

            if (balance < -1 && getBalance(parent -> left) < 0){
                return rightRotate(parent);
            }

            if(balance > 1 && getBalance(parent -> right) < 0){
                parent -> right = rightRotate(parent -> right);
                return leftRotate(parent);
            }

            if (balance < -1 && getBalance(parent -> left) > 0){
                parent -> left = leftRotate(parent -> left);
                return rightRotate(parent);
            }

            return parent;
        }

        BinaryNode<T> *removeRecursive(BinaryNode<T> *parent, T value){
            if(parent == nullptr){
                cout << "The element does not exist, it cannot be removed"<< endl;
                return parent;
            }else{
                if(value < parent -> data){
                    parent-> left = removeRecursive(parent->left,value);
                }else if(value > parent -> data){
                    parent -> right = removeRecursive(parent->right, value);
                } else{
                    BinaryNode<T> *rem = parent;
                    if(rem->left == nullptr){
                        parent = rem -> right;
                    }else if(rem-> right == nullptr){
                        parent = rem -> left;
                    }else{
                        rem = replace(rem);
                    }
                    delete rem;
                }
            }

            if(parent ==  nullptr){
                return parent;
            }

            parent -> height = updateHeight(parent);
            int balance = getBalance(parent);

            if (balance > 1 && getBalance(parent -> right) >= 0){
                return leftRotate(parent);
            }

            if (balance < -1 && getBalance(parent -> left) <= 0){
                return rightRotate(parent);
            }

            if(balance > 1 && getBalance(parent -> right) <= 0){
                parent -> right = rightRotate(parent -> right);
                return leftRotate(parent);
            }

            if (balance < -1 && getBalance(parent -> left) >= 0){
                parent -> left = leftRotate(parent -> left);
                return rightRotate(parent);
            }

            return parent;
        }

        BinaryNode<T> *replace(BinaryNode<T> * curr){
            BinaryNode<T> *parent, *child;
            parent = curr;
            child = curr->left;
            while(child->right != nullptr){
                parent = child;
                child = child->right;
            }
            curr -> data = child -> data;
            if(parent == curr){
             parent -> left = child -> left;
            }else{
                parent -> right = child -> left;
            }
            return child;
        }

        void preorderRecursive(BinaryNode<T> *parent){
            if(parent != nullptr){
                cout<<parent -> data << " ";
                preorderRecursive(parent -> left);
                preorderRecursive(parent -> right);
            }
        }

    void inorderRecursive(BinaryNode<T> *parent, int &count) {
            if (parent != nullptr && count < 5) {
                inorderRecursive(parent->right, count);

                if (count < 5) {
                    cout << "Repeticiones: " << parent->data << " IPs: ";
                    parent->print();
                    count++;
                }

                inorderRecursive(parent->left, count);
            }
        }



        void postorderRecursive(BinaryNode<T> *parent){
            if(parent != nullptr){
                postorderRecursive(parent -> left);
                postorderRecursive(parent -> right);
                cout<<parent -> data << " ";
            }
        }
        void destroyRecursive(BinaryNode<T> *parent){
            if (parent != nullptr){
                destroyRecursive(parent->left);
                destroyRecursive(parent->right);
                cout<<"Deleting: " << parent -> data << endl;
                delete parent;
            }
        }
    public:
        AVL(){
            root = nullptr;
        }

        BinaryNode<T> *search(T value){
            BinaryNode<T> * found = searchRecursive(root,value);
            if(found == nullptr){
                cout << "The element is not found" << endl;
            }
            return found;
        }

        void insert(T value, string address){
            root = insertRecursive(root, value, address);
        }

        void remove(T value){
            root = removeRecursive(root, value);
        }
        void preorder(){
            preorderRecursive(root);
            cout<<endl;
        }
         void inorder() {
            int count = 0;
            inorderRecursive(root, count);
            cout << endl;
        }

        void postorder(){
            postorderRecursive(root);
            cout<<endl;
        }
        void destroy(){
            destroyRecursive(root);
            root = nullptr;
        }

};