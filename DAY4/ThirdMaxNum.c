//Given an integer array nums, return the third DISTINCT maximum number in this array. If the third distinct maximum does not exist, return the maximum number.
//this uses brute force approach by sorting the array in descending order and then counting distinct numbers until we find the third one. The time complexity is O(N log N) due to sorting, and the space complexity is O(1) if we ignore the input array.
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
\
int compartor(const void *a, const void *b){
    return (*(int*)b - *(int*)a);
}
int thirdMax(int nums[], int N){
    qsort(nums, N, sizeof(int), compartor);
    int count=1;
    for(int i=1; i<N; i++){
        if(nums[i]!=nums[i-1]){
            count++;
        }
        if(count==3){
            return nums[i];
        }
    }
    return nums[0];
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
    printf("the third distinct maximum number is: %d\n", thirdMax(nums, N));
}