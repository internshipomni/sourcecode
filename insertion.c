#include<stdio.h>
void main()
{
    int a[10],n,i,key,pos;
    printf("Enter size of the array: ");
    scanf("%d",&n);
    printf("Enter array elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the element u want to insert: ");
    scanf("%d",&key);
    printf("Enter position: ");
    scanf("%d",&pos);
    n++;
    for(i=n;i>=pos;i--)
        a[i] = a[i-1];
    a[pos-1] = key;
    printf("New array = ");
    for (i=0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    
}