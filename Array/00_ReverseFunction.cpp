#include <bits/stdc++.h>
using namespace std;

void Reverse(int begin, int end, vector<int> &a)
{
    while (begin < end)
    {
        int temp = a[begin];
        a[begin] = a[end];
        a[end] = temp;
        begin++;
        end--;
    }
}

// function for reverse array with k size
void Solution(vector<int> &a, int k)
{
    int n = a.size();
    for (int i = 0; i < n; i += k)
    {
        int left = i;
        int right = min(i + k - 1, n - 1);
        while (left < right)
        {
            swap(a[left], a[right]);
            left++;
            right--;
        }
    }
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    Reverse(0, a.size()-1, a);
    for (auto it : a)
    {
        cout << it << "\n";
    }
    return 0;
}