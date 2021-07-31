#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
string room_number;
int numbers[11];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> room_number;
    int i = 0;
    while (room_number[i] != '\0')
    {
        numbers[room_number[i] - '0']++;
        i++;
    }
    int sum = numbers[6] + numbers[9];
    if (sum % 2 != 0)
        numbers[6] = sum / 2 + 1;
    else
        numbers[6] = sum / 2;
    numbers[9] = numbers[6];

    int max = -1;
    for (int i = 0; i < 10; i++)
    {
        if (max < numbers[i])
        {
            max = numbers[i];
        }
    }
    cout << max;
    return 0;
}