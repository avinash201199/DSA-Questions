int maxProduct(int arr[], int n){
    int mn = arr[0], mx = arr[0], res = arr[0];
    for(int i = 1; i<n; i++){
        if(arr[i] < 0) swap(mn, mx);
        mn = min(arr[i], mn*arr[i]);
        mx = max(arr[i], mx*arr[i]);
        res = max(res, mx);
    }
    return res;
}