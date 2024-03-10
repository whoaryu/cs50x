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
    bool candidateFound = false;
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            candidateFound = true;
        }
    }
    if (!candidateFound)
    {
        return false;
    }
    return true;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    candidate winners[MAX];
    bool tie = false;
    int winners_count = 1;
    for (int i = 0; i < candidate_count; i++)
    {
        if (i == 0)
        {
            winners[0] = candidates[i];
        }
        else if (candidates[i].votes > winners[0].votes)
        {
            if (!tie)
            {
                winners[0] = candidates[i];
            }
            else
            {
                for (int j = 0; j < winners_count; j++)
                {
                    winners[j] = winners[winners_count];
                }
                winners[0] = candidates[i];
                tie = false;
                winners_count = 1;
            }
        }
        else if (candidates[i].votes == winners[0].votes)
        {
            winners[winners_count] = candidates[i];
            tie = true;
            winners_count++;
        }
    }
    for (int i = 0; i < winners_count; i++)
    {
        printf("%s\n", winners[i].name);
    }
    return;
}