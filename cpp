#include <iostream>

using namespace std;

int N, M, K, cnt = 0;//N - 1 : 최대 버튼을 누를 횟수, M - 1: 0부터 다이얼의 개수, K: 타겟
int button[10] = {};

void f(int depth, int sum)//depth : 버튼을 누른 횟수
{
	if (depth > N - 1)// 버튼을 누른 횟수가 N - 1 회를 넘어가면 끝
		return;
	if (sum == K && depth > 0)
		cnt++;
	for (int i = 0; i < N; i++)
	{
		int tmp = sum;
		tmp += button[i];
		tmp %= M;
		f(depth + 1, tmp);
	}
}

int main()
{

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		cin >> button[i];
	f(0, 0);
	cout << cnt;
}
