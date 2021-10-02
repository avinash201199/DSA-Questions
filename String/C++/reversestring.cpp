// C++ program to print reverse
// of words in a string.
#include<iostream>

using namespace std;

string wordReverse(string str)
{
	int n = str.length() - 1;
	int start, end = n + 1;
	string result = "";
	
	while(n >= 0)
	{
		if(str[n] == ' ')
		{
			start = n + 1;
			while(start != end)
				result += str[start++];
			
			result += ' ';
			
			end = n;
		}
		n--;
	}
	start = 0;
	while(start != end)
		result += str[start++];
	
	return result;
}

int main()
{
	string str = "I want to work on this issue";
	
	cout << wordReverse(str);
	
	return 0;
}

