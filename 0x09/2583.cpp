#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int m, n, s;
int board[105][105];
int dist[105][105];
int x, y, a, b;
void test(){
	cout << 1 << 2;
}
void bfs(int i, int j, vector<int> &result)
{
	queue<pair<int, int>> Q;
	Q.push({i, j});
	dist[i][j] = 0;
	int distance = 0;
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n)
				continue;
			if (dist[nx][ny] >= 0 || board[nx][ny] == 1)
				continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			distance = max(dist[nx][ny], distance);
			Q.push({nx, ny});
		}
	}
	result.push_back(distance);
}
void test()
{
	cout << 1 << 2;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n >> s;

	for (int i = 0; i < s; i++)
	{
		cin >> y >> x >> b >> a;
		b--;
		a--;
		for (int j = x; j <= a; j++)
			for (int k = y; k <= b; k++)
				board[j][k] = 1;
	}
	for (int i = 0; i < m; i++)
		fill(dist[i], dist[i] + n, -1);
	vector<int> result;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 0 && !dist[i][j])
				bfs(i, j, result);
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for (auto i = result.begin(); i != result.end(); ++i)
		cout << *i << " ";
	return 0;
}
