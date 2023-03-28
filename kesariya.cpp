/*     ॐ हौं जूं सः ॐ भूर्भुवः स्वः ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम्
       उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय मामृतात् ॐ स्वः भुवः भूः ॐ सः जूं हौं ॐ।
*/

// Date: 06/01/2023


#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

void solve() {

  ll n;
  cin>>n;

  ll arr[n];


  for(int i=0;i<n;i++)
  {
    cin>>arr[i];

  }

 
 int ans= 0;
 for(int i=n-2;i>=0;i--)
 {
  if(arr[i]==0)
  {
    continue;
  }
  if(arr[i]>=arr[i+1])
  {
    ans += (arr[i+1]-arr[i]+1);
    arr[i] = arr[i+1]-1;
  }
 }
 cout<<ans<<endl;




  

}

int main(){


    int t = 1;
    cin>>t;
    while(t--){
      solve();
    }
    
    
return 0;
}
/*---------------------pgthakur------------------------------------------*/