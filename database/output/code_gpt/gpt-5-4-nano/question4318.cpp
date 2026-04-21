/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static int lettersCount(const string& s) {
    int cnt = 0;
    for (char c : s) if (isalpha((unsigned char)c)) cnt++;
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    int m;
    long double X;
    cin >> m >> X;

    struct Person {
        string name;
        long double val;
        long double diff;
        int tie;
    };

    vector<Person> v;
    v.reserve(n);

    for (int i = 0; i < n; i++) {
        string name;
        long double age, height;
        cin >> name >> age >> height;
        int L = lettersCount(name);
        long double val = age * height * (long double)L;
        long double diff = fabsl(val - X);
        v.push_back({name, val, diff, i});
    }

    sort(v.begin(), v.end(), [](const Person& a, const Person& b) {
        if (a.diff != b.diff) return a.diff < b.diff;
        if (a.val != b.val) return a.val < b.val;
        return a.tie < b.tie;
    });

    int k = min(m, n);
    for (int i = 0; i < k; i++) {
        cout << v[i].name << "\n";
    }
    return 0;
}