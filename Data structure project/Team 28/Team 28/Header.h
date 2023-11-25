#pragma once
#ifndef STATICLIST
#define STATICLIST

#include <iostream>
#include<Windows.h>
#include <string> 
#include <sstream>
#include <algorithm>
#include <vector>



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
    Node();
    Node(int x, string t);
};

class to_do {

private:
    
    Node* ref = NULL;
    Node* root;
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
    string getTheRootTitle();
    int getBalanceFactor();                     
    void insert();  
    void displayTasks();                     
    void Delete();       
    int tree_height();
   
};
int calculateAsciiSum(const string& str);
void operation(to_do t); 
string edit_string(string text);
#endif 