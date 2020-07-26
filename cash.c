#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_num(void);
int main(void)
{
    //assign variable for the number of coins 
    
    int value = get_num(); //get input for value 
    printf("%i\n", value);
// for loops to determine how many of each cent needed for the value input 
    int count = 0;
    for (int q = 1; value >= 25; q++) 
    {
        value -= 25; // keep subtracting until value is less than 0.25
        count++; //+1 to count everytime when subtracted 
    }
    for (int d = 1; value >= 10; d++)
    {
        value -= 10;
        count++;
    }
    for (int n = 1; value >= 5; n++)
    {
        value -= 5;
        count++;
    }
    for (int p = 1; value >= 1; p++)
    {
        value -= 1;
        count++;
    }
    printf("%i coins\n", count); //print count for user 
}

int get_num(void)
{
    float num;
    do
    {
        num = round((get_float("Change owed: \n")) * 100);
    }
    while (num < 0);
    return num;
}
