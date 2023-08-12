#include<iostream>
#include "Stack.h"

using namespace std;

int main()
{
    int size;
    int element;
    
    cout << "Enter the size of Stack: ";
    cin >> size;
    Stack<int> stack;
    
    cout << "Enter elements of Stack: ";
    for (size_t i = 0; i < size; i++){
        cin >> element;
        stack.push(element);    
    }

    cout << endl;
    cout << "The top of stack is: ";
    cout << stack.getTop() << endl;

    cout << endl;

    cout << endl;
    cout << "Removing top element from stack" << endl;
    stack.pop();

    cout << endl;
    cout << "The top of stack is: ";
    cout << stack.getTop() << endl;

    cout << endl;
    cout << "Is stack Empty?    ";
    if(stack.isEmpty()){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    
    cout << endl;
    cout << "Copying Stack 1 into Stack 2: " << endl;
    Stack<int> stack2(stack);

    cout << "The elements of stack1 are: ";
    while (!stack.isEmpty())
    {
        cout << stack.getTop() << " ";
        stack.pop();
    }
    cout << endl;

    cout << "The elements of stack2 are: ";

    while (!stack2.isEmpty())
    {
        cout << stack2.getTop() << " ";
        stack2.pop();
    }

    cout << endl;

    cout << "Destroying stack1 and stack2" << endl;
    stack.initialize();
    stack2.initialize();

    return 0;
}