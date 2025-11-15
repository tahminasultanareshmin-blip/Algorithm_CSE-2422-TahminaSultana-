#include <bits/stdc++.h>
using namespace std;

void rabinKarp(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();

    int d = 256;
    int q = 101;

    int pHash = 0;
    int tHash = 0;
    int h = 1;

    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    for (int i = 0; i < m; i++) {
        pHash = (d * pHash + pattern[i]) % q;
        tHash = (d * tHash + text[i]) % q;
    }

    for (int i = 0; i <= n - m; i++) {
        if (pHash == tHash) {
            bool match = true;

            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }

            if (match) {
                cout << "Pattern found at index " << i << endl;
            }
        }
        if (i < n - m) {
            tHash = (d * (tHash - text[i] * h) + text[i + m]) % q;

            if (tHash < 0) tHash += q;
        }
    }
}

int main() {
    string text, pattern;
    cin >> text >> pattern;

    rabinKarp(text, pattern);

    return 0;
}


