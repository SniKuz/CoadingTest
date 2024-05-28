#include <bits/stdc++.h>

using namespace std;

unordered_set<char> numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

vector<string> Split(const string& str) {
    vector<string> ret(2);
    int i = 0;
    while (i < str.size() && numbers.find(str[i]) == numbers.end()) {
        ret[0] += tolower(str[i]);
        ++i;
    }

    int number_start = i;
    while (i < str.size() && numbers.find(str[i]) != numbers.end()) {
        ++i;
    }

    ret[1] = str.substr(number_start, i - number_start);
    return ret;
}

bool compare(const string& a, const string& b) {
    auto splitA = Split(a);
    auto splitB = Split(b);

    if (splitA[0] < splitB[0]) return true;
    if (splitA[0] > splitB[0]) return false;

    return stoi(splitA[1]) < stoi(splitB[1]);
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), compare);
    return files;
}