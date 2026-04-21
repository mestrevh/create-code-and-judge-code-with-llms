/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double D;
    if (!(cin >> D)) return 0;

    int N;
    cin >> N;

    struct Item {
        string name;
        long long cents;
    };

    vector<Item> items(N);
    for (int i = 0; i < N; i++) {
        string name;
        string priceStr;
        cin >> name >> priceStr;

        bool neg = false;
        if (!priceStr.empty() && priceStr[0] == '-') {
            neg = true;
            priceStr = priceStr.substr(1);
        }

        string a, b;
        size_t pos = priceStr.find('.');
        if (pos == string::npos) {
            a = priceStr;
            b = "0";
        } else {
            a = priceStr.substr(0, pos);
            b = priceStr.substr(pos + 1);
        }

        long long intPart = 0;
        if (!a.empty()) intPart = stoll(a);
        long long frac = 0;
        if (b.empty()) frac = 0;
        else if (b.size() == 1) frac = stoll(b) * 10;
        else {
            string first2 = b.substr(0, 2);
            frac = stoll(first2);
        }

        long long cents = intPart * 100 + frac;
        if (neg) cents = -cents;

        items[i] = {name, cents};
    }

    long long budget = llround(D * 100.0);

    vector<Item> sorted = items;
    sort(sorted.begin(), sorted.end(), [](const Item& x, const Item& y){
        if (x.cents != y.cents) return x.cents < y.cents;
        return x.name < y.name;
    });

    long long sum = 0;
    vector<Item> chosen;
    for (const auto& it : sorted) {
        if (sum + it.cents <= budget) {
            sum += it.cents;
            chosen.push_back(it);
        }
    }

    sort(chosen.begin(), chosen.end(), [](const Item& x, const Item& y){
        return x.name < y.name;
    });

    cout.setf(std::ios::fixed);
    cout << setprecision(2);

    for (size_t i = 0; i < chosen.size(); i++) {
        double price = chosen[i].cents / 100.0;
        cout << chosen[i].name << ' ' << price;
        if (i + 1 < chosen.size()) cout << "\n";
    }

    long long trocoCents = budget - sum;
    double troco = trocoCents / 100.0;
    if (!chosen.empty()) cout << "\n";
    cout << troco;

    return 0;
}