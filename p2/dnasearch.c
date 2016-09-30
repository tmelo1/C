/*
Tony Melo
tmelo1
(201)956-2503
Project 2 - 600.120
2/23/16
*/
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define MAX_SIZE 15000
#define TRUE 1
#define FALSE 0
#include "dnasearch.h"

int isValid(char c) { //method to check for valid characters
    switch(c) {
        case 'a': case 'A': case 'c': case 'C': case 'G': case 'g': case 't': case 'T':
            return TRUE;
        default:
            puts("Invalid character present.");
            return FALSE;
    }
}

int getPatternString(char storePatterns[]) {
    char dummy_string[MAX_SIZE]; //array to store input, will copy relevent patterns
    puts("Please enter pattern(s): ");
    while (scanf("%s", dummy_string) != EOF) { //collect input until EOF entered
    }
    int plength = 0; //count number of not null characters in "dummy" string
    for (int i = 0; i < MAX_SIZE; i++) {
        if (dummy_string[i] != '\0') {
            plength++;
        }
    }
    int i = 0;
    while (dummy_string[i] != '\0') {
        if(isValid(dummy_string[i]) || !(isspace(dummy_string[i]))) { //if char isn't whitespace or invalid
            storePatterns[i] = dummy_string[i]; //copy over patterns, modify array in main
            i++;
        } else {
            puts("Error: invalid characters present in sequence."); //otherwise give error message
            return 4;
        }
    }
    char patternsCopy[plength+1];
    strcpy(patternsCopy, storePatterns);
    return 0;
}


void findOccurances(char dna[], int dnalen, char patternString[]) {
    int offset = 0; //int to represent offsets
    int match; //int to act as boolean
    char *token = strtok(patternString, "' ' '\n' '\t' '\v' '\f' '\r'");
    int len;
    while (token != NULL) {
        len = strlen(token);
        for (int i = 0; i <= dnalen - len - 1; i++) {
            match = TRUE;
            for (int c = 0; i <= len; c++) {
                if (token[c] != dna[i+c]) {
                    match = FALSE;
                    break;
                } else if (match == TRUE) {
                    offset = offset + i + c;
                    printf("%s %d \n", token, offset);
                }
            }
        }
        if (match == FALSE) {
            puts("No match found");
        }
        token = strtok(NULL, "' ' '\n' '\t' '\v' '\f' '\r'");
    }
}


