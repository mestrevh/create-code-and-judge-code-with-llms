/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> in(4);
    for (int i = 0; i < 4; i++) {
        if (!(cin >> in[i])) return 0;
    }

    vector<string> s1 = {"Carne", "Bamboo", "Sal", "Ovo"};
    vector<string> s2 = {"Carne", "Bamboo", "Shoyu", "Ovo"};
    vector<string> s3 = {"Carne", "Bamboo", "Nori", "Ovo"};
    vector<string> s4 = {"Carne", "Cebolinha", "Kimushi", "Nori"};

    string name;
    string ans;
    int price = -1;

    if (in == s1) { name = "Naruto"; price = 500; }
    else if (in == s2) { name = "Luffy"; price = 475; }
    else if (in == s3) { name = "Kirito"; price = 450; }
    else if (in == s4) { name = "Misty"; price = 600; }

    if (price == -1) {
        cout << "Está tentando inventar um novo prato? O chef aqui sou eu!";
    } else {
        cout << name << " - ¥" << price;
    }
    return 0;
}