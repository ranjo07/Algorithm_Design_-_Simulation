/*     ॐ हौं जूं सः ॐ भूर्भुवः स्वः ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम्
       उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय मामृतात् ॐ स्वः भुवः भूः ॐ सः जूं हौं ॐ।
*/

// Date: 28/03/2023


#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

void findPath(int x1,int y1, int x2, int y2, int tm, map<vector<int>,int> &isAvilable,int m, int n, int cnt,int &curr,vector<pair<int,pair<int,int>>> &curr_path,vector<pair<int,pair<int,int>>> tmp_path,bool &possibleWays,vector<vector<int>> &vis)
{
  vis[x1][y1] = 1;
  
  if(x1==x2 && y1==y2)
  {
    if(cnt<curr)
    {
      possibleWays = true;
      curr_path = tmp_path;
      curr = cnt;
      
    }
    vis[x1][y1] = 0;

    return;
  }

  if(cnt>400)
  {
    return;
  }
  

  vector<pair<int,int>> dir = {{0,0},{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
  

  for(auto it:dir)
  {
    int x = x1 + it.first;
    int y = y1 + it.second;
    if(x>=0 && x<m && y>=0 && y<n && isAvilable.find({x,y,tm+1})==isAvilable.end() && vis[x][y]==0){
    tmp_path.push_back({x,{y,tm+1}});
    findPath(x,y,x2,y2,tm+1,isAvilable,m,n,cnt+1,curr,curr_path,tmp_path,possibleWays,vis);
    tmp_path.pop_back();

    }

  }
  vis[x1][y1] = 0;

}


int main(){


    int m,n;
    cin>>m>>n;

    int drone;
    cin>>drone;

    vector<vector<int>> inf;
    map<vector<int>,int> isAvilable;
    priority_queue<pair<vector<int>,int>, vector<pair<vector<int>,int>>, greater<pair<vector<int>,int>>> pq;
    for(int i=0;i<drone;i++)
    {
      int x1,y1,x2,y2,t;
      cin>>x1>>y1>>x2>>y2>>t;
      inf.push_back({x1,y1,x2,y2,t});
      pq.push({inf[i],i});
      isAvilable[{x1,y1,t}]++;
    }
    

    map<int,vector<vector<int>>> path;
    while(!pq.empty())
    {
      int no_of_drone = pq.top().second;
      vector<int> inft = pq.top().first;
      pq.pop();

      vector<pair<int,pair<int,int>>> curr_path;
      vector<pair<int,pair<int,int>>> tmp_path;

      bool possibleWays = false;

      vector<vector<int>> vis(m,vector<int>(n,0));
      int mxi = INT_MAX;

      findPath(inft[0],inft[1],inft[2],inft[3],inft[4],isAvilable,m,n,0,mxi,curr_path,tmp_path,possibleWays,vis);

      if(possibleWays == false)
      {

        path[no_of_drone] = {{-1,-1,-1}};
        continue;
      }
      vector<vector<int>> vtmp;
      for(auto it:curr_path)
      {
        vtmp.push_back({it.first,it.second.first,it.second.second});
        isAvilable[{it.first,it.second.first,it.second.second}];

      }

      path[no_of_drone] = vtmp;

    }

    for(int i=0;i<drone;i++)
    {
      cout<<i<<"th drone path: "<<endl;
      for(auto it:path[i])
      {
        cout<<it[0]<<" "<<it[1]<<" "<<"at time - "<<" "<<it[2]<<endl;
      }
    }


    
    
return 0;
}
/*---------------------rkranjan41925@gmail.com------------------------------------------*/
