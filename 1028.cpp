#include<iostream>
using namespace std;
int find_diamond(char**mine, /*현재 행*/int c_r, /*현재 열*/int c_c, int r, int c);
int main(){
	int r, c;//가로 세로
	cin >> r;
	cin >> c;

	char **mine = new char*[r+2];
	for (int i = 0; i < r+2; i++)
	{
		mine[i] = new char[c+2];
	}
	for (int i = 1; i < r + 1; i++)
	{
		for (int j = 1; j < c + 1; j++)
		{
			cin >> mine[j][i];
		}
	}

	for (int i = 0; i < r + 2; i++)
	{
		
		mine[i][0] = '3';
		mine[i][c + 1] = '3';
		if (i > 0||i<r+1)
		{
			for (int j = 0; j < c + 2; j++)
			{
				if (j == 0 || j == c + 2)
				{
					mine[i][j] = '3';
				}
			}
		}
	}
	int total_max_size=0;
	int cur_size=0;
	for (int i = 1; i < r + 1; i++)
	{
		for (int j = 1; j < c + 1; j++)
		{
			if (mine[i][j] == '1')
			{
				cur_size = find_diamond(mine, i, j, r, c);
				if (total_max_size < cur_size)
				{
					total_max_size = cur_size;
				}
			}
		}
	}
	cout << total_max_size<<endl; 
	return 0;

}

int find_diamond(char**mine, /*현재 행*/int c_r, /*현재 열*/int c_c, int r, int c)
{
	int max_size=0; //한 점에서 만들수 잇는 가장 큰 다이아몬드.
	int n=0; //다이아몬드 높이 변수
	for (int i = r+1 ; i > c_r; i--) //큰 마름모부터 찾는다.
	{
		n = i - c_r + 1;
		if (mine[i][c_c] == '1' && n % 2 == 1 && i>max_size) //마름모 반대쪽 꼭지점이 1인지, 지금까지 찾은 마름모보다 클 가능성이 잇는지.
		{
			if (c_c - n / 2 > 0 && c_c + n / 2 <= c+1) //그 높이 n짜리 마름모가 존재할 수 있는지.
			{
				for (int j = 1; j < n; j++)
				{
					if (j <= n / 2 + 1)
					{
						if (mine[c_r + j][c_c - j] == '1' && mine[c_r + j][c_c + j] == '1')
						{
							
						}
						else
							break;
					}
					else
					{
						int a = n-j;
						if (mine[c_r + j][c_c - a] == '1' && mine[c_r + j][c_c + a] == '1')
						{
						
						}
						else
							break;
					}
					if (j == n - 1)
					{
						max_size = i/2+1;
					}
				}
			}
		}
		
	}
	for (int i = 1; i < r + 1; i++)
	{
		for (int j = 1; j < c + 1; j++)
		{
			cout << mine[i][j];
		}
		cout << endl;
	}
	return max_size;
}