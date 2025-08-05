#include <iostream>
using namespace std;

int main() {
int tree[] = {10, 20, 30, 40, 50, 60};
int n = sizeof(tree) / sizeof(tree[0]);

for (int i = 0; i < n; i++) {
    cout << "Node: " << tree[i] << "\n";

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n)
        cout << " Left Child: " << tree[left] << "\n";

    if (right < n)
        cout << " Right Child: " << tree[right] << "\n";

    cout << "------\n";
}
   return 0;
}