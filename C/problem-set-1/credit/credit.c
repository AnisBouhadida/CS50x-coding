#include <cs50.h>
#include <stdio.h>
#include <string.h>

int longlen(long number);
int intlen(int number);
string checksum(long number, string type);

int main(void)
{
    // get card number from user
    long number = get_long("Number : ");

    // get length of card number
    int length = longlen(number);

    // copy to string for manipulation
    char buffer[16];
    sprintf(buffer, "%li", number);

    // extract first two digits for validation of card number (case AMEX & MASTERCARD)
    char startwo[3];
    strncpy(startwo, buffer, 2);

    // extract first digit for validation of card number (case VISA)
    char start[5];
    strncpy(start, buffer, 1);

    // define the card's type
    string type;

    // if card number is 15 digits and starts with 34 or 37
    // it's AMEX
    if (length == 15 && (strcmp(startwo, "34") == 0 || strcmp(startwo, "37") == 0))
    {
        type = "AMEX";
    }
    // else if card number is 16 digits and starts with 51 or 52 or 53 or 54 or 55
    // it's MASTERCARD
    else if (length == 16 && ((strcmp(startwo, "51") == 0 || strcmp(startwo, "52") == 0 || strcmp(startwo, "53") == 0 ||
                               strcmp(startwo, "54") == 0 || strcmp(startwo, "55") == 0)))
    {
        type = "MASTERCARD";
    }
    // else if card number is 13 or 16 digits and starts with 4
    // it's VISA
    else if ((length == 13 || length == 16) && strcmp(start, "4") == 0)
    {
        type = "VISA";
    }
    // else
    // it's INVALID
    else
    {
        type = "INVALID";
    }

    // if card is not INVALID
    // evaluate checksum
    if (strcmp(type, "INVALID") != 0)
    {
        type = checksum(number, type);
    }

    printf("%s\n", type);
}

int longlen(long number)
{
    int counter = 0;

    while (number > 0)
    {
        number /= 10;
        counter++;
    }

    return counter;
}

int intlen(int number)
{
    int counter = 0;

    while (number > 0)
    {
        number /= 10;
        counter++;
    }

    return counter;
}

string checksum(long number, string type)
{
    int i = 0;
    int evensum = 0;
    int oddsum = 0;
    int checksum;

    while (number > 0)
    {
        if (i % 2)
        {
            int multiply = (number % 10) * 2;

            if (intlen(multiply) == 2)
            {
                int nsum = 0;
                while (multiply)
                {
                    int n = multiply % 10;
                    multiply /= 10;
                    nsum += n;
                }
                multiply = nsum;
            }
            evensum += multiply;
        }
        else
        {
            oddsum += number % 10;
        }
        number /= 10;
        i++;
    }

    checksum = evensum + oddsum;

    if (checksum % 10 != 0)
    {
        type = "INVALID";
    }

    return type;
}
