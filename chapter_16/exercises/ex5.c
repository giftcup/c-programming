#include <stdio.h>

typedef struct {
    int day, month, year;
}Date;

int day_of_year(Date date);
int compare_dates(Date date1, Date date2);
void print_compare(int comp);

int main(void)
{
    Date jan = {16, 01, 1996};
    Date may = {26, 05, 2004};
    Date jan2 = {7, 01, 2001};
    
    int comp = compare_dates(jan, jan2);
    print_compare(comp);
    comp = compare_dates(may, jan);
    print_compare(comp);

    return 0;
}

int day_of_year(Date d)
{
    return (d.day + (d.month * 30));
}

int compare_dates(Date d1, Date d2)
{
    if (day_of_year(d1) < day_of_year(d2) || d1.year < d2.year)
        return -1;
    else if (day_of_year(d1) > day_of_year(d2) || d1.year > d2.year)
        return 1;
    else
        return 0; 
}

void print_compare(int comp)
{
    if (comp == -1)
        printf("The first date is earlier\n");
    else if (comp == 1)
        printf("The second day is earlier\n");
    else
        printf("The dates are the same\n");
}