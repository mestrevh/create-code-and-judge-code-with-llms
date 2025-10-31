/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<vector<bool>> grid(501, vector<bool>(501, false));
        
        for (int i = 0; i < n; i++) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            for (int x = a; x < c; x++) {
                for (int y = b; y < d; y++) {
                    grid[x][y] = true;
                }
            }
        }

        int count = 0;
        for (int x = 0; x < 500; x++) {
            for (int y = 0; y < 500; y++) {
                if (grid[x][y]) count++;
            }
        }

        cout << count << endl;
    }
    return 0;
}
