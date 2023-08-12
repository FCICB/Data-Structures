#include<iostream>
#include "Queue.h"

using namespace std;

int main()
{
    int size;
    int element;
    
    cout << "Enter the size of queue: ";
    cin >> size;
    Queue<int> queue(10);
    
    cout << "Enter elements of Queue: ";
    for (size_t i = 0; i < size; i++){
        cin >> element;
        queue.enqueue(element);    
    }

    cout << endl;
    cout << "The front of queue is: ";
    cout << queue.getFront() << endl;

    cout << endl;
    cout << "The rear of queue is: ";
    cout << queue.getBack() << endl;

    cout << endl;
    cout << "Removing first element from queue" << endl;
    queue.dequeue();

    cout << endl;
    cout << "The front of queue is: ";
    cout << queue.getFront() << endl;

    cout << endl;
    cout << "Is queue Empty?    ";
    if(queue.isEmpty()){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    
    cout << endl;
    cout << "Copying Queue 1 into Queue 2: " << endl;
    Queue<int> queue2(queue);

    cout << "The elements of queue1 are: ";
    while (!queue.isEmpty())
    {
        cout << queue.getFront() << " ";
        queue.dequeue();
    }
    cout << endl;

    cout << "The elements of queue2 are: ";

    while (!queue2.isEmpty())
    {
        cout << queue2.getFront() << " ";
        queue2.dequeue();
    }

    cout << endl;

    cout << "Destroying queue1 and queue2" << endl;
    queue.initialize();
    queue2.initialize();

    return 0;
}