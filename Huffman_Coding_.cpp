#include <iostream>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
};

Node* createNode(char c, int f) {
    Node* temp = new Node;
    temp->ch = c;
    temp->freq = f;
    temp->left = temp->right = nullptr;
    return temp;
}

void fillCodes(Node* root, string code, char chars[], string codes[], int n) {
    if (!root)
        return;
    if (!root->left && !root->right) {
        for (int i = 0; i < n; i++) {
            if (chars[i] == root->ch) {
                codes[i] = code;
                break;
            }
        }
    }

    fillCodes(root->left, code + "0", chars, codes, n);
    fillCodes(root->right, code + "1", chars, codes, n);
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    char chars[100];
    int freq[100];
    Node* nodes[100];
    string codes[100];

    cout << "Enter characters: ";
    for (int i = 0; i < n; i++) cin >> chars[i];

    cout << "Enter frequencies: ";
    for (int i = 0; i < n; i++) cin >> freq[i];

    for (int i = 0; i < n; i++) {
        nodes[i] = createNode(chars[i], freq[i]);
        codes[i] = "";
    }

    while (true) {
        int min1 = -1, min2 = -1;
        int count = 0;
        for (int i = 0; i < n; i++)
            if (nodes[i] != nullptr) count++;
        if (count == 1) break;

        for (int i = 0; i < n; i++) {
            if (nodes[i] != nullptr) {
                if (min1 == -1 || nodes[i]->freq < nodes[min1]->freq) {
                    min2 = min1;
                    min1 = i;
                } else if (min2 == -1 || nodes[i]->freq < nodes[min2]->freq) {
                    min2 = i;
                }
            }
        }

        Node* left = nodes[min1];
        Node* right = nodes[min2];
        Node* parent = createNode('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        nodes[min1] = parent;
        nodes[min2] = nullptr;
    }

    Node* root = nullptr;
    for (int i = 0; i < n; i++)
        if (nodes[i] != nullptr) root = nodes[i];

    fillCodes(root, "", chars, codes, n);

    cout << "Huffman Codes:\n";
    for (int i = 0; i < n; i++)
        cout << chars[i] << ": " << codes[i] << endl;

    return 0;
}
