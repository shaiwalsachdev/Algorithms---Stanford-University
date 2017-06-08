#include<bits/stdc++.h>
using namespace std;

long long int total_comparisons = 0;

int partitionfirst(int A[],int l,int r){
    int pivot = A[l];
    int i = l + 1;
    for(int j = l + 1;j <=r;j++){
        if(A[j] < pivot){
            swap(A[i],A[j]);
            i++;
        }
    }

    swap(A[i-1],A[l]);
    return (i-1);
}

void quick_sort(int arr[],int l,int h){
	int p;
	long long int comparisons = 0;
	if(h > l){
        p = partitionfirst(arr,l,h);
        total_comparisons = total_comparisons + (long long int)(h-l);
       // cout << total_comparisons << endl;
	 	quick_sort(arr,l,p-1);
	 	quick_sort(arr,p+1,h);

    }
}


int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    quick_sort(arr,0,n-1);
    cout << total_comparisons << endl;
    return 0;
}
