#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

void printoptimalparens(vector< vector<int> > &s, int i, int j)
{
	//cout << "printing" << endl;
	if(i == j)
	{
		cout << "A" << i-1;
	}
	else
	{
		cout << "(";
		printoptimalparens(s,i,s[i][j]);
		printoptimalparens(s,s[i][j]+1,j);
		cout << ")";
	}

}

void MatrixChainOrder(int* p, int n)
{
	int m[n][n];
	vector< vector<int> > s(n,vector<int>(n, 0));
	/*s.resize(n-1);
	for(int i = 0; i < n-2; i++)
	{
		s[i].resize(n);
	}*/
	int j, q, l;
	for(int i = 1; i < n; i++)
	{
		//cout << "setting m diagronal to 0" << endl;
		m[i][i] = 0;
	}
	for(l = 2; l < n; l++)
	{
		//cout << "first for" << endl;
		for(int i = 1; i < n-l+1; i++)
		{
			//cout << "second for" << endl;
			j = i + l - 1;
			//m[i][j] = 2147483647;
			m[i][j] = 2000000000;
			for(int k = i; k <= j-1; k++)
			{
				//cout << "third for" << endl;
				q = m[i][k] + m[k+1][j] + (p[i-1]*p[k]*p[j]);
				if(q < m[i][j])
				{
					//cout << "if is m" << endl;
					m[i][j] = q;
					//cout << "if is s" << endl;
					s[i][j] = k;
					//cout << "if done" << endl;
				}
				//cout << "if ended" << endl;
			}
		}
	}
	cout << m[1][n-1] << endl;
	printoptimalparens(s,1,n-1);
	cout << endl;
}


int main(int argc,char **argv)
{
	int num;
	cin >> num;
	int n = num + 1;
	int p[n];
	for(int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	//cout << "calling matrixchainorder" << endl;
	MatrixChainOrder(p,n);
}
