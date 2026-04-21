/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i;
    if (!(cin >> i)) return 0;

    int b0 = (i >> 0) & 1;
    int b1 = (i >> 1) & 1;
    int b2 = (i >> 2) & 1;
    int b3 = (i >> 3) & 1;

    int p1 = b0;
    int p2 = b1;
    int p3 = !b2;
    int p4 = b2 ^ b3;

    const char* colors[] = {"rosa", "verde"};

    cout << colors[p1] << " " << colors[p2] << " " << colors[p3] << " " << colors[p4] << "\n";

    return 0;
}