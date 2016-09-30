/**
*Tony Melo
*tmelo1 - tmelo1@jhu.edu
*600.120 Spring 2016 Project 4
*2019562503
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

int main(void) {

    typedef pair<string, string> Bigram;
    typedef pair<Bigram, int> p;
    Bigram random = {"hello", "world"};
    Bigram sup = {"what's", "up"};
    Bigram testing = {"testing", "12"};
    Bigram starWars = {"han", "solo"};
    map<Bigram, int> model;
    assert(model.empty());
    vector<string> words;
    words.push_back(random.first);
    words.push_back(sup.second);
    assert(random.first.compare("hello") == 0);
    p A = {random, 1};
    p B = {sup, 2};
    p C = {testing, 3};
    p D = {starWars, 4};
    model.insert(A);
    model.insert(B);
    model.insert(C);
    model.insert(D);
    assert(!model.empty());
    assert(model[random] == 1);


}
