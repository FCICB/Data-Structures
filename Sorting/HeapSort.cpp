#pragma Once
void swap(int *first, int *second){
    int temp = *first;
    *first = *second;
    *second = temp;
}

void Hepify(int list[], int size, int root){

    int maxIndex  = 2 * root + 1;
    int i = root;

    while(maxIndex < size){
        if(i * 2 + 2 < size){
            if(list[maxIndex] < list[2 * i + 2]){
                maxIndex = 2 * i + 2;
            } 
        }

        if(list[i] >= list[maxIndex]){
            break;
        }
        else{
            swap(&list[i], &list[maxIndex]);
            i = maxIndex;
            maxIndex = i * 2 + 1;
        }
    }
}

void buildHeap(int list[], int size){
    for(int i = (size / 2) - 1;i >= 0;i--){
        Hepify(list, size, i);
    }
}

void heapSort(int list [], int size){
    buildHeap(list, size);
    for(int i = size - 1; i >= 0; i--){
        swap(&list[0], &list[i]);
        Hepify(list, i, 0);
    }
}