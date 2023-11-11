#include <iostream>
#include<Windows.h>
#include <string> 
/* you need to make 2 more functions eidt priority and title 
you will do that by deleting the old node first the creat a new one
*/


using namespace std;
void callExit()
{
    system("cls");
    cout << "\n\n\n\n\n";
    cout << "\n\tTaking You Out of The System";
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t";
    cout << "You are out of the System.\n";
    cout << "\t\t\t\t\t\t";
    cout << "Thank You !";
    cout << "\n\n";
    cout << "\t\t\t\t\t";
    system("pause");
}


void mainscreen() {
    system("cls");
    cout << "\n";
    cout << "\t\t\t\t    **********************************\n";
    cout << "\t\t\t\t              |TO-DO LIST |\n";
    cout << "\t\t\t\t    **********************************\n";
    cout << "\n\n";
    cout << "\t\t\t\t";
    cout << "Prepared By    ";
    cout << ":";
    cout << "   Omar Ahmed Gomaa Bayomi (22P0109)";
    cout << "\n\n";
    cout << "\t\t\t\t\t\t";
    cout << "   Alaa Yasser Fathy Bekhit (21P0408)";
    cout << "\n\n";
    cout << "\t\t\t\t\t\t";
    cout << "   Adham Osama Mohamed (22P0071)";
    cout << "\n\n";
    cout << "\t\t\t\t\t\t";
    cout << "   Mohamed Ahmed Abdelroauf (2001038)";
    cout << "\n\n";
    cout << "\t\t\t\t";
    cout << "Mini Project   ";
    cout << ":";
    cout << "   TO-DO LIST";
    cout << "\n\n";
    cout << "\t\t\t\t";
    cout << "\n\n";
    cout << "\n\n";
    cout << "\t\t\t\t";


    system("color 0A");
    char a = 177, b = 219;
    cout << "loading....";
    for (int i = 0; i <= 25; i++) {
        cout << a;
        Sleep(150);
    }
    cout << "\r" << "\t\t\t\t\t" << "   ";
    for (int i = 0; i <= 25; i++) {
        cout << b;
        Sleep(200);
    }
    cout << "\n\n\n" << "\t\t\t\t" << "  ";
    system("pause");
    system("cls");
}

int printop() {
    int num;
    cout << "=====================================================" << endl;
    cout << "0- Exit" << endl;
    cout << "1- Display your to-do list" << endl;
    cout << "2- Add new list item" << endl;
    cout << "3- Delete one item " << endl;
    cout << "4- See the height of the tree " << endl;
    cout << "5- get the balance factor " << endl;
    cin >> num;
    cout << endl;
    cout << "=====================================================" << endl;
    return num;
}
class Node {
public:
    string title;
    int priority;
    Node* left;
    Node* right;
    int height;
    Node() {
        right = NULL;
        left = NULL;
        height = 1;
    }
    Node(int x, string t) {
        title = t;
        priority = x;
        Node();
    }
};
class to_do {
public:
    Node* root;
    Node* ref =NULL;
    to_do() {
        root = NULL;
    }
    int tree_height(Node* r) {

        if (r == NULL) {
            return -1;
        }
        else {
            int lheight = tree_height(r->left);
            int rheight = tree_height(r->right);
            if (lheight > rheight)
                return lheight + 1;
            else
                return rheight + 1;
        }
    }
    int getBalanceFactor(Node* r) {
        if (r == NULL) {
            return -1;
        }
        else {
            return (tree_height(r->left) - tree_height(r->right));
        }
    }
    Node* rightrotation(Node* r) {
        Node* x = r->left;
        Node* y = x->right;
        x->right = r;
        r->left = y;
        return x;
    }
    Node* leftrotation(Node* r) {
        Node* x = r->right;
        Node* y = x->left;
        x->left = r;
        r->right = y;
        return x;
    }
    Node* insert(Node* r, Node* n) {

        if (r == NULL) {
            r = n;
            return r;
        }
        if (n->priority < r->priority) {
            r->left = insert(r->left, n);

        }
        else {
            r->right = insert(r->right, n);
        }
        int bf = getBalanceFactor(r);
        if (bf > 1 && n->priority < r->left->priority)
            return rightrotation(r);
        if (bf < -1 && n->priority >= r->right->priority)
            return leftrotation(r);
        if (bf > 1 && n->priority > r->left->priority) {
            r->left = leftrotation(r->left);
            return rightrotation(r);
        }
        if (bf < -1 && n->priority < r->right->priority) {
            r->right = rightrotation(r->right);
            return leftrotation(r);
        }
        return r;
    }
    void insert() {
        int x;
        string t;
        cout << "please enter your priorty" << endl;
        cin >> x;
        int y = 0;
        do {
            if (x > 0 && x <= 5) {
                y++;
            }
            else {
                cout << "priority should be between 1 and 5 renter it please" << endl;
                cin >> x;
            }
        } while (y == 0); 
        cout << "Please enter your text: "<<endl;
            
            cin.ignore();
            getline(cin, t);
            Traversal(root, t);
            if (ref != NULL) {
                cout << "item exist" << endl;
                return;
            }
        Node* n = new Node(x, t);
        root = insert(root, n);
        ref = NULL;
        return;
    }
    void inorderTraversal(Node* n) {
        if (n == nullptr)
            return;
        inorderTraversal(n->right);
        cout << "Title: " << n->title << "    , Priority: " << n->priority << endl;
        inorderTraversal(n->left);
    }
    void displayTasks() {
        if (root == NULL) {
            cout << "your to do list is empty" << endl;
            return;
        }
        inorderTraversal(root);
    }
    Node* maxim(Node* roo) {
        if (roo == NULL) {
            return NULL;
        }
        else if (roo->right == NULL) {
            return roo;
        }
        else {
            return maxim(roo->right);
        }
    }
    Node* minim(Node* roo) {
        if (roo == NULL) {
            return NULL;
        }
        else if (roo->left == NULL) {
            return roo;
        }
        else {
            return minim(roo->left);
        }
    }
    Node* Delete(Node* r, Node* ptr)
    {
        if (r == NULL||ptr==NULL) 
            return r;
        if (ptr->priority<r->priority&&ptr->title!=r->title) 
            r->left = Delete(r->left, ptr);
        else if (ptr->priority >= r->priority && ptr->title != r->title) 
            r->right = Delete(r->right, ptr);
        else
        {
            if (r->left == NULL && r->right == NULL) { 
                delete r;
                r = NULL;
            }
            else if (r->left != NULL && r->right == NULL) 
            {
                Node* le = r->left;
                r->title = r->left->title;
                r->priority = r->left->priority;
                r->left = Delete(r->left, le);
            }
            else if (r->left == NULL && r->right != NULL) 
            {
                Node* ri = r->right;
                r->title = r->right->title;
                r->priority = r->right->priority;
                r->right = Delete(r->right,ri);
            }
            else
            {
              
                Node* woh = minim(r->right);
                r->title = woh->title;
                r->right = Delete(r->right, woh);

            }

        }
        int bf = getBalanceFactor(r);
        if (bf == 2 && getBalanceFactor(r->left) >= 0)
            return rightrotation(r);
        else if (bf == 2 && getBalanceFactor(r->left) == -1) {
            r->left = leftrotation(r->left);
            return rightrotation(r);
        }
        else  if (bf == -2 && getBalanceFactor(r->right) <= 0)
            return leftrotation(r);
        else if (bf == -2 && getBalanceFactor(r->right) == 1) {
            r->right = rightrotation(r->right);
            return leftrotation(r);
        }
        return r;
    }

    void Traversal(Node* n,string x) {
        if (n == nullptr)
            return;
        if (n->title == x) {
            ref=n;
        }
        Traversal(n->right,x);
        Traversal(n->left,x);
    }
    void Delete() {
        string x;
        displayTasks();
        cout << "please entre the deletion" << endl;
        cin.ignore();
        getline(cin, x);
        Traversal(root,x);
        root = Delete(root, ref);
        ref = NULL;
        return;
    }
    int tree_height() {

        if (root == NULL) {
            return -1;
        }
        else {
            int lheight = tree_height(root->left);
            int rheight = tree_height(root->right);
            if (lheight > rheight) {
                return lheight + 1;
            }
            else {
                return rheight + 1;
            }
        }
    }

};

void operation(to_do t);

int main()
{
    to_do t;
    mainscreen();
    operation(t);


    return 0;
}
int e = 0;

void operation(to_do t) {

    do {
        int num;
        num = printop();
        switch (num)
        {
        case(0):

            callExit();
            exit(1);
            break;
        case(1):
            t.displayTasks();
            system("pause");
            system("cls");
            operation(t);
            break;
        case(2):
            t.insert();
            system("pause");
            system("cls");
            operation(t);
            break;
        case(3):
            t.Delete();
            system("pause");
            system("cls");
            operation(t);
            break;
        case(4):
            cout << "the height of the tree is : " << t.tree_height() << endl;
            system("pause");
            system("cls");
            operation(t);
            break;
        case(5):
            cout << "the balcance factor of the tree is : " << t.getBalanceFactor(t.root) << endl;
            system("pause");
            system("cls");
            operation(t);
            break;
        default:
            cout << "please enter valid number" << endl;
            system("pause");
            system("cls");
            operation(t);
            break;
        }
    } while (e == 0);

    return;
}