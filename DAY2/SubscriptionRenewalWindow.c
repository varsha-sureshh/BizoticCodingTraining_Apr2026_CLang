#include<stdio.h>
int longestWindow(int days[], int n, int K){
    int right=0;
    int left=0;
    int maxLen=0;
    for(right=0; right<n; right++){
        while (days[right]-days[left]>K){
            left++;
        }
        int len = right-left+1;
        if(len>maxLen){
            maxLen=len;
        }
    }
    return maxLen;
} 
int main(){
    int N, K;
    printf("Enter the number of days and K:");
    scanf("%d %d",&N, &K);
    int days[N];
    for(int i=0; i<N; i++){
        scanf("%d",&days[i]);
    }
    int result = longestWindow(days, N, K);
    printf("The longest window of subscription renewal is: %d\n", result);
    return 0;
}