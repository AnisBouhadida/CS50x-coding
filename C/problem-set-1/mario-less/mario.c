#include <cs50.h>
#include <stdio.h>

void print_space(int space);
void print_row(int length);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height : ");
    }
    while (height <= 0);

    for (int i = 0; i < height; i++)
    {
        print_space(height - i);
        print_row(i);
        printf("\n");
    }
}

void print_space(int space)
{
    for (int i = space - 1; i > 0; i--)
    {
        printf(" ");
    }
}

void print_row(int length)
{
    for (int j = 0; j <= length; j++)
    {
        printf("#");
    }
}
