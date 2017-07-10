#include <bits/stdc++.h>
using namespace std;

vector <int> reverse_count(3000001); 

vector <int> forward_count(3000001); 

vector <long> fintime(3000001);   


int finish_time =1;
bool satisfiable = true;

void GraphForward(long variables,long track, vector < vector<int> > &graph, long index){
	if (forward_count[track] != 0)
		return ;
	if (forward_count[track] == 0){

		forward_count[track] = index;
		
		if(track > variables){ 
			if(forward_count[track -variables] == index) 
				satisfiable= false; 
		}
		
		if(track <= variables){ 
			if(forward_count[track + variables] == index) 
				satisfiable = false; 
		}

		for (int y=0; y < graph[track].size(); y++)
			GraphForward(variables,graph[track][y], graph,index);
		
		forward_count[track] = index;
		
		return;
	}
}


void GraphRev(long r, vector < vector<int> > &graph_rev){
	if (reverse_count[r] == 1)
		return;
	
	if (reverse_count[r] != 1){
		reverse_count[r] = 1;
	
		for (int z=0; z < graph_rev[r].size(); z++)
	    	GraphRev(graph_rev[r][z] , graph_rev);
	
		
		fintime[finish_time] = r;
	
		finish_time++;
	
		return;
	}	
}

void readclauses(long variables,vector < vector<int> > &graph,vector < vector<int> > &graph_rev){

	// Variables
	int variable1,variable2,firstedge,secondedge;

	//Read the clauses
	for(int i = 1;i <= variables;i++){

		scanf("%d %d",&variable1,&variable2);
		
		if(variable1 < 0)  
			variable1 = variables + abs(variable1);	
		
		if(variable2 < 0) 
			variable2 = variables + abs(variable2);
		
		if(variable1 > variables) 
			firstedge = variable1 -variables;
		else 
			firstedge = variables + variable1;


		if(variable2 > variables)
			secondedge = variable2 -variables;
		else
			secondedge = variables + variable2;
		
		graph[firstedge].push_back(variable2);
		
		graph[secondedge].push_back(variable1);
		
		graph_rev[variable2].push_back(firstedge);
		
		graph_rev[variable1].push_back(secondedge);
		
	}
}

int main (){
	// Read the File

	FILE *fp = freopen("2sat6.txt","r",stdin);
	// variables 
	long variables;

	// Graph and Graph Rev
	vector < vector<int> > graph,graph_rev;  // holds the edges based on index of the original graph
	
	scanf("%ld",&variables);

	// Initialize the vectors
	for(int i = 0; i <= 2 * variables; i++){
	  	vector <int> row;
	  	graph.push_back(row);	
	  	graph_rev.push_back(row);	
	}


	readclauses(variables,graph,graph_rev);

	// Rev
	for(long i = 1; i < graph_rev.size(); i++)
		GraphRev(i, graph_rev);
	

	// Forward
	for(long i = finish_time-1; i > 0; i--){
		long track = fintime[i];
		GraphForward(variables,track, graph,i);
	}  

	if(satisfiable == false)
		cout << "Not satisfiable" << endl;
	else
		cout << "Satisfiable" << endl;

	fclose(fp);
	
	return 0;
}

