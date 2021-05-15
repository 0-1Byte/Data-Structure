#include <stdio.h>
#include <malloc.h>
//1单链表数据结构
typedef char elemtype;
typedef struct  lnode //节点类型
{
    elemtype data;
    struct lnode *next;
} linknode;
//2单链表的基本算法P349-52   基本算法(1)-(9)
void initlist(linknode *&l)
{
    l=(linknode *)malloc(sizeof(linknode));
    l->next=NULL;
}
void destroylist(linknode * &l)
{
    linknode *pre=l,*p=l->next;
    while(p!=NULL)
    {
        free(pre);
        pre=p;
        p=pre->next;
    }
    free(pre);
}
bool listempty(linknode *l)
{
    return(l->next==NULL);
}
int listlength(linknode *l)
{
    int n=0;
    linknode *p=l;
    while(p->next!=NULL)
    {
        n++;
        p=p->next;
    }
    return(n);
}
void displist(linknode *l)
{
    linknode *p=l->next;
    while(p!=NULL)
    {
        printf("%c ",p->data);
        p=p->next;
    }
    printf("\n");
}
bool getelem(linknode *l,int i,elemtype &e)
{
    int j=0;
    linknode *p=l;
    if(i<=0)
        return false;
    while(j<i && p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
        return false;
    else
    {
        e=p->data;
        return true;
    }
}
int locateelem(linknode *l,elemtype e)
{
    int i=1;
    linknode *p=l->next;
    while(p!=NULL && p->data!=e)
    {
        p=p->next;
        i++;
    }
    if(p==NULL)
        return(0);
    else
        return (i);
}
bool listinsert(linknode * &l,int i,elemtype e)
{
    int j=0;
    linknode *p=l,*s;
    if(i<=0)
        return false;
    while(j<i-1 && p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
        return false;
    else
    {
        s=(linknode *)malloc(sizeof(linknode));
        s->data=e;
        s->next=p->next;
        p->next=s;
        return true;
    }
}
bool listdelete(linknode * &l,int i,elemtype &e)
{
    int j=0;
    linknode *p=l,*q;
    if(i<=0)
        return false;
    while(j<i-1 && p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
        return false;
    else
    {
        q=p->next;
        if(q==NULL)
            return false;
        e=q->data;
        p->next=q->next;
        free(q);
        return true;
    }
}
void lj(linknode *l1,linknode *l2,linknode *&l3)
{
    l3=(linknode *)malloc(sizeof(linknode));
    linknode *r=l3,*p=l1->next,*s;
    while(p!=NULL)
    {
        s=(linknode *)malloc(sizeof(linknode));
        s->data=p->data;
        r->next=s;
        r=s;
    }
    p=l2->next;
    while(p!=NULL)
    {
        s=(linknode *)malloc(sizeof(linknode));
        s->data=p->data;
        r->next=s;
        r=s;
    }
    r->next=NULL;
}
//...
//3 编写主函数
int main()
{
    linknode  *h;
    elemtype e;
    int i;
    initlist(h);	//(1）初始化链表h
    listinsert(h,1,'a');	//(2)依次插入a,b,c,d,e元素
    listinsert(h,2,'b');
    listinsert(h,3,'c');
    listinsert(h,4,'d');
    listinsert(h,5,'e');
    printf("输出链表h\n");
    displist(h);//(3)输出链表h
    printf("单链表h的长度为：%d\n",listlength(h));//(4) 输出h长度
    if(listempty(h)==1)//(5)链表h是否为空
        printf("空表\n");
    else
        printf("非空表\n");
    getelem(h,3,e);
    printf("第三个元素是：%c\n",e);//（6）输出第三个元素

    i=locateelem(h,'a');//(7)输出元素a的位置
    if(i!=0)
        printf("a的位置为表中第%d个元素\n",i);
    else
        printf("a不在表中\n");
    listinsert(h,4,'f');//(8)h的第四个位置插入元素f
    printf("输出链表表h\n");
    displist(h);//(9)输出h
    listdelete(h,3,e);//(10)h的删除第三个元素
    printf("输出链表表h\n");
    displist(h);//(11)输出链表h
    char a[100];
    char b[100];
    gets(a);
    gets(b);
    linknode *l1;
    linknode *l2;
    linknode *l3;
    initlist(l1);
    initlist(l2);
    initlist(l3);
    for(int i=1; a[i]!='\0'; i++)
        listinsert(l1,i+1,a[i]);
    for(int i=1; b[i]!='\0'; i++)
        listinsert(l2,i+1,b[i]);
    lj(l1,l2,l3);
    printf("输出链表L3\n");
    displist(l3);

    destroylist(h);//(12)销毁链表表h
}
//实验习题：输入两个字符串，分别建立链表L1、L2,将L2连接到L1后得到新的链表L3，输出L3。

