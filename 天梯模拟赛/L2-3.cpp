#include <iostream>
#include <vector>
using namespace std;

void generatePostOrder(int i, int n, vector<int>& post_order) {
    if (i >= n) return;
    generatePostOrder(2 * i + 1, n, post_order); // 递归左子树
    generatePostOrder(2 * i + 2, n, post_order); // 递归右子树
    post_order.push_back(i); // 记录当前节点索引
}

int main() {
    int n;
    cin >> n;
    vector<int> post(n);
    for (int i = 0; i < n; ++i) {
        cin >> post[i];
    }
    
    vector<int> post_order;
    generatePostOrder(0, n, post_order); // 生成后序索引顺序
    
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[post_order[i]] = post[i]; // 填充层序数组
    }
    
    for (int i = 0; i < n; ++i) {
        if (i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    
    return 0;
}
