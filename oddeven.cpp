#include<stdio.h>
int main(){
	int n,arr[100];
	int en=0,on=0,count=0;
	printf("Enter the number of elements :- ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("Enter the elements:- ");
		scanf("%d",&arr[i]);
	}
	printf("\nEven Numbers:- ");
	for(int i=0;i<n;i++){
		if(arr[i]%2==0){
			printf("%d",arr[i]);
		}
	}
	printf("\nOdd Numbers:- ");
	for(int i=0;i<n;i++){
		if(arr[i]%2!=0){
			printf("%d",arr[i]);
		}
	}
}

