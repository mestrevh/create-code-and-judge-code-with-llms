/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void printArray(const vector<int>& A) {
    cout << "[";
    for (size_t i = 0; i < A.size(); ++i) {
        cout << A[i] << (i == A.size() - 1 ? "" : ", ");
    }
    cout << "]";
}

void recursiveBinarySearch(const vector<int>& A, int low, int high, int k) {
    if (low > high) {
        printArray(A);
        cout << "  ---->  -1" << endl;
        return;
    }

    int mid = (low + high) / 2;

    if (A[mid] == k) {
        printArray(A);
        cout << "  ---->  " << mid << endl;
        return;
    }

    printArray(A);
    cout << "  ---->  " << A[mid] << endl;

    if (A[mid] > k) {
        recursiveBinarySearch(A, low, mid - 1, k);
    } else {
        recursiveBinarySearch(A, mid + 1, high, k);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, n;
    if (cin >> k >> n) {
        string line;
        getline(cin >> ws, line);
        
        vector<int> A;
        stringstream ss(line);
        string item;
        while (getline(ss, item, ',')) {
            size_t first = item.find_first_not_of(" \t\r\n");
            size_t last = item.find_last_not_of(" \t\r\n");
            if (first != string::npos && last != string::npos) {
                A.push_back(stoi(item.substr(first, last - first + 1)));
            }
        }
        
        if (A.size() > (size_t)n) {
            A.resize(n);
        }
        
        if (!A.empty() || n == 0) {
            recursiveBinarySearch(A, 0, (int)A.size() - 1, k);
        }
    }

    return 0;
}