/*
A video streaming platform records user engagement score per minute over N minutes. Given the
engagement scores and a window size K (in minutes), find the K-minute window with the
HIGHEST AVERAGE engagement and report:
• The average (rounded to 2 decimals).
• The start minute (1-indexed) of that window.
• The end minute (1-indexed).
If multiple windows tie for the highest average, report the EARLIEST start.
Constraints:
• 1 <= K <= N <= 100,000
• Engagement scores fit in int (can be negative).
• Algorithm must run in O(N) time.
If N <= 0 or K <= 0 or K > N, print INVALID WINDOW and stop.
*/

#include<stdio.h>
int main(){
    int N, K;
    printf("enter the number of minutes:");
    scanf("%d", &N);
    printf("enter the window size:");
    scanf("%d", &K);
    if(N<=0 || K<=0 || K>N){
        printf("INVALID WINDOW\n");
        return 0;
    }
    int arr[N];
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }
    int sum=0;
    for(int i=0; i<K; i++){
        sum+=arr[i];
    }
    int maxSum=sum;
    int start=0;
    for(int i=K; i<N; i++){
        sum=sum-arr[i-K]+arr[i];
        if(sum>maxSum){
            maxSum=sum;
            start=i-K+1;
        }
    }
    printf("Highest Average: %.2f\n", (float)maxSum/K);
    printf("Start Minute: %d\n", start+1);
    printf("End Minute: %d\n", start+K);
    return 0;
}