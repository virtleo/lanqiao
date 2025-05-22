#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a = n * (2 * n + 1);
    
    string line1, line2;
    
    // 构造第一行
    for (int i = 0; i <= n; ++i) {
        line1 += to_string(a + i) + "^2 + ";
    }
    line1.pop_back(); // 移除末尾的'+'
    line1.pop_back();
    line1 += "=";
    
    // 构造第二行
    for (int i = n + 1; i <= 2 * n; ++i) {
        line2 += to_string(a + i) + "^2 + ";
    }
    line2.pop_back(); // 移除末尾的'+'
    line2.pop_back();
    line2.pop_back();
    cout << line1 << "\n" << line2;
    
    return 0;
}
