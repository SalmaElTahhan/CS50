#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++) //pass through all candidates
    {
        if (strcmp(candidates[i].name, name) == 0) //compare candidate names with name voted for and if they are equal
        {
            candidates[i].votes++; //increment number of votes for this candidate by one
            return true; //and return true
        }
    }
    return false; //otherwise if name entered is not in candidate names return false
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int max_vote = 0; //variable that stores maximum number of votes
    for (int i = 0; i < candidate_count; i++) //pass through all candidates
    {
        if (candidates[i].votes > max_vote) //if votes for a candidate are more than the value of max_vote
        {
            max_vote = candidates[i].votes; //increment max_vote by one
        }
    }
    for (int i = 0; i < candidate_count; i++) //pass through all candidates
    {
        if (candidates[i].votes == max_vote) //if any candidate has the same number of votes as max_vote
        {
            printf("%s\n", candidates[i].name); //print their name
        }
    }
    return;
}

