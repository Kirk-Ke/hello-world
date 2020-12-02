#include<stdio.h>
int main()
{
	int a[10],i;
	void paixu(int array[],int n);
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	paixu(a,10);
	for(i=0;i<10;i++)
		printf("%d",a[i]);
	return 0;
}
void paixu(int array[],int n)
{
	int i,j,min,k,t;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
			if(array[k]>array[j])
				k=j;
		t=array[k];
		array[k]=array[i];
		array[i]=t;
	}
}