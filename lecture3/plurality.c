#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define max 9 //max number of candidates

typedef struct // candidates' name and votes
{
    string name;
    int votes;
}
candidate;

candidate candidates[max]; // arrays

int candidate_count; // the number of candidates
//functions
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    candidate_count = argc - 1;
    if (argc < 2) //check for invaild usage
    {
        printf("Usage: ./plurality [canadidate ...]\n"); // print this line
        return 1; // return to command line 1
    }
    if (candidate_count > max)
    {
        printf("maximum number of candidates is %i\n", max);
        return 2;
    }
    for (int s = 0; s < candidate_count; s++) // loop for the voters
    {
        candidates[s].name = argv [s + 1];
        candidates[s].votes = 0;
    }
    int voter = get_int("how many voters: \n");
    for (int v = 0; v < voter; v++)
    {
        string name = get_string("enter vote: \n");
        if (!vote(name)) // check for invalid vote
        {
            printf("invalid \n");
        }
    }
    print_winner(); // print winner
}
bool vote(string name) //vote total
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

void print_winner(void) // print winner
{
    int mostvote = 0; // most vote
    int wcount = 1; // number of winners
    int winners [] = {}; // arrays for the winners
    int winner_n; //the winner
    for (int n = 0; n < candidate_count; n++) // loop for the candidates
    {
        if (candidates[n].votes >= mostvote) // if the candidate get the msot vote
        {
            mostvote = candidates[n].votes;
            winner_n = n;
        }
    }
    winners[0] = winner_n; // fill in array
    for (int i = 0; i < candidate_count; i++)
    {
        if ((i != winner_n) && (candidates[i].votes == mostvote))
        {
            winners[wcount] = i; // fill in arrays
            wcount++; // numbers of winners
        }
    }
    if (wcount == 1) // if only one winner
    {
        printf("%s \n", candidates[winners[0]].name);
    }
    else
    {
        for (int w = 0; w < wcount; w++)
        {
            printf("%s \n", candidates[winners[w]].name);
            if (w < (wcount - 1))
            {
                printf(",");
            }
        }
    }
    // printf("%i name1\n", candidates[1].votes);
    // printf("%i name2\n", candidates[2].votes);
    // printf("%i name3\n", candidates[3].votes);
    return;
}

