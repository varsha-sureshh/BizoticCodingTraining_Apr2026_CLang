//problem- a person has to climb a mountain of N steps. He can climb either 1 step or 2 steps at a time. Find the number of ways in which he can climb the mountain.
//we can solve this using recusrsion or fibonacci series

#include<stdio.h>

int fibonacci(int n){
    if(n==0||n==1)
        return 1;
    if(n==2)
        return 2;
    return fibonacci(n-1)+fibonacci(n-2);
}

int main(){
    int n;
    printf("enter the number of steps:");
    scanf("%d", &n);
    printf("the number of ways to climb the mountain is: %d\n", fibonacci(n));
    return 0;
}