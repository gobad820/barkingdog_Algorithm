#include <bits/stdc++.h>
/* header */
using namespace std;
#define endl "\n"
string s1, s2;
int alpha1[27];
int alpha2[27];
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s1 >> s2;
    int i = 0;
    int j = 0;
    while (s1[i] != '\0')
    {
        alpha1[s1[i] - 'a']++;
        i++;
    }
    while (s2[j] != '\0')
    {
        alpha2[s2[j] - 'a']++;
        j++;
    }
    int result = 0;
    for (int i = 0; i < 26; i++)
    {
        while (alpha1[i] > alpha2[i])
        {
            alpha1[i]--;
            result++;
        }
        while (alpha2[i] > alpha1[i])
        {
            alpha2[i]--;
            result++;
        }
    }
    cout << result;
    return 0;
}