#include <stdio.h>
#include <string.h>

#define TITLE_LEN 20
#define AUTHOR_LEN 20
#define DESIGN_LEN 20

int main(void)
{
    struct catalog_item {
        int stock_number;
        double price;
        int item_type;
        union {
            struct {
                char title[TITLE_LEN+1];
                char author[AUTHOR_LEN+1];
                int num_pages;
            }book;
            struct {
                char design[DESIGN_LEN+1];
            }mug;
            struct {
                char design[DESIGN_LEN+1];
                int colors;
                int sizes;
            } shirt;
        }item;
    };

    struct catalog_item c;

    strcpy(c.item.book.title, "Little things");
    strcpy(c.item.mug.design, "Lamborghini");
    strcpy(c.item.shirt.design, "Ferrari");

    printf("%s\n", c.item.mug.design);
    printf("%s\n", c.item.shirt.design);
    printf("%s\n", c.item.book.title);

}