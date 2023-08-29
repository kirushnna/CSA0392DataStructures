#include<stdio.h>
int main(){
	int ind=-1,found=0;
	int n,p,x;
	int p1,s,d;
	int n1,arr[100];
	printf("Enter the number of number of elements:- ");
	scanf("%d",&n1);
	for(int i=0;i<n1;i++){
		printf("Enter the element:- ");
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<n1;i++){
		printf("%d",arr[i]);
	}
	printf("\n");
	printf("1.INSERTION");
	printf("\n2.DELETION");
	printf("\n3.SEARCH");
	printf("\n4.DISPLAY");
	printf("\nEnter the choice:- ");
	scanf("%d",&n);
	if(n==1){
		printf("Enter the position to insert:- ");
		scanf("%d",&p);
		printf("Enter new element:- ");
		scanf("%d",&x);
		for(int i=n1;i>p;i--){
			arr[i]=arr[i-1];
		}
		arr[p]=x;
		n1++;
		printf("Array after insertion: ");
		for(int i=0;i<n1;i++){
			printf("%d",arr[i]);
		}
		printf("\n");
	}
	else if(n==2){
		printf("Enter the poisition to delete:- ");
		scanf("%d",&p1);
		for(int i=p1;i<n1-1;i++){
			arr[i]=arr[i+1];
		}
		n1--;
		printf("Array after deletion: ");
		for(int i=0;i<n1;i++){
			printf("%d",arr[i]);
		}
		printf("\n");
	}
	else if(n==3){
		printf("Enter the element to search:- ");
		scanf("%d",&s);
		for(int i=0;i<n1;i++){
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
	else if(n==4){
		printf("Enter the element index to display:- ");
		scanf("%d",&d);
		printf("Element displayed:- %d",arr[d]);
	}
	else{
		printf("INVALID CHOICE");
	}
}

