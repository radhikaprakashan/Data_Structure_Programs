#include<stdio.h>
#include<stdlib.h>

typedef struct sll
{
    int roll_num;
    char name[20];
    struct sll *next;
}SLL;

void add_end(SLL**);
void print(SLL*);

main()
{
    SLL *hp=0;
    char ch;
    do
    {
        add_end(&hp);
        printf("If we want to add another node\n");
        scanf(" %c", &ch);
    }while(ch=='y' || ch=='Y');
    print(hp);
}

void add_end(SLL **p)
{
    SLL *new,*temp;
    new=(SLL*)malloc(sizeof(SLL));

    printf("Enter the rollnum\n");
    scanf("%d",&new->roll_num);

    printf("Enter the name\n");
    scanf("%s",new->name);
    if(*p==0)
    {
        new->next=*p;
        *p=new;
    }
    else
    {
        temp=*p;
        while(temp->next)
        {
            temp=temp->next;
        }
        temp->next=new;
        new->next=0;
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

