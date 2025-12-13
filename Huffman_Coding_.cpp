#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
};

Node* newNode(char c, int f) {
    Node* temp = new Node();
    temp->ch = c;
    temp->freq = f;
    temp->left = temp->right = NULL;
    return temp;
}

struct cmp {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

string code[256];

void makeCode(Node* root, string s) {
    if (!root)
     return;

    if (root->left == NULL && root->right == NULL) {
        code[root->ch] = s;
    }

    makeCode(root->left, s + "0");
    makeCode(root->right, s + "1");
}

int main() {
    string s;
    cout << "Enter string: ";
    getline(cin, s);

    int freq[256] = {0};

    for (int i = 0; i < s.length(); i++) {
        freq[s[i]]++;
    }

    priority_queue<Node*, vector<Node*>, cmp> pq;

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            pq.push(newNode((char)i, freq[i]));
        }
    }

    while (pq.size() > 1) {
        Node* a = pq.top(); pq.pop();
        Node* b = pq.top(); pq.pop();

        Node* parent = newNode('#', a->freq + b->freq);
        parent->left = a;
        parent->right = b;

        pq.push(parent);
    }

    Node* root = pq.top();

    makeCode(root, "");

    int message = 0;
    int table = 0;

    cout << "\nCharacter  Frequency  Code\n";

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            cout << (char)i << "            "<< freq[i] << "          "<< code[i] << endl;

            message += freq[i] * code[i].length();
            table += 8 + code[i].length();
        }
    }

    cout << "\nMessage size: " << message << " bits";
    cout << "\nTable size: " << table << " bits";
    cout << "\nVariable length: " << message + table << " bits"<<endl;

    return 0;
}
