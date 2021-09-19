//Code By 1677
#include<bits/stdc++.h>
#define LMX 9223372036854775807
#define IMX 2147483647
#define M0 1000000007
#define M9 998244353
#define M8 19260817
#define M7 7221457
#define LL long long
#define pt putchar
#define gt getchar
#define cmm(a,b) if(a^b){a^=b;b^=a;a^=b;}
inline int uin(){
	int c=gt(),a=0;
	while(c<48||c>57)c=gt();
	while(c>47&&c<58)a=(a<<1)+(a<<3)+c-48,c=gt();
	return a;}

inline void lt(LL a){
	if(a<0){printf("-1          ");return;}
	if(!a){printf("0           ");return;}
	int num[12],i=0,o=0;
	for(;a;i++)num[i]=48+a%10,a/=10;
	for(int j=i-1;j>=0;j--)pt(num[j]);
	for(int j=i;j<12;j++)pt(32);}
inline void uot(int a){if(a>9)uot(a/10);pt(a%10+48);}

#define MXN 111111111
// const int I='i',E='e',B='b',Q='q',S='s',H='h',M='m';
const char A[11]="_iebqshm";
int a[MXN],b[MXN],c[MXN],d[MXN],n,t,file_=0,_sd=0,ex=0;
LL com,mov;
time_t _t;

inline void f(int l,int r,int dp){
	if(dp>4000){while(1)if(difftime(time(0),_t)>1.0)return;}
	if(difftime(time(0),_t)>1.0)return;
	int p=a[l],h=l,t=r;
	mov++;
	while(1){
		while(1)
			if(h^t){
				com++;
				if(a[t]<p){a[h]=a[t];mov++;break;}
				else t--;
			}else{
				a[t]=p;mov++;
				if(t-l>2)f(l,t-1,dp+1);else{
					if(t-l==2){
						com++;
						if(a[l]>a[t-1]){
							cmm(a[l],a[t-1]);
							mov+=3;
						}
					}
				}
				if(r-t>2)f(t+1,r,dp+1);else{
					if(r-t==2){
						com++;
						if(a[t+1]>a[r]){
							cmm(a[t+1],a[r]);
							mov+=3;
						}
					}
				} 
				return;
			}
		while(1)
			if(h^t){
				com++;
				if(a[h]>p){a[t]=a[h];mov++;break;}
				else h++;
			}else{
				a[t]=p;mov++;
				if(t-l>2)f(l,t-1,dp+1);else{
					if(t-l==2){
						com++;
						if(a[l]>a[t-1]){
							cmm(a[l],a[t-1]);
							mov+=3;
						}
					}
				}
				if(r-t>2)f(t+1,r,dp+1);else{
					if(r-t==2){
						com++;
						if(a[t+1]>a[r]){
							cmm(a[t+1],a[r]);
							mov+=3;
						}
					}
				} 
				return;
			}
	}}
inline void g(int l,int r){
	if(difftime(time(0),_t)>1.0)return;
	if(l==r)return;
	int m=(l+r)>>1;
	if(l^m){
		g(l,m);
		g(m+1,r);
	}else{
		com++;
		if(a[l]>a[r]){
			cmm(a[l],a[r]);
			mov+=3;
		}
		return;
	}
	int h1=0,h2=0;
	for(int i=l;i<=m;i++)b[h1++]=a[i];
	for(int i=m+1;i<=r;i++)c[h2++]=a[i];
	b[h1]=c[h2]=IMX;
	h1=h2=0;
	for(int i=l;i<=r;i++){
		if(b[h1]<c[h2]){
			a[i]=b[h1++];
		}else{
			a[i]=c[h2++];
		}
	}
	mov+=((r-l)+2)<<1;
	com+=r-l+1;}
inline void up(int x){
	int y=x>>1;
	if(y){
		com++;
		if(b[y]>b[x]){
			cmm(b[y],b[x]);
			mov+=3;
			up(y);
		}
	}}
inline void dn(int x){
	int l=x<<1,r=x<<1|1;
	if(l>n)return;
	com+=2;
	if(b[l]<b[r]){
		if(b[x]>b[l]){
			mov+=3;
			cmm(b[x],b[l]);
			dn(l);
		}
	}else{
		if(b[x]>b[r]){
			mov+=3;
			cmm(b[x],b[r]);
			dn(r);
		}
	}}
inline void pu(int x){
	//if(difftime(time(0),_t)>1.0)return;
	b[++t]=x;
	mov++;
	up(t);}
inline int po(){
	//if(difftime(time(0),_t)>1.0)return 1;
	int x=b[1];
	b[1]=b[t];
	b[t--]=IMX;
	mov+=3;
	dn(1);
	return x;}

inline int _(){std::sort(a,a+n);if(difftime(time(0),_t)>1.0)return 1;return 0;}
inline int I_(){
	for(int i=1;i<n;i++){
		int j=i-1,p=a[i];
		while(j>=0&&a[j]>p){
			a[j+1]=a[j];
			j--;
		}
		com+=i-j;
		mov+=i-j+1;
		a[j+1]=p;
		if(difftime(time(0),_t)>1.0)return 1;
	}
	return 0;}
inline int E_(){
	int d=n>>1;
	while(d){
		for(int i=d;i<n;i++){
			int j=i-d,p=a[i],ad=1;
			while(j>=0&&a[j]>p){
				a[j+d]=a[j];
				ad++;
				j-=d;
			}
			com+=ad;
			mov+=ad+1;
			a[j+d]=p;
		}
		d=d>>1;
		if(difftime(time(0),_t)>1.0)return 1;
	}
	return 0;}
inline int B_(){
	for(int j=0;j<=n;j++){
		int flg=com+mov;
		for(int i=0;i<n-1;i++){
			if(a[i]>a[i+1]){
				cmm(a[i],a[i+1]);
				mov+=3;
			}
			com++;
		}
		if(flg==com+mov)j=n+1;
		if(difftime(time(0),_t)>1.0)return 1;
	}
	return 0;}
inline int Q_(){f(0,n-1,1);if(difftime(time(0),_t)>1.0)return 1;return 0;}
inline int S_(){
	for(int j=0;j<n;j++){
		int x=IMX,xi;
		for(int i=0;i<n;i++){
			if(x>a[i])x=a[i],xi=i,mov++;
		}
		b[j]=x;
		a[xi]=IMX;
		mov+=3;
		if(difftime(time(0),_t)>1.0)return 1;
	}
	com=n*n;
	for(int i=0;i<n;i++)a[i]=b[i];
	mov+=n;
	return 0;}
inline int H_(){
	for(int i=0;i<n;i++){pu(a[i]);if(difftime(time(0),_t)>1.0)return 1;}
	pu(IMX);
	for(int i=0;i<n;i++){a[i]=po();if(difftime(time(0),_t)>1.0)return 1;}
	mov+=n;
	return 0;}
inline int M_(){g(0,n-1);if(difftime(time(0),_t)>1.0)return 1;return 0;}

inline int rad(int l){
	int a=0;
	for(int i=0;i<com%100;i++)rand();
	for(int i=0;i<l;i++)a=(a<<1)+(a<<3)+rand()%10;
	return a+1;}
inline void _rad(){for(int i=(mov+com)%M7;i;i--)rand();}
inline void GD(){for(int i=0;i<n;i++)d[i]=i+1;printf("Good_data:\n");}
inline void BD(){for(int i=0;i<n;i++)d[i]=n-i;printf("Bad_data:\n");}
inline void RD(){_rad();for(int i=0;i<n;i++)d[i]=rad(9);printf("Rand_data:\n");}
inline void SD(){_rad();for(int i=0;i<n;i++)d[i]=rad(2);printf("Similar_data:\n");}

inline void bg(){for(int i=0;i<n;i++)a[i]=d[i];t=com=mov=0;_t=time(0);}
inline void ot(){
	pt('n');pt(':');
	uot(n);
	pt(32);pt('c');pt(':');
	uot(com);
	pt(32);pt('m');pt(':');
	uot(mov);
	pt(10);
	for(int i=0;i<n;i++)uot(a[i]),pt(32);
	pt(10);}
inline int _sort(int c){
	if(c=='_')return _();
	if(c=='i'||c=='I')return I_();
	if(c=='e'||c=='E')return E_();
	if(c=='b'||c=='B')return B_();
	if(c=='q'||c=='Q')return Q_();
	if(c=='s'||c=='S')return S_();
	if(c=='h'||c=='H')return H_();
	if(c=='m'||c=='M')return M_();
	return 1;}
inline char *_pt(int c){
	if(c=='_')return "StdSort";
	if(c=='i'||c=='I')return "InsertSort";
	if(c=='e'||c=='E')return "ShellSort";
	if(c=='b'||c=='B')return "BSort";
	if(c=='q'||c=='Q')return "QuickSort";
	if(c=='s'||c=='S')return "SSort";
	if(c=='h'||c=='H')return "HeapSort";
	if(c=='m'||c=='M')return "MergeSort";
	return "Error";}
inline void solve(int c){
	bg();
	if(_sort(c))com=mov=EOF;
	lt(com);
	lt(mov);
	printf(" //%s\n",_pt(c));
	return;}
inline void nsolve(){
	printf("Compare     Move\n");
	for(int i=1;i<8;i++)solve(A[i]);
	pt(10);
	return;}
inline void _main(){
	printf("\nn=%d:\n\n",n);
	GD();nsolve();
	BD();nsolve();
	SD();nsolve();
	RD();nsolve();
	RD();nsolve();
	return;}
int main(){
	// file_=1;//Switch of file
	ex=1;//Switch of big_data
	_sd=1;//Switch of input
	if(file_)freopen("sort2.log","w",stdout);
	if(ex){n=1000;_main();}
	n=10000;_main();
	n=100000;_main();
	n=1000000;_main();
	if(ex){n=10000000;_main();}
	//if(ex){n=100000000;_main();}
	while(_sd){
		n=uin();
		for(int i=0;i<n;i++)d[i]=uin();
		nsolve();
	}
	if(file_)fclose(stdout);
}
