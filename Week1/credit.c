#include <cs50.h>
#include <stdio.h>

long checksum(long number);

int digisum(int num);

void testCard(int iter, long copy, int sum);

int main(void)
{
    long card_num;

    // prompt user for card number to be tested
    card_num = get_long("Number: ");

    // Calculate checksum, final digit 0?
    checksum(card_num);
    // Check length and starting digits to figure out if it's a valid card

    // Print AMEX, MASTERCARD, VISA or INVALID
}

long checksum(long number)
{
    // Multiply every other digit by 2, starting with second to last
    long temp = 0;
    int product = 0;
    int leftover = 0;
    int iter = 0;
    long copy = number;

    while (true)
    {
        temp = number % 10;
        number /= 10; // div *= 10

        if (iter % 2 == 0)
        {
            leftover += temp;
        }
        else
        {
            product += digisum(temp);
        }

        iter += 1;

        if (number == 0)
        {
            testCard(iter, copy, product + leftover);

            break;
        }
    }
    return product + leftover;
}

int digisum(int num)
{
    num = num * 2;

    long temp = 0;
    int sum = 0;

    for (int i = 0; i < 2; i++)
    {
        temp = num % 10;
        num /= 10;

        sum += temp;
    }
    return sum;
}

void testCard(int iter, long number, int sum)
{
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if (iter == 15)
    {
        number = number / 10000000000000;
        if (number == 34 || number == 37)
        {
            printf("AMEX\n");
        }
        else if (number != 34 || number != 37)
        {
            printf("INVALID\n");
        }
    }
    else if (iter == 13)
    {
        number = number / 1000000000000;
        if (number == 4)
        {
            printf("VISA\n");
        }
    }

    else if (iter == 16)
    {
        number = number / 100000000000000;
        if (50 < number && number < 56)
        {
            printf("MASTERCARD\n");
        }
        else if (number / 10 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
