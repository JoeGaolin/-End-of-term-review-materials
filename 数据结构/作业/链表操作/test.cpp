#include <iostream>
#include <stdlib.h>
using namespace std;

struct node{
    long int a,b;
    struct node *next;
};

struct node *chengfa(struct node *head1,struct node *head2)
{
    int temp;
    struct node *ptr=NULL,*head=NULL,*tail=NULL,*ptr1=NULL,*ptr2=NULL;
    //两个链表相乘得到一个新链表
    for(ptr1=head1;ptr1!=NULL;ptr1=ptr1->next)
    {
        for(ptr2=head2;ptr2!=NULL;ptr2=ptr2->next)
        {
            ptr=new(node);
            ptr->a=(ptr1->a)*(ptr2->a);
            ptr->b=(ptr1->b)+(ptr2->b);
            ptr->next=NULL;
            if(head==NULL) head=ptr;
            else tail->next=ptr;
            tail=ptr;
        }
    }
    for(ptr1=head)
}
struct node *creat(int n){
    int i,num,g;
    struct node *ptr=NULL,*head=NULL,*tail=NULL;
    for(i=0;i<n;i++){
        cin>>num>>g;
        ptr=(struct node *)malloc(sizeof(struct node));
        ptr->a=num;
        ptr->b=g;
        ptr->next=NULL;
        if(head==NULL) head=ptr;
        else tail->next=ptr;
        tail=ptr;
    }
    return head;
}
int main(){
    int n;
    struct node *ptr=NULL,*head=NULL,*tail=NULL,*head1=NULL,*head2=NULL;
    cin>>n;
    head1=creat(n);
    cin>>n;
    head2=creat(n);
    head=chengfa(head1,head2);
}