#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int compartor(const void *a, const void *b){
    return (*(int*)a - *(int*)b); // sort in ascending order
}
int thirdMax(int nums[], int N){
    qsort(nums, N, sizeof(int), compartor);

    int unique[N];
    int k=0;
    unique[k++] = nums[0];
    for(int i = 1; i < N; i++){
        if(nums[i] != nums[i-1]){
            unique[k++] = nums[i];
        }
    }
    if(k < 3){
        return unique[k-1];
    }
    //BINARY SEARCH
    int low=0, high=k-1;
    int target=unique[k-3];

    while(low<=high){
        int mid=(low+high)/2;
        if(unique[mid]==target){
            return unique[mid];
        }
        else if(unique[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1; // this should never happen since we know the target exists
}
int main(){
    int N;
    printf("enter the number:");
    scanf("%d", &N);
    int nums[N];
    printf("enter the array:");
    for(int i=0; i<N; i++){
        scanf("%d", &nums[i]);
    }
    qsort(nums, N, sizeof(int), compartor);
    printf("the third distinct maximum number is: %d\n", thirdMax(nums, N));
}