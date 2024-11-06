#include<bits/stdc++.h>
#define Max 4
using namespace std;

vector<int>vec[Max+1];
stack<int>q;

int visited[Max+1];
int onStack[Max+1];
int low[Max+1];
int in[Max+1];


static int scc=0;
static int timer=1;

void dfs(int node)
{
    visited[node]=true;
    in[node]=low[node]=timer++;
    onStack[node]=true;

    for(auto u :vec[node])
    {




            if(visited[u]==true && onStack[u]==true)
                low[node]=min(low[node] ,in[u]);

            else if(visited[u]==false){

                dfs(u);

                if(onStack[u]==true)
                low[node]=min(low[node],low[u]);
            }



    }

     int v;
     if(low[node]==in[node]){
        scc++;
        cout<<"scc#:"<<scc<<" ";
        while(1)
        {
            v=q.top();
            q.pop(),onStack[v]=false;
            cout<<v<<" ";
            if(node==v)break;
        }
        cout<<endl;
     }


}




int main()
{
    freopen("in.txt","r",stdin);

    int x,y,e;
    cin>>e;
    //ifstream fin("in.txt");
    while(e--){
        cin>>x>>y;
        vec[x].push_back(y);
    }
    

    dfs(3);
    return 0;
}

