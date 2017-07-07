#include<bits/stdc++.h>
using namespace std;
struct subset
{
	int parent;
	int rank;
};
int findme(subset* subs, int i){
	if(subs[i].parent!=i)
        subs[i].parent = findme(subs,subs[i].parent);

	return subs[i].parent;
}
void Union(subset* subs, int u, int v){
	int x = findme(subs,u);
	int y = findme(subs,v);
	if(subs[x].rank==subs[y].rank){
		subs[y].parent = x;
		subs[x].rank++;
	}else if(subs[x].rank<subs[y].rank)
            subs[x].parent = y;
	else subs[y].parent = x;
}


bool sortbysec(const pair<int,pair<int,int > > &a,const pair<int,pair<int,int > > &b)
{
    return (a.first < b.first);
}

int main(){
    //vector<int,pair<int,int > > graph;
    vector<pair<int,pair<int,int > > > graph;

    FILE *fp = freopen("clustering1.txt","r",stdin);

    int nodes = 0;
    scanf("%d", &nodes);
    //cout << number << endl;

    int source;
    int destination;
    int cost;
    while (scanf("%d %d %d", &source, &destination,&cost) > 0) {
        graph.push_back(make_pair(cost,make_pair(source,destination)));
    }

    sort(graph.begin(),graph.end(),sortbysec);


    subset subs[nodes+1];
    for(int i=1; i<=nodes; i++){
		subs[i].parent=i;
		subs[i].rank=0;
	}


   // vector<pair<int, pair<int, int> > > res;
   //  For 4 cluster max spacing keep adding edges until you have added 496 edges , not moment you add 497th, that is max spacing one
	int counter = 1;
	int j=0;
	for(int j = 0; j < graph.size();j++){
		int x = findme(subs, graph[j].second.first);
		int y = findme(subs, graph[j].second.second);
		if(x!=y){

			if(counter == 497){
                cout << graph[j].first << endl;
                break;
			}
	//		res.push_back(make_pair(graph[j].first, make_pair(graph[j].second.first, graph[j].second.second)));
			Union(subs,x,y);

			counter++;
		}
	}


    fclose(fp);

    return 0;
}
