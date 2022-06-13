#include<malloc.h>
#include<iostream>
using namespace std;

struct LNode{
   int *data;  
   int length;  // length �������Ա�ĳ��� 
};


int next(int *a,int n,int m,int k)    //�� k����һ��δ���ֵ�λ�ÿ�ʼ���� 
{
	int i=0;	
	while(1)
	{
		if(k+1==n)   //��ֹ���� k Ϊ0�����
			k=n;
		else
			k=(k+1)%n;
		if(a[k])  //kλ�õ���δ����
			i++;
		if(i==m) //��������m��ʹ����˳��֣���������˵���� 
			return k;
	}
}
void Joseph(int n,int m,int k)     //�ܹ�n���ˣ������� m ���˳���,�ӵ�k���˿�ʼ���� 
{
	LNode L;
	L.data=(int*)malloc((n+1)*sizeof(struct LNode));
	int i;
	for(i=0; i<=n; i++)   //��ʼ�����飬�����е�ÿ��Ԫ�ش���һ���ˣ���ֵ1��ʾδ���� �˹��̾���n�� 
		{
		L.data[i]=1;
		}
	int count=n;       //count��ʾʣ������
	if(k+1>n||k<=0||n<=0||m<0)
	{
		cout<<"Error!";
		return;
	}
	while(count>0)
	{
		k=next(L.data,n,m,k-1);     //����ȷ����һ�γ��ֵ��ˣ�������ֵ��˵���� 
		cout<<k<<" ";
		L.data[k]=0;     //���ֵ�����Ϊ0 
		count--;      //count����ʣ������ ִ��n*m�� 
	}
	
	cout<<endl;
 
	delete L.data;//��ɱ�����ɾ���ռ�.	
}
int main()
{
	int n,m,k;
	cin>>n>>m>>k;//����������������������ʼ��������� 
	Joseph(n,m,k);
	return 0;
}
