#include <bits/stdc++.h>

using namespace std;

string s; // input string

using ci = pair<char, int>; // char and its index

set<int> sl[26]; 

void saveSet(string s){
    for (int i = 0; i < s.size(); i++){
        int c = s[i];
        c = c - 'a';
        sl[c].insert(i+1);
    }
}



void solve(){
    
}

void opt1(){
    int pos; // position of first option
    char c; // char to be put in pos

    cin >> pos >> c;

    int o = s[pos-1];
    o = o - 'a';

    sl[o].erase(pos);
    
    
    o = c;
    o = o - 'a';
    
    sl[o].insert(pos);
    
    s[pos-1] = c;
}

void opt2(){
    int l, r; // left and right about second opt. (range of sum)
    int countDistinct = 0;

    cin >> l >> r;

    for (int i = 0; i < 26; i++){
        auto it = sl[i].lower_bound(l);
        if (it != sl[i].end() && *it <= r)
            countDistinct++;
    }

    cout << countDistinct << "\n";
    
}


int main() {

    int q; //querys
    int opt; // 1 -> change; 2 -> sum of diferent characters

    cin >> s >> q;

    saveSet(s);

    while (q--){
        cin >> opt;

        opt == 1 ? opt1() : opt2();
    }

    return 0;
}