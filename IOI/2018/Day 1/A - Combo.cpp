#include "combo.h"

using namespace std;

string guess_sequence(int N) {
    string s = "";
    if (press("AB")) {
        if (press("A")) s += 'A';
        else s += 'B';
    } else {
        if (press("X")) s += 'X';
        else s += 'Y';
    }
    if (N == 1) return s;
    string buttons = "";
    for (char c : "ABXY"s) {
        if (c != s[0]) buttons += c;
    }
    for (int i = 1; i < N - 1; i++) {
        string combo = "";
        for (int j = 0; j < 3; j++) {
            combo += s + buttons[2] + buttons[j];
        }
        combo += s + buttons[1];
        int coins = press(combo);
        s += buttons[coins - i];
        
    }
    for (int j = 0; j < 2; j++) {
        if (press(s + buttons[j]) == N) {
            return s + buttons[j];
        }
    }
    return s + buttons[2];
}
