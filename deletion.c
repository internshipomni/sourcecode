#include<stdio.h>
void main()
{
    int a[10],n,i,pos;
    printf("Enter size of the array: ");
    scanf("%d",&n);
    printf("Enter array elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter position of elements u want to delete: ");
    scanf("%d",&pos);
    for(i=pos-1;i<n-1;i++)
        a[i] = a[i+1];
    n--;
    printf("Updated array = ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}