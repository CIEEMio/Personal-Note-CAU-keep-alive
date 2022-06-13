//实验二 基于栈的中缀算术表达式求值 
/*
输入

2+2=
20*(4.5-3)=
=
输出

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

//定义符号栈及其相关操作 
typedef struct {//栈的数据结构 
    char* base;//栈底指针 
    char* top;//栈顶指针 
    int stacksize;//已用的栈的存储空间大小 
}SqStackOPTR;//符号栈 
//初始化符号栈 
int Init_SqStackOPTR(SqStackOPTR& S) {
    S.base = new char[MAXSIZE];
    if (!S.base)
        return OVERFLOW;//不为空时overflow了 
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;
}
//入栈函数 
int PushOPTR(SqStackOPTR& S, char e) {
    if (S.top - S.base == S.stacksize)//栈的大小未超过最大使用空间时 
        return ERROR;
    *S.top = e;
    S.top++;
    return OK;
}
//出栈函数 
int PopOPTR(SqStackOPTR& S, char& e) {
    if (S.top == S.base)//不为空栈时 
        return ERROR;
    --S.top;
    e = *S.top;
    return OK;
}
//取栈顶 
char GettopOPTR(SqStackOPTR& S) {
    if (S.top != S.base)//当不为空栈时 
        return *(S.top - 1);
}
//定义数字栈及其相关操作 
typedef struct {
    double* base;//栈的数据结构 
    double* top;//栈底指针 
    int stacksize;//栈顶指针 
}SqStackOPND;//数字栈 
//初始化数字栈 
int Init_SqStackOPND(SqStackOPND& S) {
    S.base = new double[MAXSIZE];
    if (!S.base)//不为空栈时overflow了 
        return OVERFLOW;
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;
}
//入栈函数 
int PushOPND(SqStackOPND& S, double e) {
    if (S.top - S.base == S.stacksize)//不超限时 
        return ERROR;
    *S.top = e;
    S.top++;
    return OK;
}
//出栈函数 
int PopOPND(SqStackOPND& S, double& e) {
    if (S.top == S.base)//为空栈时 
        return ERROR;
    --S.top;
    e = *S.top;
    return OK;
}

//取栈顶 
double GettopOPND(SqStackOPND& S) {
    if (S.top != S.base)// 不为空栈时 
        return *(S.top - 1);
}

double Fun(double a, double b, char c) {// 求两数a，b进行c运算的值 
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
			cout<<"除数为0无意义"<<endl ;
			return a/b;
		}
	}	

}

char Precede(char a, char b) {//判断两运算符号优先级，构建优先级矩阵 priority，对于每种符号组合定义优先级比较>,<和= 
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

int In(char ch) {//判断是否为符号：当返回1时ch为符号 
    if (ch >= '0' && ch <= '9')
        return 0;
    else if(ch=='.')
        return 0;
    else return 1;
}
 
int isFiniteNumber(double d) {return (d<=DBL_MAX&&d>=-DBL_MAX);}//判断输出是否超界 

int main() {
    while (1) {
        int fflag=0;//判断上一个输入是否为数字 
        char x;
        char ch;
        double integer=0;//用来记录整数
        double decimals=0;//用来记录小数
        double middle=0;//整数小数相加
        int flag = 0;//falg 表示现在的数字是在小数点前还是小数点后
        int point = 1;//记录当前数是小数点后第几位
        SqStackOPND OPND;//数字栈 
        SqStackOPTR OPTR;//符号栈 
        char theta;//运算符 
        double a, b;
        Init_SqStackOPND(OPND);
        Init_SqStackOPTR(OPTR);//初始化数字栈和符号栈 
        PushOPTR(OPTR, '=');
        cin >> ch;//输入字符串
        if (ch == '=')//只输入=时结束输入 
            return 0;
        while (ch != '=' || GettopOPTR(OPTR) != '=') {//表达式没有扫描完毕或OPTR的栈顶元素不为“=”
            if (!In(ch)) {
                if(ch!='.'){// //不是运算符则处理小数和整数 
                if (flag == 0) {
                    integer = 10 * integer;
                    integer += ch - '0';
                }
                else if (flag == 1) {//解析小数部分
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
            switch (Precede(GettopOPTR(OPTR), ch))//比较OPTR的栈顶元素和ch的优先级
            {
            case '<'://还暂时不用对数栈运算
                PushOPTR(OPTR, ch);//当前字符ch压入OPTR栈，读入下一字符ch
                cin >> ch;
                break;
            case'>'://弹出该运算符并弹出两个数，进行运算
                PopOPTR(OPTR, theta);//弹出OPTR栈顶的运算符
                PopOPND(OPND, b);//弹出OPND栈顶的两个运算数
                PopOPND(OPND, a);
                PushOPND(OPND, Fun(a, b, theta));//将运算结果压入OPND栈
                break;
            case'=': //OPTR的栈顶元素是“(”且ch是“)”，括号内容已经运算完毕，现在去括号
                PopOPTR(OPTR, x);//弹出OPTR栈顶的“(”，读入下一字符ch
                cin >> ch;
                break;
            default:
				cout<<"输入了非法字符" <<endl;
                return 0;
            }
        }
        if(isFiniteNumber(GettopOPND(OPND)))
			printf("%.2f\n",GettopOPND(OPND));//OPND栈顶元素即为表达式求值结果
		else
			cout<<"输出超出浮点数表示范围"<<endl;
    }
    return 0;
}

