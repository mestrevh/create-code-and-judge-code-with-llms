/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int knight, archer, prisoner, dog;
    cin >> knight >> archer >> prisoner >> dog;

    vector<int> actions(4, 0);

    if (knight == 0) {
        actions[0] = 1;
    }

    if (knight == 1 || archer == 1) {
        actions[1] = 1;
    }

    if (prisoner == 1 && archer == 0) {
        actions[2] = 1;
    }

    if (dog == 1 && archer == 0) {
        actions[3] = 1;
    } else if (dog == 0 && prisoner == 1 && knight == 0 && archer == 0) {
        actions[3] = 1;
    }

    for (int i = 0; i < 4; ++i) {
        cout << actions[i] << (i == 3 ? "" : " ");
    }
    cout << endl;

    return 0;
}
