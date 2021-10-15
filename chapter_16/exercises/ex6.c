#include <stdio.h>

struct time {
    int hours, minutes, seconds;
};

struct time split_time(long total_seconds);

int main(void)
{
    long seconds;
    struct time day;

    day = split_time(seconds);

    printf("Enter time in seconds: ");
    scanf("%ld", &seconds);
    
    printf("%.2d : %.2d : %.2d\n", day.hours, day.minutes, day.seconds);

    return 0;
}

struct time split_time(long total_seconds)
{
    struct time time_split;
    
    time_split.hours = (total_seconds / 3600) % 24;
    total_seconds %= 3600;
    time_split.minutes = (total_seconds / 60) % 60;
    total_seconds %= 60;
    time_split.seconds = total_seconds;

    return time_split;
}