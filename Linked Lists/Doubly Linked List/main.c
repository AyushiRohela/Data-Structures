#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node* createNode()
{
	struct node* temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter data\n");
	scanf("%d",&temp->data);
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

void insertHead(struct node **h)
{
	struct node* temp = createNode();
	if(*h == NULL)
	{
		*h = temp;
	}
	else{
		(*h)->prev = temp;
		temp->next = (*h);
		(*h) = temp;
	}

}

void insertEnd(struct node **h)
{
	struct node* temp = createNode();
	struct node* t = *h;
	t = *h;
	if(*h == NULL){
		*h = temp;
		return;
	}
	while(t->next != NULL)
	{
		t = t->next;
	}
	t->next = temp;
	temp->prev = t;

}

void insertAfter(struct node **h, int n)
{
    struct node* temp = createNode();
	struct node *t = *h;

	if(n == 0)
	{
		temp->next = *h;
		(*h)->prev = temp;
		(*h) = temp;
		return;
	}
	if(n == 1)
    {
        temp->prev = t;
        temp->next = t->next;
        t->next->prev = temp;
        t->next = temp;
        return;
    }
	while(n>1)
	{
		t = t->next;
		n--;
	}
	if(t->next != NULL)
    {
        temp->prev = t;
        temp->next = t->next;
        t->next->prev = temp;
        t->next = temp;
    }
	else{
        t->next = temp;
        temp->prev = t;
	}
}

void insertBefore(struct node **h, int n)
{
    struct node *temp = createNode();
    struct node *t = *h;
    if(n == 0)
	{
		printf("ERROR\n");
		return;
	}
	if(n == 1)
    {
        temp->next = *h;
		(*h)->prev = temp;
		(*h) = temp;
        return;
    }
	while(n>1)
	{
		t = t->next;
		n--;
	}
        temp->next = t;
        temp->prev = t->prev;
        t->prev->next = temp;
        t->prev = temp;
}

void delete(struct node **h, int n)
{
    if(*h == NULL)
    {
        printf("List already empty\n");
        return;
    }
    struct node *t = *h;
    if( n == 1 )
    {
        if((*h)->next == NULL)
        {
            *h = NULL;
            free(t);
            return;
        }
        *h = t->next;
        (*h)->prev = NULL;
        t->next = NULL;
        free(t);
        return;
    }
    n--;
    while(n>0 && t != NULL)
    {
        t= t->next;
        n--;
    }
    if(t == NULL)
    {
        printf("Insufficient number of nodes\n");
        return;
    }
    if(t->next == NULL)
    {
        t->prev->next = NULL;
        t->prev = NULL;
        free(t);
        return;
    }
    t->next->prev = t->prev;
    t->next->prev->next = t->next;
    t->next = NULL;
    t->prev = NULL;
    free(t);
}

void printList(struct node *h)
{
	struct node *t = h;
	if(h == NULL)
		printf("Empty List");
	else{
		while(t != NULL)
		{
			printf("%d ",t->data);
			t = t->next;
		}
	}
	printf("\n");
}

int main()
{
	struct node *head = NULL;
	struct node *h1, *h2, *h;
	int ch,k=1,n;
	do
	{
		printf("Choose options:\n");
		printf("0 to exit\n1 for insertion at head\n2 for insertion at the end\n3 for insertion after a given node\n4 for insertion after a before node\n5 for deletion\n6 for displaying list\n");
		scanf("%d",&ch);
		switch(ch){
			case 0:
				break;
			case 1:
				insertHead(&head);
				break;
			case 2:
				insertEnd(&head);
				break;
			case 3:
				printf("Enter position after which the node is to be inserted : ");
				scanf("%d",&n);
				insertAfter(&head, n);
				break;
            case 4:
                printf("Enter position before which the node is to be inserted : ");
                scanf("%d",&n);
                insertBefore(&head, n);
                break;
			case 5:
			    printf("Enter position at which the node is to be deleted\n");
                scanf("%d",&n);
                delete(&head,n);
                break;
            case 6:
                printList(head);
            	break;
            default:
            	printf("Invalid choice\n");
            	break;
		}
		printf("Press 1 to continue or 0 to exit\n");
		scanf("%d",&k);
	} while(k ==1);

	return 0;
}
