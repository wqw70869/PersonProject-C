#include<cstdio>
#include<fstream>
#include<iostream>
#include <vector>
#include<string>
#include<algorithm>
using namespace std;
typedef pair<string, int> t;
pair<string, int> num[10000];
int word=0;
int jszf(char t[1000])
{   
	int n=0;
	while (t[n] != '\0')
	{
		n++;
	}
	return n;
}
int wordnu(char t[1000],int n2)
{
	int f1=0;
	int i=0;
	int f2 = 0;
	int n = 0;
	char a[100] = {'\0'};
	while (t[i] != '\0')
	{
		if (t[i] >= 'A'&&t[i] <= 'Z')
		{
			a[f1] = t[i] + 32;
			f1++;
		}
		if (t[i] >= 'a'&&t[i] <= 'z')
		{
			a[f1] = t[i];
			f1++;
		}
		if(f1>=4&& (t[i] >= '0' &&t[i] <= '9'))
		{
			a[f1] = t[i];
			f1++;
		}
		if (((t[i]<'A' || (t[i] > 'z'&&t[i] < 'a') || t[i]>'z') && f1 < 4) || (f1 >= 4 && (t[i]<'0' || (t[i] > '9'&&t[i] < 'A') || (t[i] > 'Z'&&t[i] < 'a') || t[i]>'z'))||(f1>=4&&t[i+1]=='\0'))
		{
			if (f1 >= 4)
			{
				
				for (int z = 0; z <n2; z++)
				{
					if (num[z].first== a)
					{
						num[z].second++;
						f2 = 1;
						break;
					}
				}
				if (f2 == 0)
				{
					num[n2].first = a;
					num[n2].second = 1;
					n2++;
				}
				else
				{
					f2 = 0;
				}
				memset(a, '\0', sizeof(a));
				word++;
			}
			f1 = 0;
		}

		i++;
	}
	return n2;
}
bool cmp(const t &a, const t &b)
{
	if (a.second != b.second)
	{
		return a.second > b.second;
	}
	else
	{
		return a.first < b.first;
	}
}
void paixu(int n)
{
	sort(num, num+n, cmp);
}
int main(int argc,char* argv[])
{
	int line = 0;
	char c[1000] = { '\0' };
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;
	int n4 = 0;
	ifstream testfile(argv[1]);
	if (!testfile.is_open())
	{
		ofstream putout("result.txt");
		putout << "ÎÞ´ËÎÄµµ\n";
		putout.close();
	}
	else
	{
		while (!testfile.eof())
		{
			testfile.getline(c, 1000);
			n1 = n1 + jszf(c);
			n2 = wordnu(c,n2);
			if (strlen(c) != 0)
			{
				line++;
			}
			n3++;
		}
	testfile.close();
		paixu(n2);
		if (n2 > 10)
		{
			n2 = 10;
		}
		ofstream putout("result.txt");
		putout << "characters: "<<n1 + n3 - 1 << endl<<"words: " << word << endl<<"lines: "<<line<<endl;
		for (int i = 0; i < n2; i++)
		{
			putout << '<'<<num[i].first<<">: "<<num[i].second<< endl;
		}
		putout.close();
	}

	return 0;
}
