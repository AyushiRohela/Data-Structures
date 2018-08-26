#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *link;
};
struct node* createNode(){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter value\n");
	scanf("%d",&temp->data);
	temp->link = NULL;
	return temp;
}
void insertHead(struct node **head){
    struct node *temp = createNode();
	if(*head == NULL){
		*head = temp;
	}
	else{
		temp->link = *head;
		*head = temp;
	}
}
void insertEnd(struct node **head){
	struct node *temp = createNode();
	struct node *t;
    t = *head;
	if(*head == NULL){
		*head = temp;
	}
	else{
		while(t->link!=NULL)
		{
			t = t->link;
		}
		t->link = temp;
	}
}
void insertAfter(struct node **head,int n){
    struct node *temp = createNode();
    struct node *t;
		t = *head;
	if(n == 1){
        temp->link = t->link;
        t->link = temp;
	}
	else{
		while(n>1)
		{
			t = t->link;
			n--;
		}
		temp->link = t->link;
		t->link = temp;
	}

}
void deleteNode(struct node **head, int n){
	struct node *t, *next;
	t = *head;
	if(*head == NULL)
		printf("List is already empty");
	else{
		if(n-1 == 0)
		{
			*head = t->link;
			free(t);
		}
		else{
			while(n-1>1 && t!=NULL)
			{
				t=t->link;
				n--;
			}
			if(t == NULL || t->link == NULL)
				printf("Available nodes less than the position entered\n");
			else{
					next = t->link->link;
					free(t->link);
					t->link = next;
			}
		}
	}
}
int length(struct node *h)
{
	int c=0;
	while(h!=NULL)
	{
		c++;
		h=h->link;
	}
	return c;
}
int middle(struct node *h)
{
	struct node *f= h;
	struct node *s= h;
	if(h!=NULL)
	{
		while(f!=NULL && f->link != NULL)
		{
			f = f->link->link;
			s = s->link;
		}
	}
	return s->data;
}
void fromStart(struct node **h, int n)
{
	struct node *t = *h;
	int c=1;
	while(c<n && t!=NULL)
	{
		t = t->link;
		c++;
	}
	if(t == NULL)
		printf("Insufficient nodes in the list\n");
	printf("Nth node from start is %d\n",t->data);
}
void fromEnd(struct node **h, int l, int n)
{
	struct node *t = *h;
	if(l<n)
	{
		printf("Insufficient nodes in the list\n");
	}
	else{
		for(int i=1;i< l-n+1;i++)
		{
			t = t->link;
		}
		printf("Nth node from the end is %d\n",t->data);
	}
}
void reverse(struct node **h)
{
    struct node *prev, *next, *curr;
    prev= NULL;
    next= NULL;
    curr= *h;
    while(curr!=NULL)
    {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    *h = prev;
}
void swap(struct node **h,int n1, int n2)
{
    if(n1 == n2)
        return;
	struct node *p1,*c1,*p2,*c2,*t;
	c1 = *h;
	c2 = *h;
	p1 = p2 = NULL;
	while(c1 != NULL && c1->data!= n1)
	{
		p1 = c1;
		c1 = c1->link;
	}
	while(c2 != NULL && c2->data!= n2)
	{
		p2 = c2;
		c2 = c2->link;
	}
	if(c1== NULL || c2 == NULL)
	{
	    printf("Element does not exist\n");
        return;
	}

	t = c2->link;
	c2->link = c1->link;
	c1->link = t;
	if(p1 == NULL)
	{
		*h = c2;
		p2->link = c1;
	}
	if(p2 == NULL)
	{
		*h = c1;
		p1->link = c2;
	}
	if (p1 != NULL && p2 != NULL)
	{
		p1->link = c2;
		p2->link = c1;
	}

}
void merge()
{
    int k=1;
    struct node *h1 = NULL;
    struct node *h2 = NULL;
    struct node *h3 = (struct node*)malloc(sizeof(struct node));
    h3->data = -1;
    h3->link = NULL;
    printf("Enter elements of 1st list in sorted order\n");
    while(k==1)
    {
        insertEnd(&h1);
        printf("Enter 1 to continue adding or 0 to stop\n");
        scanf("%d",&k);
    }
    k=1;
    printf("Enter elements of 2nd list in sorted order\n");
    while(k==1)
    {
        insertEnd(&h2);
        printf("Enter 1 to continue adding or 0 to stop\n");
        scanf("%d",&k);
    }
    struct node *t = h3;
    while(h1!=NULL && h2!=NULL)
    {if((h1 != NULL || h2!= NULL) && (h1->data <= h2->data))
    {
        t->link = h1;
        h1 = h1->link;
        t->link->link = NULL;
        t = t->link;
    }
    else
    {
        if(h2!= NULL || h1!=NULL)
        {
            t->link = h2;
            h2 = h2->link;
            t->link->link = NULL;
            t = t->link;
        }
    }
    if(h1 == NULL)
    {
        t->link = h2;
    }
    else{
        t->link = h1;
    }}
    h3 = h3->link;
    printList(h3);
}
void rotate(struct node **h,int k)
{
	struct node *t= *h;
	struct node *p= *h;
	while(t->link!=NULL)
	{
		t = t->link;
	}
	t->link = *h;
	while(k>1)
	{
		p = p->link;
		t = t->link;
		k--;
	}
	*h = p;
	t->link = NULL;

}
void printList(struct node *t){
	while(t!=NULL)
	{
		printf("%d ",t->data);
		t=t->link;
	}
	printf("\n");
}
int main()
{
	int ch, n3=1,l,n1,n2,m,n;
	struct node *head = NULL;
	do{
		printf("Press 1 for insertion at the start\nPress 2 for insertion at the end\nPress 3 for insertion after a given node\nPress 4 for deletion\nPress 5 to print\nPress 6 to find length\nPress 7 to print middle element\nPress 8 for nth element from the start\nPress 9 to find the element from the end\nPress 10 for reverse\nPress 11 for swap\nPress 12 for merging\nPress 13 for rotation\nPress 0 to exit\n");
		scanf("%d", &ch);
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
			printf("Enter Position after which the node is to be inserted\n");
			scanf("%d",&n1);
			insertAfter(&head,n1);
			break;
			case 4:
			printf("Enter position at which the node is to be deleted\n");
			scanf("%d",&n2);
			deleteNode(&head,n2);
			break;
			case 5:
            printList(head);
            break;
            case 6:
            l = length(head);
            printf("Length is %d\n",l);
            break;
            case 7:
            m = middle(head);
            printf("Middle element is %d\n",m);
            break;
            case 8:
            printf("Enter nth position from the start\n");
            scanf("%d",&n);
            fromStart(&head,n);
            break;
            case 9:
            printf("Enter nth position from the end\n");
            scanf("%d",&n);
            l = length(head);
            fromEnd(&head,l,n);
            break;
            case 10:
            reverse(&head);
            break;
            case 11:
            printf("Enter data to be swapped\n");
            scanf("%d",&n1);
            scanf("%d",&n2);
            swap(&head,n1,n2);
            break;
            case 12:
            merge();
            break;
            case 13:
            printf("Enter k\n");
            scanf("%d",&n1);
            rotate(&head,n1);
            break;
			default:
			printf("Invalid choice\n");
			break;
		}
		printf("Press 1 to continue or 0 to exit\n");
		scanf("%d",&n3);

	}while(n3 == 1);
	return 0;
}
