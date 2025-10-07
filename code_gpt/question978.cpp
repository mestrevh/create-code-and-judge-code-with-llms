/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#include <set>

using namespace std;

int distance(const pair<int, int>& a, const pair<int, int>& b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int tsp_brute_force(const vector<pair<int, int>>& points) {
    int n = points.size();
    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 0);
    int min_cost = numeric_limits<int>::max();

    do {
        int cost = 0;
        for (int i = 0; i < n; ++i) {
            cost += distance(points[perm[i]], points[perm[(i + 1) % n]]);
        }
        min_cost = min(min_cost, cost);
    } while (next_permutation(perm.begin() + 1, perm.end()));

    return min_cost;
}

void solve_case(int case_number, int n, const vector<pair<int, int>>& points) {
    int min_cost = tsp_brute_force(points);
    cout << case_number << ": " << min_cost << endl;
}

int main() {
    int L;
    cin >> L;
    cin.ignore();

    for (int case_number = 0; case_number < L; ++case_number) {
        int N;
        cin >> N;
        vector<pair<int, int>> points(N);

        for (int i = 0; i < N; ++i) {
            cin >> points[i].first >> points[i].second;
        }
        cin.ignore();

        solve_case(case_number, N, points);
    }

    return 0;
}
