/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    char x, y;

    if (cin >> a >> x >> b >> y >> c) {
        int result;
        // Rules: '^' is conjunction (AND), 'v' is disjunction (OR).
        // Precedence: '^' > 'v'.
        
        if (x == '^' && y == '^') {
            // Expression: (a ^ b) ^ c
            result = (a && b) && c;
        } else if (x == '^' && y == 'v') {
            // Expression: (a ^ b) v c
            result = (a && b) || c;
        } else if (x == 'v' && y == '^') {
            // Expression: a v (b ^ c)
            result = a || (b && c);
        } else {
            // Expression: (a v b) v c
            result = (a || b) || c;
        }

        cout << (result ? 1 : 0) << "\n";
    }

    return 0;
}