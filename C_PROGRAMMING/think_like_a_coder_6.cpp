#include <stdio.h>

int main() 
{
    char blocks[1000];
    int freq[256] = {0};
    int i, oddCount = 0;

    printf("Enter the block letters: ");
    scanf("%999s", blocks);

    // Count the frequency of each character
    for (i = 0; blocks[i] != '\0'; i++) {
        freq[(unsigned char)blocks[i]]++; // Fixed: changed 'block' to 'blocks'
    }

    // Count how many characters have an odd frequency
    for (i = 0; i < 256; i++) {
        if (freq[i] % 2 != 0) {
            oddCount++;
        }
    }

    // A palindrome permutation can have at most one character with an odd count
    if (oddCount <= 1) {
        printf("Bridge is stable.\nPalindrome is possible.\n");
    } else {
        printf("Bridge is unstable.\nPalindrome is not possible.\n");
    }

    return 0;
}
