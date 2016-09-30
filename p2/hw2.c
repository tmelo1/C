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
#include "dnasearch.h"
#define MAX_SIZE 15000

int main(int argc, const char* argv[]) {

    if (argc == 1 || argc > 2) { //check for command line args
        puts("Error, please enter a file name");
        return 1;
    }

    FILE* input = fopen(argv[1], "r"); //open file reader
    if (input == NULL) {
        puts("Error: could not read file"); //check for invalid files
        return 2;
    }
    //counters for each base
    int count_a = 0;
    int count_c = 0;
    int count_g = 0;
    int count_t = 0;
    char ch;
    char dna[MAX_SIZE];
    int index = 0;
    while ((ch = fgetc(input)) != EOF) { //read characters until EOF
        if (!((isspace(ch)))) {
            if (isValid(ch) == 1) {
                dna[index++] = ch; //add character to dna sequence
            } else {
                puts("Invalid character present."); //exit when invalid char found
                return 3;
            }
        }
    }

    for (int i = 0; i < index; i++) { //count up bases in sequence
        if (dna[i] == 'A' || dna[i] == 'a') { //check for base ignoring case, increment respective count
            count_a++;
        } else if (dna[i] == 'c' || dna[i] == 'C') {
            count_c++;
        } else if (dna[i] == 'g' || dna[i] == 'G') {
            count_g++;
        } else if (dna[i] == 'T' || dna[i] == 't') {
            count_t++;
        }
    }

    if (count_a == 0 || count_c == 0 || count_g == 0 || count_t == 0) { //check for validity of sequence
        puts("Error, invalid sequence. No bases present.");
        return 4;
    }
    char storePatterns[MAX_SIZE] = {'\0'};
    fclose(input);
    int sequenceLength = strlen(dna);
    getPatternString(storePatterns);
    findOccurances(dna, sequenceLength, storePatterns);
    return 0;
}
