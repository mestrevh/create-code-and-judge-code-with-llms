/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

bool isValidFirst(int h, int m) {
    return h < 12; 
}

bool isValidSecond(int h1, int m1, int h2, int m2) {
    return (h2 == h1 + 3 && m2 == m1 + 12) || (h2 == h1 + 3 && m2 == m1 + 12 - 60);
}

bool isValidThird(int h2, int m2, int h3, int m3) {
    return (h3 == h2 + 23 && m3 == m2 + 0) || (h3 == h2 + 22 && m3 == m2 + 60) || (h3 == h2 + 24 && m3 == m2);
}

int main() {
    vector<int> hours(6);
    for (int i = 0; i < 6; i++) {
        cin >> hours[i];
    }

    char result[4];
    result[0] = isValidFirst(hours[0], hours[1]) ? 'v' : 'f';
    if (result[0] == 'v') {
        result[1] = isValidSecond(hours[0], hours[1], hours[2], hours[3]) ? 'v' : 'f';
        if (result[1] == 'v') {
            result[2] = isValidThird(hours[2], hours[3], hours[4], hours[5]) ? 'v' : 'f';
        } else {
            result[2] = 'f';
        }
    } else {
        result[1] = 'f';
        result[2] = 'f';
    }

    for (int i = 0; i < 3; i++) {
        cout << result[i] << endl;
    }

    cout << (result[0] == 'v' && result[1] == 'v' && result[2] == 'v' ? "sucesso" : "falha") << endl;

    return 0;
}
