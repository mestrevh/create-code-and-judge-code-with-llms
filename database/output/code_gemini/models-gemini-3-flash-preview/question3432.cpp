/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    vector<long long> v;
    while (cin >> s) {
        if (s == "x" || s == "X") break;
        try {
            v.push_back(stoll(s));
        } catch (...) {
            continue;
        }
    }

    if (v.empty()) {
        return 0;
    }

    bool is_growing = true;
    for (size_t i = 1; i < v.size(); ++i) {
        if (v[i] < v[i - 1]) {
            is_growing = false;
            break;
        }
    }

    if (!is_growing) {
        cout << "false" << endl;
    } else {
        cout << "true" << endl;
        long double sum = 0;
        for (long long x : v) {
            sum += (long double)x;
        }
        long double n = (long double)v.size();
        long double avg = sum / n;
        for (size_t i = 0; i < v.size(); ++i) {
            // Using a tiny epsilon for long double precision safety
            if ((long double)v[i] >= avg - 1e-15) {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}