/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool isValidSudoku(const array<array<int,9>,9>& a){
    for(int i=0;i<9;i++){
        array<bool,10> seen{};
        for(int j=0;j<9;j++){
            int x=a[i][j];
            if(x<1||x>9||seen[x]) return false;
            seen[x]=true;
        }
    }
    for(int j=0;j<9;j++){
        array<bool,10> seen{};
        for(int i=0;i<9;i++){
            int x=a[i][j];
            if(x<1||x>9||seen[x]) return false;
            seen[x]=true;
        }
    }
    for(int br=0;br<3;br++){
        for(int bc=0;bc<3;bc++){
            array<bool,10> seen{};
            for(int i=br*3;i<br*3+3;i++){
                for(int j=bc*3;j<bc*3+3;j++){
                    int x=a[i][j];
                    if(x<1||x>9||seen[x]) return false;
                    seen[x]=true;
                }
            }
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if(!(cin>>n)) return 0;

    for(int tc=1; tc<=n; tc++){
        array<array<int,9>,9> a{};
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cin >> a[i][j];
            }
        }

        bool ok=isValidSudoku(a);

        cout << "Instancia " << tc << "\n";
        cout << (ok ? "SIM" : "NAO") << "\n\n";
    }
    return 0;
}