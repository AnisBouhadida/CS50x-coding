#include <cs50.h>
#include <stdio.h>

void print_pyramide(int gap, int height);

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
        print_pyramide(height - i, i);
        print_pyramide(3, i);
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

void print_pyramide(int gap, int length)
{
    print_space(gap);
    print_row(length);
}
