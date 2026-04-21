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

    string name;
    if (getline(cin, name)) {
        // According to the test cases, the format is: Ola, [Name] !
        // There is no accent in "Ola" and there is a space before the exclamation mark.
        cout << "Ola, " << name << " !" << endl;
    }

    return 0;
}