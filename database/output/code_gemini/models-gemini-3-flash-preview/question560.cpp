/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int a, n;
long long c;
vector<long long> M_v, S_v, K_v;

long long getM(int age) {
    if (age <= n + 1) return M_v[age];
    return M_v[n + 1];
}

long long getS(int age) {
    if (age <= n + 1) return S_v[age];
    return S_v[n + 1];
}

long long getK(int age) {
    if (age <= n + 1) return K_v[age];
    return K_v[n + 1];
}

char choice_table[5005][5005];
char spec_choice_table[5005];
long long dp_curr_row[5005];
long long dp_next_row[5005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> a >> n >> c)) return 0;

    M_v.resize(n + 2);
    S_v.resize(n + 2);
    K_v.resize(n + 2);

    for (int i = 0; i <= n + 1; ++i) {
        cin >> M_v[i];
    }
    for (int i = 1; i <= n + 1; ++i) {
        cin >> S_v[i];
    }
    for (int i = 1; i <= n + 1; ++i) {
        cin >> K_v[i];
    }

    long long dp_next_spec, dp_curr_spec;

    for (int j = 1; j <= n; ++j) {
        dp_next_row[j] = -getK(j);
    }
    dp_next_spec = -getK(a + n);

    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= i - 1; ++j) {
            long long costM = getM(j) + dp_next_row[j + 1];
            long long costB = c - getS(j) + getM(0) + dp_next_row[1];
            if (costB < costM) {
                dp_curr_row[j] = costB;
                choice_table[i][j] = 'B';
            } else {
                dp_curr_row[j] = costM;
                choice_table[i][j] = 'M';
            }
        }

        int sj = a + i - 1;
        long long costM_spec = getM(sj) + dp_next_spec;
        long long costB_spec = 4e18; // Very high value as default
        if (sj > 0) {
            costB_spec = c - getS(sj) + getM(0) + dp_next_row[1];
        }
        if (costB_spec < costM_spec) {
            dp_curr_spec = costB_spec;
            spec_choice_table[i] = 'B';
        } else {
            dp_curr_spec = costM_spec;
            spec_choice_table[i] = 'M';
        }

        for (int j = 1; j <= i - 1; ++j) {
            dp_next_row[j] = dp_curr_row[j];
        }
        dp_next_spec = dp_curr_spec;
    }

    cout << dp_curr_spec << "\n";

    bool cur_is_spec = true;
    int cur_age = a;
    for (int i = 1; i <= n; ++i) {
        char move;
        if (cur_is_spec) {
            move = spec_choice_table[i];
            if (move == 'B') {
                cur_is_spec = false;
                cur_age = 1;
            } else {
                cur_age = a + i;
            }
        } else {
            move = choice_table[i][cur_age];
            if (move == 'B') {
                cur_age = 1;
            } else {
                cur_age = cur_age + 1;
            }
        }
        cout << move;
    }
    cout << "\n";

    return 0;
}