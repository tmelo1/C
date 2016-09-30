/**
*Tony Melo
*tmelo1 - tmelo1@jhu.edu
*600.120 Spring 2016 Project 4A
*(201)956-2503
*/

#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

//Easy to print because binary search trees are ordered
void printForward(map<pair<string, string>, int> myModel) {
    map<pair<string, string>, int>::iterator it; //create map iterator
    for (it = myModel.begin(); it != myModel.end(); ++it) {  //loop from beginning to end
        cout << it -> first.first << " " << it -> first.second << " "  //print each field
            << it -> second << endl;
    }
}

//Also easy, just using a reverse iterator
void printReverse(map<pair<string, string>, int> myModel) {
    map<pair<string, string>, int>::reverse_iterator rit; //reverse iterator on map
    for (rit = myModel.rbegin(); rit != myModel.rend(); ++rit) { //start at end, go to beginning
        cout << rit -> first.first << " " << rit -> first.second << " " //print fields
            << rit -> second << endl;
    }
}

//Little more difficult, but basically store maximum, print by frequencies, preserve order
void printByFrequency(map<pair<string, string>, int> myModel) {
    int max = 0;                                   //variable for maximum frequency
    map<pair<string, string>, int>::iterator it;  //map iterator
    for (it = myModel.begin(); it != myModel.end(); ++it) {   //find maximum frequency
        if (it -> second > max) {
            max = it -> second;    //update max
        }
    }

    for (int current = 1; current <= max; current++) {   //start at frequency 1, go to max
        for (it = myModel.begin(); it != myModel.end(); ++it) { //iterate on map
            if (it -> second == current) {   //print in ascending frequency order
                cout << it -> first.first << " " << it -> first.second << " " 
                    << it -> second << endl;     //print fields
            }
        }
    }
}

//Create txt file from map
void makeModelFile(map<pair<string, string>, int> myModel) {
    map<pair<string, string>, int>::iterator it;  //map iterator
    ofstream output("model.txt");     //print to this file name
    for (it = myModel.begin(); it != myModel.end(); ++it) {   //iterate over map
        output << it -> first.first << " " << it -> first.second << " "   //same as forward print
            << it -> second << endl;
    }
    output.close();  //close ofstream
}


int main (int argc, char *argv[]) {
    if (argc == 1) {
        cout << "Invalid arguments" << endl;
        return 7;
    }
    string word1;          //strings to store word pairs as bigrams
    string word2;
    typedef pair<string, string> Bigram;       //typedef for convenience
    map<Bigram, int> model;     //map bigrams to their respective frequencies
    cin >> word1;    //read the first word in
    Bigram first = {"<START>", word1};    //create special bigram w/ frequency 1
    model.insert(pair<Bigram, int>(first, 1));   //insert into map
    while (cin >> word2) {    //while we have valid input, scan word by word
        Bigram word_pair = {word1, word2};   //make a bigram
        map<Bigram, int>::iterator it = model.find(word_pair); //make an iterator
        if (it == model.end()) {  //if we're pointing to the end, the entry is unique
            model.insert(pair<Bigram, int>(word_pair, 1));   //insert
        } else {
            model[word_pair]++;    //update existing entry
        }
        word1 = word2;    //swap words to move down the line
    }
    Bigram last = {word2, "<END>"};    //make special bigram
    model.insert(pair<Bigram, int>(last, 1));    //insert
    makeModelFile(model);    //create txt file w/ created map
    switch(*(argv[1])) {     //call print methods based on input
        case 'a': case 'A':
            printForward(model);
            break;
        case 'r': case 'R':
            printReverse(model);
            break;
        case 'c': case 'C':
            printByFrequency(model);
            break;
        default:
            cout << "Invalid input" << endl;
            break;
    }
}




 
