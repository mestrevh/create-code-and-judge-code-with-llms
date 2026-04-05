/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int count_a = 0;
    int count_e = 0;
    int count_i = 0;
    int count_o = 0;
    int count_u = 0;

    char c;
    while (cin.get(c)) {
        switch (c) {
            case 'a':
                count_a++;
                break;
            case 'e':
                count_e++;
                break;
            case 'i':
                count_i++;
                break;
            case 'o':
                count_o++;
                break;
            case 'u':
                count_u++;
                break;
            default:
                break;
        }
    }

    cout << "a " << count_a << "\n";
    cout << "e " << count_e << "\n";
    cout << "i " << count_i << "\n";
    cout << "o " << count_o << "\n";
    cout << "u " << count_u << endl;

    return 0;
}