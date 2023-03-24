#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int main(void) {
	int m,n,**mas,i,i1,*povtor,*povtorr,k=0,i2,d,count,countn=0,mi;
	printf("Введите размерность массива: ");
	scanf("%d %d",&m,&n);
	mi=m;
	povtor=(int*)malloc((n/2)*sizeof(int));
	povtorr=(int*)malloc((n/2)*sizeof(int));
	mas=(int**)malloc(n*sizeof(int*));
	for (i=0;i<n;i++){
		mas[i]=(int*)malloc(m*sizeof(int));
	}
	for (i=0;i<m;i++){
		for (i1=0;i1<n;i1++){
			scanf("%d ",&mas[i][i1]);
		}
	}
	for (i1=0;i1<(n/2);i1++){
		povtor[i1]=0;
	}
	for (i=0;i<n-1;i++){
		for(i1=i+1;i1<n;i1++){
			if(mas[0][i]==mas[0][i1]&&mas[0][i]!=povtor[k-1]){
				povtor[k]=mas[0][i];
				povtorr[k]=mas[0][i];
				k+=1;
				break;
			}
		}
	}
	for (i=0;i<n/2;i++){
		for (i1=i+1;i1<n/2;i1++){
			if (povtor[i]==povtor[i1]){
				povtor[i1]=0;
			}
		}
	}
	for (i=0;i<n/2;i++){
		if (povtor[i]!=0){
			countn+=1;
		}
	}
	for (i=1;i<m;i++) {
		count=0;
		for (i1=0;i1<n;i1++) {
			for (k=0;k<(n/2);k++){
				if (mas[i][i1]==povtorr[k]){
					povtorr[k]=0;
					count+=1;
					break;
				}
			}
		}
		for (k=0;k<(n/2);k++){
			povtorr[k]=povtor[k];
		}
		if (count==countn){
			for(i2=i;i2<m-1;i2++){
				for (i1=0;i1<n;i1++){
			 		mas[i2][i1]=mas[i2+1][i1];
				}
			}
			i-=1;
			m-=1;
		}
	}
	if(m!=mi){
		for (i=0;i<m;i++){
			printf("\n");
			for (i1=0;i1<n;i1++){
				printf("%d ",mas[i][i1]);
			}
		}
	}
	else{
		printf("Нет");
	}
	return 0;
}
