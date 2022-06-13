#include<iostream>
#include<malloc.h>
#include <stdlib.h>
using namespace std; 
typedef int ElementType; // ElementType ����Ϊint
typedef struct LNode *List;
struct LNode{
	ElementType Data;   //������ 
	List Next;   // ��һ������ĵ�ַ 
}; 
List L;
List Make(int n); //��ʼ������ 


// ��ʼ������ 
List Make(int n){
	List head = new LNode;
	head->Data=1;
	head->Next=NULL;//��ʼ��ͷ��� 
	List L=head;
	List p;
	for(int i=2;i<=n;i++)
	{
		p=new LNode;//��ÿ���˶�Ӧ�Ľڵ��� 
		p->Data=i;
		p->Next=NULL;
		L->Next=p;
		L=L->Next;
	}
	L->Next=head;//ͷβ���� �γ�ѭ������ 
	return head;
}

void Joseph(int n,int m,int k) 
{
	if(k+1>n||k<=0||n<=0||m<0)
	{
		cout<<"Error!";
		return;
	}
	if(k+1>n||k<=0||n<=0||m<0)
	{
		cout<<"Error!";
		return ;
	}
	List p,s,head;
	head=Make(n);
	//Print(L,n); //���������Ƿ񴴽��ɹ� 
	p = head;
	int i=1;
	while(p && i<k){//�ҵ���k���� ʱ�临�Ӷ�O��k�� 
		p = p->Next;
		i++;
	}
	 while (p->Next!=p) 
	 {
	 	for (i=1; i<m; i++) {//������ÿ����m��1�˳��У�ֱ�����ֻʣ��1���� ʱ�临�Ӷ�O��m*n�� 
	 		s=p;
	 		p=p->Next;
	 	}
	 	s->Next=p->Next;//��s���ӵ�p����һ����ǰ�� 
	 	cout<<p->Data<<" ";//pָ����˱��� ���� 
	 	free(p);//ɾ��p 
	 	p=s->Next;// p����ָ����һ����������
	 }
	 cout<<p->Data<<" ";//�����һ���˵ı����� 
	
}
int main()
{
	int n,k,m;//��֪n���ˣ��Ա��1��2��3����������Χ����һȦ�����ڴӱ��Ϊk���˿�ʼ����������m���˳��У�
	cin>>n>>m>>k;
	Joseph(n,m,k);
}
