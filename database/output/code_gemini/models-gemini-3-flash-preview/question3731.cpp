/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int get_next_prime(int n) {
    int p = n + 1;
    while (!is_prime(p)) p++;
    return p;
}

int get_sum_digits(int n) {
    int s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

long long get_sum_m6(int n) {
    long long k = (n - 1) / 6;
    if (k <= 0) return 0;
    return 3LL * k * (k + 1);
}

void MudancaDeLivros(int *codigo, int *posicao) {
    int oldC = *codigo;
    int oldP = *posicao;
    
    int nP = get_next_prime(oldC);
    int sD = get_sum_digits(oldC);
    *codigo = (oldC + nP) / sD;
    
    long long s6 = get_sum_m6(oldC);
    long long diff = s6 - oldP;
    if (diff < 0) diff = -diff;
    *posicao = (int)diff;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m, n;
    vector<pair<int, int>> inputs;
    while (cin >> m >> n && m != 0) {
        inputs.push_back({m, n});
    }
    
    int sz = inputs.size();
    if (sz == 0) return 0;
    
    vector<int> finalCodes(sz);
    vector<int> finalPositions(sz);
    
    for (int i = 0; i < sz; ++i) {
        int c = inputs[i].first;
        int p = inputs[i].second;
        
        MudancaDeLivros(&c, &p);
        
        bool conflict;
        do {
            conflict = false;
            for (int j = 0; j < i; ++j) {
                if (c == finalCodes[j]) {
                    c++;
                    conflict = true;
                    break;
                }
            }
        } while (conflict);
        
        do {
            conflict = false;
            for (int j = 0; j < i; ++j) {
                if (p == finalPositions[j]) {
                    p++;
                    conflict = true;
                    break;
                }
            }
        } while (conflict);
        
        finalCodes[i] = c;
        finalPositions[i] = p;
    }
    
    for (int i = sz - 1; i >= 0; --i) {
        cout << finalCodes[i] << " - " << finalPositions[i] << "\n";
    }
    
    return 0;
}