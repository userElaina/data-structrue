//Code By 1677
#include<bits/stdc++.h>
#define LMX 9223372036854775807
#define IMX 2147483647
#define M0 1000000007
#define M9 998244353
#define M8 19260817
#define M7 7221457
#define PI 3.1415926
#define E 2.71828
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
#define MXN M7
const int mxn[30]={1,2,4,8,16,32,64,128,256,512,
	1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,
	1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912};
int t[MXN],o[MXN][4],bg[M8],fa[MXN],l[MXN],r[MXN],v[MXN],tp;
inline void bd(int x){
	int flg=0;
	for(int i=0;i<t[x];i++){
	int y=o[x][i];
		if(!v[y]){
			v[y]=1;
			fa[y]=x;
			if(flg)r[x]=y;else l[x]=y;
			flg=1;
			if(y)bd(y);else v[0]=1;
		}
	}
}
inline void o1(int x){
	if(!x)return;
	intot(x),pt(32);
	o1(l[x]);
	o1(r[x]);
}
inline void o2(int x){
	if(!x)return;
	o2(l[x]);
	intot(x),pt(32);
	o2(r[x]);
}
inline void o3(int x){
	if(!x)return;
	o3(l[x]);
	o3(r[x]);
	intot(x),pt(32);
}
inline void O1(int p){
	memset(v,0,sizeof(v));
	while(1){
		if(!p){
			p=tp;
			continue;
		}
		if(!v[p]){
			intot(p),pt(32);
			v[p]++;
			tp=p;
			p=l[p];
			continue;
		}
		if(v[p]==1){
			v[p]++;
			tp=p;
			p=r[p];
			continue;
		}
		if(v[p]==2){
			v[p]++;
			p=fa[p];
			if(p)continue;
			else break;
		}
		printf("Error1\n");
	}
}
inline void O2(int p){
	memset(v,0,sizeof(v));
	while(1){
		if(!p){
			p=tp;
			continue;
		}
		if(!v[p]){
			v[p]++;
			tp=p;
			p=l[p];
			continue;
		}
		if(v[p]==1){
			intot(p),pt(32);
			v[p]++;
			tp=p;
			p=r[p];
			continue;
		}
		if(v[p]==2){
			v[p]++;
			p=fa[p];
			if(p)continue;
			else break;
		}
		printf("Error2\n");
	}
}
inline void O3(int p){
	memset(v,0,sizeof(v));
	while(1){
		if(!p){
			p=tp;
			continue;
		}
		if(!v[p]){
			v[p]++;
			tp=p;
			p=l[p];
			continue;
		}
		if(v[p]==1){
			v[p]++;
			tp=p;
			p=r[p];
			continue;
		}
		if(v[p]==2){
			intot(p),pt(32);
			v[p]++;
			p=fa[p];
			if(p)continue;
			else break;
		}
		printf("Error3\n");
	}
}
inline void Oo(int p){
	memset(v,0,sizeof(v));
	v[0]=p;
	tp=1;
	for(int i=0;i<tp;i++){
		intot(v[i]),pt(32);
		if(l[v[i]])v[tp++]=l[v[i]];
		if(r[v[i]])v[tp++]=r[v[i]];
	}
}
inline void _de(int x){
	if(x==1){_fe();return;}
	if(l[fa[x]]^x)r[fa[x]]=0;
	else l[fa[x]]=0;
	printf("\nAfter Deleting %d.\n",x);
}
inline void _fe(){
	memset(o,0,sizeof(o));
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));
	memset(v,0,sizeof(v));
}
inline void _in(){
	_fe();
	printf("N, Deep:\n");
	int n=intin(),h=intin();
	printf("Input Format (0 is Ex-pre-order, 1 is a Set of Edge):\n");
	if(intin()){
		for(int i=1;i<n;i++){
			int x=intin(),y=intin();
			if(x)o[x][t[x]++]=y;else i--;
			if(y)o[y][t[y]++]=x;else i--;
		}
		fa[1]=0;
		v[1]=1;
		bd(1);
	}else{
		bg[1]=intin();
		for(int i=2;i<mxn[h];i+=2){
			int j=i>>1;
			bg[i]=intin();
			bg[i|1]=intin();
			fa[bg[i]]=bg[j];
			fa[bg[i|1]]=bg[j];
			l[bg[j]]=bg[i];
			r[bg[j]]=bg[i|1];
		}
	}
	l[0]=r[0]=fa[0]=0;
	// for(int i=1;i<=n;i++)printf("l(%d)=%d\n",i,l[i]);
}
inline void _ot(int x){
	printf("\nNLR (recursion):\n");o1(x);
	printf("\nLNR (recursion):\n");o2(x);
	printf("\nLRN (recursion):\n");o3(x);
	pt(10);
}
inline void _Ot(int x){
	printf("\nNLR (iteration):\n");O1(x);
	printf("\nLNR (iteration):\n");O2(x);
	printf("\nLRN (iteration):\n");O3(x);
	pt(10);
}
inline void _t(int x){
	printf("\nBFS:\n");Oo(x);
	pt(10);
}
int main(){
	_in();
	_ot(1);
	_Ot(1);
	_t(1);
	_de(intin());
	_ot(1);
	//int xx=intin();
	intot(fa[4]);pt(32);
	intot(fa[1]);pt(32);
	_de(4);
	_ot(1);
	_de(1);
	_ot(1);
	_fe();
}
/*
7 4
1
1 6
7 6
3 4
0 3
3 2
5 0
5 4
1 4
6
*/