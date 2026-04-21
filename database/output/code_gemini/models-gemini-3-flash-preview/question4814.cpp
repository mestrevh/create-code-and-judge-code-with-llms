/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (!(cin >> n)) return 0;

    long long k = 0;
    long long temp_n = n;
    if (temp_n > 1) {
        for (long long i = 2; i * i <= temp_n; ++i) {
            while (temp_n % i == 0) {
                k++;
                temp_n /= i;
            }
        }
        if (temp_n > 1) k++;
    }

    string s;
    getline(cin, s);
    if (s.empty()) {
        if (!getline(cin, s)) s = "";
    } else {
        bool all_ws = true;
        for (char c : s) {
            if (c != ' ' && c != '\r' && c != '\n' && c != '\t') {
                all_ws = false;
                break;
            }
        }
        if (all_ws) {
            if (!getline(cin, s)) s = "";
        } else {
            if (s[0] == ' ') s.erase(0, 1);
            if (s.empty()) {
                if (!getline(cin, s)) s = "";
            }
        }
    }

    cout << k << "\n";

    long long current_shift = k;
    string result = "";
    for (size_t i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (c >= 'a' && c <= 'z') {
            int original_pos = c - 'a';
            int new_pos = (original_pos + (int)(current_shift % 26)) % 26;
            result += (char)('a' + new_pos);
            current_shift++;
        } else if (c >= 'A' && c <= 'Z') {
            int original_pos = c - 'A';
            int new_pos = (original_pos + (int)(current_shift % 26)) % 26;
            result += (char)('A' + new_pos);
            current_shift++;
        } else {
            result += c;
        }
    }

    cout << result << endl;

    return 0;
}