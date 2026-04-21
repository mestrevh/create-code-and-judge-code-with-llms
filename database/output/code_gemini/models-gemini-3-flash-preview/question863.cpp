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

    string action;
    int back_stack = 0;
    int forward_stack = 0;
    bool has_current_page = false;

    while (cin >> action) {
        if (action == "ENTER") {
            if (has_current_page) {
                back_stack++;
            }
            has_current_page = true;
            forward_stack = 0;
        } else if (action == "BACK") {
            if (back_stack > 0) {
                forward_stack++;
                back_stack--;
            }
        } else if (action == "FORWARD") {
            if (forward_stack > 0) {
                back_stack++;
                forward_stack--;
            }
        }
    }

    cout << "BACK: " << back_stack << "\n";
    cout << "FORWARD: " << forward_stack << "\n";

    return 0;
}
