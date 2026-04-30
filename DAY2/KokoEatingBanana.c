//coco eating banana using binary search
#include <stdio.h>


int minEatingValue(int bunches[], int N, int H){
    int left = 1;
    int right = 0;
    for(int i=0; i<N; i++){
        if(bunches[i]>right){
            right=bunches[i]; //max=11
        }
    }
    int answer=right; //answer=11
    while(left<=right){
        int mid = left+(right-left)/2; //mid=6 
        int totalHours=0;
        for(int i=0; i<N; i++){
            totalHours+=(bunches[i]+mid-1)/mid; //totalHours=3+1+2+2=8
        }
        if(totalHours<=H){
            answer=mid; //answer=6
            right=mid-1; //right=5
        }
        else{
            left=mid+1; //left=7
        }
    }
    return answer;
}
int main(){
    int bunches[]={3,6,7,11};
    int H=8;
    int N=sizeof(bunches)/sizeof(bunches[0]);
}
