//A phone directory has N entries, each with a name and phone number, sorted by name in ascending order. Given Q query names, for each query print:"FOUND: <name> <phone>" if the name exists"NOT FOUND: <query>" if it does not.Each query must use O(log N) time (binary search, not linear scan)

#include<stdio.h>
#include<string.h>
typedef struct{
    char name[100];
    char phone[20];
}Entry;

int main(){
    int N, Q;
    printf("Enter the number of entries:");
    scanf("%d", &N);
    Entry directory[N];
    for(int i=0; i<N; i++){
        printf("Enter name and phone number:");
        scanf("%s %s", directory[i].name, directory[i].phone);
    }
    printf("enter the number of queries:");
    scanf("%d", &Q);
    char query[100];
    for(int i=0; i<Q; i++){
        printf("enter the query name:");
        scanf("%s", query);
        int left=0, right=N-1, found=0;
        while(left<=right){
            int mid=(left+right)/2;
            int cmp=strcmp(query, directory[mid].name);
            if(cmp==0){
                printf("FOUND: %s %s\n", directory[mid].name, directory[mid].phone);
                found=1;
                break;
            }
            else if(cmp<0){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        if(!found){
            printf("NOT FOUND: %s\n", query);
        }
    }
    return 0;
}