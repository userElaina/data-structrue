//Code By 1677
#include<bits/stdc++.h>
#define LMX 9223372036854775807
#define IMX 2147483647
#define M0 1000000007
#define M9 998244353
#define M8 19260817
#define M7 7221457
#define LL long long
#define doublw double
#define ini int
#define itn int
#define calss class
#define pt putchar
#define gt getchar
#define lowbit(a) (a&(~a+1))
#define cmm(a,b) if(a^b){a^=b;b^=a;a^=b;}
#define lcm(a,b) (a/gcd(a,b)*b)
#define gcd(a,b) exgcd(a>b?a:b,a>b?b:a)
#define mn(a,b) (a<b?a:b)
#define mx(a,b) (a>b?a:b)
#define ab(a) (a>=0?a:(~a+1))
#define ED(a) (~scanf("%d",&a))
#define I(b,a,c) (a>=b&&a<=c)
inline int intin(){
	int c=gt(),b=0,a=0;
	while((c^45)&&(c<48||c>57))c=gt();
	if(c==45)c=gt(),b=1;
	while(c>47&&c<58)a=(a<<1)+(a<<3)+c-48,c=gt();
	if(b)return ~a+1;return a;}
inline int uin(){
	int c=gt(),a=0;
	while(c<48||c>57)c=gt();
	while(c>47&&c<58)a=(a<<1)+(a<<3)+c-48,c=gt();
	return a;}
inline LL llin(){
	int c=gt(),b=0;LL a=0;
	while((c^45)&&(c<48||c>57))c=gt();
	if(c==45)c=gt(),b=1;
	while(c>47&&c<58)a=(a<<1)+(a<<3)+c-48,c=gt();
	if(b)return ~a+1;return a;}
inline void uot(int a){if(a>9)uot(a/10);pt(a%10+48);}
inline void intot(int a){if(a<0)pt(45),uot(~(a-1));else uot(a);}
inline void ulot(LL a){if(a>9)ulot(a/10);pt(a%10+48);}
inline void llt(LL a){if(a<0)pt(45),ulot(~(a-1));else ulot(a);}
inline LL exgcd(LL a,LL b){if(!b)return a;return exgcd(b,a%b);}

#define MXN 100
//#define MEM 16843009
int n,num,bgt,tyt,t,ot,bb,MEM,cpl,cpr,cpx,
	mp[MXN][MXN],ph[MXN][MXN],d[MXN][MXN],
	ty[MXN],a[MXN],v[MXN],pexist[MXN],id[MXN],od[MXN];
std::vector<int>r[MXN],l[MXN];

void DCG(){printf("Error: There are some cycles in the graph.\n");exit(0);}
void AK(){printf("Error: Are you kidding me?\n");exit(0);}
void TL(){printf("Error: Toooooooo large.\n");exit(0);}
int UI(){int x=intin();if(x<0)AK();return x;}
int PI(){int x=UI();if(x>=MXN||!x)TL();return x;}

void bfs(int xx){
	if(v[xx])return;
	a[0]=xx;
	v[xx]=1;
	#define x a[i]
	#define y r[x][j]
	for(int i=0;i<t;i++){
		if(ot)intot(x),pt(32);
		for(int j=0;j<r[x].size();j++)
			if(!v[y])v[y]=1,a[t++]=y;
	}
	#undef x
	#undef y
}
void dfs(int x){
	if(a[x])DCG();
	if(v[x])return;
	a[x]=1;
	v[x]=1;
	if(ot)intot(x),pt(32);
	for(int j=0;j<r[x].size();j++)dfs(r[x][j]);
	a[x]=0;
}
void BFS(int x){
	if(pexist[x]){
		t=1;
		memset(v,0,sizeof(v));
		bfs(x);
	}else printf("none");
	if(ot)pt(10);
}
void MBFS(){
	int m=UI();
	ot=1;
	if(m>100){
		memset(v,0,sizeof(v));
		for(int x=1;x<=n;x++)
			if(pexist[x]){
				t=1;
				bfs(x);
			}
	}else if(m)while(m--)BFS(PI());
	else for(int i=1;i<=n;i++)BFS(i);
	pt('#');
	pt(10);
}
void DFS(int x){
	if(pexist[x]){
		memset(v,0,sizeof(v));
		memset(a,0,sizeof(a));
		dfs(x);
	}else printf("none");
	if(ot)pt(10);
}
void MDFS(){
	int m=UI();
	ot=1;
	if(m>100){
		memset(v,0,sizeof(v));
		for(int x=1;x<=n;x++)
			if(pexist[x]){
				memset(a,0,sizeof(a));
				dfs(x);
			}
	}else if(m)while(m--)DFS(PI());
	else for(int i=1;i<=n;i++)DFS(i);
	pt('#');
	pt(10);
}

void ck(){
	bgt=ot=0;
	memset(id,0,sizeof(id));
	for(int i=1;i<=n;i++){
		if(!pexist[i])continue;
		od[i]=r[i].size();
		if(0==(id[i]=l[i].size()))ty[bgt++]=i;
	}
	#define x ty[i]
	#define y r[x][j]
	tyt=bgt;
	for(int i=0;i<tyt;i++){
		for(int j=0;j<r[x].size();j++){
			id[y]--;
			if(id[y]<0)DCG();
			if(!id[y])ty[tyt++]=y;
		}
	}
	#undef x
	#undef y
	for(int i=1;i<=n;i++)if(pexist[i]&&id[i])DCG();
	for(int i=1;i<=n;i++){
		id[i]=l[i].size();
		for(int j=1;j<=n;j++)
			d[i][j]=mp[i][j],ph[i][j]=j;
		d[i][i]=0;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				int nl=d[i][k]+d[k][j];
				if(nl<d[i][j]){
					d[i][j]=nl;
					ph[i][j]=ph[i][k];
				}
			}
	cpx=0;
	for(int i=1;i<=n;i++)
		if(!od[i])
			for(int j=1;j<=n;j++)
				if(!id[j]&&d[j][i]<MEM&&d[j][i]>cpx)
					cpx=d[cpl=j][cpr=i];
}

int fdp(int x){
	if(r[x].size())return r[x][0];
	return 0;
}
void MFP(){
	int m=UI();
	if(m)while(m--){
		int x=PI();
		if(r[x].size())intot(r[x][0]);
		else printf("none");
		pt(32);
	}else for(int x=1;x<=n;x++){
		if(r[x].size())intot(r[x][0]);
		else printf("none");
		pt(32);
	}
	pt(10);
}
void MFE(){
	int m=UI();
	while(m--){
		int x=PI(),y=PI();
		if(mp[x][y]<MEM)intot(mp[x][y]);
		else printf("inf");
		pt(32);
	}
	pt(10);
}
void MSSSP(){
	int m=UI();
	if(m)while(m--){
		int x=PI();
		for(int i=1;i<=n;i++)
			if(d[x][i]<MEM)intot(d[x][i]),pt(32);
			else printf("inf ");
		pt(10);
	}else for(int x=1;x<=n;x++){
		for(int i=1;i<=n;i++)
			if(d[x][i]<MEM)intot(d[x][i]),pt(32);
			else printf("inf ");
		pt(10);
	}
	pt('#');
	pt(10);
}
void MSP(){
	int m=UI();
	while(m--){
		int x=PI(),i=PI();
		if(d[x][i]<MEM){
			intot(d[x][i]);
			pt(':');
			pt(32);
			for(int j=x;j^i;j=ph[j][i])intot(j),pt(32);
			intot(i);
		}else printf("inf: none");
		pt(10);
	}
}
void TY(){
	for(int i=0;i<tyt;i++)intot(ty[i]),pt(32);
	pt(10);
}
void CP(){
	for(int j=cpl;j^cpr;j=ph[j][cpr])intot(j),pt(32);
	intot(cpr);pt(10);
}

void inp(int x){
	if(x>n)n=x,bb=1;
	if(!pexist[x])num++,pexist[x]=1;
}
void ine(){
	int x=PI(),y=PI(),z=UI();
	if(x==y||mp[x][y]<=z)return;
	inp(x);inp(y);
	mp[x][y]=z;
	r[x].push_back(y);
	l[y].push_back(x);
}
void MIP(){
	int m=UI();
	while(m--)inp(PI());
	ck();
}
void MIE(){
	int m=UI();
	while(m--)ine();
	ck();
}

int el(int x,int y){
	for(int i=0;i<r[x].size();i++)
		if(r[x][i]==y){
			r[x].erase(r[x].begin()+i);
			return 1;
		}
	return 0;
}
int er(int x,int y){
	for(int i=0;i<l[y].size();i++)
		if(l[y][i]==x){
			l[y].erase(l[y].begin()+i);
			return 1;
		}
	return 0;
}
void MDE(){
	int m=UI(),qq=0;
	for(int ii=0;ii<m;ii++){
		int x=PI(),y=PI();
		if(mp[x][y]<MEM){
			mp[x][y]=MEM;
			el(x,y);
			er(x,y);
		}else qq++;
	}
	if(qq){
		if(qq>1)printf("Error: %d edges are not exist.\n",qq);
		else printf("Error: An edge is not exist.\n");
	}
	if(qq^m)ck();
}
void MDP(){
	int m=UI(),qq=0;
	for(int ii=0;ii<m;ii++){
		int x=PI();
		if(pexist[x]){
			num--;
			pexist[x]=0;
			#define y r[x][i]
			for(int i=0;i<r[x].size();i++)er(x,y),mp[x][y]=MEM+1;
			#undef y
			#define y l[x][i]
			for(int i=0;i<l[x].size();i++)el(y,x),mp[y][x]=MEM+1;
			#undef y
			r[x].clear();
			l[x].clear();

		}else qq++;
	}
	if(qq){
		if(qq>1)printf("Error: %d points are not exist.\n",qq);
		else printf("Error: An point is not exist.\n");
	}
	if(qq^m)ck();
}
int main(){
	bb=bgt=0;
	n=PI();
	memset(pexist,0,sizeof(pexist));
	memset(mp,1,sizeof(mp));
	MEM=mp[0][0];
	//intot(mp[0][3]);
	MIE();
	if(bb)printf("Maybe your N is %d.\n",n);
	num=n;
	for(int i=1;i<=n;i++)pexist[i]=1;
	printf("0:BFS.\n1:DFS.\n2:Find a point.\n3:Find a edge.\n");
	printf("4:SSSP.\n5:SP.\n6:Topology.\n7:CP.\n");
	printf("8:Insert some points.\n9:Insert some edges.\n");
	printf("10:Delete some points.\n11:Delete some edges.\n");
	while(1){
		int q=intin();
		if(q==0)MBFS();else
		if(q==1)MDFS();else
		if(q==2)MFP();else
		if(q==3)MFE();else
		if(q==4)MSSSP();else
		if(q==5)MSP();else
		if(q==6)TY();else
		if(q==7)CP();else
		if(q==8)MIP();else
		if(q==9)MIE();else
		if(q==10)MDP();else
		if(q==11)MDE();else
		printf("Error: Illegal parameter.\n");
	}
}
/*
3 3
1 2 100
2 3 66
3 1 33
*/

/*
8 6
5 2 52
1 2 12
1 4 14
1 3 13
3 4 34
3 9 39
0 0
1 0
2 0
3 3 1 4 3 1 1 9
4 0
5 3 1 4 1 9 1 6
6
7

8 3 1 11 15
9 4 2 11 211 11 10 1110 4 8 48 9 8 98
0 0
1 0
4 0
5 3 1 10 1 8 1 3
6
7

10 3 3 15 13
11 3 2 11 4 1 1 6
0 0
1 0
4 0
5 3 1 10 1 8 1 3
6
7

9 1 10 11 1011


*/