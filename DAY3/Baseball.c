#include<stdio.h>
#include<string.h>

int main(){
    int n;
    printf("enter the number:");
    scanf("%d",&n);
    char operations[n][10];
    for(int i=0;i<n;i++){
        scanf("%s",operations[i]);
    }
    int stack[n];
    int top=-1;
    for(int i=0; i<n; i++){
        if(strcmp (operations[i], "+") == 0){
            int value=stack[top]+stack[top-1];
            stack[++top]=value;
            stack[++top]=value; 
        }
        else if(strcmp (operations[i], "D") == 0){
            int value=stack[top]*2;
            stack[++top]=value;
        }
        else if(strcmp (operations[i], "C") == 0){
            top--;
        }
        else{
            stack[++top]=operations[i]-'0';
        }
    }

}