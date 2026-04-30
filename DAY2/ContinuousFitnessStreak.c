//N step counts. Find longest contiguous streak where average >= T. Print "LONGEST STREAK: D DAYS / START DAY: s / END DAY: e" or "NO STREAK". 

#include<stdio.h>
int main(){
    int N, T;
    printf("enter the elements of N and T");
    scanf("%d %d",&N, &T);
    int steps[N];
    for(int i=0; i<N; i++){
        scanf("%d",&steps[i]);
    }
    int maxLen=0;
    int windowSum=0;
    int left=0;
    for(int right=0; right<N; right++){
        windowSum+=steps[right];
        while(windowSum/(right-left+1)<T){
            windowSum-=steps[left];
            left++;
        }
        int len=right-left+1;
        if(len>maxLen){
            maxLen=len;
        }
    }
    if(maxLen>0){
        printf("LONGEST STREAK: %d DAYS / START DAY: %d / END DAY: %d\n", maxLen, left+1, left+maxLen);
    }
    else{
        printf("NO STREAK\n");
    }
    return 0;
}