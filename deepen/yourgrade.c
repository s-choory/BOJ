#include <stdio.h>

int main(void)
{

    char grade[100], arr[50];
    double k[20], gradevalue, mul=0, allgrade=0;

    for(int i=0; i<20; i++)
    {
        double flag = 1;
        scanf("%s %lf %s", arr, &k[i], grade);
        if(grade[0] == 'A')
            {
                if(grade[1] == '+')
                    gradevalue = 4.5;       
                else if(grade[1] == '0')
                    gradevalue = 4.0; 
            }
        else if(grade[0] == 'B')
            {
                if(grade[1] == '+')
                    gradevalue = 3.5;       
                else if(grade[1] == '0')
                    gradevalue = 3.0; 
            }
        else if(grade[0] == 'C')
            {
                if(grade[1] == '+')
                    gradevalue = 2.5;       
                else if(grade[1] == '0')
                    gradevalue = 2.0; 
            }
        else if(grade[0] == 'D')
            {
                if(grade[1] == '+')
                    gradevalue = 1.5;       
                else if(grade[1] == '0')
                    gradevalue = 1.0; 
            }
        else if(grade[0] == 'F')
            gradevalue = 0.0;
        else if(grade[0] == 'P')
            flag = 0;
        mul += gradevalue * k[i] * flag;
        allgrade += k[i] * flag;
    } 
    printf("%lf", mul / allgrade);
    return 0;
}