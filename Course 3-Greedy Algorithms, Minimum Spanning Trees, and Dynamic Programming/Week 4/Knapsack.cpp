#include <bits/stdc++.h>
using namespace std;
long long knapsack(vector<int> &weight,vector<int> &value,int items,int W){
	// Table T
    vector<vector<long long > >T(2);

    for(int j = 0;j < 2;j++){
    	T[j].resize(W+1);
    }
  // Initialize
    for(int j=0; j<=W; j++) 
    	T[0][j]=0;
    
    for(int i = 1; i <= items; i++)
    {
        for(int x = 0; x <= W; x++){
	         if(x >= weight[i])
	            T[1][x] = max(T[0][x], T[0][x-weight[i]] + value[i]);
	         else
	            T[1][x] = T[0][x];
        }

        for(int j = 0; j <= W; j++)
        	T[0][j] = T[1][j];
    }

    return T[1][W];

}

int main()
{
	// Read the file	
	FILE *fp = freopen("knapsack_big.txt","r",stdin);
	//FILE *fp = freopen("knapsack_small.txt","r",stdin);
	 int W = 0;
     int items = 0;
     scanf("%d %d", &W,&items);
     int v;
     int w;

     vector<int>weight(items +1);
     vector<int> value(items + 1);

  	for(int i = 1;i <=items;i++){
        scanf("%d %d", &v,&w);
        value[i] = v;
        weight[i]= w;
	}
	fclose(fp);
	
	cout<<"Knapsack Solution: "<<knapsack(weight,value,items,W)<<endl;
    return 0;
}
