/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> grid(101, vector<int>(101, 0));

    for (int i = 0; i < N; ++i) {
        int Xi, Xf, Yi, Yf;
        cin >> Xi >> Xf >> Yi >> Yf;
        for (int x = Xi; x <= Xf; ++x) {
            for (int y = Yi; y <= Yf; ++y) {
                grid[x][y] = 1;
            }
        }
    }

    int area = 0;
    for (int x = 1; x <= 100; ++x) {
        for (int y = 1; y <= 100; ++y) {
            area += grid[x][y];
        }
    }

    cout << area << endl;
    return 0;
}
