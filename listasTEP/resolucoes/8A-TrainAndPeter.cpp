#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, i, f, aux;
    bool forw, back, both, fan;

    cin >> s >> i >> f;

    size_t p1 = s.find(i);
    size_t p2 = s.find(f, p1 + f.size());
    if(p1 != -1 && p2 != -1){
        forw = true;
    }
    
    aux = s;
    reverse(aux.begin(), aux.end());
    size_t p3 = aux.find(i);
    size_t p4 = aux.find(f, p3 + f.size());
    if(p3 != -1 && p4 != -1){
        back = true;
    }
    
    if(!forw && !back){
        cout << "fantasy" << endl;
    }else if (forw && !back)
    {
        cout << "forward" << endl;
    }else if (back && !forw)
    {
        cout << "backward" << endl;
    }else{
        cout << "both" << endl;
    }
    
    return 0;
}