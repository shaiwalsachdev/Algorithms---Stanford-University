#include <bits/stdc++.h>
using namespace std;
#include <string>
#include <sstream>
#define INF 999999
#include<limits.h>

// Just string to integer
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
// Finding Min vertex each time
int findmin(map<int,int> &distance,map<int,int> &visited){
    int mini = INT_MAX;
    int index = -1;
    for(map<int,int>::iterator it = distance.begin();it != distance.end();it++){
        if (it->second < mini && visited[it->first] == 0){
                index = it->first;
                mini = it->second;
        }
    }
    return index;

}
// Traversing over the vertices
void dijikstra(map<int,vector< pair <int,int> > > graph, map<int,int> &visited, map<int,int> &distance){

    for(int i = 1;i <=graph.size();i++){
        int get_min = findmin(distance,visited);
        cout << get_min << endl;
        visited[get_min] = 1;
        for(int j = 0; j < graph[get_min].size();j++){
            if(visited[graph[get_min][j].first] == 0 && distance[get_min] != INF && distance[get_min] + graph[get_min][j].second < distance[graph[get_min][j].first])
                distance[graph[get_min][j].first] = distance[get_min] + graph[get_min][j].second ;
        }
    }
}



int main(){

    // Storing graph
    map<int,vector< pair <int,int> > > graph;

    // Visited and Distance
    map<int,int> visited;
    map<int,int> distance;
    //vector< vector<int> > graph(200);
    // Read File
    FILE *fp = fopen("dijkstraData.txt","r");
    string line;
    int c = fgetc(fp);
    string source = "";
    string destination = "";
    int flag = 0;
    while(c != EOF){
            source = "";
            destination = "";
            flag = 0;
            while(true){

                if (isdigit(c) or c == ','){
                       // cout << " Hee";
                        if(flag == 0)
                            source = source + (char)c;
                        if(flag == 1)
                            destination = destination + (char)c;
                }
                if(isspace(c)){
                    if(flag == 0){

                        flag = 1;
                    }
                    if(flag == 1){
                            if(isdigit(destination[0])){
                              cout <<source << " "<< destination << endl;
                              //Split Destination into Two Parts
                              string dest= "";
                              string destlength= "";
                              int f = 0;
                              for(int z = 0; z < destination.length();z++){
                                    if(destination[z] == ','){
                                        f = 1;
                                        continue;
                                    }

                                    if(f == 0)
                                        dest = dest + (char)destination[z];
                                    else
                                        destlength = destlength + (char)destination[z];
                               }
                           //    cout << stoi(source) << " "<<stoi(dest)<< " " << stoi(destlength) << endl;
                                graph[stoi(source)].push_back(make_pair(stoi(dest),stoi(destlength)));
                                visited[stoi(source)] = 0;
                                distance[stoi(source)] = INF;
                           }

                        destination = "";
                    }
                }

                c = fgetc(fp);
                if(c == '\n')
                    break;
            }
             c = fgetc(fp);
    }

    distance[1] = 0;
    dijikstra(graph,visited,distance);

    // Printing shortest distances
    for(map<int,int>::iterator it = distance.begin();it != distance.end();it++){
        cout << it->first << "---->" << it->second << endl;
    }

    return 0;
}
