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

    string s;
    if (!(cin >> s)) return 0;

    int n = s.length();
    vector<int> count(10, 0);
    int first_conflict = -1;

    for (int i = 0; i < n; ++i) {
        int digit = s[i] - '0';
        if (count[digit] < 2) {
            count[digit]++;
        } else {
            first_conflict = i;
            break;
        }
    }

    if (first_conflict == -1) {
        cout << s << endl;
        return 0;
    }

    for (int i = first_conflict; i >= 0; --i) {
        if (i < first_conflict) {
            count[s[i] - '0']--;
        }

        int current_digit = s[i] - '0';
        for (int d = current_digit - 1; d >= 0; --d) {
            if (count[d] < 2) {
                s[i] = d + '0';
                count[d]++;
                
                for (int j = i + 1; j < n; ++j) {
                    for (int next_d = 9; next_d >= 0; --next_d) {
                        if (count[next_d] < 2) {
                            s[j] = next_d + '0';
                            count[next_d]++;
                            break;
                        }
                    }
                }
                
                bool non_zero_found = false;
                for (int k = 0; k < n; ++k) {
                    if (s[k] != '0') non_zero_found = true;
                    if (non_zero_found) cout << s[k];
                }
                if (!non_zero_found) cout << "0";
                cout << endl;
                return 0;
            }
        }
    }

    return 0;
}