/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long totalArea, tileArea;
    if (cin >> totalArea >> tileArea) {
        long long tilesNeeded = (totalArea + tileArea - 1) / tileArea;
        long long totalPrice = tilesNeeded * tileArea * 25;
        
        cout << tilesNeeded << " " << totalPrice << endl;
    }

    return 0;
}