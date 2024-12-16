/*实验4  队列的基本操作
（为方便测试，其中元素定义为：typedef  int  Elemtype，数组容量设为8）
编程实现以下功能：
设从键盘输入一个字符串a1a2a3…an。
若ai是数字字符，ai进队，若ai是小写字母，将队首元素出队；
若是其他字符，表示输入结束。最后显示队列中的字符。
要求用循环数组实现队列，其中队列数组大小为8。
 */
#include <stdio.h>
#define MAXSIZE 8
//定义存贮结构 
typedef int Elemtype;
typedef struct{//队列 
	Elemtype elem[MAXSIZE];
	int head;
	int back;
}Queue;

void Start_Queue(Queue *Q){//初始化一个队列 
	Q->head=0;
	Q->back=0;
}

int In_Queue(Queue *Q,int x){//若队未满，进队元素排在队尾,队尾如果超出elem[7]，队尾自动指向elem[0] 
 int i;
 if((Q->back+1)%MAXSIZE==Q->head) {
 	printf("队满,程序终止");
 	return 0;
 } 
 Q->elem[Q->back]=x;
 Q->back=((Q->back)+1)%MAXSIZE;
 return 1;
 }	

int Out_Queue(Queue *Q,int *y,int *temp){//队首元素出队,出队的元素用y记录 
	
	if(Q->back==Q->head){//如果队已空
		if (*temp == 0) { 
            printf("队列已空\n");
            *temp = 1; 
	}
	return 0;
}
	else{//如果队没有空
		*y=Q->elem[Q->head];
		Q->head = (Q->head + 1) % MAXSIZE;
		return 1;
	}
	 
}

int Print_Queue(Queue *Q){//打印队列元素
int i;
if(Q->back==Q->head){
	printf("队列是空");return 0;
}
i=Q->head;
while (i != Q->back) { 
        printf("%d ", Q->elem[i]);
        i = (i + 1) % MAXSIZE;
    }
    printf("\n");
return 1;
}

int judge(char str1){//判断输入的是数字/小写字母/其他字符 
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
	printf("循环队列数组大小为8，为了区分队满和队空，牺牲一格内存空间，最终该数组一次可最多临时插入7个数字，否则提示队满，终止程序\n请输入字符串：");
	char str[100];
	char str1;
	int flag=1;
	int temp=0;
	int i=0;
	int j=0;
	Queue queue;
	Start_Queue(&queue);
	while(scanf("%c",&str1)&&str1!='\n'){//用户输入字符串 
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
