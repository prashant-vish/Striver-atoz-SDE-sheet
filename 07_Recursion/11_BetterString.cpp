#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void find(string &s, int index, unordered_set<string> &st, string &ans)
    {

        if (index >= s.size())
        {
            st.insert(ans);
            return;
        }

        ans.push_back(s[index]);
        find(s, index + 1, st, ans);
        ans.pop_back();

        find(s, index + 1, st, ans);
    }

    string betterString(string &s1, string &s2)
    {

        unordered_set<string> st;
        string ans = "";
        find(s1, 0, st, ans);

        int totals1 = st.size();

        st.clear();
        ans = "";
        find(s2, 0, st, ans);

        int totals2 = st.size();

        return totals1 >= totals2 ? s1 : s2;
    }
};