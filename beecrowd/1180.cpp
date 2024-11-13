#include <bits/stdc++.h>
using namespace std;

int main(){
    int num = pow(2, 31);
    int pos = 0;
    int input = 0;

    cin >> num;

    vector<int> nums;

    for (int i = 0; i < num; i++)
    {
        cin >> input;
        nums.push_back(input);
    }

    int menor = nums[0];
    int tam = nums.size();

    for (int i = 1; i < tam; i++){
        if (nums[i] < menor){
            menor = nums[i];
            pos = i;
        }
    }
    
    cout << "Menor valor: " << menor << endl << "Posicao: " << pos << endl;

    return 0;
}