#include <iostream>
#include <vector>
using namespace std;

int main(){ 
    int n, q, query, c, l, r;
    int left = 1, right = n;

    cin >> n >> q;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int i = 1; i <= q; i++)
    {
        cin >> query;
        if(query == 1){
            cin >> c;
            left = (left + c - 1) % n + 1; // 1 + 3 - 1 = 3 % 4 + 1 = 4
            right = (right + c - 1) % n + 1; // 4 + 3 - 1 = 6 % 4 = 2 + 1 = 3
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << a[(left + i - 2) % n + 1] << " ";
    }

    cout << endl;  

    return 0;
}