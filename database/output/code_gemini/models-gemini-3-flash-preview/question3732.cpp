/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int order_num;
    int question_count = 1;

    while (cin >> order_num && order_num != 0) {
        string options[5];
        string text;
        
        cin >> text;
        options[order_num] = text;

        for (int i = 0; i < 3; ++i) {
            if (cin >> order_num >> text) {
                options[order_num] = text;
            }
        }

        cout << question_count << ")\n";
        cout << "a)" << options[1] << " c)" << options[3] << "\n";
        cout << "b)" << options[2] << " d)" << options[4] << "\n";

        question_count++;
    }

    return 0;
}