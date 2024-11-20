#include <iostream>
#include <cmath>

using namespace std;

int Hamming(string first, string two) {
    if (first.size() != two.size())
        return -1;
    int result = 0;
    for(int i = 0; i < two.length(); i++)
        if(two[i] != first[i])
            result++;
    return result;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int cost(char a, char b) {
    if(a == b) return 0;
    else return 1;
}

int Levenshtein(string first, string second) {
    int table [first.length() + 1][second.length() + 1];
    for(int i = 0; i <= first.length(); i++)
        for(int j = 0; j <= second.length(); j++) {
            if(i == 0 && j == 0)
                table[i][j] = 0;
            else if(i == 0)
                table[i][j] = table[i][j - 1] + 1;
            else if(j == 0)
                table[i][j] = table[i - 1][j] + 1;
            else {
                table[i][j] = min(
                        table[i - 1][j] + 1, min(
                        table[i][j - 1] + 1,
                        table[i - 1][j - 1] + cost(first[i - 1], second[j - 1])
                    ));
            }
    }
    return table[first.length()][second.length()];
}

int roundup(float a) {
    if(a - round(a) < 0.5) return round(a) + 1;
    else return round(a);
}

string* fragmenter(string word, int maxLength) {
    string fragments [roundup(word.length()/maxLength)];
    // cout << roundup(word.length()/maxLength) << endl;
    string add;
    int fragment = 0;
    for(int i = 0; i < word.length(); i++) {
        add += word[i];
        // cout << add << endl;
        if((i + 1)% maxLength == 0 || i == word.length() - 1) {
            // cout << fragment << endl;
            fragments[fragment] = add;
            add = "";
            fragment++;
        }
    }
    return fragments;
}

int fuzzySearch(string needle, string heystack, int fragmentLength) {
    string* fragments = fragmenter(needle, fragmentLength);
    for(int i = 0; i < fragments.length() + 1; i++) {
        cout << fragments[i] << endl;
    }
    return 0;
}

int main() {
    // cout << Hamming("pieski", "pkotki") << endl;
    // cout << Levenshtein("madagaskar", "magdagaska") << endl;
    fuzzySearch("labadabadu", "tak", 3);
    return 0;
}
