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
