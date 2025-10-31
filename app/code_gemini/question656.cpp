/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <tuple>

using namespace std;

map<string, int> num_map;
map<string, int> shape_map;
map<int, int> memo;
vector<tuple<int, int, int>> type_b_sets;
int powers_of_3[10];

void initialize_maps() {
    num_map["um"] = 0;
    num_map["dois"] = 1;
    num_map["tres"] = 2;

    shape_map["circulo"] = 0;
    shape_map["circulos"] = 0;
    shape_map["quadrado"] = 1;
    shape_map["quadrados"] = 1;
    shape_map["triangulo"] = 2;
    shape_map["triangulos"] = 2;
}

void precompute() {
    for (int k1 = 0; k1 < 9; ++k1) {
        for (int k2 = k1 + 1; k2 < 9; ++k2) {
            int i1 = k1 / 3, j1 = k1 % 3;
            int i2 = k2 / 3, j2 = k2 % 3;
            
            int i3 = (3 - (i1 + i2) % 3) % 3;
            int j3 = (3 - (j1 + j2) % 3) % 3;

            int k3 = 3 * i3 + j3;

            if (k3 > k2) {
                type_b_sets.emplace_back(k1, k2, k3);
            }
        }
    }
    
    powers_of_3[0] = 1;
    for (int i = 1; i < 10; ++i) {
        powers_of_3[i] = powers_of_3[i-1] * 3;
    }
}

int solve_dp(int state) {
    if (state == 0) {
        return 0;
    }
    if (memo.count(state)) {
        return memo[state];
    }

    int max_sets = 0;
    
    for (const auto& s : type_b_sets) {
        int k1, k2, k3;
        tie(k1, k2, k3) = s;

        if ((state / powers_of_3[k1]) % 3 > 0 &&
            (state / powers_of_3[k2]) % 3 > 0 &&
            (state / powers_of_3[k3]) % 3 > 0) {
            
            int new_state = state - powers_of_3[k1] - powers_of_3[k2] - powers_of_3[k3];
            max_sets = max(max_sets, 1 + solve_dp(new_state));
        }
    }

    return memo[state] = max_sets;
}

void solve_test_cases() {
    int n;
    while (cin >> n && n != 0) {
        vector<int> counts(9, 0);
        for (int i = 0; i < n; ++i) {
            string num_str, shape_str;
            cin >> num_str >> shape_str;
            int num = num_map[num_str];
            int shape = shape_map[shape_str];
            counts[3 * num + shape]++;
        }

        int total_sets = 0;
        
        for (int i = 0; i < 9; ++i) {
            total_sets += counts[i] / 3;
            counts[i] %= 3;
        }

        int initial_state = 0;
        for (int i = 0; i < 9; ++i) {
            initial_state += counts[i] * powers_of_3[i];
        }
        
        memo.clear();
        total_sets += solve_dp(initial_state);

        cout << total_sets << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    initialize_maps();
    precompute();
    solve_test_cases();

    return 0;
}
