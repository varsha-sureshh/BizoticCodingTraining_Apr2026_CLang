#include <stdio.h>
int N;
int main(){
    scanf("%d", &N);
    char name[50];
    int attended, total;
    float percentage;
    for(int i = 0; i < N; i++){
        scanf("%s %d %d", name, &attended, &total);
        percentage = (float)attended/total * 100;

        if(percentage >= 75){
            printf("%s eligible for exams\n", name);
        }   
        printf("%s has attended %.2f%% of the classes\n", name, percentage);
    }
    return 0;
}