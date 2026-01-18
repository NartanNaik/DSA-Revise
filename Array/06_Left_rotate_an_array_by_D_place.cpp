#include <bits/stdc++.h>
using namespace std;

void BruteforceSolution(vector<int> &a, int n, int d)
{
    // Here we have to rotate the array based on the d
    // TC = O(N+d)=> for the loops etc SC = O(d) => becasue of the temp we are taking

    // we are taking module here because if the rotate would be more than the n then the n rotate would be same and extra have to ratate ex : if the n = 7 and the d = 10 now d = 10 % 7 = 3
    d = d % n;

    int temp[d];

    // storing the d elements to the extra storage called temp
    for (int i = 0; i < d; i++)
    {
        temp[i] = a[i];
    }

    // now shifting the numbers of the array to the empty d spaces which created to back
    for (int i = d; i < n; i++)
    {
        a[i - d] = a[i];
    }

    // now putting the starting d elements to the last
    for (int i = n - d; i < n; i++)
    {
        // here we adding temp[i-(n-d)] to the a[i] because temp[i-(n-d)] gives us the emlements from the temp this is easy just do it in the paper for th clarifications
        a[i] = temp[i - (n - d)];
    }
}

void OptimalSolution(vector<int> &a, int n, int d)
{

    // TC = O(2N) SC = O(1)

    // We descussed about it previously
    d = d % n;

    // reversing the array frm beginning to the d
    reverse(a.begin(), a.begin() + d);

    // reversing the array frm d to the end
    reverse(a.begin() + d, a.end());

    // reversing the entire array
    reverse(a.begin(), a.end());
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    int d = 8;
    // BruteforceSolution(a, a.size(), d);
    OptimalSolution(a, a.size(), d);
    for (auto it : a)
    {
        cout << it << "\n";
    }
    return 0;
}