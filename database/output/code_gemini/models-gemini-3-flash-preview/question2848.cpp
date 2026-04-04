/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int distance;
    if (cin >> distance) {
        int time = distance * 2;
        cout << time << " minutos" << endl;
    }

    return 0;
}