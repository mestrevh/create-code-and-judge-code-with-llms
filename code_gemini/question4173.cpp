/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<std::vector<int>>> cube(6, std::vector<std::vector<int>>(3, std::vector<int>(3)));

void initialize_cube() {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                cube[i][j][k] = i;
            }
        }
    }
}

void rotate_face_clockwise(int face_idx) {
    std::vector<std::vector<int>> temp = cube[face_idx];
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            cube[face_idx][r][c] = temp[2 - c][r];
        }
    }
}

void move_U() {
    rotate_face_clockwise(1);
    std::vector<int> temp_row(3);
    for (int i = 0; i < 3; ++i) temp_row[i] = cube[2][0][i]; // F
    for (int i = 0; i < 3; ++i) cube[2][0][i] = cube[3][0][i]; // R -> F
    for (int i = 0; i < 3; ++i) cube[3][0][i] = cube[5][0][i]; // B -> R
    for (int i = 0; i < 3; ++i) cube[5][0][i] = cube[0][0][i]; // L -> B
    for (int i = 0; i < 3; ++i) cube[0][0][i] = temp_row[i]; // F -> L
}

void move_D() {
    rotate_face_clockwise(4);
    std::vector<int> temp_row(3);
    for (int i = 0; i < 3; ++i) temp_row[i] = cube[2][2][i]; // F
    for (int i = 0; i < 3; ++i) cube[2][2][i] = cube[0][2][i]; // L -> F
    for (int i = 0; i < 3; ++i) cube[0][2][i] = cube[5][2][i]; // B -> L
    for (int i = 0; i < 3; ++i) cube[5][2][i] = cube[3][2][i]; // R -> B
    for (int i = 0; i < 3; ++i) cube[3][2][i] = temp_row[i]; // F -> R
}

void move_F() {
    rotate_face_clockwise(2);
    int t0 = cube[1][2][0], t1 = cube[1][2][1], t2 = cube[1][2][2];
    cube[1][2][0] = cube[3][2][0]; cube[1][2][1] = cube[3][1][0]; cube[1][2][2] = cube[3][0][0];
    cube[3][0][0] = cube[4][0][2]; cube[3][1][0] = cube[4][0][1]; cube[3][2][0] = cube[4][0][0];
    cube[4][0][0] = cube[0][0][2]; cube[4][0][1] = cube[0][1][2]; cube[4][0][2] = cube[0][2][2];
    cube[0][0][2] = t0; cube[0][1][2] = t1; cube[0][2][2] = t2;
}

void move_R() {
    rotate_face_clockwise(3);
    int t0 = cube[1][0][2], t1 = cube[1][1][2], t2 = cube[1][2][2];
    cube[1][0][2] = cube[2][0][2]; cube[1][1][2] = cube[2][1][2]; cube[1][2][2] = cube[2][2][2];
    cube[2][0][2] = cube[4][0][2]; cube[2][1][2] = cube[4][1][2]; cube[2][2][2] = cube[4][2][2];
    cube[4][0][2] = cube[5][2][0]; cube[4][1][2] = cube[5][1][0]; cube[4][2][2] = cube[5][0][0];
    cube[5][0][0] = t2; cube[5][1][0] = t1; cube[5][2][0] = t0;
}

void move_L() {
    rotate_face_clockwise(0);
    int t0 = cube[1][0][0], t1 = cube[1][1][0], t2 = cube[1][2][0];
    cube[1][0][0] = cube[5][2][2]; cube[1][1][0] = cube[5][1][2]; cube[1][2][0] = cube[5][0][2];
    cube[5][0][2] = cube[4][2][0]; cube[5][1][2] = cube[4][1][0]; cube[5][2][2] = cube[4][0][0];
    cube[4][0][0] = cube[2][0][0]; cube[4][1][0] = cube[2][1][0]; cube[4][2][0] = cube[2][2][0];
    cube[2][0][0] = t0; cube[2][1][0] = t1; cube[2][2][0] = t2;
}

void move_B() {
    rotate_face_clockwise(5);
    int t0 = cube[1][0][0], t1 = cube[1][0][1], t2 = cube[1][0][2];
    cube[1][0][0] = cube[0][2][0]; cube[1][0][1] = cube[0][1][0]; cube[1][0][2] = cube[0][0][0];
    cube[0][0][0] = cube[4][2][0]; cube[0][1][0] = cube[4][2][1]; cube[0][2][0] = cube[4][2][2];
    cube[4][2][0] = cube[3][2][2]; cube[4][2][1] = cube[3][1][2]; cube[4][2][2] = cube[3][0][2];
    cube[3][0][2] = t0; cube[3][1][2] = t1; cube[3][2][2] = t2;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    initialize_cube();

    char M, D;
    while (std::cin >> M >> D) {
        int times = (D == 'R') ? 1 : 3;
        for (int i = 0; i < times; ++i) {
            switch (M) {
                case 'U': move_U(); break;
                case 'D': move_D(); break;
                case 'F': move_F(); break;
                case 'B': move_B(); break;
                case 'R': move_R(); break;
                case 'L': move_L(); break;
            }
        }
    }
    
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                std::cout << cube[i][j][k];
            }
            std::cout << '\n';
        }
        if (i < 5) {
            std::cout << '\n';
        }
    }

    return 0;
}
