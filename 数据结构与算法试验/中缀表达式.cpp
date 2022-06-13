//ʵ��� ����ջ����׺�������ʽ��ֵ 
/*
����

2+2=
20*(4.5-3)=
=
���

4.00
30.00
*/ 
#include<iostream>
#include<float.h>
using namespace std;
#define MAXSIZE 1000
#define OVERFLOW -2
#define OK 0
#define ERROR -1

//�������ջ������ز��� 
typedef struct {//ջ�����ݽṹ 
    char* base;//ջ��ָ�� 
    char* top;//ջ��ָ�� 
    int stacksize;//���õ�ջ�Ĵ洢�ռ��С 
}SqStackOPTR;//����ջ 
//��ʼ������ջ 
int Init_SqStackOPTR(SqStackOPTR& S) {
    S.base = new char[MAXSIZE];
    if (!S.base)
        return OVERFLOW;//��Ϊ��ʱoverflow�� 
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;
}
//��ջ���� 
int PushOPTR(SqStackOPTR& S, char e) {
    if (S.top - S.base == S.stacksize)//ջ�Ĵ�Сδ�������ʹ�ÿռ�ʱ 
        return ERROR;
    *S.top = e;
    S.top++;
    return OK;
}
//��ջ���� 
int PopOPTR(SqStackOPTR& S, char& e) {
    if (S.top == S.base)//��Ϊ��ջʱ 
        return ERROR;
    --S.top;
    e = *S.top;
    return OK;
}
//ȡջ�� 
char GettopOPTR(SqStackOPTR& S) {
    if (S.top != S.base)//����Ϊ��ջʱ 
        return *(S.top - 1);
}
//��������ջ������ز��� 
typedef struct {
    double* base;//ջ�����ݽṹ 
    double* top;//ջ��ָ�� 
    int stacksize;//ջ��ָ�� 
}SqStackOPND;//����ջ 
//��ʼ������ջ 
int Init_SqStackOPND(SqStackOPND& S) {
    S.base = new double[MAXSIZE];
    if (!S.base)//��Ϊ��ջʱoverflow�� 
        return OVERFLOW;
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;
}
//��ջ���� 
int PushOPND(SqStackOPND& S, double e) {
    if (S.top - S.base == S.stacksize)//������ʱ 
        return ERROR;
    *S.top = e;
    S.top++;
    return OK;
}
//��ջ���� 
int PopOPND(SqStackOPND& S, double& e) {
    if (S.top == S.base)//Ϊ��ջʱ 
        return ERROR;
    --S.top;
    e = *S.top;
    return OK;
}

//ȡջ�� 
double GettopOPND(SqStackOPND& S) {
    if (S.top != S.base)// ��Ϊ��ջʱ 
        return *(S.top - 1);
}

double Fun(double a, double b, char c) {// ������a��b����c�����ֵ 
    if (c == '+')
        return a + b;
    else if (c == '-')
        return a - b;
    else if (c == '*')
        return a * b;
    else if (c == '/')
    {
    	if (b!=0)
		return a / b;
		else
		{
			cout<<"����Ϊ0������"<<endl ;
			return a/b;
		}
	}	

}

char Precede(char a, char b) {//�ж�������������ȼ����������ȼ����� priority������ÿ�ַ�����϶������ȼ��Ƚ�>,<��= 
    int i, j;
    char priority[7][7] = {
    {'>','>','<','<','<','>','>'},
    {'>','>','<','<','<','>','>'},
    {'>','>','>','>','<','>','>'},
    {'>','>','>','>','<','>','>'},
    {'<','<','<','<','<','=','0'},
    {'>','>','>','>','0','>','>'},
    {'<','<','<','<','<','0','='}
    };
    switch (a) {
    case'+':i = 0; break;
    case'-':i = 1; break;
    case'*':i = 2; break;
    case'/':i = 3; break;
    case'(':i = 4; break;
    case')':i = 5; break;
    case'=':i = 6; break;
    default:break;
    }
    switch (b) {
    case'+':j = 0; break;
    case'-':j = 1; break;
    case'*':j = 2; break;
    case'/':j = 3; break;
    case'(':j = 4; break;
    case')':j = 5; break;
    case'=':j = 6; break;
    default:break;

    }
    return priority[i][j];
}

int In(char ch) {//�ж��Ƿ�Ϊ���ţ�������1ʱchΪ���� 
    if (ch >= '0' && ch <= '9')
        return 0;
    else if(ch=='.')
        return 0;
    else return 1;
}
 
int isFiniteNumber(double d) {return (d<=DBL_MAX&&d>=-DBL_MAX);}//�ж�����Ƿ񳬽� 

int main() {
    while (1) {
        int fflag=0;//�ж���һ�������Ƿ�Ϊ���� 
        char x;
        char ch;
        double integer=0;//������¼����
        double decimals=0;//������¼С��
        double middle=0;//����С�����
        int flag = 0;//falg ��ʾ���ڵ���������С����ǰ����С�����
        int point = 1;//��¼��ǰ����С�����ڼ�λ
        SqStackOPND OPND;//����ջ 
        SqStackOPTR OPTR;//����ջ 
        char theta;//����� 
        double a, b;
        Init_SqStackOPND(OPND);
        Init_SqStackOPTR(OPTR);//��ʼ������ջ�ͷ���ջ 
        PushOPTR(OPTR, '=');
        cin >> ch;//�����ַ���
        if (ch == '=')//ֻ����=ʱ�������� 
            return 0;
        while (ch != '=' || GettopOPTR(OPTR) != '=') {//���ʽû��ɨ����ϻ�OPTR��ջ��Ԫ�ز�Ϊ��=��
            if (!In(ch)) {
                if(ch!='.'){// //�������������С�������� 
                if (flag == 0) {
                    integer = 10 * integer;
                    integer += ch - '0';
                }
                else if (flag == 1) {//����С������
                    double t=ch-'0';
                    for (int l = 0; l < point; l++)
                        t = 0.1 * t;
                    point++;
                    decimals += t;
                }
            }
            else if(ch=='.'){
                flag=1;
            }
                fflag=1;
                cin >> ch;
                continue;
            }
            if (In(ch)&&fflag==1) {
                middle = integer + decimals;
                PushOPND(OPND, middle);
                flag = 0;
                middle = 0;
                integer = 0;
                decimals = 0;
                point = 1;
                fflag=0;
            }
            switch (Precede(GettopOPTR(OPTR), ch))//�Ƚ�OPTR��ջ��Ԫ�غ�ch�����ȼ�
            {
            case '<'://����ʱ���ö���ջ����
                PushOPTR(OPTR, ch);//��ǰ�ַ�chѹ��OPTRջ��������һ�ַ�ch
                cin >> ch;
                break;
            case'>'://���������������������������������
                PopOPTR(OPTR, theta);//����OPTRջ���������
                PopOPND(OPND, b);//����OPNDջ��������������
                PopOPND(OPND, a);
                PushOPND(OPND, Fun(a, b, theta));//��������ѹ��OPNDջ
                break;
            case'=': //OPTR��ջ��Ԫ���ǡ�(����ch�ǡ�)�������������Ѿ�������ϣ�����ȥ����
                PopOPTR(OPTR, x);//����OPTRջ���ġ�(����������һ�ַ�ch
                cin >> ch;
                break;
            default:
				cout<<"�����˷Ƿ��ַ�" <<endl;
                return 0;
            }
        }
        if(isFiniteNumber(GettopOPND(OPND)))
			printf("%.2f\n",GettopOPND(OPND));//OPNDջ��Ԫ�ؼ�Ϊ���ʽ��ֵ���
		else
			cout<<"���������������ʾ��Χ"<<endl;
    }
    return 0;
}

