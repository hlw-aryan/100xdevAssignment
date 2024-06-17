#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int beg = 0, end = 0; // Initialize counters for matching prefix and suffix

    // Find the length of the matching prefix
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == s2[i])
            beg++;
        else
            break;
    }

    // Find the length of the matching suffix
    for (int i = n - 1; i >= 0; i--)
    {
        if (s1[i + 1] == s2[i])
            end++;
        else
            break;
    }

    // Check if it's possible to make s1 identical to s2 by deleting one character
    if (beg + end + 1 < n)
        cout << 0;
    else
    {

        // No of position deletable that will make s1 identical to s2
        cout << min(beg + 1, n + 1) - max(n - end + 1, 1) + 1 << '\n';

        // Print positions where deletion can make s1 identical to s2
        for (int i = 1; i <= n + 1; i++)
        {
            if (i - 1 <= beg && n + 1 - i <= end)
            {
                cout << i << " ";
            }
        }
    }

    return 0;
}
