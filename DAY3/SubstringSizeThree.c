//Given a string s consisting of lowercase English letters, return the number of substrings of length 3 that contain three distinct characters. using sliding window approach.
#include <stdio.h>
#include <string.h>

int findUniqueSubstringOfSizeThree(char s[]){
    int n = strlen(s);
    int count = 0;

    if(n<3){
        return 0;
    }
    for(int i=0; i<=n; i++){
        char a = s[i];
        char b = s[i+1];
        char c = s[i+2];
        if(a!=b && b!=c && a!=c){
            count++;
        }
    }
    return count;
}
int main(){
    char s[100];
    printf("Enter the string:");
    scanf("%s", s);
    int result = findUniqueSubstringOfSizeThree(s);
    printf("Number of substrings of length 3 with distinct characters: %d\n", result);
    return 0;
}