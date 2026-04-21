/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct CardType {
    int n, s;
};

int cnt[9];
int max_sets;
int distinct_sets[12][3];

void solve(int set_idx, int current_sets) {
    if (set_idx == 12) {
        int total = current_sets;
        for (int i = 0; i < 9; ++i) {
            total += cnt[i] / 3;
        }
        if (total > max_sets) max_sets = total;
        return;
    }

    int rem = 0;
    for (int i = 0; i < 9; ++i) rem += cnt[i];
    if (current_sets + rem / 3 <= max_sets) return;

    // Option 0: Don't take this set type
    solve(set_idx + 1, current_sets);

    int c0 = distinct_sets[set_idx][0];
    int c1 = distinct_sets[set_idx][1];
    int c2 = distinct_sets[set_idx][2];

    // Option 1: Take this set type once
    if (cnt[c0] >= 1 && cnt[c1] >= 1 && cnt[c2] >= 1) {
        cnt[c0]--; cnt[c1]--; cnt[c2]--;
        solve(set_idx + 1, current_sets + 1);
        
        // Option 2: Take this set type twice
        if (cnt[c0] >= 1 && cnt[c1] >= 1 && cnt[c2] >= 1) {
            cnt[c0]--; cnt[c1]--; cnt[c2]--;
            solve(set_idx + 1, current_sets + 2);
            cnt[c0]++; cnt[c1]++; cnt[c2]++;
        }
        cnt[c0]++; cnt[c1]++; cnt[c2]++;
    }
}

int get_num(const string& s) {
    if (s[0] == 'u') return 0; // um
    if (s[0] == 'd') return 1; // dois
    if (s[0] == 't') return 2; // tres
    return 0;
}

int get_shape(const string& s) {
    if (s[0] == 'c') return 0; // circulo, circulos
    if (s[0] == 'q') return 1; // quadrado, quadrados
    if (s[0] == 't') return 2; // triangulo, triangulos
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    CardType types[9];
    for (int n = 0; n < 3; ++n) {
        for (int s = 0; s < 3; ++s) {
            types[n * 3 + s].n = n;
            types[n * 3 + s].s = s;
        }
    }

    int ds_count = 0;
    for (int i = 0; i < 9; ++i) {
        for (int j = i + 1; j < 9; ++j) {
            for (int k = j + 1; k < 9; ++k) {
                if ((types[i].n + types[j].n + types[k].n) % 3 == 0 &&
                    (types[i].s + types[j].s + types[k].s) % 3 == 0) {
                    distinct_sets[ds_count][0] = i;
                    distinct_sets[ds_count][1] = j;
                    distinct_sets[ds_count][2] = k;
                    ds_count++;
                }
            }
        }
    }

    int N;
    while (cin >> N && N != 0) {
        for (int i = 0; i < 9; ++i) cnt[i] = 0;
        for (int i = 0; i < N; ++i) {
            string s1, s2;
            cin >> s1 >> s2;
            cnt[get_num(s1) * 3 + get_shape(s2)]++;
        }

        int base_sets = 0;
        for (int i = 0; i < 9; ++i) {
            if (cnt[i] >= 12) {
                int take = (cnt[i] - 9) / 3;
                base_sets += take;
                cnt[i] -= take * 3;
            }
        }

        max_sets = base_sets;
        for (int i = 0; i < 9; ++i) max_sets += cnt[i] / 3;

        solve(0, base_sets);
        cout << max_sets << "\n";
    }

    return 0;
}