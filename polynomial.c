#include<stdio.h>
#include <malloc.h>

struct Node* create(int n);
void display(struct Node*);
void sum();

struct Node
{
  int power;
  int coefficient;
  struct Node *link;
}*start,*start1=NULL,*start2=NULL,*start3=NULL,*t,*p,*h1,*h2;


int main(){
	int n1,n2;
	printf("Enter the highest power of x in first polynomial : ");
	scanf("%d",&n1);
	start1=create(n1);
	printf("Enter the highest power of x in second polynomial : ");
	scanf("%d",&n2);
	start2=create(n2);
	sum();
	printf("\nFirst Ploynomial : ");
	display(start1);
	printf("\nSecond Ploynomial : ");
	display(start2);
	printf("\nAfter addition: ");
	display(start3);

	return 0;
}

struct Node* create(int n){
	start=NULL;
	while(n>=0){
		printf("Enter the coefficient of x^%d : ",n);
		t=(struct  Node*)malloc(sizeof(struct Node));
		scanf("%d",&t->coefficient);
		t->power=n;
		t-> link=NULL;
		if(start==NULL)
		{
			start=t;
		}
		else
		{
			p=start;
			while(p->link!=NULL)
			{
				p=p->link;
			}
			p->link=t;
		}
		n--;
	}
	return start;
}

void sum(){
	h1=start1;
	h2=start2;
	while(h1!=NULL && h2!=NULL){
		t=(struct  Node*)malloc(sizeof(struct Node));
		t-> link=NULL;
		if(h1->power > h2->power){
			t->power=h1->power;
			t->coefficient=h1->coefficient;
			h1=h1->link;
		}
		else if(h1->power < h2->power){
			t->power=h2->power;
			t->coefficient=h2->coefficient;
			h2=h2->link;
		}
		else if(h1->power == h2->power){
			t->power=h1->power;
			t->coefficient=(h1->coefficient + h2->coefficient);
			h1=h1->link;
			h2=h2->link;
		}
		if(start3==NULL)
		{
			start3=t;
		}
		else
		{
			p=start3;
			while(p->link!=NULL)
			{
				p=p->link;
			}
			p->link=t;
		}
	}


}
void display(struct Node* tempHead)
{
	if(tempHead==NULL)
	{
		printf("NO display");
		return;
	}
	p=tempHead;

	while(p!=NULL)
	{
		if(p->coefficient==0){
			p=p->link;
			continue;
		}
		if(p->coefficient>0){
			printf("+");
		}
		printf("%dX^%d",p->coefficient,p->power);
		p=p->link;
	}
	printf(" = 0");
	printf("\n");
}
