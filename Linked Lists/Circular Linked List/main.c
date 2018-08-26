#include <stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link ;
};

struct node* createNode()
{
	struct node *t = (struct node*)malloc(sizeof(struct node));
	printf("Enter data\n");
	scanf("%d",&t->data);
	t->link = NULL;
	return t;
}
void insertHead(struct node **l)
{
	struct node *temp = createNode();
	if((*l) == NULL)
	{
		(*l) = temp;
		(*l)->link = (*l);
	}
	else{
		temp->link = (*l)->link;
		(*l)->link = temp;
	}
}
void insertEnd(struct node **l)
{
	struct node *temp = createNode();
	temp->link = (*l)->link;
	(*l)->link = temp;
	(*l) = temp;
}
void insertAfter(struct node **l, int n)
{
	struct node *temp = createNode();
	struct node *t = *l;
	while(n>0)
	{
		t = t->link;
		n--;
	}
	temp->link = t->link;
	t->link = temp;
	if(t == (*l))
		(*l) = t->link;
}
void delete(struct node **l, int n)
{
    int f=0;
    struct node *t = *l;
    struct node *next;
    if(*l == NULL)
    {
        printf("Empty list");
        return;
    }
    while(n>1)
    {
        t = t->link;
        n--;
        f =1;
    }
    next = t->link;
    t->link = next ->link;
    if(f ==0)
        (*l)->link = next->link;
    free(next);
}
void splitList(struct node **h, struct node **h1, struct node **h2)
{
    struct node *s = *h;
    struct node *f = *h;
    if(*h == NULL)
        return;
    while((f->link != *h) && (f->link->link != *h))
    {
        s = s->link;
        f = f->link->link;
    }
    if(f->link->link == *h)
        f= f->link;
    *h1 = *h;
    if((*h)->link != *h)
        *h2 = s->link;
    f->link = s->link;
    s->link = *h;
    printf("List one: ");
    struct node *t = (*h1);
    do{
        printf("%d ",t->data);
        t = t->link;
    } while(t != (*h1));
    printf("\n");
    printf("List two: ");
    t = (*h2);
    do{
        printf("%d ",t->data);
        t = t->link;
    } while(t != (*h2));
    printf("\n");
}

void sortedInsert(struct node **l)
{
    struct node *temp = createNode();
	if((*l) == NULL)
	{
		*l = temp;
		(*l)->link = *l;
	}
	else if(temp->data <= (*l)->link->data)
	{
		temp->link = (*l)->link;
		(*l)->link = temp;
	}
	else{
		struct node *t = (*l)->link->link;
		struct node *p = (*l)->link;
		while((t->data < temp->data)&&(t != (*l)))
		{
			t = t->link;
			p = p->link;
		}
		if(t != (*l))
		{
			temp->link = p->link;
			p->link = temp;
		}
		else{
			temp->link = t->link;
			t->link = temp;
		}
		if(t == (*l))
			*l = t->link;
	}
}
void printList(struct node **l)
{
	if((*l) == NULL)
		printf("List is already empty");
	else{
		struct node *t = (*l)->link;
		do{
			printf("%d ",t->data);
			t = t->link;
		} while(t != ((*l)->link));
        printf("\n");
	}
}
int main()
{
	struct node *last = NULL;
	struct node *h1, *h2, *h;
	int ch,k=1,n;
	do
	{
		printf("Choose options:\n");
		printf("0 to exit\n1 for insertion at head\n2 for insertion at the end\n3 for insertion after a given node\n4 for deletion\n5 for displaying list\n6 for splitting the list\n7 for sorted insertion\n");
		scanf("%d",&ch);
		switch(ch){
			case 0:
				break;
			case 1:
				insertHead(&last);
				break;
			case 2:
				insertEnd(&last);
				break;
			case 3:
				printf("Enter position after which the node is to be inserted : ");
				scanf("%d",&n);
				insertAfter(&last, n);
				break;
			case 4:
			    printf("Enter position at which the node is to be deleted\n");
                scanf("%d",&n);
                delete(&last,n);
                break;
            case 5:
                printList(&last);
            	break;
            case 6:
                h = last->link;
                splitList(&h , &h1, &h2);
                break;
            case 7:
                sortedInsert(&last);
                break;
            default:
            	printf("Invalid choice");
            	break;
		}
		printf("Press 1 to continue or 0 to exit\n");
		scanf("%d",&k);
	} while(k ==1);

	return 0;
}
