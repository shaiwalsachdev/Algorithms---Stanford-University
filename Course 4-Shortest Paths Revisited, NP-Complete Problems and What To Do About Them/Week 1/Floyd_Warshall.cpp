#include <bits/stdc++.h>
using namespace std;
#define INF 99999
int main()
{
	// Read the file	
	//FILE *fp = freopen("g1.txt","r",stdin);
	//FILE *fp = freopen("g2.txt","r",stdin);
	FILE *fp = freopen("g3.txt","r",stdin);
	int vertices = 0;
	int edges = 0;
	scanf("%d %d", &vertices,&edges);
    vector<vector<int> >distance(vertices + 1);

    for(int i = 1;i < (vertices + 1);i++){
    	distance[i].resize(vertices + 1,INF);
    }


    // Set Diagonal
    for(int i = 1;i < vertices+1;i++){
    	for(int j = 1;j < vertices +1;j++){
    		if(i == j)
    			distance[i][j] = 0;
    	}
    }

    int s;
    int d;
    int w;

  	for(int i = 1;i <=edges;i++){
        scanf("%d %d %d", &s,&d,&w);
        distance[s][d] = w;
	}
	fclose(fp);


	for (int k = 1; k <=vertices; k++)
    {
        
        for (int i = 1; i <=vertices; i++)
        {
           
            for (int j = 1; j <=vertices; j++)
            {
                if (distance[i][k] + distance[k][j] < distance[i][j])
                    distance[i][j] = distance[i][k] + distance[k][j];
            }
        }
    }
	int cycle = 0;

    for(int i = 1;i < vertices+1;i++){
    	for(int j = 1;j < vertices +1;j++){
    		if(i == j & distance[i][j] < 0){
    			cycle = 1;
    		}
    	}
    }
    
    if(cycle == 1){
    	cout << "Cycle Found Oops!!!" << endl;
	}
	else{
		int min = INF;
		for(int i = 1;i < vertices+1;i++){
    	for(int j = 1;j < vertices +1;j++){
    		if(distance[i][j] < min){
    			min = distance[i][j];
    		}
    	}
    }
    cout << " Shortest Shortes Path is : "<< min<<endl;

	}

    return 0;
}
