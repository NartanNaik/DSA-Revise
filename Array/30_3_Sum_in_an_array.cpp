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

vector<vector<int>> BetterSolution(vector<int> &a)
{
    // TC = O(n^2)*log(m) where n^2 is loops and log(m) is size of the set
    // SC = O(n)+O(no. of triplates) where O(n) is haspMap and another one is the size of the matrix

    // here we insteed of taking a[k] seperately we calculate it with basic math
    // here we know that a[i]+a[j]+a[k] = 0
    // so : a[i]+a[j]=0-a[k]
    //      a[i]+a[j]=-a[k]
    // if we take a[k] left side and move it's - right side with a[i]+a[j]...
    // a[k] = -(a[i]+a[j])
    // this gives us the value of the a[k], like this we calculate the value of a[k] by reducing one O(n) and making the TC=> O(n^2)

    set<vector<int>> st;
    for (int i = 0; i < a.size(); i++)
    {
        // take an hashmap for store the inbetween elements between the a[i] and a[j]
        set<int> hashMap;
        for (int j = i + 1; j < a.size(); j++)
        {
            // calculate and get what should be the value of a[k]
            int third = -(a[i] + a[j]);

            // find that, is a[k] available or not in the hashmap... if it's between the a[i] and a[j] it would defanately stored in the hashpmap now if it's stored
            if (hashMap.find(third) != hashMap.end())
            {
                // add the triplates in the list
                vector<int> temp = {a[i], a[j], third};

                // sort it
                sort(temp.begin(), temp.end());

                // insert it in the set for unique lists
                st.insert(temp);
            }

            // addd the value of present a[j] which would be the middle element of a[i] and a[j]
            hashMap.insert(a[j]);
        }
    }

    // store the lists in the matrix
    vector<vector<int>> ans(st.begin(), st.end());

    // and return it
    return ans;
}

vector<vector<int>> OptimalSolution(vector<int> &a)
{
    // TC => O(nlogn)+O(n^2)
    // SC => O(no. of triplates)
    
    // this solution works to reduce the SC, here insteed of storing it in seperate set, we do things withought taking extra space to do it. here first ...

    vector<vector<int>> ans;

    // sort the array
    sort(a.begin(), a.end());

    // keep the i pointer at start and traverse
    for (int i = 0; i < a.size(); i++)
    {
        // if the the element is not a first element and it's not same as it's previous skip the portion once and take the i one step ahead, beacuse by this we skip the duplicate elements and move the i pointer if it's duplicate
        if (i > 0 && a[i] == a[i - 1])
        {
            continue;
        }

        // keeping the j pointer after the i
        int j = i + 1;

        // keeping the k pointer at the last 
        int k = a.size() - 1;

        // until the j crosses k or k crosses j
        while (j < k)
        {
            // add these
            int sum = a[i] + a[j] + a[k];

            // int this condition we do j++ becuase j-- gives us the negative value only which would not gives us 0 because the array is in sorted manner
            if (sum < 0)
            {
                j++;
            }

            // int this condition we do k-- becuase k++ gives us the positive value only which would not gives us 0 because the array is in sorted manner
            else if (sum > 0)
            {
                k--;
            }

            // if the submission giving us 0
            else
            {
                // add it in the list
                vector<int> temp = {a[i], a[j], a[k]};

                // no need of sorting because already sorted, push it in the matrix
                ans.push_back(temp);

                // after this step move the j forwaord to test other elements in the array
                j++;

                // and k backward to test other elements in the array
                k--;

                // if the a[j] same as it's previous move it ahead until it get unique element or it crosses the k
                while (j < k && a[j] == a[j - 1])
                {
                    j++;
                }

                // if the a[k] same as it's previous move it backwords until it get unique element or it crosses the j
                while (j < k && a[k] == a[k + 1])
                {
                    k--;
                }
            }
        }
    }

    // return the matrix
    return ans;
}

int main()
{
    vector<int> a = {1, -2, 3, -4, -1, -1, -2, 5};
    // vector<vector<int>> ans = BruteforceSolution(a);
    vector<vector<int>> ans = BetterSolution(a);
    // vector<vector<int>> ans = OptimalSolution(a);
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