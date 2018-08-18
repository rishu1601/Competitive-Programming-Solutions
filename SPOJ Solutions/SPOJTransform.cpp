#include <bits/stdc++.h>
using namespace std;
int isOperand(char ch)
{
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
int Prec(char ch)
{
	switch (ch)
	{
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	case '^':
		return 3;
	}
	return -1;
}

int Solve(char* ex)
{
	int i, k;
    stack<char> s;
	for (i = 0, k = -1; ex[i]; ++i)
	{
		if (isOperand(ex[i]))
			ex[++k] = ex[i];
		else if (ex[i] == '(')s.push(ex[i]);
		else if (ex[i] == ')')
		{
			while (!s.empty() && s.top()!= '(')
				{
				    ex[++k]=s.top();
				    s.pop();
				}
			if (!s.empty() && s.top()!= '(')
				return -1;			 
			else
				s.pop();
		}
		else 
		{
			while (!s.empty()&& Prec(ex[i]) <= Prec(s.top()))
				{
				    ex[++k]=s.top();
				    s.pop();
				}
			s.push(ex[i]);
		}

	}
	while (!s.empty())
		{
		    ex[++k]=s.top();
		    s.pop();
		}
	ex[++k] = '\0';
	printf("%s\n",ex);
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		char s[1001];
		scanf("%s",&s);
		Solve(s);
	}
	return 0;
}

