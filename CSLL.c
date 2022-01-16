#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node *link;
};
 
struct node *head = NULL, *x, *y, *z;
 
void create();
void display();
void ins_at_beg();
void ins_at_pos();
void del_at_beg();
void del_at_pos();
void traverse();
void search();
void sort();
void update();
void rev_traverse(struct node *p);
 
int main()
{
    int ch;
      
      
    while (1)
    {
      printf("\n\nEnter the operation to be performed\n"); 
    	printf("\n\n1.Creation \n2.Insertion at beginning \n3.Insertion at any position\n4.Deletion at beginning \n5.Deletion at any position\n6.traverse\n7.Search\n8.sort\n9.update\n10.Exit\n");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            create(); 
            display();
            break;
        case 2:
            ins_at_beg(); 
            display();
            break;
        case 3:
            ins_at_pos(); 
            display();
            break;
        case 4:
            del_at_beg(); 
            display();
            break;
        case 5:
            del_at_pos();
            display();
            break;
        case 6:
            traverse(); 
            display();
            break;
        case 7:
            search();
            break;
        case 8:
            sort();
            display();
            break;
        case 9:
            update();
            display();
            break;
        case 10:
           exit(0);
        default:
            printf("wrong args");
        }
    }
}
 

void create()
{
    int c,i;
 
    x = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter head node data:");
    scanf("%d", &x->data);
    x->link = x;
    head = x;
    printf("Enter no of terms:");
    scanf("%d", &c);
    for (i = 0 ; i < c ; i++)
    {
        y = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data:");
        scanf("%d", &y->data);
        x->link = y;
        y->link = head;
        x = y;
    }
}

void display()
{
	x = head;
	while(x->link != head)
	{
		printf("\t%d",x->data);
		x = x->link;
	}
	printf("\t%d",x->data);
}
 
void ins_at_beg()
{
    x = head;
    y = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data:");
    scanf("%d", &y->data);
    while (x->link != head)
    {
        x = x->link;
    }
    x->link = y;
    y->link = head;
    head = y;
}
 
void ins_at_pos()
{
    struct node *ptr;
    int c = 1, pos, count = 1;
 
    y = (struct node*)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("Cannot enter an element at this place");
    }
    printf("\nEnter the data:");
    scanf("%d", &y->data);
    printf("\nEnter the position to be inserted:");
    scanf("%d", &pos);
    x = head;
    ptr = head;
    while (ptr->link != head)
    {
        count++;
        ptr = ptr->link;
    }
    count++;
    if (pos > count)
    {
        printf("OUT OF BOUND");
        return;
    }
    while (c < pos)
    {
        z = x;
        x = x->link;
        c++;
    }
    y->link = x;
    z->link = y;
}
 
void del_at_beg()
{
    if (head == NULL) 
        printf("\nList is empty");
    else
    {
        x = head;
        y = head;
        while (x->link !=  head)
        {
            x = x->link;
        }
        head = y->link;
        x->link = head;
        free(y);
    }
}

void del_at_pos()
{
    if (head == NULL)
        printf("\nList is empty");
    else
    {
        int c = 1, pos;
        printf("\nEnter the position to be deleted:");
        scanf("%d", &pos);
        x = head;
        while (c < pos)
        {
            y = x;
            x = x->link;
            c++;
        }
        y->link = x->link;
        free(x);
    }
}

void traverse()
{
    if (head == NULL)
        printf("\nList is empty");
    else
    {
        x = head;
        while (x->link !=  head)
        { 
            printf("%d->", x->data);
            x = x->link;
        }
        printf("%d", x->data);
    }
}
 
void search()
{
    int search_val, count = 0, flag = 0;
    printf("\nEnter the element to search\n");
    scanf("%d", &search_val);
    if (head == NULL)
        printf("\nList is empty nothing to search");
    else
    {
        x = head;
        while (x->link !=  head)
        {
            if (x->data == search_val)
            {
                printf("\nThe element is found at %d", count);
                flag = 1;
                break;
            }
            count++;
            x = x->link;
        }
        if (x->data == search_val)
        {
            printf("Element found at postion %d", count);
        }
        if (flag == 0)
        {
            printf("\nElement not found");
        }
 
    }
}
 
void sort()
{
    struct node *ptr, *nxt;
    int temp;
 
    if (head == NULL)
    {
        printf("Empty linkedlist");
    }
    else
    {
        ptr = head;
        while (ptr->link !=  head)
        {
            nxt = ptr->link;
            while (nxt !=  head)
            {
                if (nxt !=  head)
                {
                    if (ptr->data > nxt->data)
                    {
                        temp = ptr->data;
                        ptr->data = nxt->data;
                        nxt->data = temp;
                    }
                }
                else
                {
                    break;
                }
                nxt = nxt->link;
            }
            ptr = ptr->link;
        }
    }
}
 
void update()
{
    struct node *ptr;
    int search_val;
    int replace_val;
    int flag = 0;
 
    if (head == NULL)
    {
        printf("\nEmpty list");
    }
    else
    {
        printf("Enter the value to be edited\n");
        scanf("%d", &search_val);
        fflush(stdin);
        printf("Enter the value to be replace\n");
        scanf("%d", &replace_val);
        ptr = head;
        while (ptr->link !=  head)
        {
            if (ptr->data == search_val)
            {
                ptr->data = replace_val;
                flag = 1;
                break;
            }
            ptr = ptr->link;
        }
        if (ptr->data == search_val)
        {
            ptr->data = replace_val;
            flag = 1;
        }
        if (flag == 1)
        {
            printf("\nUpdate sucessful");
        }
        else
        {
            printf("\nUpdate not successful");
        }
    }
}
 
void rev_traverse(struct node *p)
{
    int i = 0;
 
    if (head == NULL)
    {
        printf("Empty linked list");
    }
    else
    {
        if (p->link !=  head)
        {
            i = p->data;
            rev_traverse(p->link);
            printf(" %d", i);
        }
        if (p->link == head)
        {
            printf(" %d", p->data);
        }
    }
}

