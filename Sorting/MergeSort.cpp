void mergeList(int list[], int first, int mid, int last){
    int sizeL = mid - first + 1;
    int sizeR = last - mid;

    int left[sizeL];
    int right[sizeR];

    for(int i = 0;i <= sizeL;i++){
        left[i] = list[first + i]; 
    }

    for(int i = 0;i <= sizeR;i++){
        right[i] = list[mid + i + 1]; 
    }


    int i = 0, j = 0;
    int k = first;

    while(i < sizeL && j < sizeR){
        if(left[i] <= right[j]){
            list[k] = left[i];
            i++;
        }
        else{
            list[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < sizeL){
        list[k] = left[i];
        k++;
        i++;
    }

    while(j < sizeR){
        list[k] = right[j];
        k++;
        j++;
    }
}

void mergeSort(int list[], int first, int last){
    if(first < last){
       int mid = (first + last) / 2; 
       mergeSort(list, first, mid);
       mergeSort(list, mid + 1, last);
       mergeList(list, first, mid, last);
    }
}