/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    int arr[3] = {x, y, z};
    sort(arr, arr + 3, greater<int>());
    cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
    return 0;
}
