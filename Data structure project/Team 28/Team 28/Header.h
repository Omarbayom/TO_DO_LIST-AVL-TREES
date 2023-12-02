#pragma once
#ifndef STATICLIST
#define STATICLIST

#include <iostream>
#include<Windows.h>
#include <string> 
#include <sstream>
#include <algorithm>
#include <fstream>


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
    bool complet;
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
    void inorderTraversalC(Node* n);
    void inorderTraversalN(Node* n);
    Node* maxim(Node* roo);//No need 
    Node* minim(Node* roo);
    Node* Delete(Node* r, Node* ptr);
    void Traversal(Node* n, string x);
    void printVertical(Node* root, int level);
    void clearTree(Node* node);
    void saveToFileHelper(Node* node, ofstream& outFile);
    Node* insertf(Node* r, Node* n);
    Node* readFromFile1(ifstream& filename,  Node* node);
    


public:
    to_do(); 
    ~to_do();
    string getTheRootTitle();
    int getBalanceFactor();                     
    void insert();  
    void displayTasks();  
    void displayTasksC();
    void displayTasksN();
    void Delete();       
    int tree_height();
    void printVerticalTree();
    void updatedata();
    void readFromFile(const string& filename);
    void saveToFile(const string& filename);

};
int calculateAsciiSum(const string& str);
void operation(to_do t); 
string edit_string(string text);
#endif 