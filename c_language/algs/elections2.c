#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char* name;
    int votes;
    int rankingScore;
} Candidate;

int main(int argc, char* argv[])
{
    int num_of_candidates = argc - 1;
    Candidate candidates[num_of_candidates];
    for(int i = 0; i < argc-1; i++)
    {
        Candidate currCandidate = {name: argv[i+1], votes: 0, rankingScore: 0};
        candidates[i] = currCandidate;
    }
    
    int voters = 0;
    printf("number of voters: ");
    scanf("%i", &voters);
    
    while(voters > 0)
    {


        char selectedCandidates[3][60];

        for(int i = 0; i < 3; i++) {
            printf("rank %i: ", i + 1);
            scanf("%69s", selectedCandidates[i]); // Limit input to avoid overflow
        }
        
        printf("==========\n");
        
        for(int i = 0; i < num_of_candidates; i++)
        {
            for(int j = 0; j<3; j++){
                if(strcmp(selectedCandidates[j], candidates[i].name) == 0)
                {
                    switch (j)
                    {
                    case 0:
                        candidates[i].rankingScore += 3;
                        candidates[i].votes++; break;
                    case 1:
                        candidates[i].rankingScore += 2; break;
                    case 2:
                        candidates[i].rankingScore += 1; break;
                    }
                }
            }
        }
        voters--;  
    }
    
    int maxVotes = 0;
    for(int i = 0; i < argc-1; i++)
    {
        if(candidates[i].votes > maxVotes)
        {
            maxVotes = candidates[i].votes;
        }
    }

    Candidate winner = candidates[0];
    for (int i = 0; i < num_of_candidates; i++)
    {
        if(candidates[i].votes == maxVotes && candidates[i].rankingScore > winner.rankingScore){
            winner = candidates[i];
        }
    }


    printf("the elected winner with most votes is : %s\n", winner.name);
    printf("he has collected %i votes (with %i rankingScore)\n", winner.votes, winner.rankingScore);
    
    FILE* f = fopen("electionsRes.txt", "w");
        if(f == NULL){
            perror("something went wrong with opening the file");
            return 123;
        }
        char strVot[200];
        sprintf(strVot, "the elected winner with most votes is : %s\nhe has collected %i votes (with %i rankingScore)\n", winner.name, winner.votes, winner.rankingScore);
        fputs(strVot, f);
    fclose(f);
    
    return 0;
}