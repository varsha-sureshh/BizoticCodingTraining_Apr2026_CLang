//A bus has S numbered seats (1 to S). A sorted list of B BOOKED seat numbers is given (in ascending order). Find the FIRST (smallest) seat number that is not booked, using binary search. Print "FIRST AVAILABLE: X". If all S seats are booked, print "FULL".

#include<stdio.h>
int main(){
    int S, B;
    printf("enter S and B:");
    scanf("%d %d", &S, &B);
    int booked[B];
    printf("enter the booked seat numbers:");
    for(int i=0; i<B; i++){
        scanf("%d", &booked[i]);
    }
    if(B==0){
        printf("FIRST AVAILABLE: 1\n");
        return 0;
    }
    if(booked[0]!=1){
        printf("FIRST AVAILABLE: 1\n");
        return 0;
    }
    int low=0, high=B-1, mid;
    while(low<=high){
        int mid=(low+high)/2;
        if(booked[mid]==mid+1){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    if(low==B){
        if(B==S){
            printf("FULL\n");
        }
        else{
            printf("FIRST AVAILABLE: %d\n", B+1);
        }
    }
    else{
        printf("FIRST AVAILABLE: %d\n", low+1);
    }
    return 0;
}