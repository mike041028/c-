/*****************************/
/*�����ܣ��ϲ����Ա�*/
/*******************************/
#include <stdio.h>
#include <stdlib.h>//ʹ�����ܵ���malloc��relloc���� 
#define MAXSIZE 20//�����ʼ������� 
 typedef int ElemType; 
 typedef struct{
 	ElemType *elem; //����ָ��ָ����������� 
 	int len;//��ǰ���� 
 	int capacity;//��ǰ����
 }SqList;//����ָ�����������ָ�뼰��ǰ���鳤������������������� SqList�������� 
 
 /*�����Ǻ�������*/
 void InitList(SqList *L); // ��ʼ�����Ա�
 void CreatList(SqList *L);//�������Ա�;
 void PrintList(SqList *L);//������Ա�
 ElemType GetElem(SqList *L,int i);//ȡ�����Ա��еĵ�i��Ԫ�أ�
 int Locate(SqList *L,ElemType x);//��λx�����Ա��е�λ�ã�
 int Insert_Sq(SqList *L,int i,ElemType x);//�����Ա�L�е�i��Ԫ��֮ǰ����һ����Ԫ��x��
 void UnionList(SqList *La,SqList *Lb);//�����Ա�Lb�ϲ������Ա�La��ĩβ
 
 main(){
 	SqList la,lb;
 	InitList(&la);
    InitList(&lb);
 	printf("\n-------CreatListA---------\n");
 	CreatList(&la);
	PrintList(&la);
	printf("\n\n--------CreatListB----------\n");
    CreatList(&lb);
	PrintList(&lb);
	UnionList(&la,&lb);
	printf("\n\n---------After Union----------------\n");
	PrintList(&la);
	getchar();
 } 
 /*����������*/
 void InitList(SqList *L) {
 	 L->elem = (ElemType *)malloc(10 * sizeof(ElemType)); // ��ʼ����Ϊ 10
    if (!L->elem) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    L->len = 0;
    L->capacity = 10;
 	
 }
 void CreatList(SqList *L){
 	int x; printf("Input elements (end with -1): ");
 	while (scanf("%d", &x) && x != -1) {
        if (L->len >= L->capacity) {
            L->capacity *= 2; // ����
            L->elem = (ElemType *)realloc(L->elem, L->capacity * sizeof(ElemType));
            if (!L->elem) {
                printf("Memory reallocation failed!\n");
                exit(0);
            }
        }
        L->elem[L->len++] = x;
    }
	 }
 
 
 void PrintList(SqList *L){
 	int k;
 	printf("List have %d element:",L->len);
 	for(k=0;k<L->len;k++) printf("%5d",L->elem[k]);
 }
 
 ElemType GetElem(SqList *L,int i){
 	return (L->elem[i]);
 }
 
 int Locate(SqList *L,ElemType x){
 	int i;
 	for(i=0;i<L->len;i++)
 	{
 		if(L->elem[i]==x) return i;
	 }
	 return 0;
 }
 
 int Insert_Sq(SqList *L,int i,ElemType x)
 {
 	int j;
 	if(i<1||i>L->len+1) return 0;
 	if(L->len>=L->capacity)
 	L->capacity *= 2;
        L->elem = (ElemType *)realloc(L->elem, L->capacity * sizeof(ElemType));
        if (!L->elem) {
            printf("Memory reallocation failed!\n");
            exit(1);
        }
        for(j=L->len;j>=i;j--){
        	 L->elem[j] = L->elem[j - 1];
		}
		L->elem[i - 1] = x;
       L->len++;
       return 1;
 }
 
 void UnionList(SqList *La,SqList *Lb){
 	int blen,i,k;
 	ElemType x;
 	blen=Lb->len;
 	for(i=0;i<blen;i++){
 		x=GetElem(Lb,i);
 		k=Locate(La,x);
 		if(k==0) Insert_Sq(La,La->len+1,x);
	 }
 }
  
