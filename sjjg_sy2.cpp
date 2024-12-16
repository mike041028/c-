#include <stdio.h>
#include <stdlib.h>
typedef  int  ElemType;
typedef struct node{
	ElemType data;
	struct node *next;
}Node;

//函数声明 
Node *Create_LinkedList();
void Insert_Node(Node *,int);
void Print_LinkedList(Node *);
void Sort_LinkedList(Node *);
void Backword_LinkedList(Node *,int,int);


int main()
{
char ch[100];//定义用于用户输入的字符串 ch
char ch1;//用户实时输入字符 
int i=0;
int j=0;
int left;
	int right;
while(scanf("%c",&ch1)){
	if(ch1=='\n') break;//用户输入字符串ch
	else ch[i++]=ch1;
}
ch[i]='\0';//ch结束符 
Node *head = Create_LinkedList();//创建带有头结点的空表 
for (j=0;j<i;j+=2) {
        int value;
        if (j+1<i) {
            value = (ch[j]-'0')*10+(ch[j+1]-'0');
        } 
		else{
            value=ch[j]-'0';
        }
        Insert_Node(head, value);//插入链表
    }
    Print_LinkedList(head);
    Sort_LinkedList(head);
    Print_LinkedList(head);
    printf("输入left,right:\n");
    scanf("%d,%d",&left,&right);
    Backword_LinkedList(head,left,right);
    Print_LinkedList(head);

}

Node *Create_LinkedList(){
	Node *head=(Node *)malloc(sizeof(Node));
    head->next=NULL;
    return head;
}
	
void Insert_Node(Node *head,int value){//动态建立插入节点到表尾 
	
	Node * newNode=(Node *)malloc(sizeof(Node));
	newNode->data=value;
	newNode->next=NULL;
	Node *p=head;
	while(p->next!=NULL){
        p=p->next;
    }
	p->next=newNode;
	}
void Inserthead_Node(Node *head,int value){//动态建立插入节点到表头 
	
	Node * newNode=(Node *)malloc(sizeof(Node));
	newNode->data=value;
	newNode->next=NULL;
	Node *p=head;
newNode->next=p->next;
	p->next=newNode;
	}
void Print_LinkedList(Node *head) {
    Node *p=head->next;//跳过头节点
    while (p!=NULL) {
        printf("%d", p->data);
        if (p->next != NULL) {
            printf(",");
        }
        p = p->next;
    }
    printf("\n");
}

void Sort_LinkedList(Node *head){
	Node *singlehead = Create_LinkedList();
	Node *doublehead = Create_LinkedList();
	Node *p= head->next; 
	while(p!=NULL){
	if(p->data%2==0)
	Insert_Node(singlehead, p->data);
	else if(p->data%2==1)
	Insert_Node(doublehead, p->data);
	p=p->next;
	}	
	Node *singleTail=singlehead;
	while(singleTail->next!=NULL){
		singleTail=singleTail->next;
	}
	singleTail->next=doublehead->next;
	head->next=singlehead->next;
}
	

void Backword_LinkedList(Node *head,int left,int right) {
    if (!head||left>=right) return;//边界检查

    Node *dummy=Create_LinkedList();//哨兵节点
    dummy->next=head->next;

    Node *prev=dummy; //定位到区间的前一个结点
    for (int i=1;i<left;i++) {
        if(!prev->next) return; //越界检查
        prev=prev->next;
    }

    Node *curr=prev->next; //区间的第一个结点
    Node *end=curr;
    for(int i=left;i<right;i++) { //位到区间的最后一个结点
        if(!end->next) return; //越界检查
        end=end->next;
    }

    Node *after=end->next; //记录区间后续部分
    end->next=NULL;        //暂时断开区间

    //反转区间
    Node *prevNode=NULL, *currNode=curr;
    while(currNode){
        Node *nextNode=currNode->next;
        currNode->next=prevNode;
        prevNode=currNode;
        currNode=nextNode;
    }

    //拼接反转后的区间
    prev->next=prevNode;
    curr->next=after;

    head->next=dummy->next;
    free(dummy);
}

