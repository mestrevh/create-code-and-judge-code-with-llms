/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string part;
    long long sum = 0;
    int count = 0;

    while (cin >> part) {
        string current = "";
        for (int i = 0; i < (int)part.length(); ++i) {
            char c = part[i];
            if (isdigit(c) || c == '-') {
                current += c;
            } else {
                if (!current.empty() && current != "-") {
                    try {
                        long long val = stoll(current);
                        if (val % 2 != 0) {
                            sum += val;
                            count++;
                        }
                    } catch (...) {}
                    current = "";
                }
            }
        }
        if (!current.empty() && current != "-") {
            try {
                long long val = stoll(current);
                if (val % 2 != 0) {
                    sum += val;
                    count++;
                }
            } catch (...) {}
        }
    }

    if (count > 0) {
        cout << fixed << setprecision(2) << (double)sum / (double)count << endl;
    }

    return 0;
}