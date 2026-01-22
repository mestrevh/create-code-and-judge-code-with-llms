/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Cube {
public:
    vector<vector<int>> faces;

    Cube() {
        faces = {
            {0, 0, 0},
            {1, 1, 1},
            {2, 2, 2},
            {3, 3, 3},
            {4, 4, 4},
            {5, 5, 5}
        };
    }

    void rotate(char move) {
        switch (move) {
            case 'U': rotateU(); break;
            case 'D': rotateD(); break;
            case 'L': rotateL(); break;
            case 'R': rotateR(); break;
            case 'F': rotateF(); break;
            case 'B': rotateB(); break;
        }
    }

private:
    void rotateU() {
        rotateFace(0);
        int temp[3];
        for (int i = 0; i < 3; i++) temp[i] = faces[1][i];
        for (int i = 0; i < 3; i++) faces[1][i] = faces[4][i];
        for (int i = 0; i < 3; i++) faces[4][i] = faces[3][i];
        for (int i = 0; i < 3; i++) faces[3][i] = faces[2][i];
        for (int i = 0; i < 3; i++) faces[2][i] = temp[i];
    }

    void rotateD() {
        rotateFace(5);
        int temp[3];
        for (int i = 0; i < 3; i++) temp[i] = faces[1][i];
        for (int i = 0; i < 3; i++) faces[1][i] = faces[2][i];
        for (int i = 0; i < 3; i++) faces[2][i] = faces[3][i];
        for (int i = 0; i < 3; i++) faces[3][i] = faces[4][i];
        for (int i = 0; i < 3; i++) faces[4][i] = temp[i];
    }

    void rotateL() {
        rotateFace(1);
        int temp[3];
        for (int i = 0; i < 3; i++) temp[i] = faces[0][i];
        for (int i = 0; i < 3; i++) faces[0][i] = faces[5][2-i];
        for (int i = 0; i < 3; i++) faces[5][2-i] = faces[2][i];
        for (int i = 0; i < 3; i++) faces[2][i] = faces[4][i];
        for (int i = 0; i < 3; i++) faces[4][i] = temp[i];
    }

    void rotateR() {
        rotateFace(3);
        int temp[3];
        for (int i = 0; i < 3; i++) temp[i] = faces[0][i];
        for (int i = 0; i < 3; i++) faces[0][i] = faces[4][i];
        for (int i = 0; i < 3; i++) faces[4][i] = faces[2][2-i];
        for (int i = 0; i < 3; i++) faces[2][2-i] = faces[5][i];
        for (int i = 0; i < 3; i++) faces[5][i] = temp[i];
    }

    void rotateF() {
        rotateFace(2);
        int temp[3];
        for (int i = 0; i < 3; i++) temp[i] = faces[0][i];
        for (int i = 0; i < 3; i++) faces[0][i] = faces[1][i];
        for (int i = 0; i < 3; i++) faces[1][i] = faces[5][2-i];
        for (int i = 0; i < 3; i++) faces[5][2-i] = faces[3][i];
        for (int i = 0; i < 3; i++) faces[3][i] = temp[i];
    }

    void rotateB() {
        rotateFace(4);
        int temp[3];
        for (int i = 0; i < 3; i++) temp[i] = faces[0][i];
        for (int i = 0; i < 3; i++) faces[0][i] = faces[3][i];
        for (int i = 0; i < 3; i++) faces[3][i] = faces[5][i];
        for (int i = 0; i < 3; i++) faces[5][i] = faces[1][2-i];
        for (int i = 0; i < 3; i++) faces[1][2-i] = temp[i];
    }

    void rotateFace(int idx) {
        int temp = faces[idx][0];
        faces[idx][0] = faces[idx][2];
        faces[idx][2] = faces[idx][1];
        faces[idx][1] = faces[idx][0];
    }
    
public:
    void print() {
        for (auto &face : faces) {
            for (int color : face) {
                cout << color;
            }
            cout << endl;
        }
    }
};

int main() {
    Cube cube;
    string input;
    getline(cin, input);
    stringstream ss(input);
    char move;

    while (ss >> move) {
        cube.rotate(move);
    }

    cube.print();
    return 0;
}
