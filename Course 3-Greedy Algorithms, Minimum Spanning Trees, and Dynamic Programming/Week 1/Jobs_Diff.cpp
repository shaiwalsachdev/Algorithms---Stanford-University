
#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    if (a.second > b.second)
        return true;
    else if(a.second == b.second){
        if(a.first > b.first)
            return true;
    }
        return false;
}

int main(){


    vector<pair<int,int > > diff;

    FILE *fp = freopen("jobs.txt","r",stdin);

    int number = 0;
    scanf("%d", &number);
    //cout << number << endl;

    int w;
    int l;
    while (scanf("%d %d", &w, &l) > 0) {
           diff.push_back(make_pair(w,w-l));
    }
    fclose(fp);

    sort(diff.begin(), diff.end(), sortbysec);

    long long weightedsum = 0;
    long lengthsum = 0;
    for(int i = 0;i < diff.size();i++){
            lengthsum += (diff[i].first - diff[i].second);
          //  cout <<lengthsum << endl;
            weightedsum += diff[i].first * lengthsum;
           // cout << diff[i].first << " " << (diff[i].first - diff[i].second) <<" " << diff[i].second << " " << lengthsum<<" " << weightedsum <<endl;
    }

    cout << weightedsum << endl;

    return 0;
}
