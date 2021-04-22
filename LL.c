#include <stdio.h>
#include <stdlib.h>
#include<time.h>
struct student{

char name[50];
int ID;
int db[3];
int score;
};
int x;
int pos;
int N;
struct student a[];
char y;
struct Node{
struct student data;
struct Node* next;
};

struct Node *head=NULL;
struct Node *tail=NULL;


void input_data(){
    printf("To input student data from keyboard press 1 ");
    printf("\nTo create many students with random data press 0\n ");
    scanf("%d",&x);
    printf("\nEnter the number of students: ");
    scanf("%d",&N);
    if(x==1){
    for (int i=0;i<N;i++){
        printf("Enter the student name:");
        getchar();
        scanf("%50[^\n]s",a[i].name);
        getchar();
        printf("\nEnter the ID of student:",i+1);
        scanf("%d",&a[i].ID);
        printf("\nEnter the student score:");
        scanf("%d",&a[i].score);
        printf("\nEnter the student date of birth(day/month/year):");
        scanf("%d%d%d",&a[i].db[0],&a[i].db[1],&a[i].db[2]);
    }
    }
    else return;
}

void create (){
    int i;
    struct Node *t;
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=a[0];
    head->next=NULL;
    tail=head;
    for(i=1;i<N;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=a[i];
        t->next=NULL;
        tail->next=t;
        tail=t;
    }
printf("To insert a student at the first position press 0\n");
printf("To insert a student at the last position press 1 \n");
printf("To insert a student at any index position press 2 \n");
getchar();
scanf("%c",&y);
if (y=='0')
    insert_head();
else if (y=='1')
    insert_last();
else if(y=='2')
    insert();

}


void insert_head()
{
        struct student s;
        printf("Enter the student name:");
        getchar();
        scanf("%50[^\n]s",s.name);
        getchar();
        printf("\nEnter the ID of student:");
        scanf("%d",&s.ID);
        printf("\nEnter the student score:");
        scanf("%d",&s.score);
        printf("\nEnter the student date of birth(day/month/year):");
        scanf("%d%d%d",&s.db[0],&s.db[1],&s.db[2]);
        struct Node *t;

    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=s;
    t->next=head;
    head=t;
    }


   void insert(){
    printf("Enter position of insertion: ");
    scanf("%d",&pos);
        struct student s;
        printf("Enter the student name:");
        getchar();
        scanf("%50[^\n]s",s.name);
        getchar();
        printf("\nEnter the ID of student:");
        scanf("%d",&s.ID);
        printf("\nEnter the student score:");
        scanf("%d",&s.score);
        printf("\nEnter the student date of birth(day/month/year):");
        scanf("%d%d%d",&s.db[0],&s.db[1],&s.db[2]);
        clock_t start,end;
   start= clock();
   struct Node *t,*p;
    p=head;
    for(int i=0;i<pos-1;i++)
        p=p->next;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=s;
    t->next=p->next;
    p->next=t;
   end= clock() ;
   double time_taken = ((double)(end-start))/CLOCKS_PER_SEC; // calculate the elapsed time
   printf("The program took %f seconds to execute\n", time_taken);
    }




void insert_last(){
        struct student s;
        printf("Enter the student name:");
        getchar();
        scanf("%50[^\n]s",s.name);
        getchar();
        printf("\nEnter the ID of student:");
        scanf("%d",&s.ID);
        printf("\nEnter the student score:");
        scanf("%d",&s.score);
        printf("\nEnter the student date of birth(day/month/year):");
        scanf("%d%d%d",&s.db[0],&s.db[1],&s.db[2]);
        struct Node *t;
        t=(struct Node*)malloc(sizeof(struct Node));
    t->data=s;
    t->next=NULL;
    tail->next=t;
    tail=t;

}

int count(struct Node *p){
    int i=0;
    while (p!=NULL){
    i=i+1;
    p=p->next;
    }
    return i;
}

void insert_mid(struct student student_data){
    struct Node *t,*p;
    p=head;
    for(int i=0;i<(count(head)/2)-1;i++)
        p=p->next;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=student_data;
    t->next=p->next;
    p->next=t;

}

void Display_LL(struct Node *p){
while (p!=NULL){
    printf("\nID is %d\n",p->data.ID);
    printf("score is %d\n",p->data.score);
    printf("name is %s\n",p->data.name);
    printf("DB is %d %d %d\n",p->data.db[0],p->data.db[1],p->data.db[2]);
    p=p->next;

}
}
int main(){
printf("***WELCOME***\n");
input_data();
create();
Display_LL(head);
return 0;
}
