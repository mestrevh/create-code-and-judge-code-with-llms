/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

long long S;
int D;
vector<vector<int>> adj;
set<string> solutions;

void setup_adj() {
    adj.assign(10, vector<int>());
    pair<int, int> pos[10];
    pos[1] = {0, 0}; pos[2] = {0, 1}; pos[3] = {0, 2};
    pos[4] = {1, 0}; pos[5] = {1, 1}; pos[6] = {1, 2};
    pos[7] = {2, 0}; pos[8] = {2, 1}; pos[9] = {2, 2};
    pos[0] = {3, 1};

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (i == j) continue;
            if (abs(pos[i].first - pos[j].first) <= 1 &&
                abs(pos[i].second - pos[j].second) <= 1) {
                adj[i].push_back(j);
            }
        }
    }
}

void solve(int last_digit, int mask, string& current_digits) {
    if (!current_digits.empty()) {
        long long current_sum = 0;
        size_t len = current_digits.length();
        
        for (size_t i = 0; i + D <= len; i += D) {
            current_sum += stoll(current_digits.substr(i, D));
            if (current_sum > S) return;
        }

        size_t remainder_pos = (len / D) * D;
        if (remainder_pos < len) {
            current_sum += stoll(current_digits.substr(remainder_pos));
        }

        if (current_sum > S) {
            return;
        }

        if (current_sum == S) {
            string solution_str;
            size_t num_full_terms = len / D;
            for (size_t i = 0; i < num_full_terms; ++i) {
                if (i > 0) solution_str += " ";
                solution_str += current_digits.substr(i * D, D);
            }
            size_t remainder_len = len % D;
            if (remainder_len > 0) {
                if (num_full_terms > 0) solution_str += " ";
                solution_str += current_digits.substr(num_full_terms * D);
            }
            solutions.insert(solution_str);
        }
    }

    if (current_digits.length() == 10) {
        return;
    }

    if (last_digit == -1) {
        for (int d = 0; d < 10; ++d) {
            current_digits.push_back('0' + d);
            solve(d, 1 << d, current_digits);
            current_digits.pop_back();
        }
    } else {
        for (int neighbor : adj[last_digit]) {
            if (!((mask >> neighbor) & 1)) {
                current_digits.push_back('0' + neighbor);
                solve(neighbor, mask | (1 << neighbor), current_digits);
                current_digits.pop_back();
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    setup_adj();
    int case_num = 1;
    while (cin >> S >> D && (S != -1 || D != -1)) {
        solutions.clear();
        string current_digits = "";
        
        solve(-1, 0, current_digits);

        cout << "#" << case_num++ << "\n";
        if (solutions.empty()) {
            cout << "impossivel\n";
        } else {
            for (const auto& s : solutions) {
                cout << s << "\n";
            }
        }
    }

    return 0;
}
