/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

string buscaMaior(int l, int r, const vector<long long>& nums, long long& maior) {
    if (l == r) {
        maior = nums[l];
        return "";
    }
    int mid = (l + r) / 2;
    long long maiorEsq = 0, maiorDir = 0;
    buscaMaior(l, mid, nums, maiorEsq);
    buscaMaior(mid + 1, r, nums, maiorDir);
    maior = max(maiorEsq, maiorDir);
    return "";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<string> names(N);
    vector<long long> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> names[i] >> nums[i];
    }

    long long maior = 0;
    function<void(int,int)> rec = [&](int l, int r) {
        if (l == r) {
            maior = max(maior, nums[l]);
            return;
        }
        int mid = (l + r) / 2;
        rec(l, mid);
        rec(mid + 1, r);
    };
    rec(0, N - 1);

    bool temAlison = false;
    long long maxAparece = maior;
    for (int i = 0; i < N; i++) {
        if (names[i] == "Alison" && nums[i] == maxAparece) {
            temAlison = true;
            break;
        }
    }

    if (temAlison) {
        cout << "Ela nao tentou bancar a espertinha de novo!";
    } else {
        cout << "ELA ROUBOU DE NOVO! TODOS ATRAS DE ALISON! O maior numero na parede e " << maxAparece << "!";
    }

    return 0;
}