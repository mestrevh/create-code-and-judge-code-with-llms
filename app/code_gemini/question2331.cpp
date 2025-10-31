/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

bool solveLabyrinth(int lab[10][10], int r, int c, bool visited[10][10]) {
    if (r < 0 || r >= 10 || c < 0 || c >= 10 || lab[r][c] == 0 || visited[r][c]) {
        return false;
    }

    if (r == 9 && c == 9) {
        return true;
    }

    visited[r][c] = true;

    // South
    if (solveLabyrinth(lab, r + 1, c, visited)) {
        return true;
    }

    // East
    if (solveLabyrinth(lab, r, c + 1, visited)) {
        return true;
    }

    // North
    if (solveLabyrinth(lab, r - 1, c, visited)) {
        return true;
    }

    // West
    if (solveLabyrinth(lab, r, c - 1, visited)) {
        return true;
    }

    return false;
}

bool solveLabyrinthGreedy(int lab[10][10], int r, int c, bool visited[10][10]) {
    if (r < 0 || r >= 10 || c < 0 || c >= 10 || lab[r][c] == 0 || visited[r][c]) {
        return false;
    }

    if (r == 9 && c == 9) {
        return true;
    }

    visited[r][c] = true;
    
    int next_r, next_c;

    // South
    next_r = r + 1; next_c = c;
    if (next_r < 10 && lab[next_r][next_c] == 1 && !visited[next_r][next_c]) {
        return solveLabyrinthGreedy(lab, next_r, next_c, visited);
    }

    // East
    next_r = r; next_c = c + 1;
    if (next_c < 10 && lab[next_r][next_c] == 1 && !visited[next_r][next_c]) {
        return solveLabyrinthGreedy(lab, next_r, next_c, visited);
    }

    // North
    next_r = r - 1; next_c = c;
    if (next_r >= 0 && lab[next_r][next_c] == 1 && !visited[next_r][next_c]) {
        return solveLabyrinthGreedy(lab, next_r, next_c, visited);
    }
    
    // West
    next_r = r; next_c = c - 1;
    if (next_c >= 0 && lab[next_r][next_c] == 1 && !visited[next_r][next_c]) {
        return solveLabyrinthGreedy(lab, next_r, next_c, visited);
    }

    return false;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Ja nao se pode confiar nos refens como antigamente...\n";
        return 0;
    }

    std::vector<int> counts(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int claim;
        std::cin >> claim;
        if (claim >= 0 && claim <= n) {
            counts[claim]++;
        }
    }

    bool truth_found = false;
    for (int k = 1; k <= n; ++k) {
        if (counts[k] == k) {
            truth_found = true;
            break;
        }
    }

    if (truth_found) {
        std::cout << "Vamo nessa, temos que sair rapido...\n";

        int labyrinth[10][10];
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                std::cin >> labyrinth[i][j];
            }
        }

        bool visited[10][10] = {false};

        if (solveLabyrinthGreedy(labyrinth, 0, 0, visited)) {
            std::cout << "Tudo nosso.\n";
        } else {
            std::cout << "Continuem cavando!\n";
        }

    } else {
        std::cout << "Ja nao se pode confiar nos refens como antigamente...\n";
    }

    return 0;
}
