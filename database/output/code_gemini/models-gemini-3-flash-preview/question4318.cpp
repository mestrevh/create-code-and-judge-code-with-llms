/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

struct Candidate {
    string name;
    long double diff;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    long double x;
    if (!(cin >> x)) return 0;

    vector<Candidate> candidates(n);
    for (int i = 0; i < n; ++i) {
        string name;
        long double age, height;
        if (!(cin >> name >> age >> height)) break;
        
        long double score = (long double)name.length() * age * height;
        candidates[i].name = name;
        candidates[i].diff = fabsl(score - x);
    }

    stable_sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.diff < b.diff;
    });

    for (int i = 0; i < m && i < n; ++i) {
        cout << candidates[i].name << "\n";
    }

    return 0;
}