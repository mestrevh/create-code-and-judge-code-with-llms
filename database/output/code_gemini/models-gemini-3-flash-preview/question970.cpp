/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string a, b;
int p[300];
bool f = false;

void solve(int ia, int ib) {
    if (ib == (int)b.size()) {
        f = true;
        for (int i = 0; i < (int)b.size(); i++) {
            if (i > 0) cout << " ";
            cout << p[i];
        }
        cout << "\n";
        return;
    }
    
    int rb = (int)b.size() - ib;
    int ra = (int)a.size() - ia;
    if (ra < rb) return;
    
    for (int i = ia; i <= (int)a.size() - rb; i++) {
        if (a[i] == b[ib]) {
            p[ib] = i + 1;
            solve(i + 1, ib + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!getline(cin, a)) return 0;
    if (!getline(cin, b)) return 0;

    while (!a.empty() && (a.back() == '\r' || a.back() == '\n')) {
        a.pop_back();
    }
    while (!b.empty() && (b.back() == '\r' || b.back() == '\n')) {
        b.pop_back();
    }

    if (!b.empty()) {
        solve(0, 0);
    }

    if (!f) {
        cout << -1 << "\n";
    }

    return 0;
}