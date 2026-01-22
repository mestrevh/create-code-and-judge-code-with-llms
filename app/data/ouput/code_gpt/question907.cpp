/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<double> nums(30);
    for (int i = 0; i < 30; i++) {
        cout << "Digite um numero:\n";
        cin >> nums[i];
    }
    
    for (int i = 1; i < 30; i += 2) {
        cout << nums[i] << "\n";
    }
    
    return 0;
}
