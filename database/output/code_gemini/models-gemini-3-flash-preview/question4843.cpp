/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int binarySearchRecursive(const int arr[], int target, int left, int right) {
    if (left > right) {
        return -1;
    }
    
    int mid = left + (right - left) / 2;
    
    if (arr[mid] == target) {
        return mid;
    }
    
    if (arr[mid] > target) {
        return binarySearchRecursive(arr, target, left, mid - 1);
    }
    
    return binarySearchRecursive(arr, target, mid + 1, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int target;
    if (!(cin >> target)) return 0;

    int arr[20];
    for (int i = 0; i < 20; ++i) {
        if (!(cin >> arr[i])) break;
    }

    cout << binarySearchRecursive(arr, target, 0, 19) << endl;

    return 0;
}