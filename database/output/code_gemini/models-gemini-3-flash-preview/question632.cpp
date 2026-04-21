/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

typedef vector<int> Cube;

Cube rotX(const Cube& c) {
    return {c[4], c[1], c[0], c[3], c[5], c[2]};
}

Cube rotY(const Cube& c) {
    return {c[1], c[5], c[2], c[0], c[4], c[3]};
}

Cube rotZ(const Cube& c) {
    return {c[0], c[4], c[1], c[2], c[3], c[5]};
}

vector<Cube> perms;

void precompute() {
    set<Cube> seen;
    queue<Cube> q;
    Cube start = {0, 1, 2, 3, 4, 5};
    q.push(start);
    seen.insert(start);
    while (!q.empty()) {
        Cube curr = q.front();
        q.pop();
        perms.push_back(curr);
        Cube nxt;
        nxt = rotX(curr);
        if (seen.find(nxt) == seen.end()) {
            seen.insert(nxt);
            q.push(nxt);
        }
        nxt = rotY(curr);
        if (seen.find(nxt) == seen.end()) {
            seen.insert(nxt);
            q.push(nxt);
        }
        nxt = rotZ(curr);
        if (seen.find(nxt) == seen.end()) {
            seen.insert(nxt);
            q.push(nxt);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int n;
    while (cin >> n && n != 0) {
        set<Cube> unique_types;
        for (int i = 0; i < n; ++i) {
            Cube c(6);
            if (!(cin >> c[0])) break;
            for (int j = 1; j <= 4; ++j) cin >> c[j];
            cin >> c[5];
            
            Cube best;
            bool first = true;
            for (const auto& p : perms) {
                Cube rotated(6);
                for (int k = 0; k < 6; ++k) {
                    rotated[k] = c[p[k]];
                }
                if (first || rotated < best) {
                    best = rotated;
                    first = false;
                }
            }
            unique_types.insert(best);
        }
        cout << unique_types.size() << "\n";
    }
    return 0;
}