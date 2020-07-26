#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 9 //max number of candidates
int preferences [MAX_VOTERS][MAX_CANDIDATES];
typedef struct // candidates' name and votes
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

candidate candidates[MAX_CANDIDATES]; // arrays
int voter_count;
int candidate_count; // the number of candidates

//functions
bool vote(int voter, int rank, string name); // to find the ranking by the votes of each candidate
void tabulate(void); //arrange the candidates by votes 
bool print_winner(void); // find the winner 
int find_min(void);  // determine who has the least votes 
bool is_tie(int min);  // determine if there is a tie 
void eliminate(int min); // eliminate the least votes candidate 

int main(int argc, string argv[])
{
    candidate_count = argc - 1;
    if (argc < 2) //check for invaild usage
    {
        printf("Usage: ./plurality [canadidate ...]\n"); // print this line
        return 1; // return to command line 1
    }
    if (candidate_count > MAX_CANDIDATES) // if too many candidates
    {
        printf("maximum number of candidates is %i\n", MAX_CANDIDATES); // print max candidates 
        return 2; // return to arguement commandline 2 
    }
    for (int s = 0; s < candidate_count; s++) // loop for the voters
    {
        candidates[s].name = argv [s + 1]; // candidate is placed inside the array 
        candidates[s].votes = 0; // candidate's vote is set to 0 
        candidates[s].eliminated = false; // no elminatation 
    }

    voter_count = get_int("how many voters: \n"); // ask for voter input 
    if (voter_count > MAX_VOTERS) // if voter number is greater than the max number 
    {
        printf("max number of voter is %i \n", MAX_VOTERS); // print the max number
        return 3; // return to argument commandline 3 
    }

    for (int v = 0; v < voter_count; v++)
    {
        for (int rank = 0; rank < candidate_count; rank++)
        {
            string name = get_string("Rank %i: ", rank + 1);
            if (!vote(v, rank, name))
            {
                printf("invalid \n");
                return 4;
            }
        }
        printf("\n");
    }
    while (true)
    {
        tabulate();
        bool win = print_winner(); // if there is only one winner
        if (win)
        { 
            // if true
            break; // break
        }
        int min = find_min(); // find the candidate with the least votes
        bool tie = is_tie(min); //find if there is a tie (true/ false)
        if (tie) // if tie happens
        {
            for (int i = 0; i < candidate_count; i++)
            { 
                // check every candidate
                if (!candidates[i].eliminated) // if candidate is not elminiated
                {
                    printf("%s \n", candidates[i].name); // print name
                }
            }
            break;
        }
        eliminate(min);// elminate candidates
        for (int i = 0; i < candidate_count; i++) // check every candidate
        {
            candidates[i].votes = 0; // reset votes to 0 as eliminated
        }
    }
    return 0;
}


bool vote(int voter, int rank, string name) //vote total
{
    bool exist = false; // exist as false 
    for (int i = 0; i < candidate_count; i++) // check candidate
    {
        if (strcmp(candidates[i].name, name) == 0) // compare the input and the array 
        {
            preferences[voter][rank] = i; //set it as i 
            exist = true; // change exist to true 
            break;
        }
    }
    return exist; // return back to exist 
}
void tabulate(void) // arrange the candidates by their number of votes 
{
    for (int i = 0; i < voter_count; i++) // check voter
    {
        for (int j = 0; j < candidate_count; j++) // check candidate
        {
            if (candidates[preferences[i][j]].eliminated == false) // if the candidate is still qualifed, not eliminated
            {
                candidates[preferences[i][j]].votes += 1; // add one to their vote count 
                break; // break 
            }
        }
    }
    return; // return 
}

bool print_winner(void) // print winner
{
    for (int win = 0; win < candidate_count; win++) // check every candidate
    {
        string first = candidates[win].name; // first = winner's name 
        if (candidates[win].votes > voter_count / 2) // if winner's vote is the majority 
        {
            printf("%s \n", first); // print winner name 
            return true; // return to true 
        }
    }
    return false; // return to false 
}

int find_min(void) // find the least voter
{
    int leastv = voter_count; // the least vote will be the number of the voters
    for (int i = 0; i < candidate_count; i++) // check every candidate
    {
        if (candidates[i].eliminated == false 
            && candidates[i].votes < leastv) // if candidate is not elminated and its votes is less than the least vote
        {
            leastv = candidates[i].votes; // min votes will be assigned to the least voted candidate
        }
    }
    return leastv; // else return to leastv
}

bool is_tie(int leastv) // return true if there is a tie
{
    for (int i = 0; i < candidate_count; i++) // check for every candidates
    {
        if (candidates[i].eliminated == false 
            && candidates[i].votes != leastv) // if candidate is not elminateed and its vote does not equal to the least vote
        {
            return false; // return 
        }
    }
    return true; // return 
}

void eliminate(int min)  // eliminate candidates who has the least vote
{
    for (int i = 0; i < candidate_count; i++) // check every candidate
        if (candidates[i].votes == min) // if candidate's vote is the least 
        {
            candidates[i].eliminated = true; // eliminate the candidate 
        }
    return; // return 
}
