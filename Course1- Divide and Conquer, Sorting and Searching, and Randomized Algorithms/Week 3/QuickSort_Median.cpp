#include<bits/stdc++.h>
using namespace std;

int total_comparisons = 0;
int findmedian(int arr[], int length)
{
    int first  =  0;
    int last = length - 1;
    int middle;
    if(length%2 == 0){
        middle  = length/2 - 1;
    }
    else{
        middle = length /2;
    }

    int f_element  = arr[first];
    int m_element = arr[middle];
    int l_element   = arr[last];

    int compare[3];
    int ans = 0;
    compare[0]  = f_element;
    compare[1] = m_element;
    compare[2] = l_element;
    sort(compare,compare+3);

    if(compare[1] == f_element)
        ans = first;
    if(compare[1] == m_element)
        ans = middle;
    if(compare[1] == l_element)
        ans = last;

    return ans;
}
int partitionmedian(int A[],int length){

    int pivot = A[0];
    int i = 1;
    for(int j = 1;j < length;j++){
        if(A[j] < pivot){
            swap(A[i],A[j]);
            i++;
        }
    }

    swap(A[i-1],A[0]);
    return (i-1);
}

long long  quick_sort(int arr[],int length){
    if(length <=1) return 0;

    int pivot = findmedian(arr,length);

    swap(arr[0],arr[pivot]);

    int pos = partitionmedian(arr,length);

    total_comparisons = total_comparisons + (length-1);
    quick_sort(arr,pos);
    quick_sort(arr+pos+1,length-pos-1);

}



int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    quick_sort(arr,n);
    cout << total_comparisons << endl;
    return 0;
}

