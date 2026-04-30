//len<6 -- weak; len>=12 and all 4 classes VERY STRONG; len>=8 with digit+upper STRONG else MEDIUM. Special = !@#$%^&*()-+; print "WEAK", "MEDIUM", "STRONG", "VERY STRONG"

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    printf("Enter the password:");
    scanf("%99s", password);

    int len = strlen(password);
    int lowerCase = 0, upperCase = 0;
    int isDigit = 0, isSpecial = 0;

    for (int i = 0; password[i] != '\0'; i++) {
        if (isupper((unsigned char)password[i])) {
            upperCase = 1;
        } else if (islower((unsigned char)password[i])) {
            lowerCase = 1;
        } else if (isdigit((unsigned char)password[i])) {
            isDigit = 1;
        } else if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*' || password[i] == '(' || password[i] == ')' || password[i] == '-' || password[i] == '+') {
            isSpecial = 1;
        }
    }

    if (len < 8) {
        printf("WEAK PASSWORD");
    } else if (lowerCase && upperCase && isDigit && isSpecial && len >= 12) {
        printf("VERY STRONG PASSWORD");
    } else if (isDigit && upperCase && len >= 8) {
        printf("STRONG PASSWORD");
    } else {
        printf("MEDIUM PASSWORD");
    }

    return 0;
}

