#include<malloc.h>
#include<iostream>
using namespace std;

struct LNode{
   int *data;  
   int length;  // length 定义线性表的长度 
};


int next(int *a,int n,int m,int k)    //从 k的下一个未出局的位置开始报数 
{
	int i=0;	
	while(1)
	{
		if(k+1==n)   //防止出现 k 为0的情况
			k=n;
		else
			k=(k+1)%n;
		if(a[k])  //k位置的人未出局
			i++;
		if(i==m) //报数报到m，使这个人出局，返回这个人的序号 
			return k;
	}
}
void Joseph(int n,int m,int k)     //总共n个人，报数到 m 的人出局,从第k个人开始报数 
{
	LNode L;
	L.data=(int*)malloc((n+1)*sizeof(struct LNode));
	int i;
	for(i=0; i<=n; i++)   //初始化数组，数组中的每个元素代表一个人，赋值1表示未出局 此过程经过n步 
		{
		L.data[i]=1;
		}
	int count=n;       //count表示剩余人数
	if(k+1>n||k<=0||n<=0||m<0)
	{
		cout<<"Error!";
		return;
	}
	while(count>0)
	{
		k=next(L.data,n,m,k-1);     //重新确定下一次出局的人，输出出局的人的序号 
		cout<<k<<" ";
		L.data[k]=0;     //出局的人设为0 
		count--;      //count代表剩余人数 执行n*m次 
	}
	
	cout<<endl;
 
	delete L.data;//完成报数，删除空间.	
}
int main()
{
	int n,m,k;
	cin>>n>>m>>k;//输入总人数，报数数，开始报的人序号 
	Joseph(n,m,k);
	return 0;
}
