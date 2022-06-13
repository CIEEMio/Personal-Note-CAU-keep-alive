//实验4：基于字符串模式匹配算法的病毒感染检测问题
/*输入要求：多组数据，每组数据有一行，为序列A和B，A对应病毒的DNA序列，B对应人的DNA序列。A和B都为“0”时输入结束
输出要求：对于每组数据输出一行，若患者感染了病毒输出“YES",否则输出”NO“
输入样例：abbab abbabaab
baa cacdvcabacsd
abc def
0 0
输出样例： 
YES
YES
NO
*/
#include<iostream>
#include<string.h>
using namespace std;
#define MAXLEN 255
struct String//采用串的定长顺式存储结构 
{
	char ch[MAXLEN+1];//存储串的一维数组 
	int length;//串的当前长度 
}Virus,Person,temp;

int Index_BF(String S,String T,int pos)//BF算法 
{
	int i,j;
	//返回模式T在主串S中第pos个字符开始第一次出现的位置。若不存在，则返回值为0 
	i=pos;j=1;
	while(i<=strlen(S.ch+1)&&j<=strlen(T.ch+1)) //本算法中采用从1开始存储 
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
	return 1;//如果匹配， 返回一个非0数 
	else
	return 0;//不匹配则返回0 
}

void Virus_detection()//用BF算法实现病毒检测 
{
	int i,j,m,n;
	int k=0;
	int Flag[255]; 
	int flag=0;//用来标识是否匹配，初始为0，匹配后为1 
	cin >> Virus.ch+1;//从1号位置开始存储
    m = strlen(Virus.ch+1) ;//病毒DNA序列的长度是m
    cin >> Person.ch+1;
    n = strlen(Person.ch+1);//人DNA序列的长度是n 
    while(Virus.ch[1]!='0'&&Person.ch[1]!='0')//当输入为0 0时结束
    {
    	for(i=m+1,j=1;j<=m;j++)
    	{
    		Virus.ch[i++]=Virus.ch[j];//将病毒字符串的长度扩大两倍 
		}
		Virus.ch[2*m+1]='\0';//添加结束符号
		for(i=0;i<m;i++) 
		{
			for(j=1;j<=m;j++)
				temp.ch[j] = Virus.ch[i+j];//依次取得每个长度为m的病毒DNA环状字符串temp 
			temp.ch[m+1]='\0';//添加结束符号
			flag=Index_BF(Person,temp,1);//用于判断是否匹配 
			if(flag==1)
				break; 
			if(flag==2)
				return;
		}
		if(flag)
			Flag[k]=1;//用来记录每一串的匹配标识，未匹配为0，匹配后为1 
		else
			Flag[k]=0;
		k++;
    	cin >> Virus.ch+1; //读取新串 
    	m = strlen(Virus.ch+1) ;//病毒DNA序列的长度是m 
    	cin >> Person.ch+1; 
    	n = strlen(Person.ch+1);//人DNA序列的长度是n 

 	
	}
	int Flaglength=k;
	k=0;
	while(k<Flaglength)//遍历重头每一串的匹配标识 
	{
		if(Flag[k])
		cout<<"YES"<<endl;//如果记录标识为1，则输出YES，否则输出NO 
		else
		cout<<"NO"<<endl;
		k++;
	}
	
}
int main()
{
	Virus_detection();	
}
