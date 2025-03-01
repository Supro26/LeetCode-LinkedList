#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode {
     int data;
     struct ListNode *next;
 } node;
node *start=NULL;
node *start1=NULL;
node *start2=NULL;
node *insert_end(int data,int f)
{
	node *tmp;
	tmp=(node*)malloc(sizeof(node));
	tmp->data=data;
	tmp->next=NULL;
    if(f== 1)
    {
	if(start1 == NULL)
	{
		start1=tmp;
		printf("Inserting %d at the end.....\n",tmp->data);
	}
	else{
		node *m;
		m=start1;
		while(m->next != NULL)
		{
			m=m->next;
		}
		m->next=tmp;
		printf("Inserting %d at the end.....\n",tmp->data);
	}
    return start1;
    }
    else{
        if(start2 == NULL)
	{
		start2=tmp;
		printf("Inserting %d at the end.....\n",tmp->data);
	}
	else{
		node *m;
		m=start2;
		while(m->next != NULL)
		{
			m=m->next;
		}
		m->next=tmp;
		printf("Inserting %d at the end.....\n",tmp->data);
	}
    return start2;
    }
}
node *mergeTwoLists(struct ListNode* start1, struct ListNode* start2) {
    node *newstart=NULL;
    node *curr1=start1;
    node *prev1=NULL;
    node *curr2=start2;
    node *prev2=NULL;
	if(start1 == NULL)
				return start2;
	else if(start2 ==NULL)
                return start1;
    while(curr2 != NULL && curr1 != NULL)
        {
            if(curr1->data < curr2->data)
            {
				if(newstart == NULL)    newstart=start1;
                prev1=curr1;
                curr1=curr1->next;
				// if(curr1->data < curr2->data)	continue;
				if(prev2 != NULL)
				{
                prev2->next=prev1;
                prev1->next=curr2;
                prev2=prev1;
				}
				else{
					prev1->next=curr2;
					prev2=prev1;
				}
            }
            else if(curr1->data >= curr2->data && curr2->next == NULL)
            {
                curr2->next=curr1;
				if(curr2 == start2 && curr1 == start1)
					newstart=start2;
				break;
            }
            else{
                if(newstart == NULL)    newstart=start2;
                	prev2=curr2;
                	curr2=curr2->next;
            }
		}
    return newstart;
}
void display()
{
	if(start==NULL)
	{
		printf("The Link List is Empty\n");
		return;
	}
	node *tmp;
	tmp=start;
    printf("List : ");
	while(tmp != NULL)
	{
		printf("%d ",tmp->data);
		tmp=tmp->next;
	}
	printf("\n");
}
int main()
{
	int n,d,p;
	n=1;
	
	while(n>0)
	{	
        printf("Enter\n'1'=insert at 1st List\n'2'=insert at 2nd List\n'3'= merge lists\n'4'=to print\n'5'=to stop\n");
        printf("Enter choice:");	
		scanf("%d",&n);
		switch (n){
			case 1:
                printf("Enter the data:\n");
				scanf("%d",&d);
				insert_end(d,1);
				break;
			case 2:
                printf("Enter the data:\n");
				scanf("%d",&d);
				insert_end(d,2);
				break;
                case 3:
                start=mergeTwoLists(start1,start2);
                display();
                break;
			case 4:
                display();
				break;
			case 5:
				n=-999;
				break;
			default:
				printf("Invalid Input!");
			}
	}
	return 0;
}