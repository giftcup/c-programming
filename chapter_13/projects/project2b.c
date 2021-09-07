/* Prints a one month reminder list */

#include <stdio.h>
#include <string.h>

#define MAX_REMIND 60   // maximum number of reminders
#define MSG_LEN 60     // max length of reminder message

int read_line(char str[], int n);

int main(void)
{
    char reminders[MAX_REMIND][MSG_LEN + 3];
    char time_str[10], msg_str[MSG_LEN + 1];
    int day, i, j, num_remind = 0;
    int hour, min;

    for(;;)
    {
        if (num_remind == MAX_REMIND)
        {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter day 24-hour time and reminder: ");
        scanf("%2d", &day);
        scanf("%2d:%2d", &hour, &min); // max two numbers
        if (day == 0)
            break;
        // task (a)
        if (day < 0 || day > 31)
        {
            printf("Valid days are only from 0 - 31\n");
            continue;
        }
        sprintf(time_str, "%2d %.2d:%.2d",day, hour, min);
        read_line(msg_str, MSG_LEN);

        for (i = 0; i < num_remind; i++)
            if (strcmp(time_str, reminders[i]) < 0)
                break;
        for (j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j - 1]);

        strcpy(reminders[i], time_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }



    printf("\nDay Time Reminder\n");
    for (i = 0; i < num_remind; i++)
        printf(" %s\n", reminders[i]);

return 0;           
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}