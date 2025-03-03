#include<stdio.h>
#include<stdlib.h>
struct ListNode {
         int val;
         struct ListNode *next;
     };
struct ListNode *head=NULL;
struct ListNode* rotateRight(struct ListNode* head, int k) {
        if(head == NULL)
                return head;
            int c=1;
            struct ListNode *m1=head;
        while(m1->next != NULL)
                {
                    c++;
                    m1=m1->next;
                }
        for(int i=k%c;i>0;i--)
        {
            if(head->next != NULL)
            {
                m1=head;
                while(m1->next->next != NULL)
                {
                    m1=m1->next;
                }
                m1->next->next=head;
                head=m1->next;
                m1->next=NULL;
            }
            else{
                return head;
            }
        }
        return head;
    }
int main()
{
    int k,n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        struct ListNode *new_node=(struct ListNode*)malloc(sizeof(struct ListNode));
        printf("Enter the value of node %d: ",i+1);
        scanf("%d",&new_node->val);
        new_node->next=NULL;
        if(head==NULL)
            head=new_node;
        else
        {
            struct ListNode *last=head;
            while(last->next!=NULL)
                last=last->next;
            last->next=new_node;
        }
    }
    printf("Enter the number of positions to rotate: ");
    scanf("%d",&k);
    head=rotateRight(head,k);
    printf("Rotated Linked List: ");    
    struct ListNode *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->val);
        temp=temp->next;
    }
    printf("\n");
    return 0;
}