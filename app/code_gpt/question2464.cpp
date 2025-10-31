/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canPass(const vector<int>& obstacles, int jump) {
    int position = 0;
    for (int obs : obstacles) {
        while (position + jump < obs) {
            position++;
        }
        if (position == obs) return false;
        position = obs;
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> obstacles(N);
    for (int i = 0; i < N; i++) {
        cin >> obstacles[i];
    }

    vector<int> field(5001, 0);
    for (int obs : obstacles) {
        field[obs] = 1;
    }

    for (int i = 0; i < field.size(); i++) {
        cout << field[i];
    }
    cout << endl;

    int minJump = 1;
    while (!canPass(obstacles, minJump)) {
        minJump++;
    }

    cout << "Pulo minimo: " << minJump << endl;

    return 0;
}
