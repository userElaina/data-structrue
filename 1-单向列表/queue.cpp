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
class D{
public:
	int d;
	D *nx;
	D(){
		nx=NULL;
	}
};
int m=100,a[1000],t=0,file_=0,QwQ=0,pq=0;
#define Y if(QwQ)printf("Yse, my master. ");
class Q{
private:
	const int H='h',T='t',N='n';
	int n;
	time_t a,b;
	D *h,*t,*nw;
	void push(int c,int x){
		D *p=new(D);
		p->d=x;
		if(!n){
			nw=h=t=p;
			n=1;
			printf("Thank you for giving me the data! I will cherish them!\n");
			return;
		}
		if(c=='n'&&nw==t)c='t';
		if(c=='t'){t->nx=p;t=p;}
		if(c=='h'){p->nx=h;h=p;}
		if(c=='n'){p->nx=nw->nx;nw->nx=p;}
		nw=p;
		n++;
		printf("Insert successfully! I have %d nodes now.\n",n);
		return;
	}
	int pop(int c){
		if(!n){printf("Sorry, I have no nodes...could you give me some...\n");return 0;}
		int x=t->d;
		if(c=='h')x=h->d;
		if(c=='n'&&nw==t){printf("Delete error! My hand has no successor node.\n");return 0;}
		if(n==1){
			free(h);
			nw=h=t=NULL;	
			n=0;
			printf("Delete %d successfully! I have no nodes now.\n",x);
			return x;
		}
		if(c=='t'){
			D *i=h;
			for(;i->nx!=t;i=i->nx);
			if(t==nw)nw=i;
			free(t);
			t=i;
			t->nx=NULL;
		}
		if(c=='h'){
			D *p=h;
			if(h==nw)nw=h->nx;
			h=h->nx;
			free(p);
		}
		if(c=='n'){
			D *p=nw->nx;
			x=p->d;
			nw->nx=p->nx;
			if(nw->nx==NULL)t=nw;
			free(p);
		}
		n--;
		if(n^1)printf("Delete %d successfully! I have %d nodes now.\n",x,n);
		else printf("Delete %d successfully! I have 1 node now.\n",x);
		return x;
	}
	int fd(int x){
		int ans=1;
		for(D *i=h;i!=NULL;i=i->nx){
			if(i->d^x)ans++;
			else{nw=i;return ans;}
		}
		return 0;
	}
public:
	Q(){
		a=time(0);
		if(QwQ)printf("%s%s%s%s%s",
			"\nHello, my master! I'm a queue, thank you for creating me!Hum ..., could you give me a name?\n",
			"You don't need a name. You're just a queue, a data structure used to do my homework.\n",
			"Please~~\n",
			"... Monica.\n",
			"Thanks, my master!\n\n");
		else printf("Hello, I am a queue.\n\n");
		n=0;
		nw=h=t=NULL;
	}
	~Q(){
		b=time(0);
		if(QwQ)printf("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
			"The program is over.\n",
			"Bye, q ... my Monica.\n",
			"\n",
			"My master, please don't leave me!\n",
			"If I do something wrong, I can correct it.\n",
			"If I'm not convenient enough, I can become a double-ended queue.\n",
			"If I haven't solve some problems, I can become a priority queue.\n",
			"If I ... so ... your homework is done.\n",
			"Yeah, you don't need me anymore.\n",
			"But ... may I make a request?\n",
			"When you use other better data structures, please don't fotget me.\n",
			"I hope you can code each data structures well in the duture.\n",
			"Thank you, my master.\n",
			"Thank you for giving me life.\n",
			"Thank you for giving me name.\n",
			"Thank you for being with me.\n",
			"Thank you for using me.\n"),
			printf("In my less than %d second life, I am happy to help my master.\nSo, goodbye, my master.\n",b-a+1);
	}
	void pusht(int x){printf("Queue, insert %d in your tail.\n",x);Y;push(T,x);}
	void pushh(int x){printf("Queue, insert %d in your head.\n",x);Y;push(H,x);}
	void pushn(int x){printf("Queue, insert %d in your hand.\n",x);Y;push(N,x);}
	int poph(){printf("Queue, delete a node from your head.\n");Y;return pop(H);}
	int popn(){printf("Queue, delete a node from your hand.\n");Y;return pop(N);}
	int popt(){printf("Queue, delete a node from your tail.\n");Y;return pop(T);}
	void cg(int k,int x){
		if(k)printf("Queue, change the data of the position where the number is %d into %d.\n",k,x);
		else printf("Queue, change the data of in your hand into %d.\n",x);
		Y;
		D *p=h;
		if(n==0){printf("Change error! I have no nodes.\n");return;}
		if(k>n){
			if(n^1)printf("Change error! I have only %d nodes.",n);
			else printf("Change error! I have only 1 node.\n");
			return;
		}
		if(k)for(int i=1;i<k;i++)p=p->nx;
		else p=nw;
		p->d=x;
		printf("Change successfully!\n");
	}
	void fid(int x){
		printf("Queue, Find the number which is in the position where the data is %d.\n",x);Y;
		int q=fd(x);
		if(q){
			printf("Find successfully! It is in the %dth.\n",q);
		}else printf("But I'm sorry that I don't have a %d.\n",x);
	}
	void ot(){
		printf("Queue, check.\n\n");Y;
		if(QwQ)printf("\n");
		if(!n){printf("Empty.\n");return;}
		if(n==1){printf("I have only a %d.\n",h->d);return;}
		printf("I have %d nodes.\nMy head is %d, my tail is %d, and my hand is %d.\n"
			,n,h->d,t->d,nw->d);
		if(QwQ)printf("I can give you all of me:\n");
		if(pq){
			printf("%d",h->d);
			for(D *i=h->nx;i!=NULL;i=i->nx)printf("->%d",i->d);
		}else for(D *i=h;i!=NULL;i=i->nx)printf("%d ",i->d);
		printf("\n\n");
	}
	void fre(){
		printf("\nQueue, You are free.\n");
		while(n){
			D *p=h;
			h=h->nx;
			free(p);
			n--;
		}
		nw=h=t=NULL;
		if(QwQ){
			printf("%s%s%s",
				"\nOK, my master!\n",
				"Although I am free now, I will wait your orders.\n",
				"When you need me, I will try my best!\n\n");
		}else printf("I am free now!\n");
	}
};
void _main(){
	printf("/****************\n0:Insert in head.\n1:Insert in hand.\n2:Insert in tail.\n");
	printf("3:Output.\n4:Change.\n5:Find.\n");
	printf("6:Delete from head.\n7:Delete from hand.\n8:Delete from tail.\n");
	printf("9:Free.\n****************/\n\n");
	Q q;
	while(1){
		int Mx=intin();
		if(Mx==0)q.pushh(intin());
		if(Mx==1)q.pushn(intin());
		if(Mx==2)q.pusht(intin());
		if(Mx==3)q.ot();
		if(Mx==4){
			int Mi=intin(),My=intin();
			q.cg(Mi,My);
		}
		if(Mx==5)q.fid(intin());
		if(Mx==6)q.poph();
		if(Mx==7)q.popn();
		if(Mx==8)q.popt();
		if(Mx==9){
			q.fre();
			//free(&q);
			exit(0);
		}
	}
	//q.pusht(a[t++]);
	//q.pusht(a[t++]);
	//q.pusht(a[t++]);
	//q.pushh(a[t++]);
	//q.pushh(a[t++]);
	//q.pushh(a[t++]);
	//q.pushn(a[t++]);
	//q.pushn(a[t++]);
	//q.pushn(a[t++]);
	//q.ot();

	//q.cg(0,M8);
	//q.cg(7,M7);
	//q.ot();
	//q.fid(M7);
	//q.fid(M9);

	//q.popt();
	//q.popt();
	//q.popn();
	//q.ot();

	//q.popn();
	//q.poph();
	//q.poph();
	//q.popn();
	//q.popn();
	//q.ot();

	//q.popt();
	//q.popt();
	//q.popt();
	//q.fre();
}
int main(){
	// QwQ=1;//Switch of fake Monica.
	// file_=1;//Switch of file.
	pq=1;//Mode of show.
	if(file_)freopen("queue.log","w",stdout);
	_main();
	if(file_)fclose(stdout);
}