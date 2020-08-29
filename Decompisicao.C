#include<stdio.h>
#include <stdlib.h>

int soma;

int printavel(int n,int* v){
    for(int i=0;i<n-1;i++)//verifica se o vetor esta decrescente
            if(v[i]<v[i+1])
                    return 1;
    return 0;
}

void ArrumaVetor(int n,int* v){
    for(int i=n-2;i>=0;i--){//percorre o vetor de trás pra frente
			if(v[i]>v[i+1] && v[i+1]==1){//checa se o vetor precisa diminuir
                    soma=0;
                    for(int j=i+1;j<n;j++){//soma os proximos digitos
                        soma+=v[j];
                        v[j]=0;
                    }
                    v[i]-=1;
                    v[i+1]=soma+1;//coloca a soma na proxima posição
                    break;
			}
			if(v[i]>1 && v[i+1]<v[i]){//mudança padrão
				v[i]-=1;
				v[i+1]+=1;
				break;
			}
		}
}

int main(){

	int n;

	printf("Digite um numero inteiro: ");
	scanf("%d",&n);
	int v[n];
	//v = malloc(sizeof(int)*n);//vetor de n posições
	printf("Decomposicao:\n");

	for(int i=0;i<n;i++)//zera o vetor
	  v[i]=0;

	v[0]=n;//coloca zero na posição inicial

	printf("%d\n",n);//printa o primeiro numero

        while(1){

                    ArrumaVetor(n,v);

                    while(printavel(n,v))
                            ArrumaVetor(n,v);

                    //começa a printar o número
                     printf("%d",v[0]);
                     for(int i=1;i<n;i++)
                          if(v[i]>0)
                            printf(" + %d",v[i]);
                    printf("\n");
                    //termina de printar

                    if(v[0]==1)//termina o loop
                      break;
        }
}
