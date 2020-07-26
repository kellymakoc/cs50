#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strlen(text)
#include <math.h> // for rounding and calculaitons for the level of grade in the text

int main(int argc, char *argv[ ]) // the number of commandline arguement, arguemtn vector
{
    if (argc != 2 || atoi(argv [1]) < 0) // if command line is not equal to 2 or less than 0
    {
        printf("Usage: ./caesar k"); // print this line
        return 1; // return to command line 1
    }
    else
    {
        string text = get_string("plain text: \n"); // if not, ask for text
        printf("ciphertext: ");
        int k = atoi(argv [1]); // convert string to integer
        for (int i = 0; i < strlen(text); i++) // for every letter in the text
        {
            if (text[i] >= 'A' && text[i] <= 'Z') //configure if it is Uppercase
            {
                text[i] = (((text[i] + k) - 'A') % 26) + 'A'; // do this calculation
                printf("%c", text[i]);
            } //65 -- A
            else if (text[i] >= 'a' && text[i] <= 'z') // configure if it is lowercase
            {
                text[i] = (((text[i] + k) - 'a') % 26) + 'a'; //do this calculation
                printf("%c", text[i]);
            } //97 -- a
            else // if the letter does not fit in either the if statements like punctuations
            {
                printf("%c", text[i]);  // print the same thing
            }
        }
        printf("\n");
        return 0; // return back to command line 0
    }
}