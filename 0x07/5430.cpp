#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

void input_deque(deque<int> &dq, string command)
{
	int i = 0;
	int k = 0;
	int nu = 0;
	while (command[i] != '\0')
	{
		while (command[i] != ',')
		{
			if (command[i] - '0')
			{
				nu = nu * 10 + command[i] - '0';
			}
			i++;
		}
		i++;
	}
}

int command_check(string command)
{
	int i = 0;
	int d = 0;
	for (int i = 0; i <= command.length(); i++)
	{
		if (command[i] == 'D')
			d++;
	}
	return d;
}

void reverse(deque<int> &dq)
{

	deque<int> dq2;
	for (int i = 1; !dq.empty(); i++)
	{
		dq2.push_back(dq.back());
		dq.pop_back();
	}

	for (int i = 1; !dq2.empty(); i++)
	{
		dq.push_back(dq2.front());
		dq2.pop_front();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	cin >> tc;

	string command;
	string arr;
	int arr_size;
	int d = 0;

	while (tc--)
	{
		cin >> command;
		d = command_check(command);
		cin >> arr_size;
		cin >> arr;

		deque<int> dq;
		input_deque(dq, arr);

		if (d > arr_size)
		{
			cout << "Error" << endl;
			continue;
		}

		for (int j = 0; j < command.length(); j++)
		{
			if (command[j] == 'R')
				reverse(dq);
			else
			{
				dq.pop_front();
			}
		}

		cout << "[";
		int dsize = dq.size();
		for (int k = 0; k < dsize - 1; k++)
		{
			cout << dq.front() << ",";
			dq.pop_front();
		}
		cout << dq.front() << "]" << endl;
	}

	return 0;
}
