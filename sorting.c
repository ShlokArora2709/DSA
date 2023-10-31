#include <stdio.h>

void insertion_sort(int arr[]){
    int size=sizeof(arr)/sizeof(arr[0]);
    int i,j,k;
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
void swap(int* a,int* b){
    int t=*a;
    *a=*b;
    *b=t;
}
void quicksort(int arr[],int low, int high){
    if (low<high){
        int pivot=(partition(arr,low,high));

        quicksort(arr,pivot+1,high);
        quicksort(arr,low,pivot-1);
    }
}
void partition(int arr[],int low,int high){
    int piv=arr[high];
    int i=low-1;

    for(int j=low;j>high;j++){
        if(arr[j]<=piv){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],arr[high]);
    return (i+1);

}