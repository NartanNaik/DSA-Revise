#include <bits/stdc++.h>
using namespace std;

// Consiqutives ones refered as highest number of ones which are in serial without break for example in the array a = {1, 1, 0, 0, 1, 1, 1, 0, 0, 1} consiqutive ones is 3 which are between the 0s and also maximum ones in that arary

// this is easy so we can go to optmimal solution because the solution itself straight forward
int OptimalSolution(vector<int> &a)
{
    // TC = O(N)
    // SC = O(1)

    // take max and count with the value 0
    int mx = 0;
    int cnt = 0;

    // traverse thought the aray
    for (int i = 0; i < a.size(); i++)
    {
        // if the element is 1 then increase the count and take max as, maximum of max and count... this will helps to keep the max as maximum of 1's, ,like if in future the the cnt turn into 0 the mx still be the earlier value of it...
        if (a[i] == 1)
        {
            cnt++;
            mx = max(mx, cnt);
        }
        // bring cnt back into 0 if 0 found in the array
        else
        {
            cnt = 0;
        }
    }

    // return the max which now have the answer
    return mx;
}

int main()
{
    vector<int> a = {1, 1, 0, 0, 1, 1, 1, 0, 0, 1};
    int solution = OptimalSolution(a);
    cout << "The consiquitive one numbers are: " << solution;
    return 0;
}