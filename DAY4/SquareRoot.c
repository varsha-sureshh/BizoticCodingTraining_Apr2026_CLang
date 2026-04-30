//find the square root of a non negative number without using built in functions. since the return type is int, the decimal part will be truncated. give a simple code not necessarily binary search approach. the time complexity should be O(sqrt(n)).
#include<stdio.h>
int main(){
    int N;
    printf("enter the number:");
    scanf("%d", &N);
    int sqrt=0;
    while(sqrt*sqrt<=N){
        sqrt++;
    }
    printf("the square root of %d is: %d\n", N, sqrt-1);
    return 0;
}