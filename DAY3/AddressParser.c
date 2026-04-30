//N addresses formatted Name,DoorNo,Street,City,PIN. Validate in order: Name (letters+spaces), DoorNo (starts with digit), Street (non-empty), City (letters+spaces), PIN (exactly 6 digits). Report first failure or VALID. Summary at end.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char num1[1000], num2[1000];
    char result[2001];
    printf("enter the numbers");
    int i=strlen(num1)-1;
    int j=strlen(num2)-1;
    int k=0, carry=0;
    while(i>=0||j>=0||carry>0){
        int d1=(i>=0)? num1[i]-'0': 0;
        int d2=(j>=0)? num2[j]-'0': 0;
        int sum=d1+d2+carry;
        result[k++]=(sum%10)+'0';
        carry=sum/10;
        i--;
        j--;
    }
    result[k]='\0';
    for(int p=k-1; p>=0; p--){
        printf("%c", result[p]);
    }
    return 0;
}
