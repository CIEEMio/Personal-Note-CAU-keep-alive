//ʵ��5�����ڹ�������������ѹ���㷨
/*����������
aaaaaaabbbbbccdddd
aabccc
0 
��������� 
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
    int weight;//���Ȩ��
    int parent, lchild, rchild;//����㡢���ӡ��Һ����������е�λ���±�
}HTNode, *HuffmanTree;

typedef char**HuffmanCode;

//HT�����д�ŵĹ���������end��ʾHT�����д�Ž�������λ�ã�s1��s2���ݵ���HT������Ȩ��ֵ��С���������
void Select(HuffmanTree HT, int n, int &s1, int &s2)
{
	s1=s2=0;
    int i; //���������ʼ�±�Ϊ 1
    for(i=1;i<n;++i){//�ҵ���û�������Ľ��
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

    //���ҵ����������Ƚϴ�С
    if(HT[s1].weight > HT[s2].weight){
        int tmp = s1;
        s1 = s2;
        s2 = tmp;
    }
    //�������ͺ���������δ���������Ľ�����Ƚ�
    for(i=i+1; i<n; ++i)
    {
        //���޸����Ľ�� 
        if(HT[i].parent != 0){
            continue;
        }
        //�������С�Ļ�С����s2=s1��s1��ֵ�µĽ����±�
        if(HT[i].weight < HT[s1].weight){
            s2 = s1;
            s1 = i;
        }
        //�����������֮�䣬��s2��ֵΪ�µĽ���λ���±�
        else if(HT[i].weight >= HT[s1].weight && HT[i].weight <  HT[s2].weight){
            HT[s2].weight = HT[i].weight;
            s2 = i;
        }
    }
}

 void CreateHuffmanTree(HuffmanTree &HT,int n,int weight[]) //�����������HT 
 {
 	int i;
 	if(n<=1)return;
 	int m=2*n-1;
 	HT=new HTNode[m+1];//0�ŵ�Ԫδ�ã�������Ҫ��̬����m+1����Ԫ��HT[m]��ʾ���ڵ� 
 	for(i=1;i<=m;i++)
 	{
 		HT[i].parent=0;
 		HT[i].lchild=0;
 		HT[i].rchild=0;
	 }
	for(i=1;i<=n;i++)
		HT[i].weight=weight[i-1];//��¼ǰn����Ԫ��Ҷ�ӽڵ��Ȩֵ
	/*��ʼ����������ʼ������������*/
	for(i=n+1;i<=m;i++)
	{
		int s1,s2;
		Select(HT,i,s1,s2);
		HT[s1].parent=i;
		HT[s2].parent=i;//�õ��½ڵ�i����ɭ����ɾ��s1��s2����s1��s2��˫������0��Ϊi
		HT[i].lchild=s1;
		HT[i].rchild=s2;//s1,s2 �ֱ���Ϊi�����Һ���
		HT[i].weight=HT[s1].weight+HT[s2].weight;//i��ȨֵΪ���Һ��ӵ�Ȩֵ�ĺ� 
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

void CreateHuffmanCode(HuffmanTree HT,HuffmanCode &HC,int n)//��Ҷ�ӵ���������ÿ���ַ��Ĺ��������룬�洢�ڱ����HC�� 
{
	int start;
	int i,f,c;
	HC=new char*[n+1];//����洢n���ַ��ı���ı����ռ� 
	char *cd=new char[n];//������ʱ���ÿ���ַ�����Ķ�̬����ռ� 
	cd[n-1]='\0';//��������� 
	for(i=1;i<=n;++i)//����ַ������������
	{
		start = n-1;//start��ʼʱָ����󣬼����������λ�� 
		c=i;
		f=HT[i].parent;//fָ����c��˫�׽�� 
		while(f!=0)//��Ҷ�ӽ�㿪ʼ ���ϻ��ݣ�ֱ������� 
		{
			--start;//��������start��ǰָһ��λ�� 
			if(HT[f].lchild==c)//���c��f�����ӣ������ɴ���0 
				cd[start]='0';
			else //���c��f���Һ��ӣ������ɴ���1 
				cd[start]='1';
			c=f;//�������ϻ��� 
			f=HT[f].parent;
		}
		HC[i]=new char[n-start];
		strcpy(HC[i],&cd[start]);//����õı��븴�Ƶ�HC��ǰ���� 
	}
	delete cd;
}


void Huffman()
{
	char ch[255];
	int weight[26];
	while (1) //�����벻Ϊ����ʱ��������һ���ַ��� 
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
				count[ch[i]-'a']++;//����Ϸ���ΪСд��ĸ 
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
				cs[j]='a'+i;//��¼���ֹ�����ĸ 
				weight[j]=count[i];//��¼����ĸ��Ӧ��Ȩֵ 
				j++;
				n++;
			}
		 }
		CreateHuffmanTree(HT,n,weight);
		CreateHuffmanCode(HT,HC,n);
		for(k=0;k<j;k++)
		{
			cout<<cs[k]<<":"<<weight[k]<<" ";//����ַ�����ĸƵ��ͳ�ƽ�� 
		} 
		cout<<endl;
		Print(HT,n);//������������ 
		for(k=0;k<j;k++)
		{
			cout<<cs[k]<<":"<<HC[k+1]<<" ";//����ַ������� 
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
