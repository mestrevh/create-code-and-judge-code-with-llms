/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if(!(cin >> s)) return 0;
    int n = 0, m = 0;
    {
        string t = s;
        for(char &c : t) if(c=='x' || c=='X') c=' ';
        stringstream ss(t);
        ss >> n >> m;
    }

    if(m % 2 == 0) {
        cout << "Nao posso construir nessas proporcoes";
        return 0;
    }
    if(n < 2) {
        cout << "Nao posso construir nessas proporcoes";
        return 0;
    }

    vector<string> upper(n, string(m, '='));
    int mid = m/2;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            upper[i][j] = '=';
        }
    }

    int portSide = mid;
    if(n < 2) {
        cout << "Nao posso construir nessas proporcoes";
        return 0;
    }

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < m; j++) upper[i][j] = '=';
        upper[i][portSide] = 'H';
    }

    for(int i = 2; i < n; i++){
        for(int j = 0; j < m; j++) upper[i][j] = '=';
    }

    for(int i = 0; i < n; i++){
        bool windowsOnThisFloor = (i % 2 == 1); 
        if(i < 2) windowsOnThisFloor = false;
        if(windowsOnThisFloor){
            for(int j = 0; j < m; j++){
                if(j % 2 == 1 && j != portSide) upper[i][j] = 'o';
            }
        }
    }

    if(m < 3) {
        cout << "Nao posso construir nessas proporcoes";
        return 0;
    }

    for(int i = 0; i < 2; i++){
        if(upper[i][portSide] != 'H') {
            cout << "Nao posso construir nessas proporcoes";
            return 0;
        }
        for(int j = 0; j < m; j++){
            if(j == portSide && upper[i][j] == 'o') {
                cout << "Nao posso construir nessas proporcoes";
                return 0;
            }
        }
    }

    int foundationWidth = 2*m - 1;
    vector<string> foundation(1, string(foundationWidth, '-'));

    long long cost = 0;
    cost += 500;

    int totalWindows = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(upper[i][j] == 'o') totalWindows++;
        }
    }
    cost += 250LL * totalWindows;

    int totalMasonry = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(upper[i][j] == '=') totalMasonry++;
        }
    }
    cost += 85LL * totalMasonry;

    int totalFoundations = 2*m - 1;
    cost += 133LL * totalFoundations;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << upper[i][j] << (j+1<m ? ' ' : ' ');
        }
        cout << "\n";
    }
    cout << string(foundation[0]) << "\n\n";
    cout << "E o valor total eh " << cost;

    return 0;
}