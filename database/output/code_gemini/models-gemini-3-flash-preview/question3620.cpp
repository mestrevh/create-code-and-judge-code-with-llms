/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

void derivada(int *coeficiente, int *expoente) {
    *coeficiente = (*coeficiente) * (*expoente);
    if (*expoente > 0) {
        (*expoente) = (*expoente) - 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    while (cin >> n && n != 0) {
        vector<int> coefs(n);
        vector<char> vars(n);
        vector<int> exps(n);
        
        char main_var = '0';
        bool found_var = false;
        
        for (int i = 0; i < n; i++) {
            cin >> coefs[i] >> vars[i] >> exps[i];
            if (!found_var && vars[i] != '0') {
                main_var = vars[i];
                found_var = true;
            }
        }
        
        if (!found_var) {
            main_var = '0';
        }
        
        for (int i = 0; i < n; i++) {
            derivada(&coefs[i], &exps[i]);
        }
        
        cout << "f'(" << main_var << ")=";
        
        bool any_printed = false;
        for (int i = 0; i < n; i++) {
            if (coefs[i] != 0) {
                if (coefs[i] > 0) {
                    cout << "+";
                } else {
                    cout << "-";
                }
                
                int val = coefs[i] < 0 ? -coefs[i] : coefs[i];
                cout << val;
                
                if (exps[i] > 0) {
                    cout << vars[i] << "^" << exps[i];
                }
                any_printed = true;
            }
        }
        
        if (!any_printed) {
            cout << "0";
        }
        cout << "\n";
    }
    
    return 0;
}