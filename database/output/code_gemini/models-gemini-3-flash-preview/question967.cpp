/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n) {
        // Drawing the leaf part of the tree
        // The pattern starts at width 1 and goes up to width N
        for (int w = 1; w <= n; w += 2) {
            int dashes = (n - w) / 2;
            for (int i = 0; i < dashes; ++i) cout << '-';
            for (int i = 0; i < w; ++i) cout << '*';
            for (int i = 0; i < dashes; ++i) cout << '-';
            cout << '\n';
        }

        // Calculating leaf height (number of rows in the leaf part)
        int h = (n + 1) / 2;

        // Trunk calculation: trunk base size B is the first odd integer >= leaf height
        int b = (h % 2 != 0) ? h : h + 1;

        // Drawing the trunk part
        // The trunk follows the leaf pattern but ends at width B - 2
        for (int w = 1; w <= b - 2; w += 2) {
            int dashes = (n - w) / 2;
            for (int i = 0; i < dashes; ++i) cout << '-';
            for (int i = 0; i < w; ++i) cout << '*';
            for (int i = 0; i < dashes; ++i) cout << '-';
            cout << '\n';
        }

        // Blank line after each tree
        cout << '\n';
    }

    return 0;
}