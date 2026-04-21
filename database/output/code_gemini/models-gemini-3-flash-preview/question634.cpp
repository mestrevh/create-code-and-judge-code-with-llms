/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long S_target;
int D_limit;
vector<vector<string>> results;

vector<int> adj[10] = {
    {7, 8, 9},       // 0: neighbors are 7, 8, 9 (diagonal and vertical)
    {2, 4, 5},       // 1: neighbors are 2, 4, 5
    {1, 3, 4, 5, 6}, // 2: neighbors are 1, 3, 4, 5, 6
    {2, 5, 6},       // 3: neighbors are 2, 5, 6
    {1, 2, 5, 7, 8}, // 4: neighbors are 1, 2, 5, 7, 8
    {1, 2, 3, 4, 6, 7, 8, 9}, // 5: neighbors are 1-4, 6-9
    {2, 3, 5, 8, 9}, // 6: neighbors are 2, 3, 5, 8, 9
    {4, 5, 8, 0},    // 7: neighbors are 4, 5, 8, 0
    {4, 5, 6, 7, 9, 0}, // 8: neighbors are 4, 5, 6, 7, 9, 0
    {5, 6, 8, 0}     // 9: neighbors are 5, 6, 8, 0
};

void check_path(const string& P) {
    int L = (int)P.length();
    if (L == 0) return;
    
    // According to the rules, all terms except the last must have length D_limit.
    // The last term must have length between 1 and D_limit.
    // For a total length L, the number of terms Q+1 is uniquely determined.
    int Q = (L - 1) / D_limit;
    long long current_sum = 0;
    vector<string> terms;
    
    for (int i = 0; i < Q; ++i) {
        string t = P.substr(i * D_limit, D_limit);
        terms.push_back(t);
        current_sum += stoll(t);
    }
    
    // The last term takes the remaining digits.
    string last_t = P.substr(Q * D_limit);
    terms.push_back(last_t);
    current_sum += stoll(last_t);
    
    if (current_sum == S_target) {
        results.push_back(terms);
    }
}

void dfs(int u, int mask, string& path) {
    path.push_back(u + '0');
    check_path(path);
    
    for (int v : adj[u]) {
        if (!(mask & (1 << v))) {
            dfs(v, mask | (1 << v), path);
        }
    }
    
    path.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int caseNum = 1;
    while (cin >> S_target >> D_limit && (S_target != -1 || D_limit != -1)) {
        results.clear();
        string path = "";
        
        // Explore all possible paths on the phone keypad without repeating digits.
        for (int i = 0; i <= 9; ++i) {
            dfs(i, (1 << i), path);
        }
        
        // Sort and unique to satisfy lexicographical order requirements.
        sort(results.begin(), results.end());
        results.erase(unique(results.begin(), results.end()), results.end());
        
        cout << "#" << caseNum++ << "\n";
        if (results.empty()) {
            cout << "impossivel\n";
        } else {
            for (const auto& seq : results) {
                for (int i = 0; i < (int)seq.size(); ++i) {
                    cout << seq[i] << (i == (int)seq.size() - 1 ? "" : " ");
                }
                cout << "\n";
            }
        }
    }
    
    return 0;
}

