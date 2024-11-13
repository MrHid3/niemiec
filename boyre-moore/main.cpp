#include <chrono>
#include <iostream>
#include <fstream>

using namespace std;
using namespace std::chrono;

int estupido(string needle, string haystack) {
    for(int i = 0; i < haystack.length(); i++) {
        int checked = 0;
        for(int j = 0; j < needle.length(); j++) {
            if(haystack[i + j] == needle[j])
                checked++;
            else {
                break;
            }
        }
        if(checked == needle.length()) return i;
    }
    return -1;
}

int boyreMoore(string needle, string haystack) {
    int alphabet[256];

    for(int i = 0; i < 255; i++)
        alphabet[i] = needle.length();
    for(int i = 0; i < needle.length(); i++)
        alphabet[(int)needle[i]] = needle.length() - i;

    int addedIndex;
    for(int i = needle.length() - 1; i < haystack.length(); i += addedIndex) {
        int checked = 0;
        for(int j = 0; j < needle.length(); j++) {
            if(haystack[i - j] == needle[needle.length() - j - 1])
                checked++;
            else
                break;
        }
        if(checked == needle.length())
            return i - (needle.length() - 1);
        addedIndex = alphabet[(int)haystack[i]];
    }
    return -1;
}

int main() {

    return 0;
}

