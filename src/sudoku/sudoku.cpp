#include"pch.h"//#include"stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<fstream>
using namespace std;

class shudu
{
public:
	int order;
	int order_order;
	int sd[10][10];
	int sd_count[10][10];
	bool flag[10][10];
	bool check[10][10][10];

	void shudu_re(int m);
	void check_2(int j, int k, int m);
	void check_3(int j, int k, int m);
	void total(int m);
};

void shudu::shudu_re(int m)
{
	order = m;
	order_order = m * m;
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			sd[i][j] = 0;
			flag[i][j] = false;
			sd_count[i][j] = m;
			for (int k = 0; k < 10; ++k)
			{
				check[i][j][k] = false;
			}
		}
	}
}
void shudu::check_2(int i, int j, int m)
{
	bool flag_2[10];
	int sum;
	sum = m;
	for (int ii = 0; ii < 10; ++ii)
	{
		flag_2[ii] = false;
	}
	for (int ii = 1; ii <= m; ++ii)
	{
		if (ii == i) continue;

		if (sd[ii][j] != 0)
		{
			flag_2[sd[ii][j]] = true;
			sum--;
		}
		else
		{
			for (int jj = 1; jj <= m; ++jj)
			{
				if (check[ii][j][jj] == false && flag_2[jj] == false)
				{
					flag_2[jj] = true;
					sum--;
				}
			}
		}
	}
	if (sum == 1)
	{
		for (int ii = 1; ii <= m; ++ii)
		{
			if (flag_2[ii] == false)
			{
				sd[i][j] = ii;
			}
		}
		return;
	}
	sum = m;
	for (int jj = 0; jj < 10; ++jj)
	{
		flag_2[jj] = false;
	}
	for (int jj = 1; jj <= m; ++jj)
	{
		if (jj == j) continue;

		if (sd[i][jj] != 0)
		{
			flag_2[sd[i][jj]] = true;
			sum--;
		}
		else
		{
			for (int ii = 1; ii <= m; ++ii)
			{
				if (check[i][jj][ii] == false && flag_2[ii] == false)
				{
					flag_2[ii] = true;
					sum--;
				}
			}
		}
	}
	if (sum == 1)
	{
		for (int ii = 1; ii <= m; ++ii)
		{
			if (flag_2[ii] == false)
			{
				sd[i][j] = ii;
			}
		}
		return;
	}
	if (m == 3 || m == 5 || m == 7 || m >= 0) return;
	int row = 0, col = 0;
	switch (m)
	{
	case 4:
		row = 2;
		col = 2;
		sum = 4;
		break;
	case 6:
		row = 3;
		col = 2;
		sum = 6;
		break;
	case 8:
		row = 2;
		col = 4;
		sum = 8;
		break;
	case 9:
		row = 3;
		col = 3;
		sum = 9;
		break;
	default:;
	}
	for (int jj = 0; jj < 10; ++jj)
	{
		flag_2[jj] = false;
	}
	for (int ii = ((i - 1) / col) * col, x_x = 1; x_x <= col; ++x_x)
	{
		for (int jj = ((j - 1) / row) * row, y_y = 1; y_y <= row; ++y_y)
		{
			if (ii + x_x == i && jj + y_y == j)
				continue;

			if (sd[ii + x_x][jj + y_y] != 0)
			{
				flag_2[sd[ii + x_x][jj + y_y]] = true;
				sum--;
			}
			else
			{
				for (int kk = 1; kk <= m; ++kk)
				{
					if (check[ii + x_x][jj + y_y][kk] == false && flag_2[kk] == false)
					{
						flag_2[kk] = true;
						sum--;
					}
				}
			}
		}
	}
	if (sum == 1)
	{
		for (int ii = 1; ii <= m; ++ii)
		{
			if (flag_2[ii] == false)
			{
				sd[i][j] = ii;
			}
		}
		return;
	}
}

void shudu::check_3(int i, int j, int m)
{
	for (int o = 1; o <= m; ++o)
	{
		if (o == i || sd[o][j] != 0 || check[o][j][sd[i][j]] == true)
		{
			continue;
		}
		else
		{
			check[o][j][sd[i][j]] = true;
			sd_count[o][j]--;
		}
	}
	for (int o = 1; o <= m; ++o)
	{
		if (o == j || sd[i][o] != 0 || check[i][o][sd[i][j]] == true)
			continue;
		else
		{
			check[i][o][sd[i][j]] = true;
			sd_count[i][o]--;
		}
	}
	if (m == 3 || m == 5 || m == 7) return;
	int row = 0, col = 0;
	switch (m)
	{
	case 4:
		row = 2;
		col = 2;
		break;
	case 6:
		row = 3;
		col = 2;
		break;
	case 8:
		row = 2;
		col = 4;
		break;
	case 9:
		row = 3;
		col = 3;
		break;
	default:;
	}
	if (m == 4 || m == 9 || m == 8 || m == 6)
	{
		for (int xxx = ((i - 1) / col) * col, x_x = 1; x_x <= col; ++x_x)
		{
			for (int yyy = ((j - 1) / row) * row, y_y = 1; y_y <= row; ++y_y)
			{
				if (sd[xxx + x_x][yyy + y_y] == 0 && check[xxx + x_x][yyy + y_y][sd[i][j]] == false)
				{
					check[xxx + x_x][yyy + y_y][sd[i][j]] = true;
					sd_count[xxx + x_x][yyy + y_y]--;
				}
			}
		}
	}
}
void shudu::total(int m)
{
	for (int ii = 0; ii <= 81; ++ii)
	{
		if (order_order <= 0) break;
		for (int i = 1; i <= m; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				if (sd[i][j] != 0 && flag[i][j] == false)
				{
					order_order--;
					sd_count[i][j] = 1;
					flag[i][j] = true;
					for (int kk = 1; kk <= m; ++kk)
					{
						check[i][j][kk] = true;
					}
					check_3(i, j, m);
				}
				else if (sd[i][j] == 0)
				{
					if (sd_count[i][j] == 1)
					{
						for (int k = 1; k <= m; ++k)
						{
							if (check[i][j][k] == false)
							{
								sd[i][j] = k;
							}
						}
					}
					else check_2(i, j, m);
				}
			}
		}
	}
}
/*---Main---*/
int main(int argc, char *argv[])
{
	shudu sudu;
	int m = atoi(argv[2]);
	int n = atoi(argv[4]);
	int mm = m * m;
	ifstream inf;
	ofstream outf;
	inf.open(argv[6]);
	if (!inf) { cout << "intput error " << endl; exit(1); }
	outf.open(argv[8]);
	if (!outf) { cout << "output error " << endl; exit(1); }

	for (int i = 0; i < n; ++i)
	{
		char ch;
		sudu.shudu_re(m);
		for (int j = 1; j <= m; ++j)
		{
			for (int k = 1; k <= m; ++k)
			{
				inf >> ch;
				sudu.sd[j][k] = ch - '0';
			}
		}
		sudu.total(m);
		for (int j = 1; j <= m; ++j)
		{
			for (int k = 1; k <= m; ++k)
			{
				ch = sudu.sd[j][k] + '0';
				outf << ch;
				outf << " ";
				outf << " ";
			}
			outf << endl;
		}
		outf << endl;
	}
	inf.close();
	outf.close();
	return 0;
}
