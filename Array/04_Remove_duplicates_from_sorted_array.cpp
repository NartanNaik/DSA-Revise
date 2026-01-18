#include <bits/stdc++.h>
using namespace std;

vector<int> BruteforceSolution(vector<int> &a)
{
    // here we took the all the element in the set which only excepts the unique elements and we add it again in the array we got by doing this we get the unique element in the beginning of the array which we wanted and we also get the index which is like how many unique elements are there in the array
    // TC = O(NlogN)+N (if we return for index it self),  SC = O(N) because we are using hte set here

    set<int> st;
    for (int i = 0; i < a.size(); i++)
    {
        st.insert(a[i]);
    }

    int index = 0;
    for (auto it : st)
    {
        a[index] = it;
        index++;
    }

    return a;
}

int OptimalSolution(vector<int> &a)
{
    // Here we take the i in the place of a[0] and j in the place of a[1] and we compare i with the j and if the j is eqvavelent to the i then we put the i in the place of j and move the j to ahead we repeat this process until the array ends
    // here we are returing that how many elemets are unique in the sorted array
    // So the time complexity will be TC = O(N) and SC = O(1)
    int i = 0;
    for (int j = 1; j < a.size(); j++)
    {
        if (a[j] != a[i])
        {
            a[i + 1] = a[j];
            i++;
        }
    }

    return i + 1;
}

int main()
{
    vector<int> a = {1, 1, 2, 2, 3, 4, 5, 5, 6, 9};
    // vector<int> arr = BruteforceSolution(a);
    // for (auto it : arr)
    // {
    //     cout << it << "\n";
    // }
    int index = OptimalSolution(a);
    cout << "The count of unique elements is: " << index;
    return 0;
}