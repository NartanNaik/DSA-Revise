#include <bits/stdc++.h>
using namespace std;

int Solution(vector<int> &a)
{
    sort(a.begin(), a.end());
    int cnt = 1, longest = 1;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i + 1] == a[i] + 1)
        {
            cnt++;
        }
        else
        {
            longest = max(longest, cnt);
            cnt = 1;
        }
    }
    longest = max(longest, cnt);
    return longest;
}

int main()
{
    vector<int> a = {45, 46, 42, 1, 2, 5, 4};
    int length = Solution(a);
    cout << "The longest consequtive array's length is: " << length;
    return 0;
}