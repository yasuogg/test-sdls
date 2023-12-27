
#include <stdio.h>
#include <stdbool.h>


void convertIntToCharWithSpaces(int intArray[], char charArray[], int length, int spacesBetweenChars) {
    int charIndex = 0;

    for (int i = 0; i < length; i++) {
        // Convert the integer to a character and assign to the charArray
        charArray[charIndex] = intArray[i] + '0';
        charIndex++;

        // Insert spaces if not the last character
        if (i < length - 1) {
            for (int space = 0; space < spacesBetweenChars; space++) {
                charArray[charIndex] = ' ';
                charIndex++;
            }
        }
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}