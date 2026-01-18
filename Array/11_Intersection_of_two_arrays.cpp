#include <bits/stdc++.h>
using namespace std;

// intersaction is which present in the both the arrays ex a1={1,2,3} a2={2} then the intersection of these arrays will be = {2}

vector<int> BruteforeceSolution(vector<int> &a1, vector<int> &a2)
{
    // TC = O(n*m)
    // SC = O(m)

    // size of the array 1
    int n = a1.size();

    // size of the array 2
    int m = a2.size();

    // array to store the intersection elements
    vector<int> ans;

    // an array containing all 0's with the size of array 2 and this will marks as 1 when it selected for intersection
    int visited[m] = {0};

    // i pointer for the array 1
    for (int i = 0; i < n; i++)
    {
        // j pointer for the array 2 and for one iteration of the for loop of the aray 1 this will run till array 2 end ex = for alphabet A of the array 1 this will look up to A to Z of the array 2
        for (int j = 0; j < m; j++)
        {
            // if the array 1's element matches the element from the 2nd array and the visited array marked as 0 for this place the element push to the ans array and break this loop and look for next element in the array 1
            if (a1[i] == a2[j] && visited[j] == 0)
            {
                ans.push_back(a1[i]);
                visited[j] = 1;
                break;
            }

            // if the array 2's element is bigger than the array 1 then the loop breaks because hence the arrays are sorted the if this element is bigger obviously all ahead elements are bigger than it
            if (a2[j] > a1[i])
            {
                break;
            }
        }
    }
    return ans;
}

vector<int> OptimalSolution(vector<int> &a1, vector<int> &a2)
{
    // TC = O(n+m)
    // SC = O(min(n,m))

    // taking the array to store the intersection elements
    vector<int> intersection;

    // i pointer to the array 1
    int i = 0;

    // j pointer to the array 2
    int j = 0;

    // size of the array 1
    int n = a1.size();

    // size of the array 2
    int m = a2.size();

    // while there are elements in the in "both" the arrays
    while (i < n && j < m)
    {
        // if elemet of the array 1 is smaller than the array 2
        if (a1[i] < a2[j])
        {
            // move the i pointer 1 step ahead
            i++;
        }
        // if elemet of the array 2 is smaller than the array 1
        else if (a1[i] > a2[j])
        {
            // move the j pointer 2 step ahead
            j++;
        }
        // if both the elemetns are equalent
        else
        {
            // and if the intersection array is empty or the elements which gonna push to it not already exist in the array which we are gonna push
            if (intersection.empty() || intersection.back() != a1[i])
            {
                // push that element in the array we created
                intersection.push_back(a1[i]);
            }
            // move the i and j one step ahead
            i++;
            j++;
        }
    }

    // return the final array we got
    return intersection;
}

int main()
{
    vector<int> a1 = {1, 2, 3, 4, 5, 6, 7};
    vector<int> a2 = {2, 3, 4, 6, 7};
    // vector<int> newArray = BruteforeceSolution(a1, a2);
    vector<int> newArray = OptimalSolution(a1, a2);
    for (auto it : newArray)
    {
        cout << it << " ";
    }
    return 0;
}