/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Tri {
    int a, b, c;
    double area;
};

void calculaArea(int a, int b, int c, double *area) {
    double s = (a + b + c) / 2.0;
    *area = sqrt(max(0.0, s * (s - a) * (s - b) * (s - c)));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<Tri> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i].a >> t[i].b >> t[i].c;
        double ar;
        calculaArea(t[i].a, t[i].b, t[i].c, &ar);
        t[i].area = ar;
    }

    sort(t.begin(), t.end(), [](const Tri& x, const Tri& y) {
        if (x.area != y.area) return x.area < y.area;
        if (x.a != y.a) return x.a < y.a;
        if (x.b != y.b) return x.b < y.b;
        return x.c < y.c;
    });

    for (int i = 0; i < n; i++) {
        cout << t[i].a << ' ' << t[i].b << ' ' << t[i].c << "\n";
    }
    return 0;
}