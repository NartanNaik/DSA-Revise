#include <bits/stdc++.h>
using namespace std;

vector<int> BruteforceSolution(vector<int> a)
{
    // We have to remove all the zeros from the array have to add all those in the last of the array
    // What we did in this appraoch is we take all the non 0 numbers in the temp and add it back to the original array then after in leftover space we have added 0s
    // Here the time complexity will be O(2N)=> becasue we are using the 2 loops and SC = O(N)=> becuse we are storing it in the temp
    vector<int> temp;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != 0)
        {
            temp.push_back(a[i]);
        }
    }
    for (int i = 0; i < temp.size(); i++)
    {
        a[i] = temp[i];
    }
    for (int i = temp.size(); i < a.size(); i++)
    {
        a[i] = 0;
    }

    return a;
}

vector<int> OptimalSolution(vector<int> &a)
{
    // TC = O(N) SC = O(1)

    int j = -1;
    // Here we assigning the j to the first 0 breaking the loop after getting the first zero
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == 0)
        {
            j = i;
            break;
        }
    }

    // Return the array if there is no 0s in the array
    if (j == -1)
    {
        return a;
    }

    // keep the i infront of the j and swap them if the i will be the non zero and move the j and i front and if the i is non zero move it forward but don't move the j
    for (int i = j + 1; i < a.size(); i++)
    {
        if (a[i] != 0)
        {
            swap(a[i], a[j]);
            j++;
        }
    }

    // Now we have the array we needed and return it
    return a;
}

int main()
{
    vector<int> a = {1, 0, 3, 4, 0, 6, 7};
    // vector<int> arr = BruteforceSolution(a);
    vector<int> arr = OptimalSolution(a);
    for (auto it : arr)
    {
        cout << it << "\n";
    }
    return 0;
} 