#include<iostream>
#include<malloc.h>
#include <stdlib.h>
using namespace std; 
typedef int ElementType; // ElementType 定义为int
typedef struct LNode *List;
struct LNode{
	ElementType Data;   //数据域 
	List Next;   // 下一个链表的地址 
}; 
List L;
List Make(int n); //初始化链表 


// 初始化链表 
List Make(int n){
	List head = new LNode;
	head->Data=1;
	head->Next=NULL;//初始化头结点 
	List L=head;
	List p;
	for(int i=2;i<=n;i++)
	{
		p=new LNode;//给每个人对应的节点编号 
		p->Data=i;
		p->Next=NULL;
		L->Next=p;
		L=L->Next;
	}
	L->Next=head;//头尾相连 形成循环链表 
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
	//Print(L,n); //测试链表是否创建成功 
	p = head;
	int i=1;
	while(p && i<k){//找到第k个人 时间复杂度O（k） 
		p = p->Next;
		i++;
	}
	 while (p->Next!=p) 
	 {
	 	for (i=1; i<m; i++) {//报数，每报到m有1人出列，直到最后只剩下1个人 时间复杂度O（m*n） 
	 		s=p;
	 		p=p->Next;
	 	}
	 	s->Next=p->Next;//将s连接到p的下一个的前面 
	 	cout<<p->Data<<" ";//p指向的人报数 出列 
	 	free(p);//删除p 
	 	p=s->Next;// p重新指向下一个报数的人
	 }
	 cout<<p->Data<<" ";//将最后一个人的编号输出 
	
}
int main()
{
	int n,k,m;//已知n个人（以编号1，2，3，…，代表）围坐成一圈。现在从编号为k的人开始报数，数到m的人出列；
	cin>>n>>m>>k;
	Joseph(n,m,k);
}
