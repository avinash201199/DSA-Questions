// Question Statement:
// You are given an array prices where prices[i] is the price of a given stock on the ith day. You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Example 1:
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

// Example 2:
// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.

// Constraints:
// - 1 <= prices.length <= 105
// - 0 <= prices[i] <= 104

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// o(n^2) Solution:

int maxProfit1(int price[], int n)
{
    if (n == 1)
    {
        return 0;
    }
    int maxprice = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            maxprice = max(maxprice, price[j] - price[i]);
    }
    return maxprice;
}
// By o(n) space and time approach
int maxProfit2(int price[], int n)
{
    if (n == 1)
    {
        return 0;
    }
    int maxprice = 0;
    vector<int> v;
    v.push_back(price[n - 1]);
    int maxi = price[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        maxi = max(price[i], maxi);
        v.push_back(max(maxi, price[i]));
    }

    for (int i = 0; i < n; i++)
        maxprice = max(maxprice, v[i] - price[i]);

    return maxprice;
}
// By o(n) time approach
int maxProfit3(int price[], int n)
{
    if (n == 1)
    {
        return 0;
    }
    int maxprice = 0,maxele=price[0];
    for (int i = 0; i < n; i++)
    {
        maxele=max(price[i],maxele);
        maxprice=max(maxprice,maxele-price[i]);
    }
    
    return maxprice;
}
int main()
{
    int price[] = {100, 180, 260, 310,
                   40, 535, 695};
    int n = sizeof(price) / sizeof(price[0]);

    cout << "By o(n^2) approach: " << maxProfit1(price, n) << endl;

    cout << "By o(n) time and space approach: " << maxProfit2(price, n) << endl;
    cout << "By o(n) time with o(1) space approach: " << maxProfit2(price, n) << endl;

    return 0;
}