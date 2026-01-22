/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> knows(n, vector<int>(n));
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> knows[i][j];

    int celeb = 0;

    for (int i = 1; i < n; i++) {
        if (knows[celeb][i] == 1) 
            celeb = i; 
    }

    bool isCeleb = true;
    for (int i = 0; i < n; i++) {
        if (i != celeb) {
            if (knows[celeb][i] == 1 || knows[i][celeb] == 0) {
                isCeleb = false;
                break;
            }
        }
    }

    if (isCeleb)
        cout << celeb << endl;
    else
        cout << "NAO HA CELEBRIDADE" << endl;

    return 0;
}
