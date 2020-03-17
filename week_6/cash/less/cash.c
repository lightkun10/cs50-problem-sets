#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars;
    int coins;
    int owed = 0;
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;

    do
    {
        dollars = get_float("Enter change owed: ");
    } while (dollars < 0.00);

    coins = round(dollars * 100);
    
   while (coins >= quarter)
   {
       coins = coins - quarter;
       owed++;
   }

   while (coins >= dime)
   {
       coins = coins-dime;
       owed++;
   }

   while (coins >= nickel)
   {
       coins = coins-nickel;
       owed++;
   }

   while (coins >= penny)
   {
       coins = coins-penny;
       owed++;
   }

   printf("%i\n", owed);
}
