
#include "Header.h"
#include <iostream>

using namespace std;

int main()
{
    to_do t;
    mainscreen();
    t.readFromFile("todolist.txt");
    operation(t);
    return 0;
}

