#include <chrono>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
using namespace std::chrono;

int estupido(string needle, string haystack) {
    int stupidmeter = 0;
    for(int i = 0; i < haystack.length(); i++) {
        int checked = 0;
        for(int j = 0; j < needle.length(); j++) {
            stupidmeter++;
            if(haystack[i + j] == needle[j])
                checked++;
            else {
                break;
            }
        }
        if(checked == needle.length())
            return i;

    }
    return -1;
}

// acbdefgdupa
//   dupadupa

int boyreMoore(string needle, string heystack) {
    int alphabet[256];

    for(int i = 0; i < 255; i++)
        alphabet[i] = needle.length();
    for(int i = needle.length() - 1; i >= 0; i--)
        if(alphabet[(int)needle[i]] == needle.length())
            alphabet[(int)needle[i]] = needle.length() - i;

    int addedIndex;
    for(int i = needle.length() - 1; i < heystack.length(); i += addedIndex) {
        bool checked = true;
        for(int j = 0; j < needle.length(); j++) {
            if(heystack[i - j] != needle[needle.length() - j - 1]){
                checked = false;
                break;
            }
        }
        // cout << "checked: " << checked << endl;
        // cout << "addedIndex: " << alphabet[(int)heystack[i]] << endl;
        // cout << "heystack[i]: " << heystack[i] << endl;
        if(checked){
            return i - (needle.length() - 1);
        }
        addedIndex = alphabet[(int)heystack[i]];
    }
    return -1;
}

int main() {
    string needle = "string";
    ifstream f("../boyre-moore/lorem.txt");
    if (!f.is_open()) {
        cerr << "Error opening the file!";
        return 1;
    }
    string heystack;
    getline(f, heystack);

    auto start = high_resolution_clock::now();
    cout << "naiwna: " << estupido(needle, heystack) << endl;
    auto stop = high_resolution_clock::now();
    cout << duration_cast<microseconds>(stop - start) << endl;

    start = high_resolution_clock::now();
    cout << "boyre-moore: " << boyreMoore(needle, heystack) << endl;
    stop = high_resolution_clock::now();
    cout << duration_cast<microseconds>(stop - start) << endl;

    return 0;
}