/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool isUpperLetter(char c){ return c >= 'A' && c <= 'Z'; }
static bool isVowel(char c){
    return c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<char> a;
    a.reserve(3);

    string token;
    while (cin >> token) {
        for (char c : token) {
            if (!isspace((unsigned char)c)) {
                if ((int)a.size() < 3) a.push_back(c);
            }
        }
        if ((int)a.size() >= 3) break;
    }

    if ((int)a.size() < 3) return 0;

    bool hasInvalid = false;
    for (char c : a) if (!isUpperLetter(c)) hasInvalid = true;
    if (hasInvalid) {
        cout << "Etiquetas erradas!";
        return 0;
    }

    sort(a.begin(), a.end());

    vector<int> nums(3);
    for(int i=0;i<3;i++) nums[i]=a[i]-'A';

    int d1 = nums[1]-nums[0];
    int d2 = nums[2]-nums[1];

    bool sameDist = (d1 == d2);
    int dist = d1;

    bool perfectLike = (a[0] + dist == a[1] && a[1] + dist == a[2]);

    if (!sameDist || !perfectLike) {
        cout << "Só umas letras ai...";
        return 0;
    }

    bool allConsonants = true, hasVowel = false;
    for(char c: a){
        if (isVowel(c)) { allConsonants = false; hasVowel = true; }
    }

    if (dist == 1) {
        if (allConsonants) cout << "Sequência perfeita.";
        else cout << "Sequência quase perfeita.";
    } else if (dist == 2) {
        if (allConsonants) cout << "Bissequência perfeita.";
        else cout << "Bissequência quase perfeita.";
    } else if (dist == 3) {
        if (allConsonants) cout << "Trissequência perfeita.";
        else cout << "Trissequência quase perfeita.";
    } else {
        cout << "Só umas letras ai...";
    }

    return 0;
}