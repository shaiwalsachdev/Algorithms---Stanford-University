#include <bits/stdc++.h>
using namespace std;


int main()
{
	// Read the file	
	FILE *fp = freopen("mwis.txt","r",stdin);
     int nodes = 0;
     scanf("%d", &nodes);
    	
     int weight[nodes+1];
     weight[0] = 0;
     int w;
     for(int i = 1;i <= nodes;i++){
        scanf("%d", &w);
       	weight[i] = w;
	}
     
    int dp[nodes + 1];
    dp[0] = 0;
    dp[1] = weight[1];

    for(int i = 2 ; i <=nodes; ++i){
        dp[i] = max( dp[i-1] , dp[i-2] + weight[i] );
    }
 	
 	int i = nodes;
 	//1, 2, 3, 4, 17, 117, 517, and 997

 	map<int,int> mp;
 	mp[1] = 0;
 	mp[2] = 0;
 	mp[3] = 0;
 	mp[4] = 0;
 	mp[17] = 0;
 	mp[117] = 0;
 	mp[517] = 0;
 	mp[997] = 0;

 	map<int,int>::iterator it;
 	cout <<"Items in the Result Set --------------------- " << endl;
 	for(int n = nodes;n > 1;){
 		if(dp[i-2]+weight[i] > dp[i-1]){
 			
 			if(mp.find(i) != mp.end())
        		mp[i] = 1;
            
            cout << i <<" , ";
            
            i = i - 2;

            if(i == 1){
            	cout << 1 << endl;
            	mp[1] = 1;
            	break;
            }
 		}
 		else{
 			i = i - 1;
 		}
 	}
    cout << "Result-------> " <<mp[1]<<mp[2]<<mp[3]<<mp[4]<<mp[17]<<mp[117]<<mp[517]<<mp[997]<< endl;
    return 0;
}