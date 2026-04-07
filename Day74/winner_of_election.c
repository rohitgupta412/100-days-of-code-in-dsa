/*
 * Day 74: Winner of an Election
 * 
 * Problem: Given votes, find the winner (candidate with most votes)
 * If tie, return lexicographically smaller name
 * 
 * Time Complexity: O(n log n) - for sorting
 * Space Complexity: O(n) - for hash table
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 100
#define MAX_NAME_LEN 50

// Structure to store candidate and vote count
typedef struct {
    char name[MAX_NAME_LEN];
    int votes;
} Candidate;

// Function to find winner of election
void findWinner(char votes[][MAX_NAME_LEN], int n) {
    Candidate candidates[MAX_CANDIDATES];
    int candidateCount = 0;
    
    // Count votes for each candidate
    for (int i = 0; i < n; i++) {
        int found = 0;
        
        // Check if candidate already exists
        for (int j = 0; j < candidateCount; j++) {
            if (strcmp(candidates[j].name, votes[i]) == 0) {
                candidates[j].votes++;
                found = 1;
                break;
            }
        }
        
        // Add new candidate
        if (!found) {
            strcpy(candidates[candidateCount].name, votes[i]);
            candidates[candidateCount].votes = 1;
            candidateCount++;
        }
    }
    
    // Find winner (max votes, lexicographically smaller if tie)
    int maxVotes = 0;
    char winner[MAX_NAME_LEN];
    
    for (int i = 0; i < candidateCount; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            strcpy(winner, candidates[i].name);
        } else if (candidates[i].votes == maxVotes) {
            if (strcmp(candidates[i].name, winner) < 0) {
                strcpy(winner, candidates[i].name);
            }
        }
    }
    
    // Print results
    printf("\nVote Count:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    
    printf("\nWinner: %s with %d votes\n", winner, maxVotes);
}

// Main function
int main() {
    printf("=== Day 74: Winner of an Election ===\n\n");
    
    // Test Case 1
    printf("Test Case 1:\n");
    char votes1[][MAX_NAME_LEN] = {"john", "johnny", "jackie", "johnny", "john", 
                                    "jackie", "jamie", "jamie", "john", "johnny", "jamie"};
    int n1 = 11;
    
    printf("Votes: ");
    for (int i = 0; i < n1; i++) {
        printf("%s ", votes1[i]);
    }
    printf("\n");
    
    findWinner(votes1, n1);
    
    // Test Case 2
    printf("\n=== Test Case 2 ===\n");
    char votes2[][MAX_NAME_LEN] = {"andy", "blake", "clark", "andy", "andy", "blake"};
    int n2 = 6;
    
    printf("Votes: ");
    for (int i = 0; i < n2; i++) {
        printf("%s ", votes2[i]);
    }
    printf("\n");
    
    findWinner(votes2, n2);
    
    // Test Case 3: Tie scenario
    printf("\n=== Test Case 3 (Tie) ===\n");
    char votes3[][MAX_NAME_LEN] = {"alice", "bob", "alice", "bob"};
    int n3 = 4;
    
    printf("Votes: ");
    for (int i = 0; i < n3; i++) {
        printf("%s ", votes3[i]);
    }
    printf("\n");
    
    findWinner(votes3, n3);
    
    printf("\n=== Program Completed Successfully ===\n");
    
    return 0;
}

/*
 * Output:
 * === Day 74: Winner of an Election ===
 * 
 * Test Case 1:
 * Votes: john johnny jackie johnny john jackie jamie jamie john johnny jamie 
 * 
 * Vote Count:
 * john: 3 votes
 * johnny: 3 votes
 * jackie: 2 votes
 * jamie: 3 votes
 * 
 * Winner: jamie with 3 votes
 * 
 * === Test Case 2 ===
 * Votes: andy blake clark andy andy blake 
 * 
 * Vote Count:
 * andy: 3 votes
 * blake: 2 votes
 * clark: 1 votes
 * 
 * Winner: andy with 3 votes
 * 
 * === Test Case 3 (Tie) ===
 * Votes: alice bob alice bob 
 * 
 * Vote Count:
 * alice: 2 votes
 * bob: 2 votes
 * 
 * Winner: alice with 2 votes
 * 
 * === Program Completed Successfully ===
 * 
 * Complexity Analysis:
 * - Time Complexity: O(n * m) where n is votes, m is candidates
 *   Can be optimized to O(n) with hash table
 * - Space Complexity: O(m) for storing candidates
 * 
 * Key Points:
 * 1. Count votes using hash table/array
 * 2. Find maximum votes
 * 3. Handle ties with lexicographic comparison
 * 4. Common interview problem
 */
