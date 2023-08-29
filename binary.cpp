#include<stdio.h>
int main(){
	int n,arr[100];
	int temp,s;
	int found=0,ind=-1;
	//input of array elements
	printf("Enter the number of number of elements:- ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("Enter the element:- ");
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<n;i++){
		printf("%d",arr[i]);
	}
	//sorting of array
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	printf("\nSORTED ARRAY");
	for(int i=0;i<n;i++){
		printf("\n%d\n",arr[i]);
	}
	//binary search after sorting
	printf("Enter the element to search:- ");
	scanf("%d",&s);
	for(int i=0;i<n;i++){
		if(arr[i]==s){
			found=1;
			ind=i;
			break;
		}
	}
	if(found){
		printf("Element found:- %d",ind);
	}
	else{
		printf("Element not found");
	}
}

