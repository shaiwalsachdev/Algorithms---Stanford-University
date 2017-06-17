#include <bits/stdc++.h>
using namespace std;
#include <string>
#include <sstream>


#define ITERATIONS 20
int stoi(string s){
    int length = s.length();
    if(length == 1){
        return ((s[0]-'0')*1)- 1;
    }
    if(length == 2){
        return ((s[0]-'0')*10  +  (s[1]-'0')*1) - 1;
    }
    if(length == 3){
        return ((s[0]-'0')*100 + (s[1]-'0')*10 + (s[2]-'0')*1) - 1;
    }
    return -1;

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

int countgraph(map<int,vector<int> > mymap){
    int c = 0;
    for (map<int,vector<int> >::iterator it=mymap.begin(); it!=mymap.end(); ++it){
            //cout << it->first << " => " << " ";
            vector<int> v = it->second;
            for(int j = 0;j < v.size();j++){
                c++;
            }
            cout << endl;
    }
    return (c/2);
}



int minimum_cut(map<int,vector<int> > graph){
//    cout << graph.size() << endl;

    while(graph.size() > 2){

        //int first = rand()%(graph.size());

        map<int,vector<int> >:: iterator it = graph.begin();
        advance(it, rand() % graph.size());
        int first = it->first;
        vector<int> temp = graph[first];
        int sizeofirst = temp.size();
        int last = rand()%sizeofirst;
        int elementlast = graph[first][last];

     //   cout << graph.size()<<endl;
      //  cout << first << " " << sizeofirst << " " << elementlast << endl;
        for(int i = 0;i < graph[elementlast].size(); i++){
            if(graph[elementlast][i] != first)
                graph[first].push_back(graph[elementlast][i]);
        }

        for(int i = 0;i < graph[elementlast].size(); i++){
 //           vector<int> vec = graph[graph[elementlast][i]];

            for(int j = 0;j  < graph[graph[elementlast][i]].size();j++){
                if(graph[graph[elementlast][i]][j] == elementlast){
                    graph[graph[elementlast][i]].erase(graph[graph[elementlast][i]].begin() + j);
                    break;
                }
            }
     //       vec.erase (remove(vec.begin(), vec.end(), elementlast), vec.end());
            if(graph[elementlast][i] != first)
                graph[graph[elementlast][i]].push_back(first);
        }
        graph.erase(elementlast);


//        printgraph(graph);
    }

    int x = countgraph(graph);
    return x;
}

int main(){

    map<int,vector<int> > graph;
    //vector< vector<int> > graph(200);
    // Read File
    FILE *fp = fopen("kargerMinCut.txt","r");
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

                if (isdigit(c)){
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
                      //        cout <<stoi(source) << " "<< stoi(destination) << endl;
                              graph[stoi(source)].push_back(stoi(destination));
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


    int mini = 10000;
  //  cout <<graph[197].size() << endl;
    for(int iter = 0; iter < ITERATIONS; iter++){
            cout << "Iteration ===== "<<iter<<endl;
            int cut = minimum_cut(graph);
            //cout << cut << endl;
            if(cut < mini  & cut > 1)
                mini = cut;

    }

    cout << mini << endl;


    return 0;
}
