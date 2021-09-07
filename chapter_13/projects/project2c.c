/* Prints a one month reminder list */

#include <stdio.h>
#include <string.h>

#define MAX_REMIND 60   // maximum number of reminders
#define MSG_LEN 60     // max length of reminder message

int read_line(char str[], int n);

int main(void)
{
    char reminders[MAX_REMIND][MSG_LEN + 3];
    char day_str[15], msg_str[MSG_LEN + 1];
    int day, i, j, num_remind = 0;
    int hour, min, month;

    for(;;)
    {
        if (num_remind == MAX_REMIND)
        {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter month and day (month/day) 24-hour time (hour:min) and reminder: ");
        scanf("%2d/%2d", &month, &day);
        scanf("%2d:%2d", &hour, &min); // max two numbers
        if (month == 0 || day == 0)
            break;
        // task (a)
        if (day < 0 || day > 31)
        {
            printf("Valid days are only from 0 - 31\n");
            continue;
        }
        sprintf(day_str, "%.2d\t%.2d\t%.2d:%.2d\t", month, day, hour, min); // writes the day read into the string `day_str`
        read_line(msg_str, MSG_LEN);

        for (i = 0; i < num_remind; i++)
            if (strcmp(day_str, reminders[i]) < 0)
                break;
        for (j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j - 1]);

        strcpy(reminders[i], day_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }

    printf("\nMonth\tDay\tTime\tReminder\n");
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