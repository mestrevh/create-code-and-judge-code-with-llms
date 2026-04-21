/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    if (!getline(cin, line)) {
        return 0;
    }

    long long sum = 0;
    long long count = 0;
    long long mx = numeric_limits<long long>::min();
    long long mn = numeric_limits<long long>::max();

    string cur = "";
    for (char c : line) {
        if ((c >= '0' && c <= '9') || c == '-') {
            cur += c;
        } else {
            if (!cur.empty() && cur != "-") {
                try {
                    long long v = stoll(cur);
                    if (v > mx) mx = v;
                    if (v < mn) mn = v;
                    sum += v;
                    count++;
                } catch (...) {}
                cur = "";
            }
        }
    }

    if (!cur.empty() && cur != "-") {
        try {
            long long v = stoll(cur);
            if (v > mx) mx = v;
            if (v < mn) mn = v;
            sum += v;
            count++;
        } catch (...) {}
    }

    if (count > 0) {
        cout << "Maior: " << mx << "\n";
        cout << "Menor: " << mn << "\n";
        cout << "Media: " << fixed << setprecision(2) << (double)sum / (double)count << "\n";
    }

    return 0;
}