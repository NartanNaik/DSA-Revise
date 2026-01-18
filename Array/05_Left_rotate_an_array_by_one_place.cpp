#include <bits/stdc++.h>
using namespace std;

vector<int> OptmialSollution(vector<int> &a)
{
    // here we have tp rotate the array to the left place by one that means the first number of the array come to the last
    // So we here store the array in the temp and shift the other numbers to the left and last we put the temp's number at the last 
    // SC = O(1) TC = O(N)
    int temp = a[0];
    for (int i = 1; i < a.size(); i++)
    {
        a[i - 1] = a[i];
    }
    a[a.size() - 1] = temp;
    return a;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    vector<int> newArray = OptmialSollution(a);
    for (auto it : newArray)
    {
        cout << it << "\n";
    }
    return 0;
}