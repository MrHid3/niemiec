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
    string* fragments [roundup(word.length()/maxLength)];
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

int boyreMoore(string needle, string heystack) {
    int alphabet[256];

    for(int i = 0; i < 255; i++)
        alphabet[i] = needle.length();
    for(int i = needle.length() - 1 ; i >= 0; i--)
        if(alphabet[(int)needle[i]] == needle.length())
            alphabet[(int)needle[i]] = needle.length() - i;

    int addedIndex;
    for(int i = needle.length() - 1; i < heystack.length(); i += addedIndex) {
        int checked = 0;
        for(int j = 0; j < needle.length(); j++) {
            if(heystack[i - j] == needle[needle.length() - j - 1])
                checked++;
            else
                break;
        }
        // cout << "checked: " << checked << endl;
        // cout << "addedIndex: " << alphabet[(int)heystack[i]] << endl;
        // cout << "heystack[i]: " << heystack[i] << endl;
        if(checked == needle.length()){
            return i - (needle.length() - 1);
        }
        addedIndex = alphabet[(int)heystack[i]];
    }
    return -1;
}

int* fuzzySearch(string needle, string heystack, int fragmentLength) {
    string* fragments = fragmenter(needle, fragmentLength);
    // for(int i = 0; i < fragments.length() + 1; i++) {
    //     cout << fragments[i] << endl;
    // }
    int fragmentSumLength = 0;
    for(int i = 0; i < fragments.length() + 1; i++) {
        fragmentSumLength += fragments[i].length();
        int index = boyreMoore(fragments[i], heystack);
        if (index != -1){
            int checked = 0;
            for(int j = 0; j < needle.length(); j++){
                if(heystack[i - fragmentSumLength + j] == needle[j])
                    checked++
                else
                    break
            }
            if(checked == needle.length() - 1)
                return index;
        }
    }
    return -1;
}

int main() {
    // cout << Hamming("pieski", "pkotki") << endl;
    // cout << Levenshtein("madagaskar", "magdagaska") << endl;
    fuzzySearch("labadabadu", "tak", 3);
    return 0;
}
