#include <iostream>
#include "QuickSort.cpp"
#include "HeapSort.cpp"
#include "MergeSort.cpp"
using namespace std;

void print(int list[], int size){
    for(int i = 0;i < size;i++){
        cout << list[i] << " ";
    }
}

void shellSort(int list[], int size){
    int interval;
    int counter;
    for(interval = size / 2;interval >= 1;interval /= 2){
        for(int i = interval;i < size;i++){
            int index = i;
            for(int j = i - interval;j >= 0;j -= interval){
                if(list[index] < list[j]){
                    int temp = list[index];
                    list[index] = list[j];
                    list[j] = temp;
                    index -= interval;
                }
            } 
        }
    }
}

void selectionSort(int list[], int size){
    for(int i = 0;i < size;i++){
        int min = INT32_MAX;
        int pos = -1;
        for(int j = i;j < size;j++){
            if(min > list[j]){
                min = list[j];
                pos = j;
            }
        }
        int temp = list[i];
        list[i] = list[pos];
        list[pos] = temp;
    }

   // print(list, size);
}


void insertionSort(int list[], int size){
    for(int i = 1;i < size;i++){
        int index = i;
        for(int j = i - 1;j >= 0;j--, index--){
            if(list[index] < list[j]){
                int temp = list[index];
                list[index] = list[j];
                list[j] = temp;
            }
        }
    }

    print(list, size);
}


int main(){
    int list[6] = {6,5,4,3,2,1};
    
    selectionSort(list, 6);
    print(list, 6);
    cout << endl;
    
    insertionSort(list, 6);
    print(list, 6);
    cout << endl;
    
    quickSort(list, 0, 5);
    print(list, 6);
    cout << endl;
    
    mergeSort(list, 0, 5);
    print(list, 6);
    cout << endl;
    
    heapSort(list, 6);
    print(list, 6);
    cout << endl;
    
    shellSort(list, 6);  
    print(list, 6);
    cout << endl;
    
    return 0;
}