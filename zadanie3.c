#include <stdio.h>
#include <stdlib.h>

typedef struct OWN{
	 float data;
	 struct OWN *next;
 }OWN;
 
typedef struct{
	OWN *beg;
	OWN *cur;
} LOWL;

typedef struct TWN{
	float data;
	struct TWN *prev;
	struct TWN *next;
}TWN;

typedef struct{
	TWN *cur;
}CTWL;

LOWL *lowl_create_empty(void)
{
	LOWL *Z;

	Z=(LOWL *)malloc(sizeof(LOWL));
	if(Z==NULL)
		return NULL;
	else
	{
		Z->beg=NULL;
		Z->cur=NULL;
		return Z;
	}
}

CTWL *ctwl_create_empty(void)
{
	CTWL *Z;
	Z=(CTWL *)malloc(sizeof(CTWL));
	if(Z==NULL)
		return NULL;
	
	else
	{
		Z->cur=NULL;
		return Z;
	}
}
void ctwl_cur_step_right(CTWL *list)
{
	if(list->cur == NULL)
		return;
	list->cur=list->cur->next;
	return;
}

void ctwl_cur_step_left(CTWL *list)
{
	if(list->cur == NULL)
		return;
	list->cur=list->cur->prev;
	
}	

OWN *lowl_insert_left(LOWL *list,float val)
{
	OWN *aktualny,*novy;
	aktualny=list->beg;
	
	if (list->beg==NULL)
	{
		novy=malloc(sizeof(OWN));
		if(novy==NULL)
			return NULL;
		list->beg=novy;
		list->cur=novy;
		novy->data=val;
		return novy;
	}
	
	if (list->beg==list->cur)
	{
		novy=malloc(sizeof(OWN));
		if (novy==NULL)
			return NULL;
		novy->next=list->beg;
		list->beg=novy;
		novy->data=val;
		return novy;
	}
	
	while(aktualny->next != list->cur)
		aktualny=aktualny->next;
		
	novy=malloc(sizeof(OWN));
	if (novy==NULL)
		return NULL;
	
	novy->next=list->cur;
	aktualny->next=novy;
	novy->data=val;
	return novy;
	
}

TWN *ctwl_insert_left(CTWL *list,float val)
{
	TWN *novy;
	novy=malloc(sizeof(TWN));
	
	if(novy==NULL)
		return novy;
	
	novy->data=val;
	
	if(list->cur == NULL)
	{
		list->cur=novy;
		novy->prev=novy;
		novy->next=novy;
		return novy;
	}
	
	list->cur->prev->next=novy;
	novy->prev=list->cur->prev;
	novy->next=list->cur;
	list->cur->prev=novy;
	return novy;	
	
}

TWN *ctwl_insert_right(CTWL *list,float val)
{
	TWN *novy;
	novy=malloc(sizeof(TWN));
	
	if (novy==NULL)
		return novy;
	
	novy->data=val;
	
	if (list->cur == NULL)
	{
		list->cur=novy;
		novy->next=novy;
		novy->prev=novy;
		return novy;
	}
	
	list->cur->next->prev=novy;
	novy->next=list->cur->next;
	novy->prev=list->cur;
	list->cur->next=novy;
	return novy;
	
}
	
OWN *lowl_insert_right(LOWL *list,float val)
{
	OWN *aktualny,*novy;
	aktualny=list->beg;
	
	if(list->beg==NULL)
	{
		novy=malloc(sizeof(OWN));
		if (novy==NULL)
				return NULL;
		list->beg=novy;
		list->cur=novy;
		novy->data=val;
		return novy;
	}
	
	if(list->cur->next==NULL)
	{
		novy=malloc(sizeof(OWN));
		if (novy==NULL)
			return NULL;
		
		list->cur->next=novy;
		novy->next=NULL;
		novy->data=val;
		return novy;
	}
	
	aktualny=list->cur->next;
	novy=malloc(sizeof(OWN));
	if(novy==NULL)
		return NULL;
	novy->next=aktualny;
	list->cur->next=novy;
	novy->data=val;
	return novy;
	
}

CTWL *ctwl_create_random(unsigned int size)
{
	CTWL *Z;
	float nahodne;
	unsigned int i;
	
	Z=ctwl_create_empty();
	if (Z== NULL)
		return Z;
		
	for (i=0; i<=size; i++)
	{
		nahodne= (rand()%256)/12.0;
		Z->cur=ctwl_insert_right(Z,nahodne);
	}
	
	return Z;
		
}	
		
void lowl_print(LOWL *list)
{
	OWN *aktualny;
	aktualny=list->cur;
	
	while (aktualny != NULL)
	{
		printf("data= %.3f, ",aktualny->data);
		aktualny=aktualny->next;
	}
	printf("\n");
	
}

void ctwl_print(CTWL *list)
{
	TWN *aktualny;
	
	aktualny=list->cur;
	
	do
	{
		printf("data C: %.3f \n",aktualny->data);
		aktualny=aktualny->next;
	}
	while(aktualny != list->cur->prev);
	printf("\n");
	
}	

LOWL *ctwl_to_lowl (CTWL *list)
{
	TWN *aktualny;
	LOWL *prvy;
	OWN *novy;
	
	aktualny = list->cur;
	
	if(list==NULL)
		return NULL;
	
	prvy = (LOWL *)malloc(sizeof(LOWL));
	
	if(prvy==NULL)
		return NULL;
	
	prvy->beg->data=aktualny->data;
	
	do
	{
		novy = (OWN *)malloc(sizeof(OWN));
		if(novy==NULL)
			return NULL;
		novy->data=aktualny->prev->data;
		novy->next=(OWN *)aktualny->prev->prev;
		aktualny=aktualny->prev;
	}
	while(aktualny->prev == list->cur);
	
	return prvy;	

}

int main(void)
{
	LOWL *list;
	list=lowl_create_empty();
	lowl_insert_left(list,5.345);
	lowl_insert_right(list,4.34);
	lowl_insert_left(list,8.457);
	lowl_print(list);
	printf("\n");
	CTWL *first;
	first=ctwl_create_random(6);
	ctwl_print(first);

	LOWL *C;
	C=ctwl_to_lowl(first);
	lowl_print(C);

}
