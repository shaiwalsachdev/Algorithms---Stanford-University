#include <bits/stdc++.h>
using namespace std;

// Count inversions
long long int merge(int arr[],int l,int mid,int h){

	int n1 = mid - l + 1;
    int n2 =  h - mid;

    long long int inv = 0;
    int L[n1], R[n2];


    for (int i = 0; i < n1; i++){
        L[i] = arr[l + i];
    //	cout << L[i] << " ";
    }
  //   cout << endl;


    for (int j = 0; j < n2; j++){

        R[j] = arr[mid + 1+ j];
    //    cout << R[j] << " ";
    }



    int i = 0;
    int j = 0;
    int k = l;
    int y = 0;

	while (y < (n1+n2))
    {
        if ((i < n1 &&L[i] <= R[j]) || j == n2)
        {
            arr[k] = L[i];
          	i++;
        }
        else
        {
        	if(L[i] >  R[j]){
        		//cout << L[i] << " " << R[j]<<endl;
        		inv+=(n1-i);

        	}
            arr[k] = R[j];
          	j++;
        }
        k++;
        y++;
    }
  //  cout << inv << endl;
    return inv;

}
long long int merge_sort(int arr[],int l,int h){
	int mid;
	long long int inv = 0;
	if(h > l){

		mid = (l+h)/2;
	 	inv = merge_sort(arr,l,mid);
		inv += merge_sort(arr,mid+1,h);
		inv += merge(arr,l,mid,h);
	}

	return inv;
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    cout << merge_sort(arr,0,n-1) << endl;
    return 0;
}

