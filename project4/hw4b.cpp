/**
*Tony Melo
*tmelo1 - tmelo1@jhu.edu
*600.120 Spring 2016 Project 4B
*(201)956-2503
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cctype>

using namespace std;


int main(int argc, char *argv[]) {
    if (argc != 2) { //check num args 
        return 1;
    }
    typedef pair<string, string> Bigram;
    map<Bigram, int> model;  //just same as part a, making model
    string specialFirst = "<START>";   //special bigram strings
    string specialEnd = "<END>";
    Bigram start;
    Bigram end;
    vector<string> word_freq;   //vector to hold words in their frequencies
    string word1;
    string word2;
    cin >> word1;   //read first word
    while (cin >> word2) {   //read while valid input
        Bigram word_pair = {word1, word2};   //make bigram
        if (model.empty()) {   //special case
            model.insert(pair<Bigram, int>(word_pair, 1));
        }
        map<Bigram, int>::iterator it = model.find(word_pair); //make iterator
        if (it == model.end()) {  //pair not found
            model.insert(pair<Bigram, int>(word_pair, 1));
        } else if ((it -> first).first.compare(specialFirst) == 0) { //found the start
            start = {(it -> first).first, (it -> first).second};
        } else if ((it -> first).second.compare(specialEnd) == 0) { //found end
            end = {(it -> first).first, (it -> first).second};
        } else {
            model[word_pair]++; //increment frequency
        }
        word1 = word2;  //swap words for next bigram
    }
    for (map<Bigram, int>::iterator it = model.begin(); it != model.end(); ++it) {
        for (int i = 0; i < it -> second; i++) {
            word_freq.push_back((it -> first).first); //add words the number of times they appear
        }
    }
    vector<string>::iterator vector_it = word_freq.begin(); //iterate
    for (int i = 0; i <= *argv[1]; i++) { //make this many sentences
        int randIndex = rand() % (word_freq.size()-1);  //access random element
        cout << start.first << " " << start.second << " ";
        string current = word_freq[randIndex]; //printing stuff
        while (current.compare(specialEnd) != 0) {
            cout << current << " ";
            advance(vector_it, randIndex);
            current = *vector_it;
        }
        cout << end.first << " " << end.second << endl;
    }
}
