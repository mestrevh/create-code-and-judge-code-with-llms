/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int identify(int m[3][3]) {
    bool isP = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j) {
                if (m[i][j] != 1) isP = false;
            } else {
                if (m[i][j] != 0) isP = false;
            }
        }
    }
    if (isP) return 1;

    bool isS = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i + j == 2) {
                if (m[i][j] != 1) isS = false;
            } else {
                if (m[i][j] != 0) isS = false;
            }
        }
    }
    if (isS) return 2;

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long lukeLife, vaderLife;
    if (!(cin >> lukeLife >> vaderLife)) return 0;

    int mLuke[3][3];
    int mVader[3][3];

    while (cin >> mLuke[0][0]) {
        for (int j = 1; j < 3; ++j) cin >> mLuke[0][j];
        for (int i = 1; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cin >> mLuke[i][j];
            }
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cin >> mVader[i][j];
            }
        }

        int typeL = identify(mLuke);
        int typeV = identify(mVader);

        if (typeL != 0 && typeV == 0) {
            vaderLife -= 15;
        } else if (typeL == 0 && typeV != 0) {
            lukeLife -= 15;
        } else if (typeL != 0 && typeV != 0) {
            if (typeL == typeV) {
                lukeLife -= 15;
                vaderLife -= 15;
            }
        }
    }

    if (lukeLife > vaderLife) {
        cout << "Luke Skywalker venceu." << endl;
    } else if (vaderLife > lukeLife) {
        cout << "Darth Vader venceu." << endl;
    } else {
        cout << "Houve empate." << endl;
    }

    return 0;
}