#include <cs50.h>
#include <stdio.h>
#include <string.h> // for the length of the string 
#include <ctype.h> // for the conditons to determine the words 
#include <math.h> // for rounding and calculaitons for the level of grade in the text 

int main(void)
{
    string text = get_string("enter text: \n");//enter text by user
    float letter = 0, word = 1, sen = 0; // count for letter,word and sentence
    for (int i = 0; i < strlen(text); i++) // the length of the text 
    { 
        // if statements for counting the variables 
        if ((text[i] == ' ' || text[i] == '"' || text[i] == ':') && (isalpha(text[i + 1]))) 
        {
            word++; // +1 to word 
        }
        else  if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sen++; // +1 to sentence
        }
        else if ((text[i] <= 'z' && text[i] >= 'a') || (text[i] <= 'Z' && text[i] >= 'A'))
        {
            letter++; // +1 to letter 
        }
    } 
    //calculations 
    float L = (letter / word) * 100;
    float S = (sen / word) * 100;
    float index = (0.0588 * L) - (0.296 * S) - 15.8; //Coleman-Liau index
    // printf("%.2f letter,%.2f words, %.2f sentences, %.2f index",letter, word, sen, index); 
    //printf("%i\n", (int)round(index));
    // different conditions for determining the grade level of the text 
    if (index >= 16) // if index is greater or equal to 16 
    {
        printf("Grade 16+\n"); // print grade 16+
    }
    else if (index < 1) //if index is smaller than 1
    {
        printf("Before Grade 1\n"); // print before grade 1 
    }
    else if (index <= 15 && index > 0) // if index is greater than 0 and smaller or equal to 15
    {
        printf("Grade %i\n", (int) round(index));// cast float to int for a whole number 
        // print the grade level 
    }
}


