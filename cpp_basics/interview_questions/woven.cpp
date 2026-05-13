#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

string getFeedback(string guess, string secret) {
    int n = guess.size();

    string result(n, '_');

    unordered_map<char, int> freq;

    // First pass: exact matches
    for (int i = 0; i < n; i++) {
        if (guess[i] == secret[i]) {
            result[i] = '*';
        } else {
            freq[secret[i]]++;
        }
    }

    // Second pass: wrong place matches
    for (int i = 0; i < n; i++) {

        // already matched
        if (result[i] == '*')
            continue;

        if (freq[guess[i]] > 0) {
            result[i] = '+';
            freq[guess[i]]--;
        }
    }

    return result;
}

int main() {

    cout << getFeedback("aaaaa", "hello") << endl;
    // *++++

    cout << getFeedback("lllll", "hello") << endl;
    // _**__

    cout << getFeedback("aaaaa", "hello") << endl;
    // _____
}