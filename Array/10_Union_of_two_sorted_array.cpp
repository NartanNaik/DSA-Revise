#include <bits/stdc++.h>
using namespace std;

// Union is like you have to take the comman from the array ex: union of the a1 ={1,2,3,4} and a2 ={2,5,6} that the union will be 1,2,3,4,5,6

set<int> BruteforceSolution(vector<int> &a1, vector<int> &a2)
{
    // here we are just adding the both arrays in the set with the quality of the set only unique elements get stored
    // TC = O((n + m) log(n + m))
    // SC = O(n + m)
    // We use set to store unique elements in sorted order
    set<int> st;
    for (int i = 0; i < a1.size(); i++)
    {
        st.insert(a1[i]);
    }

    for (int i = 0; i < a2.size(); i++)
    {
        st.insert(a2[i]);
    }

    return st;
}

vector<int> OptimalSolution(vector<int> &a1, vector<int> &a2)
{
    // TC = O(n1+n1)
    // SC = O(n1+n2) => only for returning in the answer not in the algorithm

    // We took an array to add all the union numbers to it
    vector<int> unionArray;

    // this will be place at the a1 start
    int i = 0;

    // this will be place at the a2 start
    int j = 0;

    // size of the array 1
    int n1 = a1.size();

    // size of the array 2
    int n2 = a2.size();

    // while "both" i and j reach the last of the array
    while (i < n1 && j < n2)
    {
        // if element of a1 is smaller or equals to a2
        if (a1[i] <= a2[j])
        {
            // if this is the first element to be enter or if the element is not same in as the element already present in our union array
            if (unionArray.size() == 0 || unionArray.back() != a1[i])
            {
                // push this element in the array
                unionArray.push_back(a1[i]);
            }
            // and move the i pointer 1 step forward
            i++;
        }
        else
        {
            // if this is the first element to be enter or if the element is not same in as the element already present in our union array
            if (unionArray.size() == 0 || unionArray.back() != a2[j])
            {
                // push this element in the array
                unionArray.push_back(a2[j]);
            }
            // and move the j pointer 1 step forward
            j++;
        }
    }

    // if some elements left in the array 2 while the array 1 is empty already
    while (j < n2)
    {
        // if this is the first element to be enter or if the element is not same in as the element already present in our union array
        if (unionArray.size() == 0 || unionArray.back() != a2[j])
        {
            // push this element in the array
            unionArray.push_back(a2[j]);
        }
        // and move the j pointer 1 step forward
        j++;
    }

    // if some elements left in the array 1 while the array 2 is empty already
    while (i < n1)
    {
        // if this is the first element to be enter or if the element is not same in as the element already present in our union array
        if (unionArray.size() == 0 || unionArray.back() != a1[i])
        {
            // push this element in the array
            unionArray.push_back(a1[i]);
        }
        // and move the i pointer 1 step forward
        i++;
    }

    // returning the union array which cost SC = O(n1+n2)
    return unionArray;
}

int main()
{
    vector<int> a1 = {1, 2, 3, 4, 5, 6};
    vector<int> a2 = {5, 6, 7, 8};
    vector<int> ans = OptimalSolution(a1, a2);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}