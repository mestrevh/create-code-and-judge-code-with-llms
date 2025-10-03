/*
Código criado pelo modelo gemini-2.5-pro
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int oldest, middle, youngest;
    oldest = max({a, b, c});
    youngest = min({a, b, c});
    middle = a + b + c - oldest - youngest;
    cout << middle << endl;
    return 0;
}
