//Supriya Kulkarni(sgk140430)
#include<stdlib.h>
#include<stdio.h>


void WIS_Noviolation(int a[],int w[],int size);
void WIS_Violation(int a[],int w[],int size,int allowed_errors);
void print_result_partA(int indicies[],int a[],int max_k,int size);


main()

{
int size,allowed_errors,j;
printf("Enter Input \n");
scanf("%d %d",&size,&allowed_errors);
int *a = (int*)malloc(sizeof(int)*size+1);
int *w = (int*)malloc(sizeof(int)*size+1);
for(j=1;j<=size;j++)
   {
	scanf("%d",&a[j]);
	scanf("%d",&w[j]);
    }	
a[0]=-9999;
w[0]=0;
WIS_Noviolation(a,w,size);  //function to calculate weighted increasing subsequence with no violations
WIS_Violation(a,w,size,allowed_errors); //function to calculate weighted increasing subsequence with k violations


}

void WIS_Noviolation(int a[],int w[],int size)
{

int *wis = (int*)malloc(sizeof(int)*(size+1));
int *indices=(int*)malloc(sizeof(int)*(size+1));
int i,j,k,max_k=0,max=0;
for(j=0;j<=size;j++){
indices[j]=0;
wis[j]=0;

}
	 
     for(i=1;i<=size;i++)
      {
       
	 
	 for(j=0;j<i;j++)
	{

	 if (a[i]> a[j] && wis[i]<w[i]+wis[j] )
	{

	   wis[i]=w[i]+wis[j];
	   indices[i]=j;
	   
	 }
	 }

	}
	 printf("RESULT PART A \n");
	 max=wis[0];
	 for(k=0;k<=size;k++){
	 if(wis[k] > max){
	 max=wis[k];
	 max_k=k;
	 }
	 
	 }
	
	 printf("Max weight-->%d\n",max);
         print_result_partA(indices,a,max_k,size);
         
	  
	}

void WIS_Violation(int a[],int w[],int size,int allowed_error)
{

  int max=0,l,max_i=0,max_k=0 ,i,j,k,len;
int *path_index = (int*)malloc(sizeof(int)*(size+1));
int *result_indicies=(int*)malloc(sizeof(int)*(size+1));

int **wis_k=(int **)malloc((size+1) * sizeof(int *));
int **indicies=(int **)malloc((size+1) * sizeof(int *));

for(i=0;i<=size;i++){
wis_k[i]=(int *)malloc((allowed_error+1) * sizeof(int *));
indicies[i]=(int *)malloc((allowed_error+1) * sizeof(int *));
}

for(i=0;i<=size;i++){
for(j=0;j<=allowed_error;j++){

wis_k[i][j]=0;
indicies[i][j]=0;
}

}

for(i=1;i<=allowed_error;i++){
wis_k[0][i]=-99999999;
}

for(i=1;i<=size;i++){
for(j=0;j<i;j++)
{
if(a[i]>a[j] && wis_k[i][0]<(wis_k[j][0]+w[i])){
wis_k[i][0]=wis_k[j][0]+w[i];
indicies[i][0]=j;
}
}
}


for(k=1;k<=allowed_error;k++){
for(i=1;i<=size;i++){
for(j=0;j<i;j++){
if(a[i]<= a[j] && wis_k[i][k] <(wis_k[j][k-1]+w[i] -((a[j]-a[i])*w[i]))){
wis_k[i][k]=(wis_k[j][k-1]+w[i] -((a[j]-a[i])*w[i]));
indicies[i][k]=j;
}


else if(a[i] > a[j] && wis_k[i][k]<(wis_k[j][k]+w[i])){
wis_k[i][k]=(wis_k[j][k]+w[i]);
indicies[i][k]=j;
}
}
}
}

printf("\n\n\nRESULT PART B\n");
max=wis_k[0][0];
for(i=0;i<=size;i++){
for(k=0;k<=allowed_error;k++){
if(max < wis_k[i][k]){
max=wis_k[i][k];
max_i=i;
max_k=k;
}
}
}

printf("Max Weight-->%d",max);
for(i=0;i<=size;i++){
path_index[i]=0;
result_indicies[i]=0;
}
	i=max_i;

	while(i>0)
	{
		l=indicies[i][max_k];
		path_index[i]=l;
		i=l;
		if(i==0)
			break;
	}
	len=0;
	
	for(i=0;i<=size;i++)
	{
		if(path_index[i]!=0)
		{
			
			result_indicies[len++]=path_index[i];
		}
	}
	
	result_indicies[len]=max_i;
	printf("\n");
	printf("Indicies-->");
	for(i=0;i<=size;i++)
	{
		if(result_indicies[i]!=0)
			printf("%d ",result_indicies[i]);
	}
	printf("\nElements-->");

	for(i=0;i<=size;i++)
	{
		if(result_indicies[i]!=0)
			printf("%d ",a[result_indicies[i]]);
	}
	  
}




void print_result_partA(int indicies[],int a[], int max_k ,int size)


{
int i,j=0;
int *result_indicies = (int*)malloc(sizeof(int)*(size+1));
for(i=0;i<=size;i++)
{
result_indicies[i]=0;
}
for(i=max_k;i>0;)
{
result_indicies[j]=i;
j=j+1;
i=indicies[i];
}
printf("Indicies-->");
for(i=j-1;i>=0;i--)
{
printf("%d ",result_indicies[i]);
}
printf("\nElements-->");
for(i=j-1;i>=0;i--)
{
printf("%d ",a[result_indicies[i]]);
}
}



 
