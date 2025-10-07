/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int bin_to_dec(string bin) {
    int dec = 0;
    int power = 1;
    for (int i = bin.length() - 1; i >= 0; i--) {
        if (bin[i] == '1') {
            dec += power;
        }
        power *= 2;
    }
    return dec;
}

int main() {
    int n1;
    cin >> n1;

    vector<string> bin_strings(n1);
    for (int i = 0; i < n1; i++) {
        cin >> bin_strings[i];
    }

    int bin_len = bin_strings[0].length();
    int pos_len = log2(bin_len);
    int id_len = bin_len - pos_len;
    int num_seats = pow(2, pos_len);

    vector<string> seats(num_seats, "");

    for (int i = 0; i < n1; i++) {
        string pos_str = bin_strings[i].substr(0, pos_len);
        string id_str = bin_strings[i].substr(pos_len);
        int pos = bin_to_dec(pos_str);

        while (pos < num_seats && seats[pos] != "") {
            pos++;
        }
        if (pos < num_seats) {
            seats[pos] = id_str;
        }
    }

    int n2;
    cin >> n2;

    for (int i = 0; i < n2; i++) {
        int seat_num;
        cin >> seat_num;
        if (seat_num < num_seats && seats[seat_num] != "") {
            cout << seats[seat_num] << endl;
        } else {
            cout << "Nao tem ninguem" << endl;
        }
    }

    return 0;
}
