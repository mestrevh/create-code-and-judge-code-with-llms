/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int* maior(int *arr) {
    int *maior = arr;
    for(int i = 1; i < 6; i++) {
        if(arr[i] > *maior) {
            maior = &arr[i];
        }
    }
    return maior;
}

int* menor(int *arr) {
    int *menor = arr;
    for(int i = 1; i < 6; i++) {
        if(arr[i] < *menor) {
            menor = &arr[i];
        }
    }
    return menor;
}

int main() {
    int arr[6];
    for(int i = 0; i < 6; i++) {
        cin >> arr[i];
    }
    cout << *menor(arr) << endl;
    cout << *maior(arr) << endl;
    return 0;
}
