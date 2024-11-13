// C++ program to distinct permutations of the string
#include <bits/stdc++.h>
using namespace std;

// Returns true if str[curr] does not matches with any of the
// characters after str[start]
bool shouldSwap(string str, int start, int curr)
{
    for (int i = start; i < curr; i++) 
        if (str[i] == str[curr])
            return 0;
    return 1;
}

// Prints all distinct permutations in str[0..n-1]
void findPermutations(string str, int index, int n)
{
    if (index >= n) {
        cout << str << endl;
        return;
    }

    for (int i = index; i < n; i++) {

        // Proceed further for str[i] only if it 
        // doesn't match with any of the characters
        // after str[index]
        bool check = shouldSwap(str, index, i);
        if (check) {
            swap(str[index], str[i]);
            findPermutations(str, index + 1, n);
            swap(str[index], str[i]);
        }
    }
}

// Driver code
int main()
{
    string str = "acab";
    int n = str.length();
    //sort(str.begin(), str.end());
    findPermutations(str, 0, n);
    return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
