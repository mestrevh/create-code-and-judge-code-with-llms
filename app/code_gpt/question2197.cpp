/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, char>> pedaços(N);
    
    for (int i = 0; i < N; i++) {
        cin >> pedaços[i].first >> pedaços[i].second;
    }
    
    sort(pedaços.begin(), pedaços.end());
    
    for (const auto& p : pedaços) {
        cout << p.second;
    }
    
    cout << endl;
    return 0;
}
