//sliding window problem using two pointer
#include<stdio.h>
int main(){
    int N;
    printf("enter the value of N");
    scanf("%d",&N);
    int arr[N];
    for (int i=0; i<N; i++){
        scanf("%d",&arr[i]);
    }
    int maxSum=0;
    int windowSum=0;
    for(int i=0; i<N; i++){
        windowSum+=arr[i];
        if(i>=2){
            windowSum-=arr[i-2];
        }
        if(windowSum>maxSum){
            maxSum=windowSum;
        }
    
    }
    printf("Maximum sum of subarray of size 3 is: %d", maxSum);
    return 0;
    
}