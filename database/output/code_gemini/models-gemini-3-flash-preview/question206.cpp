/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B, C;
    long long X, Y, Z;

    if (!(cin >> A >> B >> C)) return 0;
    if (!(cin >> X >> Y >> Z)) return 0;

    long long countX = X / A;
    long long countY = Y / B;
    long long countZ = Z / C;

    if (countX < 0) countX = 0;
    if (countY < 0) countY = 0;
    if (countZ < 0) countZ = 0;

    long long result = countX * countY * countZ;

    cout << result << endl;

    return 0;
}