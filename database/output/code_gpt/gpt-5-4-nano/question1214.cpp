/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool isSpaceChar(char c){
    return c==' ' || c=='\t' || c=='\r' || c=='\f' || c=='\v';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    string out;
    bool firstOutLine = true;

    const string digitMap = "* )$!+@-/(%"; // indices 0..9: 0->*,1->),2->$,... but string includes spaces? fix below
    // digitMap with correct mapping:
    // We'll build properly:
    vector<char> dmap(10);
    dmap[0] = '*';
    dmap[1] = ')';
    dmap[2] = '$';
    dmap[3] = '!';
    dmap[4] = '+';
    dmap[5] = '@';
    dmap[6] = '-';
    dmap[7] = '/';
    dmap[8] = '(';
    dmap[9] = '%';

    auto encodeLetterDigitId = [&](int id)->string{
        return to_string(id);
    };

    while (true) {
        string original;
        if(!std::getline(cin, original)) break;

        string cleaned;
        cleaned.reserve(original.size());
        for(char c: original){
            if(isSpaceChar(c)) continue;
            cleaned.push_back(c);
        }

        string reversed = cleaned;
        reverse(reversed.begin(), reversed.end());

        string s = reversed;
        string res;
        res.reserve(s.size()*3);

        int symbolsSoFar = 0;

        for(char c: s){
            if(c>='0' && c<='9'){
                char mapped = dmap[c-'0'];
                res.push_back(mapped);
                symbolsSoFar++;
            } else if(c>='A' && c<='Z'){
                int id = (c - 'A') + 1;
                res += encodeLetterDigitId(id);
                symbolsSoFar += (int)to_string(id).size();
            } else if(c>='a' && c<='z'){
                int id = (c - 'a') + 1;

                if(symbolsSoFar % 2 == 0){
                    res += encodeLetterDigitId(id);
                } else {
                    int parity = symbolsSoFar % 2;
                    (void)parity;
                    res.push_back(char('a' - 'a' + id)); // placeholder, not correct
                }
            } else {
                // remove symbols and punctuation
            }
        }

        // The above for lowercase incorrect; implement properly by redoing with correct logic.
        // We'll just redo loop correctly for this line to avoid confusion.
        res.clear();
        symbolsSoFar = 0;

        for(char c: s){
            if(c>='0' && c<='9'){
                char mapped = dmap[c-'0'];
                res.push_back(mapped);
                symbolsSoFar++;
            } else if(c>='A' && c<='Z'){
                int id = (c - 'A') + 1;
                string t = to_string(id);
                res += t;
                symbolsSoFar += (int)t.size();
            } else if(c>='a' && c<='z'){
                int id = (c - 'a') + 1;
                bool even = (symbolsSoFar % 2 == 0);
                if(even){
                    string t = to_string(id);
                    res += t;
                    symbolsSoFar += (int)t.size();
                } else {
                    string t = to_string(id);
                    res += t;
                    symbolsSoFar += (int)t.size();
                }
            } else {
                // remove other symbols
            }
        }

        // Actually lowercase rule: minuscule becomes uppercase if symbols to left even; otherwise lowercase form.
        // Since input is only letters/digits/spaces per statement, other symbols not present.
        // But the rule says: "Letras minúsculas devem ser em sua forma: Maiúscula, se a quantidade de símbolos a esquerda da letra for par; Minúscula, se ... ímpar."
        // Interpreting "forma" as whether to output as uppercase or lowercase letter after rearrangement.
        // However the replacement described for lowercase is not by digit; it says output letter in uppercase/lowercase.
        // Yet earlier constraints mention mapping uppercase letters to digit identifiers; not mention lowercase. It says lowercase letters should be in their form: uppercase or lowercase.
        // So lowercase letters output as original letter but case adjusted.
        // Let's implement correct behavior: remove spaces/symbols; digits map; uppercase letters -> digit id; lowercase letters -> either uppercase or lowercase letter itself depending on parity.
        // If parity even: output uppercase letter (same letter id but as uppercase letter). That means output char 'A'+(id-1).
        // If parity odd: output lowercase letter char 'a'+(id-1).
        // We'll implement that now.

        res.clear();
        symbolsSoFar = 0;

        for(char c: s){
            if(c>='0' && c<='9'){
                char mapped = dmap[c-'0'];
                res.push_back(mapped);
                symbolsSoFar++;
            } else if(c>='A' && c<='Z'){
                int id = (c - 'A') + 1;
                string t = to_string(id);
                res += t;
                symbolsSoFar += (int)t.size();
            } else if(c>='a' && c<='z'){
                int id = (c - 'a') + 1;
                if(symbolsSoFar % 2 == 0){
                    char outc = char('A' + (id - 1));
                    res.push_back(outc);
                    symbolsSoFar++;
                } else {
                    char outc = char('a' + (id - 1));
                    res.push_back(outc);
                    symbolsSoFar++;
                }
            } else {
            }
        }

        if(!firstOutLine) cout << "\n";
        firstOutLine = false;
        cout << res;
    }

    return 0;
}