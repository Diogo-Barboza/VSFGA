#include <bits/stdc++.h>
using namespace std;

unsigned long long fib(unsigned long long n){
    vector<unsigned long long> numbers;
    numbers.push_back(0);
    numbers.push_back(1);
    unsigned long long fib = 0;

    if (n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }

    for (int i = 2; i <= n; i++)
    {
        fib = numbers[i - 2] + numbers[i - 1];
        numbers.push_back(fib);
    }

    return numbers[n];
}

int main() {
    int tam = 0;
    int ent = 0;

    cin >> tam;

    for (int i = 0; i < tam; i++)
    {
        cin >> ent;

        cout << "Fib(" << ent << ") = " << fib(ent) << endl;
    }

    return 0;
}