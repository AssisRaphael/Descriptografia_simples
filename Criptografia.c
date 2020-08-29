#include<stdio.h>
#include<stdlib.h>

FILE *fp;
char *text;
int tam;
int cont;

int contar(){
	int i;
	for(i=0;text[i]!=0;i++);

	return i;
}

void Despermuta(){
	
	int t1=0, t2=tam-3;//armazenam os caracteres
	char aux;

	for(;t1<t2;t1+=4,t2-=4){
		//Troca as primeira letra com a ultima
		aux = text[t1];
		text[t1] = text[t2];
		text[t2] = aux;
		//Troca a segunda letra com a penultima
		aux = text[t1+1];
		text[t1+1] = text[t2+1];
		text[t2+1] = aux;
	}
}

void Refletir(){

	int i=0;//armazenam os caracteres
	char aux;

	for(i=0;i<tam-1;i+=2){
		aux = text[i];
		text[i] = text[i+1];
		text[i+1] = aux;
	}

}

void Decifrar(){
	
	for(int i=0;i<tam;i++){

		if(text[i]!='#'){
			text[i]-=3;
			cont++;
		}

		if(text[i]<65 && text[i]>61){
			text[i]+=26;
		}

		if(text[i]<97 && text[i]>93){
			text[i]+=26;
		}
	}

}

void TiraE(){

	int i;	

	for(i=0;i<tam-1;i++){
		if(text[i]=='#'){
			text[i]=' ';
		}
	}

	if(cont%2!=0)//Quantidade ímpar de letras
		text[i]=0;
}



int main(){

	char nome[500];
	cont = 0;

	printf("Digite o nome do arquivo: ");
	scanf("%s",nome);

    fp = fopen(nome,"r");
        if(fp==NULL)
        	return 1;//Arquivo não encontrado

	text = malloc(sizeof(char)*10005);//aloca 20000 caracteres para a mensagem

	int i=0;
	while(1){//Copia a frase pro vetor text
		text[i]=fgetc(fp);
		if(text[i]==EOF){
			text[i]=0;
			break;		
		}
		i++;
	}

	tam = contar(text);

	printf("\n--------------------\nMensagem codificada:\n--------------------\n");
	printf("%s",text);
	printf("\n----------------------\nMensagem decodificada:\n----------------------\n");

	Despermuta();
	Refletir();
	Decifrar();
	TiraE();

	for(int i=0;i<tam-1;i++)
		printf("%c",text[i]);
	putchar('\n');
	return 0;
}
