//Two names (fgets, may contain spaces). Case-insensitive, ignore spaces. Frequency-compare. Print ANAGRAMS or NOT ANAGRAMS.

#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    char name1[100], name2[100];
    printf("Enter the first name:");
    fgets(name1, sizeof(name1), stdin);
    printf("Enter the second name:");
    fgets(name2, sizeof(name2), stdin);

    int freq1[26] = {0}, freq2[26] = {0};

    for (int i = 0; name1[i] != '\0'; i++) {
        if (isalpha((unsigned char)name1[i])) {
            freq1[tolower((unsigned char)name1[i]) - 'a']++;
        }
    }

    for (int i = 0; name2[i] != '\0'; i++) {
        if (isalpha((unsigned char)name2[i])) {
            freq2[tolower((unsigned char)name2[i]) - 'a']++;
        }
    }

    int anagram = 1;
    for (int i = 0; i < 26; i++) {
        if (freq1[i] != freq2[i]) {
            anagram = 0;
            break;
        }
    }

    if (anagram) {
        printf("ANAGRAMS\n");
    } else {
        printf("NOT ANAGRAMS\n");
    }

    return 0;
}
