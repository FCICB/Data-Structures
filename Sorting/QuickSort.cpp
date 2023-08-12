#pragma Once
void swap(int *first, int *second){
    int temp = *first;
    *first = *second;
    *second = temp;
}

int partition(int list[], int first, int last){
    
    int pivot = (first + last) / 2;
    swap(&list[first], &list[pivot]);

    pivot = first;
    int lastIndex = first;

    for(int i = first + 1; i <= last;i++){
        if(list[i] < list[pivot]){
            lastIndex++;
            swap(&list[i], &list[lastIndex]);
        }
    }

    swap(&list[pivot], &list[lastIndex]);
    
    return lastIndex;
}



void quickSort(int list[], int first, int last){
    if(first < last){
        int pivot = partition(list, first, last);
        quickSort(list, first, pivot - 1);
        quickSort(list, pivot + 1, last);
    }
}