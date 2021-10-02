here is the code for the following:

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[n][n];
	int cnt = 0;
	for(int i=0; i<n; i++) {
	    for(int j=0; j<n; j++) {
	        cin >> arr[i][j];
	        if(arr[i][j] == 0) {
	            cnt++;
	        }
	    }
	}
	cout << cnt << endl;
	return 0;
}
  
