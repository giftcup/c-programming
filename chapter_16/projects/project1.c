#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_COUNTRY 10

struct country
{
    char *name;
    int code;
};

int main(void)
{
    int i, code;
    struct country country_codes[NUM_COUNTRY] = {
        {"Cameroon", 237},
        {"Nigeria", 234},
        {"South Africa", 27},
        {"South Sudan", 211},
        {"Tunisia", 216},
        {"The Gambia", 220},
        {"Mali", 223},
        {"Niger", 227},
        {"Ghana", 233},
        {"Chad", 235}
    };

    printf("Enter dialing code: ");
    scanf("%d", &code);

    for (i = 0; i < NUM_COUNTRY; i++)
    {
        if (country_codes[i].code == code)
        {
            printf("Country code corresponds to %s\n", country_codes[i].name);
            break;
        }
    }

    if (i == NUM_COUNTRY)
        printf("Country not found\n");
    return 0;
    
}