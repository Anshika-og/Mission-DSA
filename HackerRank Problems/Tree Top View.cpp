#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

void topView(Node* root) {
    if (!root) return;
    map<int, int> m;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    
    while (!q.empty()) {
        Node* temp = q.front().first;
        int hd = q.front().second;
        q.pop();
        
        if (m.find(hd) == m.end()) {
            m[hd] = temp->data;
        }
        
        if (temp->left) q.push({temp->left, hd - 1});
        if (temp->right) q.push({temp->right, hd + 1});
    }
    
    for (auto& p : m) cout << p.second << " ";
    cout << endl;
}

int main() {
    // Input binary tree and call topView()
    return 0;
}
