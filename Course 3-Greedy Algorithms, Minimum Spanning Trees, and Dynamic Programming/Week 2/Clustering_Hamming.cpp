#include <bits/stdc++.h>
using namespace std;
vector<int> candidates(300,0);
void createcandidates(){
    int k = 0;
    for(int i = 0;i < 24;i++){
        for(int j = i;j < 24;j++){
            int m = 1 << i;
            int m2 = 1 << j;
            candidates[k++] = m | m2;
        }
    }
}
void read(vector<int> &nodes_in_graph,vector<int> &index){
     FILE *fp = freopen("clustering_big.txt","r",stdin);
     int nodes = 0;
     int bits = 0;
     scanf("%d %d", &nodes,&bits);
     int cluster = 1;
     for(int i = 0;i < nodes;i++){
        int num = 0;
        int bit = 0;
        for(int j = 0;j < bits;j++){
            scanf("%d", &bit);
            num  = num + bit*pow(2,23-j);
        }
        //cout << num << endl;
        index.push_back(num);
        nodes_in_graph[num] = cluster;
        //cout << nodes_in_graph[num] << endl;
        cluster++;
     }
     
     fclose(fp);
}

int main(){
    createcandidates();
    vector<int> nodes_in_graph(pow(2,24),0);
    vector<int> index;
    vector<int> newclust;
    vector<int> tempclust;
    vector<int> neighborslist;
    read(nodes_in_graph,index);

    cout << " Reading Done..." << endl;
    cout << index.size() << endl;
    
    
    vector<int> groups;
    groups.push_back(0);
    int counter  = 0;
    for(int i = 0;i < index.size();i++){
        int flag = 0;
        for(int f = 0; f < groups.size();f++){
            if(groups[f] == nodes_in_graph[index[i]])
             {
                flag = 1;
                break;
             }   
        }

        if(flag == 1){
            continue;
        }
        
        newclust.clear();
        newclust.push_back(index[i]);
        
        while(newclust.size() != 0){
            tempclust.clear();
            for(int j = 0;j < newclust.size();j++){
                //cout << nclust[j]<< endl;
                neighborslist.clear();
                for(int ii = 0;ii < candidates.size();ii++){
      
                    int y = newclust[j]^candidates[ii];
            
                     if(nodes_in_graph[y] != 0){
                          
                            neighborslist.push_back(y);
                            
                    }
                }
                /*
                for(int n = 0;n < neighborslist.size();n++){
                    cout << neighborslist[n] << ",";
                }
                cout << endl;
                */
                for(int k = 0;k < neighborslist.size();k++){
                    if(nodes_in_graph[neighborslist[k]] != nodes_in_graph[index[i]]){
                        tempclust.push_back(neighborslist[k]);
                      
                        nodes_in_graph[neighborslist[k]] = nodes_in_graph[index[i]];

                    }
                }
            }
            newclust.clear();
            for(int m = 0; m < tempclust.size();m++)
                newclust.push_back(tempclust[m]);
        
            cout << groups.size()-1 << endl;
        }
        groups.push_back(nodes_in_graph[index[i]]);
       
    }

   cout << groups.size()-1 << endl;
    
    return 0;
}

