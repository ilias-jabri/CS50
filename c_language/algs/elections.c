#include <stdio.h>
#include <string.h>

typedef struct {
    char* name;
    int votes;
} Candidate;

int main(int argc, char* argv[])
{
    Candidate candidates[argc - 1];
    for(int i = 0; i < argc-1; i++)
    {
        Candidate currCandidate = {name: argv[i+1], votes: 0};
        candidates[i] = currCandidate;
    }
    
    int voters = 0;
    printf("number of voters: ");
    scanf("%i", &voters);
    
    while(voters > 0)
    {
        char* selectedCandidate;

        printf("voting for: ");
        scanf("%s", selectedCandidate);
        
        for(int i = 1; i < argc; i++)
        {
            if(strcmp(selectedCandidate, candidates[i].name) == 0)
            {
                candidates[i].votes++;
            }
        }
        voters--;    
    }
    
    int maxVotesIdx = 0;
    for(int i = 0; i < argc-1; i++)
    {
        if(candidates[i].votes > candidates[maxVotesIdx].votes)
        {
            maxVotesIdx = i;
        }
    }
    printf("the elected winner with most votes is : %s\n", candidates[maxVotesIdx].name);
    printf("he has collected %i votes\n", candidates[maxVotesIdx].votes);
    
    return 0;
}