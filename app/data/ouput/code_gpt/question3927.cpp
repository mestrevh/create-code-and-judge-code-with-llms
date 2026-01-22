/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<pair<int, int>> vitores(4), lk(3);
    vector<int> jogadas(3);
    
    for (int i = 0; i < 4; ++i) {
        cin >> vitores[i].first >> vitores[i].second;
    }
    
    for (int i = 0; i < 3; ++i) {
        cin >> lk[i].first >> lk[i].second;
    }
    
    for (int i = 0; i < 3; ++i) {
        cin >> jogadas[i];
    }
    
    vector<bool> usado(3, false);
    
    for (int i = 0; i < 3; ++i) {
        int j = jogadas[i];
        int x = vitores[j].first, y = vitores[j].second;
        for (int k = 0; k < 3; ++k) {
            if (!usado[k] && (lk[k].first == x || lk[k].first == y || lk[k].second == x || lk[k].second == y)) {
                cout << lk[k].first << "-" << lk[k].second << " " << (k + 1) << endl;
                usado[k] = true;
                break;
            }
        }
    }
    
    return 0;
}
