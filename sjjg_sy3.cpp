
/*���ܣ�����׺���ʽת��Ϊ��׺���ʽ��
Ҫ������һ����׺���ʽ�����ʽ����+��-��*��/���������Լ���  ����
���ʽ�е���������Ϊ��д����ĸ����#������
Ҫ��õ���Ӧ�ĺ�׺���ʽ�������ʾ����
���磺����A*(B-C)/D+E#  ��� ABC-*D/E+   �� */

#include <stdio.h>
#define MAXSIZE 20

//�����Ǵ洢�ṹ 
typedef char ElemType; 
typedef struct {
	ElemType elem[MAXSIZE];
	int top;
}SqStack;


//�����Ǻ������� 
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
	//����һ����ջ
	S->top=0; 
}
int isletter(char c){//�ж�c�Ƿ�Ϊ��ĸ�����򷵻�1�� 
	if(c>='A'&&c<='Z') return 1;
	else return 0;
}

int Empty_Sq(SqStack *S){
	//�ж�ջ�Ƿ�Ϊ�գ����򷵻�1
	return (S->top==0);
}
int Push_Sq(SqStack *S,ElemType x){
	//��ջSδ������Ԫ��x��ջ
	if(S->top==MAXSIZE) return 0;//ջ��
	S->elem[S->top]=x;
	S->top++;
	return 1;
}

int Pop_Sq(SqStack *S,ElemType *y){
	//��ջ���ַ� 
	if(S->top==0) return 0;
	*y=S->elem[--S->top];
	return 1;
}
ElemType GetTop(SqStack *S) { // ��ȡջ��Ԫ��
    if (!Empty_Sq(S))
        return S->elem[S->top - 1];
    return '\0';
}

void InfixToSuffix(char str[],int length){//��׺ת��׺
        SqStack sq;//ʵ����һ��ջsq 
	    InitStack_Sq(&sq);//��ʼ��sqջ 
	for(int i=0;i<length;i++){
		char c=str[i];//ȡ����ǰ�ַ� 
		
		if(isletter(c)){//��c����ĸ��ֱ�Ӽ��뵽�����
			printf("%c",c);	
		} 
		//������ַ� 
		else if(c=='(') {//��c��'(',��ջ
			Push_Sq(&sq,c);
		}
		else if(c==')'){//��c��')'��ѭ����ջ����ӡ,��ջ���ַ�Ϊ'('��ջ���ֹ���ٴ�ӡ 
			char top;
            while (Pop_Sq(&sq, &top) && top != '(') {
                printf("%c", top);
			}
		} 
		else if (c == '+' || c == '-' || c == '*' || c == '/'){//��c������� 
			 
		while(Empty_Sq(&sq)==0&&Priority(c)<=Priority(GetTop(&sq))){
		//��c���ȼ�<=ջ���ַ����ȼ���ѭ����ջ����ӡ��ֱ��ջ���ַ����ȼ�<c���ȼ���ջ�ǿ�
			printf("%c",GetTop(&sq));
			 char tmp;
            Pop_Sq(&sq, &tmp);
		}
		//��c��ջ
		Push_Sq(&sq,c);
		}
		else if (c == '#') { // ��������ֹͣ����
            break;
        }
	}
	//ѭ����ȡ��������ջ�ǿ���Ҫ��ʣ��ջ�е��ַ����γ�ջ����ӡ 
	while(Empty_Sq(&sq)==0){
		char top;
        Pop_Sq(&sq, &top);
        printf("%c", top);
	} 
} 



int main()
{
	char str[100];//�û��ۼ������ַ��� 
	char str1;//�û�ʵʱ�����ַ� 
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
