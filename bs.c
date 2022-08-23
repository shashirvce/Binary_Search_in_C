#include<stdio.h>
#include<conio.h>
void input(int a[],int size);
void display(int a[],int size);
int binary_search(int a[],int item,int low,int high);
void bs_loop(int a[],int item,int low,int high);

void main()
{
    int a[20],size,item=4,low=0,high,res,ch;
    printf("\n\t\t\t\t\tBinary Search\n\n");
    system("cls");
    while(1)
    {
        printf("\n\t\t\t\t\tBinary Search\n\n");
        printf("1:Input\n2:Display\n3:Binary Search Using Recursion\n4:Binary Search Using Loop\n5:Exit\n\nEnter Your Choice:\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("Enter Size Of Array:");
            scanf("%d",&size);
            input(a,size);
            system("cls");
        }
        else if(ch==2)
        {
            display(a,size);
            getch();
            system("cls");
        }
        else if(ch==3)
        {
            printf("Enter The Number To Search:\n");
            scanf("%d",&item);
            high=size-1;
            res=binary_search(a,item,low,high);
        if(res==-1)
            printf("\nNumber Is Not Found");
        else
            printf("\nNumber found at %d index",res);
        getch();
        system("cls");
        }
        else if(ch==4)
        {
            printf("Enter The Number To Search:\n");
            scanf("%d",&item);
            high=size-1;
            bs_loop(a,item,low,high);
            getch();
            system("cls");
        }
        else
        {
            printf("\nPress 1-->EXIT\nPress 2-->Main-Menu\n");
            scanf("%d",&ch);
            if(ch==1)
                break;
            else
            {
                system("cls");
                continue;
            }
        }
    }
}
void input(int a[],int size)
{
    int i;
    printf("\nEnter Elements In Array ");
    for(i=0;i<size;i++)
    {
        printf("[%d] Index:",i);
        scanf("%d", &a[i]);
    }
}

void display(int a[],int size)
{
    int i;
    printf("\nElements In Array are:");
    for(i=0;i<size;i++)
    {
        printf("%d ",a[i]);
    }
}

int binary_search(int a[],int item,int low,int high)
{
    int mid;
    if(low>high)
        return -1;
    mid=(low+high)/2;
    if(a[mid]==item)
    {
        return mid;
    }
    else if(item<a[mid])
    {
        high=mid-1;
        return binary_search(a,item,low,high);
    }
    else
    {
        low=mid+1;
        return binary_search(a,item,low,high);
    }
}

void bs_loop(int a[],int item,int low,int high)
{
    int mid;
    while(low<=high)
    {
          mid=(low+high)/2;
          if(a[mid]==item)
          {
            printf("\nNumber found at %d index",mid);
            return;
          }
          else if(item<a[mid])
               high=mid-1;
          else
            low=mid+1;
    }
       printf("\nNumber Not found");
}
