/*
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. 
Assume that all bars have the same width and the width is 1 unit. This problem is also known as Maximum Area of Histogram
We can solve it using Nearest Smaller element to the Left problem and Nearest Smaller element to the right problem
*/
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
	int arr[] = {6, 2, 5, 4, 5, 1, 6}; // 1 5 3 5 5 7 7 
	int n = sizeof(arr)/sizeof(arr[0]);

  // Nearest Smaller element to the Left
	vector<int> left;
	stack<pair <int, int>> s1;

    int pseudo_index = -1;
	for(int i=0; i<n ; i++){
		if(s1.size()==0)
			left.push_back(pseudo_index);

		else if(s1.size()>0 && s1.top().first<arr[i])
			left.push_back(s1.top().second);

		else if(s1.size()>0 && s1.top().first>=arr[i]){
			while(s1.size()>0 && s1.top().first>=arr[i])
				s1.pop();

			if(s1.size()==0)
				left.push_back(pseudo_index);
			else
				left.push_back(s1.top().second);
		}
		s1.push({arr[i], i});
	}
  
  // Nearest Smaller element to the right 
    pseudo_index = 7;
    vector<int> right;
	stack<pair <int, int>> s2;
	for(int i=n-1; i>=0; i--){
		if(s2.size()==0)
			right.push_back(pseudo_index);

		else if(s2.size()>0 && s2.top().first<arr[i])
			right.push_back(s2.top().second);

		else if(s2.size()>0 && s2.top().first>=arr[i]){
			while(s2.size()>0 && s2.top().first>=arr[i])
				s2.pop();

			if(s2.size()==0)
				right.push_back(pseudo_index);
			else
				right.push_back(s2.top().second);
		}
		s2.push({arr[i], i});
	}
	reverse(right.begin(), right.end());
  
  
	int width[n] = {};
	int area[n] = {};
	for(int i=0; i<n; i++)
	    width[i] = right[i] - left[i] - 1;
	for(int i=0; i<n; i++)
	    area[i] = width[i]*arr[i];
	cout << *max_element(area, area + n);
	return 0;
}
