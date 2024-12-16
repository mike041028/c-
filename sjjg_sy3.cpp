
/*功能：将中缀表达式转换为后缀表达式。
要求输入一个中缀表达式，表达式中有+、-、*、/四种运算以及（  ），
表达式中的其他符号为大写的字母，以#结束。
要求得到相应的后缀表达式并输出显示。（
例如：输入A*(B-C)/D+E#  输出 ABC-*D/E+   ） */

#include <stdio.h>
#define MAXSIZE 20

//以下是存储结构 
typedef char ElemType; 
typedef struct {
	ElemType elem[MAXSIZE];
	int top;
}SqStack;


//以下是函数定义 
int Priority(char c) {
	switch(c){
		case '+':
		case '-':return 1;
		case '*':
		case '/':return 2;
		default:return 0;
	}
	return 0;	
}

void InitStack_Sq(SqStack *S){
	//建立一个空栈
	S->top=0; 
}
int isletter(char c){//判断c是否为字母，是则返回1； 
	if(c>='A'&&c<='Z') return 1;
	else return 0;
}

int Empty_Sq(SqStack *S){
	//判断栈是否为空，空则返回1
	return (S->top==0);
}
int Push_Sq(SqStack *S,ElemType x){
	//若栈S未满，将元素x进栈
	if(S->top==MAXSIZE) return 0;//栈满
	S->elem[S->top]=x;
	S->top++;
	return 1;
}

int Pop_Sq(SqStack *S,ElemType *y){
	//出栈顶字符 
	if(S->top==0) return 0;
	*y=S->elem[--S->top];
	return 1;
}
ElemType GetTop(SqStack *S) { // 获取栈顶元素
    if (!Empty_Sq(S))
        return S->elem[S->top - 1];
    return '\0';
}

void InfixToSuffix(char str[],int length){//中缀转后缀
        SqStack sq;//实例化一个栈sq 
	    InitStack_Sq(&sq);//初始化sq栈 
	for(int i=0;i<length;i++){
		char c=str[i];//取出当前字符 
		
		if(isletter(c)){//若c是字母，直接加入到结果中
			printf("%c",c);	
		} 
		//如果是字符 
		else if(c=='(') {//若c是'(',入栈
			Push_Sq(&sq,c);
		}
		else if(c==')'){//若c是')'，循环出栈并打印,当栈顶字符为'('出栈后截止不再打印 
			char top;
            while (Pop_Sq(&sq, &top) && top != '(') {
                printf("%c", top);
			}
		} 
		else if (c == '+' || c == '-' || c == '*' || c == '/'){//若c是运算符 
			 
		while(Empty_Sq(&sq)==0&&Priority(c)<=Priority(GetTop(&sq))){
		//若c优先级<=栈顶字符优先级，循环出栈并打印，直到栈顶字符优先级<c优先级且栈非空
			printf("%c",GetTop(&sq));
			 char tmp;
            Pop_Sq(&sq, &tmp);
		}
		//将c入栈
		Push_Sq(&sq,c);
		}
		else if (c == '#') { // 结束符，停止处理
            break;
        }
	}
	//循环读取结束，若栈非空需要将剩余栈中的字符依次出栈并打印 
	while(Empty_Sq(&sq)==0){
		char top;
        Pop_Sq(&sq, &top);
        printf("%c", top);
	} 
} 



int main()
{
	char str[100];//用户累计输入字符串 
	char str1;//用户实时输入字符 
	int length=0;
	while(scanf("%c",&str1)){
		if(str1=='#') break;
		else{
			str[length]=str1;
		length++;
		}	 
	}
	InfixToSuffix(str,length); 
	return 0;
	
}
