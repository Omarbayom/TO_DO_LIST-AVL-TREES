#include "Header.h"


string edit_string(string text) {

    // Try to split string normally  
    istringstream iss(text);
    string word;
    string words;

    bool extractedWord = false;

    while (iss >> word) {
        words += word + " ";
        extractedWord = true;
    }

    // If no words extracted, treat whole input as single "word"
    if (!extractedWord) {
        words = text + " ";
    }

    // Join words back together
    text = words;

    // Remove trailing space
    if (!text.empty() && text.back() == ' ') {
        text.pop_back();
    }

    return text;
}

int  calculateAsciiSum(const string& str) {
    int sum = 0;

    for (char ch : str) {
        // Add the ASCII value of each character to the sum
        sum += static_cast<int>(ch);
    }

    return sum;
}
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
    cout << "Presented To    ";
    cout << ":";
    cout << "  Prof. Ashraf Ahmed Abdel Raouf Hamdi";
    cout << "\n\n";
    cout << "\t\t\t\t\t\t";
    cout << "   Eng. Ahmad Salama Abdelaziz Salama Salama ";
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
int C = 0;
void to_do:: inorderTraversalC(Node* n) {
    if (n == nullptr)
        return;
    inorderTraversalC(n->right);
    if (n->complet) {
        cout << "Title: " << n->title << "    , Priority: " << n->priority << "    , State: ";
        if (n->complet == 0)
            cout << "Incomlete";
        else
            cout << "Complete";
        cout << endl;
        C++;
    }
    inorderTraversalC(n->left);
}
int N = 0;
void to_do:: inorderTraversalN(Node* n) {
    if (n == nullptr)
        return;
    inorderTraversalN(n->right);
    if (!(n->complet)) {
        cout << "Title: " << n->title << "    , Priority: " << n->priority << "    , State: ";
        if (n->complet == 0)
            cout << "Incomlete";
        else
            cout << "Complete";
        cout << endl;
        N++;
    }
    inorderTraversalN(n->left);
}
void to_do:: displayTasksC() {
    inorderTraversalC(root);
    if (C == 0) {
        cout << "Your list is empty" << endl;
        C = 0;
    }
}
void to_do:: displayTasksN() {
    inorderTraversalN(root);
    if (N == 0) {
        cout << "Your list is empty" << endl;
        N = 0;
    }
}

int printop() {
    string num;
    cout << "=====================================================" << endl;
    cout << "0- Exit" << endl;
    cout << "1- Display your to-do list" << endl;
    cout << "2- Add new list item" << endl;
    cout << "3- Delete one item " << endl;
    cout << "4- See the height of the tree " << endl;
    cout << "5- get the balance factor " << endl;
    cout << "6- 2D print" << endl;
    cout << "7- Update" << endl;
    cout << ">>";
    getline(cin, num);
    num = edit_string(num);
    int y = calculateAsciiSum(num);
    int x = y - '0';
    cout << endl;
    cout << "=====================================================" << endl;
    return x;
}

Node::Node() {
    right = NULL;
    left = NULL;
    complet = false;
}

Node::Node(int x, string t) {
    title = t;
    priority = x;
    Node();
}

to_do::to_do() {
    root = NULL;
}



int to_do::getBalanceFactor() {
    return getBalanceFactor(root);
}

int to_do:: getBalanceFactor(Node* r) {
    if (r == NULL) {
        return -1;
    }
    else {
        return (tree_height(r->left) - tree_height(r->right));
    }
}

Node* to_do::rightrotation(Node* r) {
    Node* x = r->left;
    Node* y = x->right;
    x->right = r;
    r->left = y;
    return x;
}

Node* to_do::leftrotation(Node* r) {
    Node* x = r->right;
    Node* y = x->left;
    x->left = r;
    r->right = y;
    return x;
}

Node* to_do::insert(Node* r, Node* n) {

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
    if (bf > 1 && n->priority < r->left->priority)//R
        return rightrotation(r);
    if (bf > 1 && n->priority > r->left->priority) {//lR
        r->left = leftrotation(r->left);
        return rightrotation(r);
    }
    if (bf < -1 && n->priority >= r->right->priority)//l
        return leftrotation(r);
    if (bf < -1 && n->priority < r->right->priority) {//Rl
        r->right = rightrotation(r->right);
        return leftrotation(r);
    }
    return r;
}

bool to_do::isfound(Node* r) {
    if (r == nullptr)
        return false;
    if (ref == r) {
        return true;
    }
    if (isfound(r->right)) {
        return true;
    }
    else if (isfound(r->left)) {
        return true;
    }
    else { return false; }
}

void to_do::insert() {
    int x;
    string t,num;
    cout << "please enter your priorty" << endl;
    getline(cin, num);
    num = edit_string(num);
    int z = calculateAsciiSum(num);
    x = z - '0';
    int y = 0;
    do {
        if (x > 0 && x <= 5) {
            y++;
        }
        else {
            cout << "priority should be between 1 and 5 renter it please" << endl;
            getline(cin, num);
            num = edit_string(num);
            int z = calculateAsciiSum(num);
            x = z - '0';
        }
    } while (y == 0);
    cout << "Please enter your text: " << endl;
    getline(cin, t);
    t = edit_string(t);
    Traversal(root, t);
    if (ref != NULL) {
        cout << "item exist" << endl;
        ref = NULL;
        return;
    }
    Node* n = new Node(x, t);
    root = insert(root, n);
    ref = NULL;
    return;
}

void to_do::inorderTraversal(Node* n) {   //Right - Node - Left
    if (n == nullptr)
        return;
    inorderTraversal(n->right);
    cout << "Title: " << n->title << "    , Priority: " << n->priority<< "    , State: " ;
    if (n->complet == 0)
        cout<<"Incomlete";
    else
       cout<< "Complete";
    cout << endl;
    inorderTraversal(n->left);
}

void to_do::displayTasks() {
    string num;
    if (root == NULL) {
        cout << "your to do list is empty" << endl;
        return;
    }
    cout << "1. All your to_do list     ";
    cout << "2. All your completed to_do list     ";
    cout << "3. All your incomplete to_do list     "<<endl;
    getline(cin, num);
    num = edit_string(num);
    int y = calculateAsciiSum(num);
    int x = y - '0';
    switch (x) {
    case(1):
          inorderTraversal(root);
          break;
    case(2):
        displayTasksC();
        break;
    case(3):
        displayTasksN();
        break;
    }

    
}

Node* to_do::maxim(Node* roo) {
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

Node* to_do::minim(Node* roo) {
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

Node* to_do::Delete(Node* r, Node* ptr)
{
    Traversal(r, ptr->title);
    if (r == NULL || ptr == NULL)
        return r;
    if (isfound(r->left)) {
        r->left = Delete(r->left, ptr);
    }
    else if (isfound(r->right)) {
        r->right = Delete(r->right, ptr);
    }
    else {
        if (r->left == NULL && r->right == NULL) {
            delete r;
            r = NULL;
        }
        else if (r->left != NULL && r->right == NULL){
            Node* le = r->left;
            r->title = r->left->title;
            r->priority = r->left->priority;
            r->left = Delete(r->left, le);
        }
        else if (r->left == NULL && r->right != NULL){
            Node* ri = r->right;
            r->title = r->right->title;
            r->priority = r->right->priority;
            r->right = Delete(r->right, ri);
        }
        else {
            Node* woh = minim(r->right);
            r->title = woh->title;
            r->priority = woh->priority;
            r->right = Delete(r->right, woh);
        }
    }
    int bf = getBalanceFactor(r);
    if (bf == 2 && getBalanceFactor(r->left) >= 0)//R
        return rightrotation(r);
    else if (bf == 2 && getBalanceFactor(r->left) == -1) {//LR
        r->left = leftrotation(r->left);
        return rightrotation(r);
    }
    else  if (bf == -2 && getBalanceFactor(r->right) <= 0)//L
        return leftrotation(r);
    else if (bf == -2 && getBalanceFactor(r->right) == 1) {//RL
        r->right = rightrotation(r->right);
        return leftrotation(r);
    }
    return r;
}

void to_do::Traversal(Node* n, string x) {
    if (n == nullptr)
        return;
    if (n->title == x) {
        ref = n;
    }
    Traversal(n->right, x);
    Traversal(n->left, x);
}

void to_do:: printVertical(Node* root, int level) {
    if (root == nullptr) {
        for (int i = 0; i < level; i++) {
            cout << "   ";
        }
        cout << "(NULL)"<<endl;
        return;
    }
    printVertical(root->right, level + 1);
    for (int i = 0; i < level; i++) {
        cout << "   ";
    }
    cout << "(" << root->priority << ", " << root->title << ")\n";
    printVertical(root->left, level + 1);
}

void to_do:: printVerticalTree() {
    printVertical(root, 0);
}
void to_do:: updatedata() {
    string x,num,change;
    int c;
    inorderTraversal(root);
    
    if (root != NULL) {
       cout << "Please enter the title of the task that you want to edit " << endl;
        getline(cin, x);
        x = edit_string(x);
        Traversal(root, x);
        if (ref == NULL) {
           cout << "Item doesn't exist" << endl;
           return;
        }
        else {
            cout << "1.For Tiltle     2.For status" << endl;
            getline(cin, num);
            num = edit_string(num);
            int z = calculateAsciiSum(num);
            c = z - '0';
            int y = 0;
            do {
                if (c > 0 && c <= 2) {
                    y++;
                }
                else {
                    cout << "please enter only 1 or 2 " << endl;
                    getline(cin, num);
                    num = edit_string(num);
                    int z = calculateAsciiSum(num);
                    c = z - '0';
                }
            } while (y == 0); 
            ref = NULL;
            switch (c) {
            case(1):
                cout << "Please enter new title " << endl;
                getline(cin, change);
                change = edit_string(change);
                Traversal(root, change);
                if (ref == NULL) {
                    Traversal(root, x);
                    ref->title = change;
                }
                else {
                    cout << "Item exist" << endl;
                }
                break;
            case(2):
                cout << "The status has been changed " << endl;
                Traversal(root, x);
                ref->complet = !(ref->complet);
            }
                    

              ref = NULL;
           
        }
    }
}
    

void to_do:: Delete() {
    string x,y;
    cout << "1.for certen task      2.All tasks" << endl;
    getline(cin, y);
    y = edit_string(y);
    int z = calculateAsciiSum(y);
    int c = z - '0';
    switch (c) {
    case(1):
        displayTasks();
        if (root != NULL) {
            cout << "please entre the deletion" << endl;
            getline(cin, x);
            x = edit_string(x);
            Traversal(root, x);
            if (ref != NULL) {
                root = Delete(root, ref);
                ref = NULL;
            }
            else {
                cout << "Item doesn't exist" << endl;
            }
        }
        break;
    case(2):
        clearTree(root);
        root = NULL;
        break;
    }
    return;
}

string to_do::getTheRootTitle() {
    if (root != NULL) {
        return root->title;
    }
    else {
        return "Your To_DO List Is Empty";
    }
}
int to_do::tree_height(Node* r) {
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
int to_do::tree_height() {

    return tree_height(root);

}


void operation(to_do t) {

   while(true){
        int num;
        num = printop();
        switch (num)
        {
        case(0):

            callExit();
            t.saveToFile("todolist.txt");
            exit(1);
            break;
        case(1):
            t.displayTasks();
            system("pause");
            system("cls");
            break;
        case(2):
            t.insert();
            system("pause");
            system("cls");
            t.saveToFile("todolist.txt");
            break;
        case(3):
            t.Delete();
            system("pause");
            system("cls");
            t.saveToFile("todolist.txt");
            break;
        case(4):
            cout << "the height of the tree is : " << t.tree_height() << endl;
            cout << "the root of the tree is : " << t.getTheRootTitle() << endl;
            system("pause");
            system("cls");
            break;
        case(5):
            cout << "the balcance factor of the tree is : " << t.getBalanceFactor() << endl;
            cout << "the root of the tree is : " << t.getTheRootTitle() << endl;
            system("pause");
            system("cls");
            break;
        case(6):
            t.printVerticalTree();
            system("pause");
            system("cls");
            break;
        case(7):
            t.updatedata();
            system("pause");
            system("cls");
            t.saveToFile("todolist.txt");
            break;
        default:
            cout << "please enter valid number" << endl;
            system("pause");
            system("cls");
            break;
        }
    } 
    return;
}

void to_do::saveToFile(const string& filename) {
    ofstream outFile(filename);

    if (!outFile.is_open()) {
        cout << "Error: Unable to open the file for saving." << endl;
        return;
    }

    saveToFileHelper(root, outFile);

    outFile.close();
    
}
void to_do::clearTree(Node* node) {
    if (node == nullptr) {
        return;
    }

    clearTree(node->left);
    clearTree(node->right);

    delete node;
}

to_do::~to_do() {
    clearTree(root);
}

void to_do::saveToFileHelper(Node* node, ofstream& outFile) {
    if (node == nullptr) {
        outFile << 0 <<endl;
        return;
    }

    outFile << node->priority << " " << node->complet << " " << node->title << endl;

    saveToFileHelper(node->left, outFile);
    saveToFileHelper(node->right, outFile);
}
void to_do::readFromFile(const string& filename) {
    ifstream inFile(filename);

    if (!inFile.is_open()) {
        cout << "Error: Unable to open the file for reading." << endl;
        return;
    }

    clearTree(root);
    root = nullptr; // Initialize root to null

 
    root = readFromFile1(inFile, root);

    inFile.close();
}

Node* to_do::readFromFile1(ifstream& inFile, Node* node) {
    // Base case: end of file or marker
    if (inFile.eof() ) {
        return node;
    }

    // Read data line by line
    string data;
    getline(inFile, data);

    // Extract node data
    stringstream ss(data);
    int priority;
    bool completed;
    string title;
    ss >> priority >> completed >> ws;
    if (priority == 0) {
        return NULL;
    }
    getline(ss, title);

    // Create new node and set data
    Node* newNode = new Node(priority, title);
    newNode->complet = completed;

    // Recursively build left and right subtrees
    newNode->left = readFromFile1(inFile, newNode->left);
    newNode->right = readFromFile1(inFile, newNode->right);

    return newNode;
}



