#include <bits/stdc++.h>
using namespace std;

// you have given an array and you have to first give the second permituation of it that means when you take a permutation of an array in asscending order, you have to look for the original array in that permutation and and have to return the next permutation of it and if the next permutation won't exist becuase it's appeared in the last permutation you have to return the first one

// ex: a = {3,1,2} so it's permutation will be : 123, 132,213,231,312,321 so you have to return 321 and if the array was = {3,2,1} you have to return 123

vector<int> BruteforceSolution(vector<int> &a)
{
    // find all the permutations
    // traverse and search which one is the array elements
    // return it's next permutation

    // we have to do it with the recursion and this will have lots of TC
}

vector<int> BetterSolution(vector<int> &a)
{
    // this is the inbuild cpp stl how this gonna work we will see in the optimal solution
    next_permutation(a.begin(), a.end());
    return a;
}

vector<int> OptimalSolution(vector<int> &a)
{
    // TC = O(3N) in verse case where O(N) is first loop O(N) is second loop and O(N) is reverse at the last in worst case we may have to traverse the entire array
    // SC = O(1)=> we are not using any extra space

    // 1. find the number which is a[i] < a[i+1]
    // 2. find the number which is > than it and also smaller one in the array
    // 2. arrange the remaining elements in sorted order
    int index = -1;
    int n = a.size();

    // traverse from the second last element to the starting of the array considering whether the previous one is smaller or not. when we get the first smaller element we store it as index and break the loop
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] < a[i + 1])
        {
            index = i;
            break;
        }
    }

    // if the index is still the same as before that means we don't have smaller element in the array which's next is bigger than so that means the array it self the last array so we just need to reverse it to get the next permutaion that meant the first permutation
    if (index == -1)
    {
        reverse(a.begin(), a.end());
        return a;
    }

    // if we get the index traverse from the last element to the index's element ans search for the element which's greater than the index. in the very movement we get the number which is bigger than the index we have swap the index value and that value and break the array
    for (int i = n - 1; i >= index; i--)
    {
        if (a[i] > a[index])
        {
            swap(a[i], a[index]);
            break;
        }
    }

    // after that reverse the array from the index's next element to the last of the array to get the next permutation of it...
    reverse(a.begin() + index + 1, a.end());

    // return the next permutation array
    return a;
}

int main()
{
    vector<int> a = {4,3,5,6};
    vector<int> ans = BetterSolution(a);
    cout << "Next permutation: ";
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}