
#include <bits/stdc++.h>
using namespace std;
#include <string>
#include <sstream>

int timer = 0;
int connectedcomponents = 0;
map<int,int> components;

map<int,int> finishingtime;
void dfs(map<int,vector<int> > graph,int vertex,map<int,int> &visited){
    visited[vertex] = 1;
    for(int i = 0;i < graph[vertex].size(); i++){
            if (visited[graph[vertex][i]] == 0){
                dfs(graph,graph[vertex][i],visited);
            }
    }
    timer++;
    finishingtime[vertex] = timer;
    components[connectedcomponents] = components[connectedcomponents] + 1;
   // cout << vertex << "--->" << timer<< endl;
}

void dfs_stlstack(map<int,vector<int> > graph,int vertex,map<int,int> &visited){
    stack<int> st;
    st.push(vertex);
    visited[vertex] = 1;
    while(!st.empty()){
        int top = st.top();
        timer++;
        finishingtime[top] = timer;
        cout << top << "--->" << timer<< endl;
        components[connectedcomponents] = components[connectedcomponents] + 1;
        st.pop();
        for(int i = 0;i < graph[top].size(); i++){
            if (visited[graph[top][i]] == 0){
                visited[graph[top][i]] = 1;
                st.push(graph[top][i]);
            }
        }

    }


   // cout << vertex << "--->" << timer<< endl;
}

void dfs_loop_stlstack(map<int,vector<int> > graph,map<int,int > visited){
    int len = graph.size();
    for (int j = len;j > 0;j--){
         //   cout << j<< endl;

            if (visited[j] == 0){
                connectedcomponents++;
                components[connectedcomponents] = 0;
                dfs_stlstack(graph,j,visited);
            }
    }
}


void dfs_loop(map<int,vector<int> > graph,map<int,int > visited){
    int len = graph.size();
    for (int j = len;j > 0;j--){
         //   cout << j<< endl;

            if (visited[j] == 0){
                connectedcomponents++;
                components[connectedcomponents] = 0;
                dfs(graph,j,visited);
            }
    }
}
void printgraph(map<int,vector<int> > mymap){
    for (map<int,vector<int> >::iterator it=mymap.begin(); it!=mymap.end(); ++it){
            cout << it->first << " => " << " ";
            vector<int> v = it->second;
            for(int j = 0;j < v.size();j++){
                cout << v[j] << " ";
            }
            cout << endl;
    }

}
void printcompo(map<int,int > mymap){
    for (map<int,int >::iterator it=mymap.begin(); it!=mymap.end(); ++it){
            cout << it->first << " => " << " ";
            cout << it->second << endl;
    }

}

int stoi(string s){
    int length = s.length();
    if(length == 1){
        return ((s[0]-'0')*1);
    }
    if(length == 2){
        return ((s[0]-'0')*10  +  (s[1]-'0')*1);
    }
    if(length == 3){
        return ((s[0]-'0')*100 + (s[1]-'0')*10 + (s[2]-'0')*1);
    }
    if(length == 4){
        return ((s[0]-'0')*1000 + (s[1]-'0')*100 + (s[2]-'0')*10 + (s[3]-'0')*1);
    }
    if(length == 5){
        return ((s[0]-'0')*10000 + (s[1]-'0')*1000 + (s[2]-'0')*100 + (s[3]-'0')*10 + (s[4]-'0')*1);
    }
    if(length == 6){
        return ((s[0]-'0')*100000+ (s[1]-'0')*10000 + (s[2]-'0')*1000 + (s[3]-'0')*100 + (s[4]-'0')*10 + (s[5]-'0')*1);
    }
    return -1;

}
int main(){

    map<int,vector<int> > graph;
     map<int,vector<int> > graphrev;
      map<int,vector<int> > graphnew;
     map<int,int > visited;
    //vector< vector<int> > graph(200);

    // Read File
    FILE *fp = fopen("TestFile_new.txt","r");
    //string line;
    int c = fgetc(fp);
    string source = "";
    string destination = "";
    int flag = 0;


    while(c != EOF){
            source = "";
            destination = "";
            flag = 0;
            while(true){

                if (isdigit(c)){
                       // cout << " Hee";
                        if(flag == 0)
                            source = source + (char)c;
                        if(flag == 1)
                            destination = destination + (char)c;
                }
                if(isspace(c)){
                    if(flag == 0){
            //            cout <<stoi(source) << " "<< endl;
                        flag = 1;
                    }
                    if(flag == 1){
                            if(isdigit(destination[0])){
                              cout <<stoi(source) << " "<< stoi(destination) << endl;
                              graph[stoi(source)].push_back(stoi(destination));
                              graphrev[stoi(destination)].push_back(stoi(source));
                              visited[stoi(source)] = 0;
                              // graph[stoi(source)] = stoi(destination);
                            }
                        //graph[0].push_back(0);
                       // cout <<stoi(source) << " "<< stoi(destination) << endl;
                        destination = "";
                    }
                }

                c = fgetc(fp);
                if(c == '\n')
                    break;
            }
             c = fgetc(fp);
    }

/*
    // Read from file
    FILE* fp=freopen("SCC.txt","r",stdin);
    int source, destination;
    while (scanf("%d %d", &source, &destination) > 0) {
        cout << source << " " << destination<<endl;
            graph[source].push_back(destination);
            graphrev[destination].push_back(source);
            visited[source] = 0;
    }
    fclose(fp);
    cout <<"Reading .... DOne" << endl;
    //printgraph(graph);
    // Write to fi;e
    FILE* fp1=fopen("SCC_new.txt","w");
    //int source, destination;
    for (map<int,vector<int> >::iterator it=graph.begin(); it!=graph.end(); ++it){
            fprintf(fp1,"%d ",it->first);
            //cout << it->first << " ";
            vector<int> v = it->second;
            for(int j = 0;j < v.size();j++){
                fprintf(fp1,"%d ",v[j]);
              //  cout << v[j] << " ";
            }
          //  cout << endl;
            fprintf(fp1,"\n");
    }


    fclose(fp1);
*/
    // Make the finishing time array
    //printgraph(graph);
    //printgraph(graphrev);
   // dfs_loop(graphrev,visited);

   cout << "Making Finishing Time" << endl;
   dfs_loop(graphrev,visited);
    //dfs_loop_stlstack(graphrev,visited);
   // printgraph(finishingtime);

    // Change graph by finishing time
    for (map<int,vector<int> >::iterator it=graph.begin(); it!=graph.end(); ++it){
            vector<int> v = it->second;
            for(int j = 0;j < v.size();j++)
                graphnew[finishingtime[it->first]].push_back(finishingtime[v[j]]);

    }

    //printgraph(graphnew);
    connectedcomponents  = 0;
    dfs_loop(graphnew,visited);
   // dfs_loop_stlstack(graphnew,visited);
    printcompo(components);

    return 0;
}
