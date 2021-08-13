/* Description: Program displays the departure and arrival time for a flight whose departure is closest to that entered by the user.
** Source: C Programming A Modern Approach
*/

#include <stdio.h>

void find_closest_flight(int desired_time, int * departure_time, int *arrival_time);

int main(void)
{
    int hour, min, desired_time;
    int departure_time, arrival_time;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &min);

    // Convert the time inputed to minutes
    desired_time = (hour * 60) + min;

    find_closest_flight(desired_time, &departure_time, &arrival_time);
    
    printf("Closest departure time is %.2d:%.2d, arriving at %.2d:%.2d\n", departure_time /60, departure_time % 60, arrival_time / 60, arrival_time % 60);
    
    return 0;
}

void find_closest_flight(int desired_time, int * departure_time, int *arrival_time)
{
    if (desired_time < 533)
    {
        *departure_time = 480;
        *arrival_time = 616;
    }
    else if (desired_time < 632)
    {
        *departure_time = 583;
        *arrival_time = 712;
    }
    else if (desired_time < 724)
    {
        *departure_time = 679;
        *arrival_time = 811;
    }
    else if (desired_time < 805)
    {
        *departure_time = 767;
        *arrival_time = 900;
    }
    else if (desired_time < 894)
    {
        *departure_time = 14 * 60;
        *arrival_time = 16 * 60 + 8;
    }
    else if (desired_time < 1044)
    {
        *departure_time = 15 * 60 + 45;
        *arrival_time = 17 * 60 + 55;
    }
    else if (desired_time < 1224)
    {
        *departure_time = 19 * 60;
        *arrival_time = 21 * 60 +20;
    }
    else
    {
        *departure_time = 21 * 60 + 45;
        *arrival_time = 23 * 60 + 58;
    }
}