#include <cs50.h>
#include <stdio.h>

int get_num(void); // get input function 
int main(void) //main function
{
    int height = get_num(); // get input from get_num function 
    for (int i = 1; i < height + 1; i++) // for loop 
    {
        for (int s = 0; s < height - 1 - i + 1; s++)// for loop 
        {
            printf(" "); //print space 
        }
        for (int n = 0; n < i; n++)// for loop 
        {
            printf("#"); // print hash
        }
        printf("\n"); // go to the new line 
    }
}
int get_num(void) //getting an integer from this function 
{
    int num;//garbage value 
    do
    {
        num = get_int("Height: ");//get input for num 
    }
    while (num < 1 || num > 8);//while num is less than 1 or greater than 8
    return num; // return to num for input 
}
    
