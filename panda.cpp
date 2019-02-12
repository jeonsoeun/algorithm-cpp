#include<iostream>

using namespace std;
//////////////////////...........�Ǵ�.
int find(int **m, int x, int y, int n);
int** check;
int num = 0;
int main(){

	int n;
	while (1)
	{
		cin >> n;
		for (; cin.fail();)
		{
			cin.clear();
			cin.ignore();
			if (n > 500)
			{
				cout << "1<n<500" << endl;
			}
			cin >> n;
		}
		if (n > 500 || n < 1)
		{
			cout << "1<n<500" << endl;
			continue;
		}
		else
			break;
	}
	
	int ** m = new int*[n + 2];
	for (int i = 0; i < n + 2; i++)
	{
		m[i] = new int[n + 2];
	}

	for (int i = 0; i < n + 2; i++)
	{
		for (int j = 0; j < n + 2; j++)
		{
			if (i == 0 || i == n + 1)
			{
				m[i][j] = -1;
			}
			else if (j == 0 || j == n + 1)
			{
				m[i][j] = -1;
			}
		}
	}

	for (int i = 0; i < n*n; i++)
	{
		cin >> m[(i / n) + 1][(i%n) + 1];
		for (; cin.fail();)
		{
			cin.clear();
			cin.ignore();
			cin >> m[(i / n) + 1][(i%n) + 1];
		}
	}
	check = new int *[n];
	for (int i = 0; i < n; i++)
	{
		check[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			check[i][j] = 0;
		}
	}

	for (int i = 0; i < n*n; i++)
	{
		if (check[(i / n)][(i%n)] == 0)
		{
			find(m, (i / n) + 1, (i%n) + 1, 1);
		}
	}

	cout << num;

}

int find(int **m, int x, int y, int n)
{
	if (m[x - 1][y] >m[x][y])
	{
		find(m, x - 1, y, n + 1);
		check[x-2][y-1] = 1;
	}
	if (m[x][y - 1] >m[x][y])
	{
		find(m, x, y - 1, n + 1);
		check[x-1][y-2] = 1;
	}
	if (m[x + 1][y] >m[x][y])
	{
		find(m, x + 1, y, n + 1);
		check[x][y -1] = 1;
	}
	if (m[x][y + 1] >m[x][y])
	{
		find(m, x, y + 1, n + 1);
		check[x -1][y] = 1;
	}

	if (n > num)
		num = n;
	return 0;

}

/////////////////////////////////....���̾Ƹ��.

//int main()
//{
//	int r, c; // r�� ��, c�� ��
//	while (1)
//	{
//		cin >> r;	//���� ������ �Է¹޴´�.
//		if (cin.fail())	//����ó��1 : ���ڰ� �ƴ� ���� �Է¹޾�����.
//		{
//			cin.clear();
//			cin.ignore();
//			cout << " "<<endl;
//		}
//		else if (r > 750 || r < 1)//����ó��2 : �����ȿ� ���� �ƴҶ�.
//		{
//			cout << "1<=r<=750" << endl;
//		}
//		else
//			break;
//	}
//
//	while (1)
//	{
//		cin >> c;
//		if (cin.fail())
//		{
//			cin.clear();
//			cin.ignore();
//			cout << " " << endl;
//		}
//		else if (c > 750 || c < 1)
//		{
//			cout << "1<=c<=750" << endl;
//		}
//		else
//			break;
//	}
//
//	int** dia = new int*[r];
//	for (int i = 0; i < r; i++)
//	{
//		dia[i] = new int[c];
//	}
//
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j < c; j++)
//		{
//			cin >> dia[i][j];
//		}
//	}
//
//	for (int i = 0; i < r; i++)
//	{
//		for (int i = 0; i < c; i++)
//		{
//
//		}
//	}
//
//
//}