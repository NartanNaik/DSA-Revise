#include <bits/stdc++.h>
using namespace std;

// you have given an array and have to find the triplates which's submission gives 0. Note: there should be no dublicates ex: you can have [4, 1, 3] and [4, 1, 2] but not [4, 1, 3] and [4, 3, 1]... this is called as dublicate

vector<vector<int>> BruteforceSolution(vector<int> &a)
{
    // TC => O(n^3)log(no. of unique triplates) 3 loops and set
    // SC => 2*O(no of triplate) => matrix and set

    // we will store the vectors inside the set... which helps us to remove dublicate lists
    set<vector<int>> st;

    // traverse thorgh the entire array and check the elements
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i + 1; j < a.size(); j++)
        {
            for (int k = j + 1; k < a.size(); k++)
            {
                // if the sum is giving us 0
                if (a[i] + a[j] + a[k] == 0)
                {
                    // add that triplates in the temp list
                    vector<int> temp = {a[i], a[j], a[k]};

                    // now sort it... we are sorting it because we have to return the unique triplates like [4, 1, 3] and [4, 1, 2] but not [4, 1, 3] and [4, 3, 1]... so if we sort it we get the elements like [1,3,4] and for another list also [1,3,4] this helps us to take only one list in the set
                    sort(temp.begin(), temp.end());

                    // here the set take the list (only unique one becuase we sorted the list already)
                    st.insert(temp);
                }
            }
        }
    }

    // collecting all the unique list inside the matrix
    vector<vector<int>> ans(st.begin(), st.end());

    // returning the answer
    return ans;
}



int main()
{
    vector<int> a = {1, -2, 3, -4, -1, -1, -2, 5};
    vector<vector<int>> ans = BruteforceSolution(a);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}