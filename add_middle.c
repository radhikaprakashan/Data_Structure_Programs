#include<stdio.h>
#include<stdlib.h>

typedef struct sll
{
    int roll_num;
    char name[20];
    struct sll *next;
}SLL;

void add_middle(SLL**);
void print(SLL*);

main()
{
    SLL *hp=0;
    char ch;
    do
    {
        add_middle(&hp);
        printf("If we want to add another node\n");
        scanf(" %c", &ch);
    }while(ch=='y' || ch=='Y');
    print(hp);
}
void add_middle(SLL **p)
{
    SLL *temp,*temp1;
    temp=(SLL*)malloc(sizeof(SLL));

    printf("Enter the rollnum\n");
    scanf("%d",&temp->roll_num);

    printf("Enter the name\n");
    scanf("%s",temp->name);
    if(*p==0 || (*p)->roll_num>temp->roll_num)
    {
        temp->next=*p;
        *p=temp;
    }
    else
    {
        temp1=*p;
        while(temp1)
        {
            if(temp1->next==0 || (temp1->next->roll_num)>((temp->roll_num)));
            {
                temp->next=temp1->next;
                temp1->next=temp;
                break;
            }
            temp1=temp1->next;
        }

    }
}
void print(SLL *ptr)
{
    if(ptr==0)
    {
        printf("No node present\n");
    }
    else
    {
        while(ptr)
        {
            printf("%d %s\n", ptr->roll_num,ptr->name);
            ptr=ptr->next;
        }
    }
}

