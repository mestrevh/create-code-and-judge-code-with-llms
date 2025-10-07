/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

void floodFill(int x, int y, vector<vector<int>>& image) {
    if (x < 0 || x >= image.size() || y < 0 || y >= image[0].size() || image[x][y] == 0) return;
    image[x][y] = 0; // marca como visitado
    floodFill(x + 1, y, image);
    floodFill(x - 1, y, image);
    floodFill(x, y + 1, image);
    floodFill(x, y - 1, image);
}

int main() {
    int n, caseNumber = 1;
    while (cin >> n) {
        vector<vector<int>> image(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> image[i][j];

        int warEagles = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (image[i][j] == 1) {
                    floodFill(i, j, image);
                    warEagles++;
                }
            }
        }
        cout << "Image number " << caseNumber++ << " contains " << warEagles << " war eagles." << endl;
    }
    return 0;
}
