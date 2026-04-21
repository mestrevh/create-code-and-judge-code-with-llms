/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    int n = s.length();
    unsigned long long sum = 0;
    
    for (int i = 0; i < n; ++i) {
        int digit = s[i] - '0';
        unsigned long long p = 1;
        for (int j = 0; j < n; ++j) {
            p *= (unsigned long long)digit;
        }
        sum += p;
    }

    unsigned long long original = 0;
    bool overflow_orig = false;
    if (s.length() > 20) {
        overflow_orig = true;
    } else {
        for (char c : s) {
            unsigned long long next = original * 10 + (c - '0');
            if (next < original && original != 0) { // Simple overflow check
                overflow_orig = true;
                break;
            }
            original = next;
        }
    }

    if (!overflow_orig && sum == original) {
        cout << "Armstrong" << endl;
    } else {
        cout << "soma: " << sum << endl;
    }

    return 0;
}