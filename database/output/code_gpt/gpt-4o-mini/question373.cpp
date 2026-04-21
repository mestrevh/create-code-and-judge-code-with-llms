/*
Código criado pelo gpt-4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

bool canPreserveProject(int A1, int A2, int A3, int A4) {
    int areas[] = {A1, A2, A3, A4};
    sort(areas, areas + 4);
    return (areas[0] + areas[3] == areas[1] + areas[2]);
}

int main() {
    int A1, A2, A3, A4;
    cin >> A1 >> A2 >> A3 >> A4;
    if (canPreserveProject(A1, A2, A3, A4)) {
        cout << 'S' << endl;
    } else {
        cout << 'N' << endl;
    }
    return 0;
}