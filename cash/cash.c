#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    int cents = get_cents();

    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    int coins = quarters + dimes + nickels + pennies;
    printf("%i\n", coins);
}

int get_cents(void)
{
    int c;
    do
    {
        c=get_int("Change owed: ");
        printf("\n");
    }
    while(c<0);
    return c;
}

int calculate_quarters(int cents)
{
    int f=cents/25;
    return f;
}

int calculate_dimes(int cents)
{
    int f=cents/10;
    return f;
}

int calculate_nickels(int cents)
{
    int f=cents/5;
    return f;
}

int calculate_pennies(int cents)
{
    int f=cents/1;
    return f;
}
