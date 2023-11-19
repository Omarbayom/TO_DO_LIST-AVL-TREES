#pragma once
#ifndef STATICLIST
#define STATICLIST

#include <iostream>
#include<Windows.h>
#include <string> 

using namespace std;

void callExit();
void mainscreen();
int printop();
class Node {
public:
    string title;
    int priority;
    Node* left;
    Node* right;
    int height;
    Node();
    Node(int x, string t);
};

class to_do {

private:
    Node* root;
    Node* ref = NULL;
    int tree_height(Node* r);
    int getBalanceFactor(Node* r);
    Node* rightrotation(Node* r);
    Node* leftrotation(Node* r);
    bool isfound(Node* r);
    Node* insert(Node* r, Node* n);
    void inorderTraversal(Node* n);
    Node* maxim(Node* roo);//No need 
    Node* minim(Node* roo);
    Node* Delete(Node* r, Node* ptr);
    void Traversal(Node* n, string x);


public:
    to_do(); 
    int getBalanceFactor();                     
    void insert();  
    void displayTasks();                     
    void Delete();       
    int tree_height();
   
};

void operation(to_do t);
#endif 