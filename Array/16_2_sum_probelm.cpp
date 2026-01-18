#include <bits/stdc++.h>
using namespace std;

// you have to find the two elemets which's sum == target

bool BruteforceSultion(vector<int> a, int t)
{
    // TC = O(N*N)
    // SC = O(1)

    // take the i at first index
    for (int i = 0; i < a.size(); i++)
    {
        // take j at the next index of the i
        for (int j = i; j < a.size(); j++)
        {
            // if the elements of the index i and j == target
            if (a[i] + a[j] == t)
            {
                // return true
                return true;
            }
        }
    }

    // if there is not elements matching the target return false
    return false;
}

bool BetterSolution(vector<int> &a, int t)
{
    // TC = O(N*logN)=> if we took ordered map and O(N) and O(N*N) in the worst case if we take unordered map
    // SC = O(N)
    // this works like we are at the element x and for get the target we need the element y and if that y exist in the array then we return true

    map<int, int> mpp;

    // Traverse through the array
    for (int i = 0; i < a.size(); i++)
    {
        // store the element at the index i in the variable el
        int el = a[i];

        // get the remaining element if we subtract the el with the target
        int more = t - el;

        // if that remaining exist in the array that means there IS a 2 elements which's sum == target
        if (mpp.find(more) != mpp.end())
        {
            return true;
        }
        // if the more is not in the mapp than add that more inside the map
        mpp[el] = i;
    }

    // return false if there is no elements
    return false;
}

bool OptimalSolution(vector<int> &a, int t)
{
    // TC = O(NlogN)
    // SC = O(1)

    // keep the left at the first index
    int left = 0;

    // keep the right at the last index
    int right = a.size() - 1;

    // sort the array
    sort(a.begin(), a.end());

    // while the left cross the right
    while (left < right)
    {
        // in the movement where the sum of left and right == t
        if (a[left] + a[right] == t)
        {
            // return true
            return true;
        }

        // if it's greater than the t
        if (a[left] + a[right] > t)
        {
            // we have to bring the right one step back because the array os sorted
            right--;
        }

        // if it's lesser than the t
        if (a[left] + a[right] < t)
        {
            // we have to move the left one step ahead because the array is sorted
            left++;
        }
    }

    // return the flase if no elements found for 2 sum
    return false;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6};
    int t = 3;
    // if (BruteforceSultion(a, t))
    // if (BetterSolution(a, t))
    if (OptimalSolution(a, t))
    {
        cout << "Yes the two elements exist for " << t;
    }
    else
    {
        cout << "There is not elements for this...";
    }

    return 0;
}