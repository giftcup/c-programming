/* Generates the Caesar cipher for some text */

#include <stdio.h>
#include <string.h>

#define N 80

int read_line(char *message, int n);
void encrypt(char *message, int shift);
void decrypt(char *message, int shift);

int main(void)
{
    char message[N + 1], ch;
    int shift;
   
    printf("Enter message to be encrypted: ");
    read_line(message, N);
    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    encrypt(message, shift);

    printf("Encrypted message: %s\n", message);

    return 0;
}

void encrypt(char *message, int shift)
{
    for (int j = 0; j < strlen(message); j++)
    {
        if (message[j] >= 'A' && message[j] <= 'Z')
            message[j] = ((message[j] - 'A') + shift) % 26 + 'A';
        else if (message[j] >= 'a' && message[j] <= 'z')
            message[j] = ((message[j] - 'a') + shift) % 26 + 'a';
    }
}

void decrypt(char *message, int shift) {
    for (int j = 0; j < strlen(message); j++) 
    {
        if (message[j] >= 'A' && message[j] <= 'Z')
            message[j] = ((message[j] - 'A') - shift) % 26 + 'A';]
        else if (message[j] >= 'a' && message[j] <= 'z')
            message[j] = ((message[j] - 'a') - shift) % 26 + 'a';\
    }
}

int read_line(char *message, int n)
{
    int ch, i = 0;
    
    while ((ch = getchar()) != '\n' && i < N)
        message[i++] = ch;
    message[i] = '\0';

    return i;
}
