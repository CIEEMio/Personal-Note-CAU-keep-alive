//实验5：基于哈夫曼树的数据压缩算法
/*输入样例：
aaaaaaabbbbbccdddd
aabccc
0 
输出样例： 
a:7 b:5 c:2 d:4
1 7 7 0 0
2 5 6 0 0
3 2 5 0 0
4 4 6 0 0
5 6 6 3 4
6 11 7 2 5
7 18 0 1 6
a:0 b:10 c:110 d:111
00000001010101010110110111111111111
aaaaaaabbbbbccdddd
a:2 b:1 c:3
1 2 4 0 0
2 1 4 0 0
3 3 5 0 0
4 3 5 2 1
5 6 0 3 4
a:11 b:10 c:0
111110000
aabccc
*/
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

typedef struct {
    int weight;//结点权重
    int parent, lchild, rchild;//父结点、左孩子、右孩子在数组中的位置下标
}HTNode, *HuffmanTree;

typedef char**HuffmanCode;

//HT数组中存放的哈夫曼树，end表示HT数组中存放结点的最终位置，s1和s2传递的是HT数组中权重值最小的两个结点
void Select(HuffmanTree HT, int n, int &s1, int &s2)
{
	s1=s2=0;
    int i; //遍历数组初始下标为 1
    for(i=1;i<n;++i){//找到还没构建树的结点
    	if(HT[i].parent==0)
    	{
    		if(s1==0)
    			s1=i;
    		else
    		{
    			s2=i;
    			break;
			}
		}
    }

    //对找到的两个结点比较大小
    if(HT[s1].weight > HT[s2].weight){
        int tmp = s1;
        s1 = s2;
        s2 = tmp;
    }
    //两个结点和后续的所有未构建成树的结点做比较
    for(i=i+1; i<n; ++i)
    {
        //找无父结点的结点 
        if(HT[i].parent != 0){
            continue;
        }
        //如果比最小的还小，将s2=s1，s1赋值新的结点的下标
        if(HT[i].weight < HT[s1].weight){
            s2 = s1;
            s1 = i;
        }
        //如果介于两者之间，将s2赋值为新的结点的位置下标
        else if(HT[i].weight >= HT[s1].weight && HT[i].weight <  HT[s2].weight){
            HT[s2].weight = HT[i].weight;
            s2 = i;
        }
    }
}

 void CreateHuffmanTree(HuffmanTree &HT,int n,int weight[]) //构造哈夫曼树HT 
 {
 	int i;
 	if(n<=1)return;
 	int m=2*n-1;
 	HT=new HTNode[m+1];//0号单元未用，所以需要动态分配m+1个单元，HT[m]表示根节点 
 	for(i=1;i<=m;i++)
 	{
 		HT[i].parent=0;
 		HT[i].lchild=0;
 		HT[i].rchild=0;
	 }
	for(i=1;i<=n;i++)
		HT[i].weight=weight[i-1];//记录前n个单元中叶子节点的权值
	/*初始化结束，开始创建哈夫曼树*/
	for(i=n+1;i<=m;i++)
	{
		int s1,s2;
		Select(HT,i,s1,s2);
		HT[s1].parent=i;
		HT[s2].parent=i;//得到新节点i，从森林中删除s1，s2，将s1和s2的双亲域由0改为i
		HT[i].lchild=s1;
		HT[i].rchild=s2;//s1,s2 分别作为i的左右孩子
		HT[i].weight=HT[s1].weight+HT[s2].weight;//i的权值为左右孩子的权值的和 
	}
  } 
void Print(HuffmanTree HT,int n)
{
    for(int i=1, m=2*n-1; i<=m; ++i){
        cout << i ;
        cout << " "<< HT[i].weight ;
        cout << " " << HT[i].parent;
        cout << " "<< HT[i].lchild;
        cout << " " << HT[i].rchild;
        cout<<endl;
    }
}

void CreateHuffmanCode(HuffmanTree HT,HuffmanCode &HC,int n)//从叶子到根逆向求每个字符的哈夫曼编码，存储在编码表HC中 
{
	int start;
	int i,f,c;
	HC=new char*[n+1];//分配存储n个字符的编码的编码表空间 
	char *cd=new char[n];//分配临时存放每个字符编码的动态数组空间 
	cd[n-1]='\0';//编码结束符 
	for(i=1;i<=n;++i)//逐个字符求哈夫曼编码
	{
		start = n-1;//start开始时指向最后，即编码结束符位置 
		c=i;
		f=HT[i].parent;//f指向结点c的双亲结点 
		while(f!=0)//从叶子结点开始 向上回溯，直到根结点 
		{
			--start;//回溯依次start向前指一个位置 
			if(HT[f].lchild==c)//结点c是f的左孩子，则生成代码0 
				cd[start]='0';
			else //结点c是f的右孩子，则生成代码1 
				cd[start]='1';
			c=f;//继续向上回溯 
			f=HT[f].parent;
		}
		HC[i]=new char[n-start];
		strcpy(HC[i],&cd[start]);//将求得的编码复制到HC当前行中 
	}
	delete cd;
}


void Huffman()
{
	char ch[255];
	int weight[26];
	while (1) //当输入不为结束时，继续下一个字符串 
	{
		HuffmanTree HT;
		HuffmanCode HC; 
		cin>>ch;
		int i,j=0,k,n=0;
		int count[26]={0};
		int weight[26]; 
		char cs[26]={'0'};
		if(ch[0]=='0')
		return;
		for(i=0;ch[i]!='\0';i++)
		{
			if(ch[i]<123&&ch[i]>96)
				count[ch[i]-'a']++;//输入合法均为小写字母 
			else
			{
				cout<<"Input error!"<<endl;
				return;
			}
			
		}
		for(i=0;i<26;i++)
		{
			if(count[i]!=0)
			{
				cs[j]='a'+i;//记录出现过的字母 
				weight[j]=count[i];//记录该字母对应的权值 
				j++;
				n++;
			}
		 }
		CreateHuffmanTree(HT,n,weight);
		CreateHuffmanCode(HT,HC,n);
		for(k=0;k<j;k++)
		{
			cout<<cs[k]<<":"<<weight[k]<<" ";//输出字符串字母频度统计结果 
		} 
		cout<<endl;
		Print(HT,n);//输出生成树结果 
		for(k=0;k<j;k++)
		{
			cout<<cs[k]<<":"<<HC[k+1]<<" ";//输出字符编码结果 
		}   
		cout<<endl;
		for(i=0;ch[i]!='\0';i++)
		{
			for(j=0;cs[j]!='\0';j++)
			{
				if(ch[i]==cs[j])
				{
					cout<<HC[j+1];
				}
			}
		}
		cout<<endl;
		cout<<ch<<endl;
	}
	
}

  int main()
  {	
	Huffman();
  	return 0;
  }
