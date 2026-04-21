/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> ans;
    for (int x = 1500; x <= 2700; x++) {
        if (x % 7 == 0 && x % 5 == 0) ans.push_back(x);
    }
    for (size_t i = 0; i < ans.size(); i++) {
        if (i) cout << ",";
        cout << ans[i];
    }
    return 0;
}