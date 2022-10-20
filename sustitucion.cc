#include <iostream>
using namespace std;

char char_encrypt(char a, char b) {
    if (a == ' ') a = 26;
    else a -= 'a';
    if (b == ' ') b = 26;
    else b -= 'a';
    
    char c = (a + b)%27;
    if (c == 26) c = ' ';
    else c += 'a';
    return c;
}
char char_desencrypt(char c, char b) {
    if (c == ' ') c = 26;
    else c -= 'a';
    if (b == ' ') b = 26;
    else b -= 'a';
    
    char a = (c - b);
    if (a < 0) a += 27;
    
    if (a == 26) a = ' ';
    else a += 'a';
    return a;
}

string encrypt(string t, string c) {
    int n = t.size();
    int n_c = c.size();

    string e = t;
    for (int i = 0; i < n; ++i) {
        e[i] = char_encrypt(t[i], c[i%n_c]);
    }
    return e;
}

string desencrypt(string e, string c) {
    int n = e.size();
    int n_c = c.size();

    string t = e;
    for (int i = 0; i < n; ++i) {
        t[i] = char_desencrypt(e[i], c[i%n_c]);
    
        
    }
    return t;
}

int main()
{
    string t = "dont worry if there is a hell below we are all going to go";
    string c = "curtis mayfield";
    
    string e = encrypt(t, c);
    cout << t << endl;
    cout << e << endl;
    string d = desencrypt(e, c);
    cout << d << endl;

    return 0;
}
