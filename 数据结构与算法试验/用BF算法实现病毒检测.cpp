//ʵ��4�������ַ���ģʽƥ���㷨�Ĳ�����Ⱦ�������
/*����Ҫ�󣺶������ݣ�ÿ��������һ�У�Ϊ����A��B��A��Ӧ������DNA���У�B��Ӧ�˵�DNA���С�A��B��Ϊ��0��ʱ�������
���Ҫ�󣺶���ÿ���������һ�У������߸�Ⱦ�˲��������YES",���������NO��
����������abbab abbabaab
baa cacdvcabacsd
abc def
0 0
��������� 
YES
YES
NO
*/
#include<iostream>
#include<string.h>
using namespace std;
#define MAXLEN 255
struct String//���ô��Ķ���˳ʽ�洢�ṹ 
{
	char ch[MAXLEN+1];//�洢����һά���� 
	int length;//���ĵ�ǰ���� 
}Virus,Person,temp;

int Index_BF(String S,String T,int pos)//BF�㷨 
{
	int i,j;
	//����ģʽT������S�е�pos���ַ���ʼ��һ�γ��ֵ�λ�á��������ڣ��򷵻�ֵΪ0 
	i=pos;j=1;
	while(i<=strlen(S.ch+1)&&j<=strlen(T.ch+1)) //���㷨�в��ô�1��ʼ�洢 
	{
		if(S.ch[i]<65||S.ch[i]>122)
		{
			cout<<"Input error!" <<endl;
			return 2;
		}
		if(S.ch[i]>90&&S.ch[i]<97)
		{
			cout<<"Input error!" <<endl;
			return 2;
		}
		if(T.ch[j]<65||T.ch[j]>122)
		{
			cout<<"Input error!" <<endl;
			return 2;
		}
		if(T.ch[j]>90&&T.ch[j]<97)
		{
			cout<<"Input error!" <<endl;
			return 2;
		}
		if(S.ch[i]==T.ch[j]){
			++i;
			++j;
		}
		else{ 
			i = i-j +2;
			j = 1;
		}
	}
	if(j>strlen(T.ch+1))
	return 1;//���ƥ�䣬 ����һ����0�� 
	else
	return 0;//��ƥ���򷵻�0 
}

void Virus_detection()//��BF�㷨ʵ�ֲ������ 
{
	int i,j,m,n;
	int k=0;
	int Flag[255]; 
	int flag=0;//������ʶ�Ƿ�ƥ�䣬��ʼΪ0��ƥ���Ϊ1 
	cin >> Virus.ch+1;//��1��λ�ÿ�ʼ�洢
    m = strlen(Virus.ch+1) ;//����DNA���еĳ�����m
    cin >> Person.ch+1;
    n = strlen(Person.ch+1);//��DNA���еĳ�����n 
    while(Virus.ch[1]!='0'&&Person.ch[1]!='0')//������Ϊ0 0ʱ����
    {
    	for(i=m+1,j=1;j<=m;j++)
    	{
    		Virus.ch[i++]=Virus.ch[j];//�������ַ����ĳ����������� 
		}
		Virus.ch[2*m+1]='\0';//��ӽ�������
		for(i=0;i<m;i++) 
		{
			for(j=1;j<=m;j++)
				temp.ch[j] = Virus.ch[i+j];//����ȡ��ÿ������Ϊm�Ĳ���DNA��״�ַ���temp 
			temp.ch[m+1]='\0';//��ӽ�������
			flag=Index_BF(Person,temp,1);//�����ж��Ƿ�ƥ�� 
			if(flag==1)
				break; 
			if(flag==2)
				return;
		}
		if(flag)
			Flag[k]=1;//������¼ÿһ����ƥ���ʶ��δƥ��Ϊ0��ƥ���Ϊ1 
		else
			Flag[k]=0;
		k++;
    	cin >> Virus.ch+1; //��ȡ�´� 
    	m = strlen(Virus.ch+1) ;//����DNA���еĳ�����m 
    	cin >> Person.ch+1; 
    	n = strlen(Person.ch+1);//��DNA���еĳ�����n 

 	
	}
	int Flaglength=k;
	k=0;
	while(k<Flaglength)//������ͷÿһ����ƥ���ʶ 
	{
		if(Flag[k])
		cout<<"YES"<<endl;//�����¼��ʶΪ1�������YES���������NO 
		else
		cout<<"NO"<<endl;
		k++;
	}
	
}
int main()
{
	Virus_detection();	
}
