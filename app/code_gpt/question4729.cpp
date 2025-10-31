/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

void shoot(vector<int>& balls, int pos, int value) {
    pos--; // Transformar para index base 0
    balls.insert(balls.begin() + pos, value);
    int left = pos - 1, right = pos + 1;
    bool destroyed = false;

    // Verifica e destrói a sequência à esquerda
    while (left >= 0 && balls[left] == value) {
        destroyed = true;
        balls.erase(balls.begin() + left);
        left--;
    }
    
    // Verifica e destrói a sequência à direita
    while (right < balls.size() && balls[right] == value) {
        destroyed = true;
        balls.erase(balls.begin() + right);
    }

    if (!destroyed) {
        balls.insert(balls.begin() + pos, value);
    }
}

int main() {
    int n, m;
    cin >> n;
    vector<int> balls(n);
    
    for (int i = 0; i < n; i++) {
        cin >> balls[i];
    }
    
    cin >> m;
    for (int i = 0; i < m; i++) {
        int pos, value;
        cin >> pos >> value;
        shoot(balls, pos, value);
    }

    for (int i = 0; i < balls.size(); i++) {
        cout << balls[i] << (i < balls.size() - 1 ? " " : "");
    }
    cout << endl;

    return 0;
}
