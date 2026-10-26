#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char path[15];
int tree[15];
int target, length = 0;

// Recursive function to find the path to the target node
int findpath(int node) {
    // Base case: out of bounds or node is closed/empty
    if (node >= 15 || tree[node] == 0)
        return 0;
    
    // Base case: target node found
    if (node == target)
        return 1;
    
    // Traverse Left Child (2 * node + 1)
    path[length] = 'L';
    length++;
    if (findpath(2 * node + 1))
        return 1;
    length--; // Backtrack
    
    // Traverse Right Child (2 * node + 2)
    path[length] = 'R';
    length++;
    if (findpath(2 * node + 2))
        return 1;
    length--; // Backtrack
    
    return 0;
}

int main() {
    int i;
    int found = 0;
    
    // Initialize random seed
    srand(time(NULL)); 
    
    printf("Enter Tree node values: ");
    printf("\n 1 -> Open node, 0 -> Closed node \n");
    
    // Input tree configuration
    for (i = 0; i < 15; i++) {
        printf("Node %d: ", i);
        scanf("%d", &tree[i]);
    }
    
    // Generate a valid random target node
    target = rand() % 15;
    while (!found) {
        if (target == 0 || tree[target] == 0) {
            target = rand() % 15;
            continue;
        }
        
        length = 0;
        if (findpath(0)) {
            found = 1;
        } else {
            // If the target is unreachable, pick a new one
            target = rand() % 15; 
        }
    }
    
    // Print the final path
    printf("Path: Start");
    for (i = 0; i < length; i++) {
        if (path[i] == 'L')
            printf(" -> Left");
        else
            printf(" -> Right");
    }
    printf(" -> Target\n");
    
    return 0;
}
