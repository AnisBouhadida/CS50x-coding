#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int change;
    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 0);

    int counter = 0;

    while (change - 25 >= 0)
    {
        change -= 25;
        counter++;
    }
    while (change - 10 >= 0)
    {
        change -= 10;
        counter++;
    }
    while (change - 5 >= 0)
    {
        change -= 5;
        counter++;
    }
    while (change - 1 >= 0)
    {
        change -= 1;
        counter++;
    }
    printf("%i\n", counter);
}
