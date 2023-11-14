#include <bits/stdc++.h>
using namespace std;
using lf=double;
const lf k1=0.1,k2=0.5;
vector<vector<lf> >dist,dist0,d;
vector<set<int> >V;
vector<vector<int> >G;
set<int>A;
int N;
lf D[(1<<21)][23];
pair<int,int> anc[(1<<21)][23];
lf f(lf r){return k1/(1+exp(k2*r));}
lf C(int u){
    lf ret=0;
    for(register int v=1;v<=N;v++)if(v^u)ret+=(dist[u][v]);
    return ret;
}
void Divde(){
    if(A.empty())return;
    lf mx=0,X=0;
    register int i;
    for(auto it=A.begin();it!=A.end();it++){
        lf now=C(*it);
        if(now>mx){mx=now;X=*it;}
    }
    vector<pair<lf,int> >B;
    for(auto it=A.begin();it!=A.end();it++)B.push_back({dist[X][*it],*it});
    V.push_back(set<int>());
    sort(B.begin(),B.end());
    for(i=0;i<(int)B.size();i++){
        if(A.empty())break;
        if(V.back().empty()){
            A.erase(B[i].second);
            V.back().insert(B[i].second);
            continue;
        }
        lf M=f(0);bool flag=true;
        for(auto it=V.back().begin();it!=V.back().end();it++){
            flag&=(0.85*M<=f(dist[B[i].second][*it]));
            //cout<<M<<" "<<f(dist[B[i].second][*it])<<endl;
        }
        if(flag){
            A.erase(B[i].second);
            V.back().insert(B[i].second);
        }
    }
    Divde();
    return;
}
int n,Q;
void TSP(int bit,int cur){
    if(D[bit][cur])return;
    D[bit][cur]=9e18;
    bool flag=true;
    for(int x=1;x<=n;x++){
        if(bit&(1<<(x-1)))continue;
        TSP(bit|(1<<(x-1)),x);
        flag=false;
        if(D[bit][cur]>D[bit|(1<<(x-1))][x]+d[cur][x]){
        	D[bit][cur]=D[bit|(1<<(x-1))][x]+d[cur][x];
        	anc[bit][cur]={bit|(1<<(x-1)),x};
        }
    }
    if(flag&&(Q==cur||!Q)){
    	D[bit][cur]=0;
    }
}
lf opt_TSP(int bit,int cur){
    if(bit==(1<<N)-1)return dist[cur][1];
    if(D[bit][cur])return D[bit][cur];
    D[bit][cur]=9e18;
    for(int x=1;x<=N;x++){
        if(bit&(1<<(x-1)))continue;
        D[bit][cur]=min(D[bit][cur],opt_TSP(bit|(1<<(x-1)),x)+dist[cur][x]);
    }
    return D[bit][cur];
}
pair<int,int>ps[103][103];
int main(){
    freopen("data/WCG/20_1.in","r",stdin);
    //ios_base::sync_with_stdio(false);cin.tie(NULL);
    N=20;
    cout<<fixed;
    cout.precision(2);
    register int i,j;
    dist.resize(N+1);
    G.resize(N+1);
    double mn=9e18,mx=-9e18;
    for(i=1;i<=N;i++){
        A.insert(i);
        dist[i].resize(N+1);
        for(j=1;j<=N;j++){
            lf a;cin>>a;
            dist[i][j]=a;
            mn=min(mn,a);
            mx=max(mx,a);
        }
    }
    dist0=dist;
    for(int i=1;i<=N;i++){
    	for(int j=1;j<=N;j++){
    		dist[i][j]=(dist[i][j]-mn)/(mx-mn);
    	}
    }
    int SS=clock();
    Divde();
    int EE=clock();
    cout<<"Number of Set: "<<V.size()<<"\n\n";
    cout<<"k1 and k2\nk1: "<<k1<<"   k2: "<<k2<<"\n\n";
    cout<<"____SET_info______\n";
    for(i=0;i<(int)V.size();i++){
        cout<<"["<<i+1<<"] ";
        for(auto it=V[i].begin();it!=V[i].end();it++)cout<<*it<<" ";
        cout<<"\n";
    }
    cout<<"Running Time: "<<EE-SS<<"ms\n\n\n";
    cout<<flush;
    SS=clock();

    double ans=0;

    n=V.size();
    auto tmp=vector<vector<lf> >(n+2,vector<lf>(n+2,0));
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            lf mn=9e18;int p=0,q=0;
            for(auto it=V[i].begin();it!=V[i].end();it++){
                for(auto jt=V[j].begin();jt!=V[j].end();jt++){
                    if(dist0[*it][*jt]<mn){mn=dist0[*it][*jt];p=*it;q=*jt;}
                }
            }
            ps[i+1][j+1]={p,q};ps[j+1][i+1]={q,p};
            tmp[i+1][j+1]=tmp[j+1][i+1]=dist0[p][q];
        }
    }
    d=tmp;
    Q=0;
    TSP(1,1);
    pair<int,int>iter={1,1};
    vector<int>path;
    while(iter.first){
    	path.push_back(iter.second);
    	iter=anc[iter.first][iter.second];
    }

    vector<vector<int> >tour(N+2);
    map<int,int>mp,inv;
    int pre=0,apr=0;
    int np=path.size();
    for(int i=0;i<(int)path.size();i++){
    	int t=path[(i-1+np)%np],u=path[i],v=path[(i+1)%np];
    	int idx=0,p=ps[t][u].second,q=ps[u][v].first;
    	if(!i)apr=p;
    	if(p==q){
    		lf mn=9e18;
    		for(auto it=V[u-1].begin();it!=V[u-1].end();it++){
    			for(auto jt=V[v-1].begin();jt!=V[v-1].end();jt++){
    		    	if(dist0[*it][*jt]<mn&&*it!=p){mn=dist0[*it][*jt];q=*it;}
    		    }
    		}
    		ps[u][v]={p,q};ps[v][u]={q,p};
    		tmp[u][v]=tmp[v][u]=dist0[p][q];
    	}
    	n=V[u-1].size();
    	d=vector<vector<lf> >(n+2,vector<lf>(n+2,0));
    	for(auto it=V[u-1].begin();it!=V[u-1].end();it++){
    		mp[*it]=++idx;
    		inv[idx]=*it;
    	}
    	for(auto it=V[u-1].begin();it!=V[u-1].end();it++){
    		for(auto jt=V[u-1].begin();jt!=V[u-1].end();jt++){
    			d[mp[*it]][mp[*jt]]=dist0[*it][*jt];
    			d[mp[*jt]][mp[*it]]=dist0[*jt][*it];
    		}
    	}
    	memset(anc,0,sizeof(anc));
    	memset(D,0,sizeof(D));
    	if(u==path.back()){
    		q=apr;
    		tour[q].push_back(ps[u][v].second);
    		tour[ps[u][v].second].push_back(q);
    	}

    	p=mp[p],Q=mp[q];
    	TSP(1<<(p-1),p);

    	ans+=D[1<<(p-1)][p]+tmp[u][v];
    	iter={1<<(p-1),p};

    	while(iter.first){
    		if(pre){
    			tour[pre].push_back(inv[iter.second]);
    			tour[inv[iter.second]].push_back(pre);
    		}
    	    pre=inv[iter.second];
    	    iter=anc[iter.first][iter.second];
    	}
    	mp.clear();
    }

    int x=1;
    vector<bool>vis(N+2,false);
    while(1){
    	vis[x]=true;
    	cout<<x<<" ";
    	bool stop=true;
    	for(int y:tour[x]){
    		if(vis[y])continue;
    		stop=false;
    		x=y;
    		break;
    	}
    	if(stop)break;
    }
    cout<<endl;
    cout<<"RESULT\n";
    cout<<"Weight of Tour: "<<ans<<"\n";
    EE=clock();
    cout<<"Running Time: "<<EE-SS<<"ms\n\n";
    memset(D,0,sizeof(D));
    cout<<flush;
    SS=clock();
    cout<<"Weight of Optimal Tour: "<<opt_TSP(1,1)<<"\n";
    EE=clock();
    cout<<"Running Time: "<<EE-SS<<"ms\n\n";
    return 0;
}
