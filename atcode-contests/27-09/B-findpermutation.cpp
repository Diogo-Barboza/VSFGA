#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n, aux, organiza = 0;
    vector<int> v;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    bool rep = true;

    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> aux;
        v.push_back(aux);
    }

    for(int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++)
        {
            if(v[i] == v[j] && v[i] != -1)
                rep = false;
        }
        if (v[i] != -1){
            for(int k = 0; k < nums.size(); k++){
                if(v[i] == nums[k])
                    nums.erase(nums.begin() + k);
            }
        }
    }
    
    if(!rep)
        cout << "No" << endl;
    else{
        for(int i = 0; i < n; i++){
            if (v[i] == -1)
                v[i] = nums[organiza++];
        }
        cout << "Yes" << endl;
        for (int i: v)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}