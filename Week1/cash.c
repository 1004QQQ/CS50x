#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    int cents;
    do
    {

        // prompt user for change owed in cents
        cents = get_int("Change owed: ");
    }
    while (1 > cents);

    int quarters = 0, dimes = 0, nickels = 0, pennies = 0;
    // Calculate how many quarters you should give customer
    // Subtract the value of those quarters from cents
    quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;
    // Calculate how many dimes you should give customer
    // Subtract the value of those dimes from remaining cents
    dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;
    // Calculate how many nickels you should give customer
    // Subtract the value of those nickels from remaining cents
    nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;
    // Calculate how many pennies you should give customer
    // Subtract the value of those pennies from remaining cents
    pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;
    // Sum the number of quarters, dimes, nickels, and pennies used
    // Print that sum
    int sum = quarters + dimes + nickels + pennies;
    printf("%d\n", sum);
}

int calculate_quarters(int cents)
{
    // Calculate how many quarters you should give customer
    int quarters = cents / 25;
    return quarters;
}

int calculate_dimes(int cents)
{
    // Calculate how many quarters you should give customer
    int dimes = cents / 10;
    return dimes;
}

int calculate_nickels(int cents)
{
    // Calculate how many quarters you should give customer
    int nickels = cents / 5;
    return nickels;
}

int calculate_pennies(int cents)
{
    // Calculate how many quarters you should give customer
    int pennies = cents / 1;
    return pennies;
}
