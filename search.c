#include <stdio.h>

void main(){
    int k,a;
    int ar[5] = {21, 43, 18, 87, 23};
    printf("enter element to search");
    scanf("%d",&k);
    int a=linear_search(arr,k);
    if(a==0){
        printf("element not found");
    }
    else{
        printf("element found at position %d",a);
    }
} 

int linear_search(int arr[],int key){
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i;i<size;i++){
        if(arr[i]==key){
            return i+1;
        }
    }
    return 0;
}

int binary_search(int arr[],int key){
    int size=sizeof(arr)/sizeof(arr[0]);
    int front=0,end=size-1;
    do{
        int mid=(front+end)/2;
        if(arr[mid]==key){
            return mid+1;
        }
        if(arr[mid]>key){
            end=mid-1;
        }
        if(arr[mid]<key){
            front=mid+1;
        }
    }while (front <= end);
    return 0;

}