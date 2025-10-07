/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> pop_version(vector<int> arr, int pos) {
    if (arr.empty()) {
        cout << "[ ]" << endl;
        cout << "A lista estah vazia - nao eh possivel remover elementos" << endl;
        return {};
    }
    if (pos < 0 || pos >= arr.size()) {
        cout << "[ ";
        for (int x : arr) cout << x << " ";
        cout << "]" << endl;
        cout << "Nao eh possivel remover o elemento" << endl;
        return arr;
    }
    
    int item = arr[pos];
    arr.erase(arr.begin() + pos);
    cout << "[ ";
    for (int x : arr) cout << x << " ";
    cout << "]" << endl;
    cout << "O item " << item << " serah removido da lista" << endl;
    return arr;
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    int pos;
    cin >> pos;

    cout << "[ ";
    for (int x : arr) cout << x << " ";
    cout << "]" << endl;

    arr = pop_version(arr, pos);

    return 0;
}
