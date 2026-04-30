/*A college engineering department is generating the semester-end attendance summary. For each
student, you are given:
• name (a single word, no spaces, up to 31 characters)
• classes_attended (non-negative integer)
• total_classes (positive integer)
Compute each student's attendance percentage and classify:
• ELIGIBLE if percentage >= 75.00
• NOT-ELIGIBLE if percentage < 75.00
For each student, print on a single line: NAME PERCENTAGE STATUS with percentage rounded to 2
decimals.
After all students, print the summary (exact format): TOTAL STUDENTS: <n> ELIGIBLE: <e>
NOT-ELIGIBLE: <ne> HIGHEST ATTENDANCE: <name> <pct> LOWEST ATTENDANCE: <name>
<pct>
If multiple students tie for highest or lowest, report the EARLIEST (smallest index) in the input.
If N = 0, print NO STUDENTS and stop.*/


#include<stdio.h>
#include<string.h>
typedef struct{
    char name[32];
    int classes_attended;
    int total_classes;
    float percentage;
}Student;
int main(){
    int N;
    printf("enter the number of students:");
    scanf("%d", &N);
    if(N==0){
        printf("NO STUDENTS\n");
        return 0;
    }
    Student students[N];
    for(int i=0; i<N; i++){
        printf("enter name, classes attended and total classes:");
        scanf("%s %d %d", students[i].name, &students[i].classes_attended, &students[i].total_classes);
        students[i].percentage=(float)students[i].classes_attended/students[i].total_classes*100;
    }
    int eligible=0, not_eligible=0;
    char highest_name[32];
    float highest_percentage=-1;
    char lowest_name[32];
    float lowest_percentage=101;
    for(int i=0; i<N; i++){
        if(students[i].percentage>=75.00){
            printf("%s %.2f ELIGIBLE\n", students[i].name, students[i].percentage);
            eligible++;
        }
        else{
            printf("%s %.2f NOT-ELIGIBLE\n", students[i].name, students[i].percentage);
            not_eligible++;
        }
        if(students[i].percentage>highest_percentage){
            highest_percentage=students[i].percentage;
            strcpy(highest_name, students[i].name);
        }
        if(students[i].percentage<lowest_percentage){
            lowest_percentage=students[i].percentage;
            strcpy(lowest_name, students[i].name);
        }
    }
    printf("TOTAL STUDENTS: %d ELIGIBLE: %d NOT-ELIGIBLE: %d HIGHEST ATTENDANCE: %s %.2f LOWEST ATTENDANCE: %s %.2f\n", N, eligible, not_eligible, highest_name, highest_percentage, lowest_name, lowest_percentage);
}