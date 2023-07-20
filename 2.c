#include<stdio.h>
int binary_search(int arr[],int low,int high,int size,int key){
    if(low==high){
        if(arr[low]==key){
            return low;
        }
        else
            return -1;
    }
    else{
        int mid = (low+high)/2;
        if(arr[mid]==key)
            return mid;
        else{
            if(arr[mid]>key){
                return binary_search(arr,low,mid-1,size,key);
            }
            else{
                return binary_search(arr,mid+1,high,size,key);
            }
        }
    }
}
void printArray(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
}
int main(){
    int key;
    int arr[]={1,3,5,7,9,11,13,15,17,19,21};
    int size = sizeof(arr)/sizeof(arr[0]);
    int low = 0;int high = size; 
    printArray(arr,size);
    printf("Enter the search key\n");
    scanf("%d",&key);
    int index = binary_search(arr,low,high,size,key);
    printf("Key found at index %d",index);
}