/**
*Tony Melo
*tmelo1 - tmelo1@jhu.edu
*2019562503
*600.120 Spring 2016 Project 4 Test
*/

#include <map>
#include <cassert>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main(void) {
    typedef pair<string, string> Bigram;
    map <Bigram, int> model;
    string word1;
    string word2;
    cin >> word1;
    Bigram first = {"<START>", word1};
    model.insert(pair<Bigram, int>(first, 1));
    while (cin >> word2) {
        Bigram wpair = {word1, word2};
        map<Bigram, int>::iterator it = model.find(word_pair);
        if (it == model.end()) {
            model.insert(pair<Bigram, int>(word_pair, 1));
        } else {
            model[word_pair]++;
        }
        word1 = word2;
    }
    assert(model.size() != 0);
    assert(model != null);
    map<Bigram, int>::iterator it;
    for (it = model.begin(); it != model.end(); ++it) {
        assert((it -> first.first) != "");
        assert((it -> first.second) != "");
        assert((it -> second) != 0);
    }
