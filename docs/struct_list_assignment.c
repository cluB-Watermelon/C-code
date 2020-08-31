#include <stdio.h>
#include <stdlib.h>

typedef struct atomic{
	char *name;
	char *symbol;
	float weight;
	struct atomic *next;
} atomic;

atomic *create_a_list(char n[15], char s[3], float wt)
{
	atomic *elements=malloc(sizeof(atomic));
	elements->name=n;
	elements->symbol=s;
	elements->weight=wt;
	elements->next=NULL; 
	return elements;
}

atomic *add_to_front(char n[15], char s[3], float wt, atomic *e)
{
	atomic *elements=create_a_list(n, s, wt);
	elements->next=e;
	return elements;
}

void print_list(atomic *elements, int i)
{
	printf("\nS.No \t Atomic Name \t Symbol \t Weight");
	do
	{
		printf("\n%d \t %s \t %s \t\t %f", i, elements->name, elements->symbol, elements->weight);
		i++;
		elements=elements->next;
	}while(elements!=NULL);
}

int main(void)
{
	atomic *elements;
	int no;
	printf("How many elements do you want to enter: ");
	scanf("%d", &no);
	char n[no][15], s[no][3];
	float wt[no];
	for(int i=0 ; i<no ; i++)
	{
		printf("Enter name of element %d: ", i+1);
		scanf("%s", &n[i]);
		printf("Enter symbol of element %d: ", i+1);
		scanf("%s", &s[i]);
		printf("Enter atomic weight of element %d: ", i+1);
		scanf("%f", &wt[i]);
		if(i==0)
		{
			elements=create_a_list(n[i], s[i], wt[i]);
		}
		else
		{
			elements=add_to_front(n[i], s[i], wt[i], elements);
		}
		printf("\n");
	}
	print_list(elements, 1);
}
