#include <stdio.h>
#include <stdlib.h>
typedef  int  ElemType;
typedef struct node{
	ElemType data;
	struct node *next;
}Node;

//�������� 
Node *Create_LinkedList();
void Insert_Node(Node *,int);
void Print_LinkedList(Node *);
void Sort_LinkedList(Node *);
void Backword_LinkedList(Node *,int,int);


int main()
{
char ch[100];//���������û�������ַ��� ch
char ch1;//�û�ʵʱ�����ַ� 
int i=0;
int j=0;
int left;
	int right;
while(scanf("%c",&ch1)){
	if(ch1=='\n') break;//�û������ַ���ch
	else ch[i++]=ch1;
}
ch[i]='\0';//ch������ 
Node *head = Create_LinkedList();//��������ͷ���Ŀձ� 
for (j=0;j<i;j+=2) {
        int value;
        if (j+1<i) {
            value = (ch[j]-'0')*10+(ch[j+1]-'0');
        } 
		else{
            value=ch[j]-'0';
        }
        Insert_Node(head, value);//��������
    }
    Print_LinkedList(head);
    Sort_LinkedList(head);
    Print_LinkedList(head);
    printf("����left,right:\n");
    scanf("%d,%d",&left,&right);
    Backword_LinkedList(head,left,right);
    Print_LinkedList(head);

}

Node *Create_LinkedList(){
	Node *head=(Node *)malloc(sizeof(Node));
    head->next=NULL;
    return head;
}
	
void Insert_Node(Node *head,int value){//��̬��������ڵ㵽��β 
	
	Node * newNode=(Node *)malloc(sizeof(Node));
	newNode->data=value;
	newNode->next=NULL;
	Node *p=head;
	while(p->next!=NULL){
        p=p->next;
    }
	p->next=newNode;
	}
void Inserthead_Node(Node *head,int value){//��̬��������ڵ㵽��ͷ 
	
	Node * newNode=(Node *)malloc(sizeof(Node));
	newNode->data=value;
	newNode->next=NULL;
	Node *p=head;
newNode->next=p->next;
	p->next=newNode;
	}
void Print_LinkedList(Node *head) {
    Node *p=head->next;//����ͷ�ڵ�
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
    if (!head||left>=right) return;//�߽���

    Node *dummy=Create_LinkedList();//�ڱ��ڵ�
    dummy->next=head->next;

    Node *prev=dummy; //��λ�������ǰһ�����
    for (int i=1;i<left;i++) {
        if(!prev->next) return; //Խ����
        prev=prev->next;
    }

    Node *curr=prev->next; //����ĵ�һ�����
    Node *end=curr;
    for(int i=left;i<right;i++) { //λ����������һ�����
        if(!end->next) return; //Խ����
        end=end->next;
    }

    Node *after=end->next; //��¼�����������
    end->next=NULL;        //��ʱ�Ͽ�����

    //��ת����
    Node *prevNode=NULL, *currNode=curr;
    while(currNode){
        Node *nextNode=currNode->next;
        currNode->next=prevNode;
        prevNode=currNode;
        currNode=nextNode;
    }

    //ƴ�ӷ�ת�������
    prev->next=prevNode;
    curr->next=after;

    head->next=dummy->next;
    free(dummy);
}

