//Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, return its 0-based index. Otherwise, return -1. The algorithm must run in O(log n) time.

#include<stdio.h>
#include<string.h>
int binarySearch(int arr[], int left, int right, int target){
    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
return -1;
}

int main(){
    int N, target;
    printf("enter the number of elements:");
    scanf("%d", &N);
    int arr[N];
    printf("enter the sorted array:");  
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }
    printf("enter the target:");
    scanf("%d", &target);   
    int result=binarySearch(arr, 0, N-1, target);
    if(result!=-1){
        printf("Target found at index: %d\n", result);
    }
    else{
        printf("Target not found in the array.\n");
    }
}