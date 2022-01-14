#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
void len();
void Display();
using namespace std;
//linked use for dynamic memory lecotaion

struct Node
{
  string name,number;
  struct Node *next;

};

struct Node *head,*newNode,*last;
void createNode(string n,string num)
{

 newNode=(struct Node*)malloc(sizeof(struct Node));
 newNode->name=n;
 newNode->number=num;
 newNode->next=0;

 if(head==NULL)
    head=last=newNode;
else
last->next=newNode;
last=newNode;


}

void menu()
{
  cout<<"enter 1 for contact"<<endl;
   cout<<"enter 2 for display all contact"<<endl;
  cout<<"enter 3 for search contact"<<endl;
   cout<<"enter 4 to delete contact "<<endl;
  cout<<"enter 5 for clear contact"<<endl;
 }



void searchName()
{
   int c,found=0;
  struct Node *p=head;
  string s;
 cout<<"enter the contact you want to search:";
 cin>>s;
  if(head==NULL)
    printf("\nno contact save");

 while( p!=NULL)
{

  if(s==p->name|| s==p->number)
    last=p;
    found=1;
  p=p->next;
  c++;
}
if(found==1){
  cout<<"name="<<last->name;
     cout<<"number="<<last->number;
     cout<<"index="<<c;
}
  else
    printf("\ncontact not found");
}


void deletePosition(int dpos)//delete at the given position
{
  struct Node *p,*q;
  p=head;

   for(int i=0;i<dpos-1;i++)
    q=p;
     p=p->next;

  p->next=p->next;

  free(p);
  printf("data deleted succefully");
 }


void clearContact()
{
 struct Node *temp;
 temp=head;
 while(head!=NULL)
 {
   head=head->next;
   free(head);
 }
  free(temp);
 printf("contact is empty now");
}

int main()
{
  string name,number;
  int s,dpos;
  while(true){
    system("clear");
    menu();
    cin>>s;

    switch(s)
    {
      case 1:
          printf("enter name ");
          cin>>name;
          printf("enter phone number");
          cin>>number;
          createNode(name,number);
          break;

      case 2:
         Display();
         break;

      case 3:
        searchName();
        break;
    case 4:
       printf("enter the position you want to delete");
       cin>>dpos;
       deletePosition(dpos);
       break;
    case 5:
       clearContact();
       break;
    default:
         printf("please enter valid input");
        break;
    }

}
    return 0;
}



void Display()
{
  int length=0;
 if(head==NULL)
   printf("display list in empty");

 else
   last=head;
   while(last!=NULL)
     {
       cout<<last->name<<endl;
       cout<<last->number<<endl;
       last=last->next;
       length++;
     }
cout<<"Total contact in the list="<<length<<endl;
}
