/*
Tony Melo
tmelo1
(201)956-2503
Project 2 - 600.120
2/23/16
*/

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "dnasearch.h"

//In my README i explain why my program isn't exactly functional, my apologies to whoever grades my assignment
int main(void) {
    assert(isValid('G') == 1);
    assert(isValid('B') == 0);
    assert(isValid('f') == 0);
    assert(isValid('a') == 1);
    char testPatterns[67];
    char dna[10] = {'T', 'C', 'A', 'G','C','T','A','T','C'};
    getPatternString(testPatterns);
    assert(testPatterns[0] == 'A');
    findOccurances(dna, strlen(dna), testPatterns);
}
