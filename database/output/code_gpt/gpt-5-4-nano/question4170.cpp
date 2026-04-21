/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> a(10);
    for (int i = 0; i < 10; i++) {
        if (!(cin >> a[i])) return 0;
    }

    long long last = a.back();
    int cntLast = 0, cntEven = 0, cntDiv3 = 0;
    long long sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += a[i];
        if (a[i] == last) cntLast++;
        if (a[i] % 2 == 0) cntEven++;
        if (a[i] % 3 == 0) cntDiv3++;
    }

    double media = sum / 10.0;

    vector<long long> greater;
    for (int i = 0; i < 10; i++) {
        if ((double)a[i] > media) greater.push_back(a[i]);
    }

    cout << fixed << setprecision(1);
    cout << "Media: " << media << "\n";
    cout << "Ultimo numero: " << cntLast << "\n";
    cout << "Pares: " << cntEven << "\n";
    cout << "Divisiveis por 3: " << cntDiv3 << "\n";

    cout << "Lista maiores que a media: [";
    for (size_t i = 0; i < greater.size(); i++) {
        if (i) cout << ", ";
        cout << greater[i];
    }
    cout << "]\n";

    return 0;
}