/*ʵ��4  ���еĻ�������
��Ϊ������ԣ�����Ԫ�ض���Ϊ��typedef  int  Elemtype������������Ϊ8��
���ʵ�����¹��ܣ�
��Ӽ�������һ���ַ���a1a2a3��an��
��ai�������ַ���ai���ӣ���ai��Сд��ĸ��������Ԫ�س��ӣ�
���������ַ�����ʾ��������������ʾ�����е��ַ���
Ҫ����ѭ������ʵ�ֶ��У����ж��������СΪ8��
 */
#include <stdio.h>
#define MAXSIZE 8
//��������ṹ 
typedef int Elemtype;
typedef struct{//���� 
	Elemtype elem[MAXSIZE];
	int head;
	int back;
}Queue;

void Start_Queue(Queue *Q){//��ʼ��һ������ 
	Q->head=0;
	Q->back=0;
}

int In_Queue(Queue *Q,int x){//����δ��������Ԫ�����ڶ�β,��β�������elem[7]����β�Զ�ָ��elem[0] 
 int i;
 if((Q->back+1)%MAXSIZE==Q->head) {
 	printf("����,������ֹ");
 	return 0;
 } 
 Q->elem[Q->back]=x;
 Q->back=((Q->back)+1)%MAXSIZE;
 return 1;
 }	

int Out_Queue(Queue *Q,int *y,int *temp){//����Ԫ�س���,���ӵ�Ԫ����y��¼ 
	
	if(Q->back==Q->head){//������ѿ�
		if (*temp == 0) { 
            printf("�����ѿ�\n");
            *temp = 1; 
	}
	return 0;
}
	else{//�����û�п�
		*y=Q->elem[Q->head];
		Q->head = (Q->head + 1) % MAXSIZE;
		return 1;
	}
	 
}

int Print_Queue(Queue *Q){//��ӡ����Ԫ��
int i;
if(Q->back==Q->head){
	printf("�����ǿ�");return 0;
}
i=Q->head;
while (i != Q->back) { 
        printf("%d ", Q->elem[i]);
        i = (i + 1) % MAXSIZE;
    }
    printf("\n");
return 1;
}

int judge(char str1){//�ж������������/Сд��ĸ/�����ַ� 
	if(str1>='0'&&str1<='9'){
	return 1;}
	else if(str1>='a'&&str1<='z'){
	return 2;
	}
	else{
		return 3;
	} 
	
}

int main(){
	printf("ѭ�����������СΪ8��Ϊ�����ֶ����Ͷӿգ�����һ���ڴ�ռ䣬���ո�����һ�ο������ʱ����7�����֣�������ʾ��������ֹ����\n�������ַ�����");
	char str[100];
	char str1;
	int flag=1;
	int temp=0;
	int i=0;
	int j=0;
	Queue queue;
	Start_Queue(&queue);
	while(scanf("%c",&str1)&&str1!='\n'){//�û������ַ��� 
	         str[i]=str1;
	         i++;
		}
	str[i]='\0';
	for (int j = 0; j < i; j++) {
    str1= str[j];
    int type = judge(str1);
    if (type == 1) { 
    int z;
           z=In_Queue(&queue, str1 - '0');
         if(z==0) return 0;   
    } else if (type == 2) { 
        int y;
        if (Out_Queue(&queue, &y, &temp) == 0) return 0;
    } else { 
    break;
        }
    }
    Print_Queue(&queue);
	return 0;
}
