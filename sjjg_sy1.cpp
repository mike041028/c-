/*****************************/
/*程序功能：合并线性表*/
/*******************************/
#include <stdio.h>
#include <stdlib.h>//使程序能调用malloc、relloc函数 
#define MAXSIZE 20//定义初始最大容量 
 typedef int ElemType; 
 typedef struct{
 	ElemType *elem; //定义指针指向的数据类型 
 	int len;//当前长度 
 	int capacity;//当前容量
 }SqList;//定义指向整型数组的指针及当前数组长度与数组容量，捆绑成 SqList数据类型 
 
 /*以下是函数声明*/
 void InitList(SqList *L); // 初始化线性表
 void CreatList(SqList *L);//创建线性表;
 void PrintList(SqList *L);//输出线性表
 ElemType GetElem(SqList *L,int i);//取出线性表中的第i个元素；
 int Locate(SqList *L,ElemType x);//定位x在线性表中的位置；
 int Insert_Sq(SqList *L,int i,ElemType x);//在线性表L中第i个元素之前插入一个新元素x；
 void UnionList(SqList *La,SqList *Lb);//将线性表Lb合并到线性表La的末尾
 
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
 /*各函数定义*/
 void InitList(SqList *L) {
 	 L->elem = (ElemType *)malloc(10 * sizeof(ElemType)); // 初始容量为 10
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
            L->capacity *= 2; // 扩容
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
  
