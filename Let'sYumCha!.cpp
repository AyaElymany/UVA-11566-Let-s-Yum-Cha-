#include<bits/stdc++.h>
using namespace std;

int n,k,f[100],p[100],vis[100][1101][22],m;

int solve(int idx,int v,int num){
	
  if(idx==k||num==n)
    return 0;

	if(vis[idx][v][num]!=-1)
    return vis[idx][v][num];

	vis[idx][v][num]=solve(idx+1,v,num);

	if(v+p[idx]<=m)
		vis[idx][v][num]=max(vis[idx][v][num],solve(idx+1,v+p[idx],num+1)+f[idx]);

	if(v+2*p[idx]<=m&&num+2<=n)
		vis[idx][v][num]=max(vis[idx][v][num],solve(idx+1,v+p[idx]*2,num+2)+2*f[idx]);

	return vis[idx][v][num];
}

int main(){
	int t,x,sum,temp;
	float ans;
	while(scanf("%d",&n)&&n){
		memset(vis,-1,sizeof vis);
		scanf("%d%d%d",&x,&t,&k);
		n++;
		m=floor(double(1.0*n*x)/1.1+1e-6)-n*t;
		for(int i=0;i<k;i++){
			scanf("%d",&p[i]);
			sum=0;
			for(int j=0;j<n;j++)
				scanf("%d",&temp),sum+=temp;
			f[i]=sum;
		}
		n*=2;
		ans=solve(0,0,0);
		ans=ans*2.0/n;
		printf("%.2f\n",ans);
	}
}
