#include <iostream>
#include "Hashing.h"
using namespace std;

int main(){
    Hashing<int> list(6);
    list.insert(1,25);
    list.insert(2,20);
    list.insert(3,15);
    list.insert(4,10);
    list.insert(5,5);
    list.insert(7,50);

    cout << "The list contains: ";
    list.print();
    cout << "\n\n";

    bool found = list.search(2,20);

    if(found){
        cout << "Element 20 is in the list" << endl;
    }
    else{
        cout << "Element 20 isn't in the list" << endl;
    }
    cout << endl;

    list.remove(2,20);
    list.remove(3,15);
    list.remove(8,70);

    cout << "The list after removal contains: ";
    list.print();
    cout << endl;
    return 0;
}