/*A payroll system generates monthly salary slips. For each of N employees, you are given:
• name (single word, no spaces, up to 31 characters)
• basic (basic salary in rupees per month, positive floating-point or integer)
Compute using these rules (all percentages on BASIC unless specified):
1. HRA = 20% of basic.
2. DA = 10% of basic.
3. GROSS = basic + HRA + DA.
4. PF deduction = 12% of basic.
5. Annual gross = GROSS * 12.
6. Annual tax (slab-based, applied on ANNUAL gross):
• Up to Rs 5,00,000: no tax.
• Rs 5,00,001 to Rs 10,00,000: 10% on the portion above 5L.
• Above Rs 10,00,000: flat Rs 50,000 on the 5L-10L slab + 20% on the portion above 10L.
1. Monthly tax = annual_tax / 12.
2. NET = GROSS - PF - monthly_tax.
For each employee, print on a single line: NAME BASIC HRA DA GROSS PF TAX NET (all amounts
with 2 decimals, space-separated).
After all employees, print: TOTAL PAYROLL NET: <sum> (2 decimals)*/
#include<stdio.h>
#include<string.h>
typedef struct{
    char name[32];
    float basic;
    float hra;
    float da;
    float gross;
    float pf;
    float tax;
    float net;
}Employee;
int main(){
    int N;
    printf("enter the number of employees:");
    scanf("%d", &N);
    Employee employees[N];
    float total_net=0;
    for(int i=0; i<N; i++){
        printf("enter name and basic salary:");
        scanf("%s %f", employees[i].name, &employees[i].basic);
        employees[i].hra=0.20*employees[i].basic;
        employees[i].da=0.10*employees[i].basic;
        employees[i].gross=employees[i].basic+employees[i].hra+employees[i].da;
        employees[i].pf=0.12*employees[i].basic;
        float annual_gross=employees[i].gross*12;
        if(annual_gross<=500000){
            employees[i].tax=0;
        }
        else if(annual_gross<=1000000){
            employees[i].tax=0.10*(annual_gross-500000);
        }
        else{
            employees[i].tax=50000+0.20*(annual_gross-1000000);
        }
        employees[i].net=employees[i].gross-employees[i].pf-employees[i].tax/12;
        total_net+=employees[i].net;
    }
    printf("TOTAL PAYROLL NET: %.2f\n", total_net);
    return 0;
}