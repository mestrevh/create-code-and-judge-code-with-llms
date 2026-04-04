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

    int age;
    string sex;
    int free_count = 0;

    while (cin >> age && age != 111) {
        if (!(cin >> sex)) break;
        
        bool is_free = false;
        
        // Children up to 10 or elderly over 60 (any gender)
        if (age <= 10 || age > 60) {
            is_free = true;
        } 
        // Males between 25 and 35 (exclusive)
        else if (!sex.empty() && (sex[0] == 'm' || sex[0] == 'M')) {
            if (age > 25 && age < 35) {
                is_free = true;
            }
        }
        
        if (is_free) {
            free_count++;
        }
    }

    cout << free_count << endl;

    return 0;
}