#include <stdio.h>
#include <stdlib.h>
#include<time.h>
struct student{

char name[50];
int ID;
int db[3];
int score;
};
struct student a[];
int x,y,pos;
int N;
struct student *ptr,*first;



void input_data(){
    printf("To input student data from keyboard press 1 ");
    printf("\nTo create many students with random data press 0\n ");
    scanf("%d",&x);
    printf("\nEnter the number of students: ");
    scanf("%d",&N);
    ptr=(struct student*)calloc(N,sizeof(struct student));
    first=ptr;
    if(x==1){
        for (int i=0;i<N;i++){
            printf("Enter the student name:");
            getchar();
            scanf("%50[^\n]s",ptr->name);
            getchar();
            printf("\nEnter the ID of student:");
            scanf("%d",&ptr->ID);
            printf("\nEnter the student score:");
            scanf("%d",&ptr->score);
            printf("\nEnter the student date of birth(day/month/year):");
            scanf("%d%d%d",&ptr->db[0],&ptr->db[1],&ptr->db[2]);
            ptr++;
                            }
            }

    else {
        struct student s;
    for (int i=0;i<N;i++){
        *ptr=s;
         ptr++;
                         }
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


void insert_head(){
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
N++;
first=(struct student*)realloc(first,N*sizeof(struct student));
for(int i=N;i>0;i--)
        *(first+i)=*(first+i-1);
*first=s;
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
        N++;
first=(struct student*)realloc(first,N*sizeof(struct student));
for(int i=N;i>0;i--){
        if (i==pos)
        break;
        *(first+i)=*(first+i-1);

}
*(first+pos)=s;
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
        N++;
first=(struct student*)realloc(first,N*sizeof(struct student));
*(first+N-1)=s;

}



void disp(struct student *p){
    for(int i=0;i<N;i++){
    printf("\nID is %d\n",p->ID);
    printf("score is %d\n",p->score);
    printf("name is %s\n",p->name);
    printf("DB is %d %d %d\n",p->db[0],p->db[1],p->db[2]);
    p++;
}
}
int main()
{
printf("********WELCOME********\n");
input_data();
disp(first);


    return 0;
}
