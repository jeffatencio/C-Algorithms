#include <stdio.h>
#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insertNode(Node* root, int data){
    if(root == nullptr){ //Tree is empty
        return createNode(data);
    }

    if(data < root->data){
        root->left= insertNode(root->left, data);
    }

    else if(data > root->data){
        root->right = insertNode(root->right, data);
    }

    return root;
}

//Traversal of BST

void inorderTraversal(Node* root){
    if(root != nullptr){
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

//Given a key search for value in BST

Node* searchNode(Node* root, int key){

    if(root == nullptr || root->data == key){
        return root;
    }

    if(root-> data < key){
        return searchNode(root->right, key);
    }

    return searchNode(root->left, key);

}

Node* minValueNode(Node* node){
    Node* current = node;
    while(current && current-> left != nullptr){
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int data){

    if(root == nullptr){
        return root;
    }

    if(data < root ->data){
        root->left = deleteNode(root->left,data);
    }

    else if(data > root->data){
        root->right = deleteNode(root->right, data);
    }

    else{
        if(root->left == nullptr){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr){
            Node* temp = root->left;
            delete root;
            return temp;
        }



    Node * temp = minValueNode(root->right);

    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
    }

    return root;
}


int main(){
    Node* root = nullptr;

    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    cout << "Traversal of BST in order is: ";
    inorderTraversal(root);
    cout << endl;

    root = deleteNode(root, 20);
    cout << "After the deletion of 20: ";
    inorderTraversal(root);
    cout << endl;

    root = insertNode(root, 25);
    cout << "After insertion of 25: ";
    inorderTraversal(root);
    cout<< endl;

    Node * found = searchNode(root, 25);

    if(found != nullptr){
        cout <<"Node 25 found!" << endl;
    }
    else{
        cout <<"Node 25 not found :(" << endl;
    }

    return 0;

}