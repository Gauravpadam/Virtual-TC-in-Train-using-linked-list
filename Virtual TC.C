#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct compartment
{
    int count,checked,unchecked,fined,totalfine;
    struct compartment *next;
}compartment;

compartment *start;

//prototypes
void train(int);
void tc();
void analytics(compartment*);

int main()
{
    printf("**Virtual TC**\n");
    int val;
    printf("How many compartments does your train have?\n");
    scanf("%d",&val);
    train(val);
    printf("Got it, Sending Virtual TC In!\n");
    tc();
    return(0);
}

void train(int val)
{
    int i;
    compartment *newcompartment,*ptr;
    for (i=0;i<val;i++)
    {
        newcompartment=(compartment*)malloc(sizeof(compartment));
        newcompartment->count=10;
        newcompartment->checked=newcompartment->unchecked=newcompartment->fined=newcompartment->totalfine=0;

        if(start==NULL)
        {
            newcompartment->next=NULL;
            ptr=newcompartment;
            start=newcompartment;
        }

        else
        {
            newcompartment->next=NULL;
            ptr->next=newcompartment;
            ptr=newcompartment;
        }
    }
}

void tc()
{
    compartment *ptr=start;
    int op;
    while (ptr!=NULL)
    {
        while (ptr->checked!=ptr->count)
        {
            printf("Good afternoon Dear Passenger!, Do you have a ticket?\n1.Yes\n2.No\n");
            scanf("%d",&op);

            if (op==1)
            {
                printf("Thank you Sir, Have a nice day!\n");
                ptr->checked=(ptr->checked)+1;
            }

            else
            {
                printf("You have to pay a fine of 500 rs\n");
                printf("Press 1 to hand over 500 rs\n");
                scanf("%d",&op);
                printf("Be careful next time Sir!\n");
                ptr->checked=(ptr->checked)+1;
                ptr->fined=(ptr->fined)+1;
                ptr->totalfine=(ptr->totalfine)+500;
            }

            ptr->unchecked=(ptr->count)-(ptr->checked);

            if(ptr->checked<ptr->count)
            {
                printf("Moving to the next passenger...\n");
                Sleep(2500);
            }
        }

        printf("Compartment Analysis: ");
        analytics(ptr);

        if (ptr->next==NULL)
            printf("All compartments are done!\n");

        
        else
        {
            printf("Please wait, I'm Moving to the next compartment\n");
            printf("...\n");
            Sleep(2000);
            printf("...\n");
            Sleep(2000);
            printf("...\n");
            Sleep(2000);
        }

        ptr=ptr->next;
    }
}

void analytics (compartment* ptr)
{
    printf("\n----------------------------------\n");
    printf("No. of Passengers: %d\n",ptr->count);
    printf("No. of Passengers checked: %d\n",ptr->checked);
    printf("No. of Passengers Unchecked: %d\n",ptr->unchecked);
    printf("No. of Passengers Fined: %d\n",ptr->fined);
    printf("Total fine collected from compartment: %d\n",ptr->totalfine);
    printf("----------------------------------\n");
}