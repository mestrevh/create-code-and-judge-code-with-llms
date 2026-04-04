/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string name, choice;
    set<string> yes_group, no_group;
    string habay_friend = "";
    int max_length = -1;

    while (cin >> name && name != "FIM") {
        cin >> choice;
        if (choice == "YES") {
            if (yes_group.find(name) == yes_group.end()) {
                int current_length = (int)name.length();
                if (current_length > max_length) {
                    max_length = current_length;
                    habay_friend = name;
                }
                yes_group.insert(name);
            }
        } else {
            no_group.insert(name);
        }
    }

    for (const string& n : yes_group) {
        cout << n << "\n";
    }
    for (const string& n : no_group) {
        cout << n << "\n";
    }

    cout << "\nAmigo do Habay:\n" << habay_friend << "\n";

    return 0;
}