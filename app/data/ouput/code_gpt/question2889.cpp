/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> area_codes(15);
    vector<string> phone_numbers(15);
    
    for (int i = 0; i < 15; i++) {
        cout << "Digite o codigo de area e o telefone:\n";
        cin >> area_codes[i] >> phone_numbers[i];
    }
    
    string desired_code;
    cout << "Digite o codigo de area desejado:\n";
    cin >> desired_code;
    
    cout << "Telefones com o codigo de area " << desired_code << ":\n";
    bool found = false;

    for (int i = 0; i < 15; i++) {
        if (area_codes[i] == desired_code) {
            cout << area_codes[i] << " " << phone_numbers[i] << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << "Nao ha nenhum telefone com o codigo " << desired_code << endl;
    }

    return 0;
}
