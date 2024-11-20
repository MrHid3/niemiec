#include <iostream>

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

int main() {
    // cout << Hamming("pieski", "pkotki") << endl;
    cout << Levenshtein("madagaskar", "magdagaska") << endl;
    return 0;
}
