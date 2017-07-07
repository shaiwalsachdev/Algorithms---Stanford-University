
#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int,pair<double,double > > &a,const pair<int,pair<double,double > > &b)
{
    if (a.second.second > b.second.second)
        return true;
    else if(a.second.second == b.second.second){
        if(a.second.first > b.second.first)
            return true;
    }
        return false;
}

int main(){


    vector<pair<int,pair<double,double > > >diff;

    FILE *fp = freopen("jobs.txt","r",stdin);

    int number = 0;
    scanf("%d", &number);
    //cout << number << endl;

    int w;
    int l;
    while (scanf("%d %d", &w, &l) > 0) {
           diff.push_back(make_pair(l,make_pair(w,w/(double)l)));
    }
    fclose(fp);

    sort(diff.begin(), diff.end(), sortbysec);

    long long weightedsum = 0;
    long lengthsum = 0;
    for(int i = 0;i < diff.size();i++){
            lengthsum += diff[i].first;
          //  cout <<lengthsum << endl;
            weightedsum += diff[i].second.first * lengthsum;
           cout << diff[i].second.first << " " << (diff[i].first) <<" " << diff[i].second.second << " " << lengthsum<<" " << weightedsum <<endl;
    }

    cout << weightedsum << endl;

    return 0;
}

