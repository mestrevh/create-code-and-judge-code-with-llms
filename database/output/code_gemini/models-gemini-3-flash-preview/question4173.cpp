/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int cube[6][3][3];

void rotateFace(int f, bool cw) {
    int temp[3][3];
    if (cw) {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                temp[j][2 - i] = cube[f][i][j];
    } else {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                temp[2 - j][i] = cube[f][i][j];
    }
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            cube[f][i][j] = temp[i][j];
}

void moveU(bool cw) {
    rotateFace(1, cw);
    int t[3];
    if (cw) {
        for(int i=0; i<3; ++i) t[i]=cube[0][0][i];
        for(int i=0; i<3; ++i) cube[0][0][i]=cube[3][0][i];
        for(int i=0; i<3; ++i) cube[3][0][i]=cube[5][0][i];
        for(int i=0; i<3; ++i) cube[5][0][i]=cube[2][0][i];
        for(int i=0; i<3; ++i) cube[2][0][i]=t[i];
    } else {
        for(int i=0; i<3; ++i) t[i]=cube[0][0][i];
        for(int i=0; i<3; ++i) cube[0][0][i]=cube[2][0][i];
        for(int i=0; i<3; ++i) cube[2][0][i]=cube[5][0][i];
        for(int i=0; i<3; ++i) cube[5][0][i]=cube[3][0][i];
        for(int i=0; i<3; ++i) cube[3][0][i]=t[i];
    }
}

void moveD(bool cw) {
    rotateFace(4, cw);
    int t[3];
    if (cw) {
        for(int i=0; i<3; ++i) t[i]=cube[0][2][i];
        for(int i=0; i<3; ++i) cube[0][2][i]=cube[2][2][i];
        for(int i=0; i<3; ++i) cube[2][2][i]=cube[5][2][i];
        for(int i=0; i<3; ++i) cube[5][2][i]=cube[3][2][i];
        for(int i=0; i<3; ++i) cube[3][2][i]=t[i];
    } else {
        for(int i=0; i<3; ++i) t[i]=cube[0][2][i];
        for(int i=0; i<3; ++i) cube[0][2][i]=cube[3][2][i];
        for(int i=0; i<3; ++i) cube[3][2][i]=cube[5][2][i];
        for(int i=0; i<3; ++i) cube[5][2][i]=cube[2][2][i];
        for(int i=0; i<3; ++i) cube[2][2][i]=t[i];
    }
}

void moveL(bool cw) {
    rotateFace(2, cw);
    int t[3];
    if (cw) {
        for(int i=0; i<3; ++i) t[i]=cube[0][i][0];
        for(int i=0; i<3; ++i) cube[0][i][0]=cube[1][i][0];
        for(int i=0; i<3; ++i) cube[1][i][0]=cube[5][2-i][2];
        for(int i=0; i<3; ++i) cube[5][2-i][2]=cube[4][i][0];
        for(int i=0; i<3; ++i) cube[4][i][0]=t[i];
    } else {
        for(int i=0; i<3; ++i) t[i]=cube[0][i][0];
        for(int i=0; i<3; ++i) cube[0][i][0]=cube[4][i][0];
        for(int i=0; i<3; ++i) cube[4][i][0]=cube[5][2-i][2];
        for(int i=0; i<3; ++i) cube[5][2-i][2]=cube[1][i][0];
        for(int i=0; i<3; ++i) cube[1][i][0]=t[i];
    }
}

void moveR(bool cw) {
    rotateFace(3, cw);
    int t[3];
    if (cw) {
        for(int i=0; i<3; ++i) t[i]=cube[0][i][2];
        for(int i=0; i<3; ++i) cube[0][i][2]=cube[4][i][2];
        for(int i=0; i<3; ++i) cube[4][i][2]=cube[5][2-i][0];
        for(int i=0; i<3; ++i) cube[5][2-i][0]=cube[1][i][2];
        for(int i=0; i<3; ++i) cube[1][i][2]=t[i];
    } else {
        for(int i=0; i<3; ++i) t[i]=cube[0][i][2];
        for(int i=0; i<3; ++i) cube[0][i][2]=cube[1][i][2];
        for(int i=0; i<3; ++i) cube[1][i][2]=cube[5][2-i][0];
        for(int i=0; i<3; ++i) cube[5][2-i][0]=cube[4][i][2];
        for(int i=0; i<3; ++i) cube[4][i][2]=t[i];
    }
}

void moveF(bool cw) {
    rotateFace(0, cw);
    int t[3];
    if (cw) {
        for(int i=0; i<3; ++i) t[i]=cube[1][2][i];
        for(int i=0; i<3; ++i) cube[1][2][i]=cube[2][2-i][2];
        for(int i=0; i<3; ++i) cube[2][2-i][2]=cube[4][0][2-i];
        for(int i=0; i<3; ++i) cube[4][0][2-i]=cube[3][i][0];
        for(int i=0; i<3; ++i) cube[3][i][0]=t[i];
    } else {
        for(int i=0; i<3; ++i) t[i]=cube[1][2][i];
        for(int i=0; i<3; ++i) cube[1][2][i]=cube[3][i][0];
        for(int i=0; i<3; ++i) cube[3][i][0]=cube[4][0][2-i];
        for(int i=0; i<3; ++i) cube[4][0][2-i]=cube[2][2-i][2];
        for(int i=0; i<3; ++i) cube[2][2-i][2]=t[i];
    }
}

void moveB(bool cw) {
    rotateFace(5, cw);
    int t[3];
    if (cw) {
        for(int i=0; i<3; ++i) t[i]=cube[1][0][i];
        for(int i=0; i<3; ++i) cube[1][0][i]=cube[3][i][2];
        for(int i=0; i<3; ++i) cube[3][i][2]=cube[4][2][2-i];
        for(int i=0; i<3; ++i) cube[4][2][2-i]=cube[2][2-i][0];
        for(int i=0; i<3; ++i) cube[2][2-i][0]=t[i];
    } else {
        for(int i=0; i<3; ++i) t[i]=cube[1][0][i];
        for(int i=0; i<3; ++i) cube[1][0][i]=cube[2][2-i][0];
        for(int i=0; i<3; ++i) cube[2][2-i][0]=cube[4][2][2-i];
        for(int i=0; i<3; ++i) cube[4][2][2-i]=cube[3][i][2];
        for(int i=0; i<3; ++i) cube[3][i][2]=t[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int f = 0; f < 6; ++f)
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                cube[f][i][j] = f;

    string move;
    while (cin >> move) {
        if (move.length() < 2) continue;
        char face = move[0];
        bool cw = (move[1] == 'R');
        if (face == 'U') moveU(cw);
        else if (face == 'D') moveD(cw);
        else if (face == 'L') moveL(cw);
        else if (face == 'R') moveR(cw);
        else if (face == 'F') moveF(cw);
        else if (face == 'B') moveB(cw);
    }

    for (int f = 0; f < 6; ++f) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << cube[f][i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}