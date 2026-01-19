#include <bits/stdc++.h>
using namespace std;

// you have to return the elements in the array which's right side elements are smaller than it

vector<int> BruteforceSolution(vector<int> &a)
{
    // we traverse through the array and check whether the element is bigger than it's right or not, if the element don't get the element which is greater than it the flag remains the same which we maintained for every element before checking, if we get the element which is greater than it we turn the flag into 1 and.. at last we check and add the elements in the array which's flag will remain the 0

    // TC = O(N*N)
    // SC = O(N)=>just to return the answer

    vector<int> ans;
    for (int i = 0; i < a.size(); i++)
    {
        int flag = 0;
        for (int j = i; j < a.size(); j++)
        {
            if (a[j] > a[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            ans.push_back(a[i]);
        }
    }

    return ans;
}

vector<int> OptimalSolution(vector<int> &a)
{
    // here we traverse from backwords and push the greater element to the array, and do compare it's next (previous in the loop) element that whether it's greater than it or not.. if the next element is greater we also add it inside the array same goes for entire array

    // TC = O(N)
    // SC = O(N)=>Just to return the answer

    vector<int> ans;
    int n = a.size();
    int mx = INT_MIN;

    // traverse the array from backwords
    for (int i = n - 1; i >= 0; i--)
    {
        // if the element in greater than the max push it to the ans array
        if (a[i] > mx)
        {
            ans.push_back(a[i]);
        }
        // keep the track of which is the maximum element
        mx = max(mx, a[i]);
    }

    // return the ans array
    return ans;
}

int main()
{
    vector<int> a = {1, 5, 4, 2, 8, 3, 4};
    vector<int> leaders = BruteforceSolution(a);
    cout << "Leaders in the array are: ";
    for (auto it : leaders)
    {
        cout << it << " ";
    }
    return 0;
}