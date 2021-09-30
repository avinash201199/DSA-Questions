// Q) Palindrome Number

// Given an integer x, return true if x is palindrome integer.
// An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.

#include <bits/stdc++.h>
using namespace std;

// function to check whether number is palindrome or not
bool isPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }
    int n = x;
    long long ans = 0;
    while (x > 0)
    {
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    return n == ans;
}

// main function
int main()
{
    int num;
    cin >> num;
    if (isPalindrome(num))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    return 0;
}

// Example 1 :
// Input : x = 121
// Output : true

// Example 2 :
// Input : x = -121
// Output : false
// Explanation : From left to right,it reads - 121. From right to left, it becomes 121 -.Therefore it is  not a palindrome.