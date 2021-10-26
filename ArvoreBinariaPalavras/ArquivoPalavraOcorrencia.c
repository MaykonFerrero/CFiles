#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_PALAVRA 30

FILE* abreArquivo(char* nome){
	return fopen(nome,"r");
}

void fechaArquivo(FILE* arquivo){
	fclose(arquivo);
}

struct conta_palavra{
	char palavra[TAM_MAX_PALAVRA];
	int num_ocorrencia;
	struct conta_palavra *esq;	
	struct conta_palavra *dir;
};

struct conta_palavra *insere_arvore(struct conta_palavra *no, char pal[]){
	int i;
	if(no ==NULL){
		if((no=(struct conta_palavra *)malloc(sizeof(*no))) ==NULL){
			printf("Sem memoria n");			
			exit(0);
		};

		sprintf(no->palavra,pal);
		no->num_ocorrencia =1;
		no->dir =NULL;
		no->esq =NULL;
	}
	else
		{   
            if((i = strcmp(no->palavra, pal))== 0){
				no->num_ocorrencia++;
			}
			else
				if(i>0)	
					no->esq =insere_arvore(no->esq,pal);
				else
					no->dir =insere_arvore(no->dir,pal);
		
			return (no);
        }
	}

void lista(struct conta_palavra *no){
	if(no!= NULL){
	lista(no->esq);
	printf("%s-> %d ocorrencias \n", no->palavra, no->num_ocorrencia);
	lista(no->dir);
	}
}


int busca_arvore (struct conta_palavra *no, char pal[]){
	int i, ret = 0;
	if (no !=NULL)
		if((i=strcmp(no->palavra, pal))==0)
			ret = busca_arvore(no->esq,pal);
		else
			ret = busca_arvore(no->dir,pal);
		return (ret);
}

int main(int argc, char *argv[]){

    struct conta_palavra *raiz, *insere_arvore();
    char palavra[TAM_MAX_PALAVRA], letra;
    int ocorrencia, i, quantas;
    raiz = NULL;
    FILE *arquivo;
    char nomeArq[50];
    printf("Qual o nome do arquivo?");
    scanf("%s", &nomeArq);
    arquivo = abreArquivo(nomeArq);
    if(arquivo){
        printf("Processando arquivo....\n");
        while(!feof(arquivo)&& !ferror(arquivo)){
            i=0;
            while(1){

                letra = fgetc(arquivo);
                if(letra==EOF)
                    break;
                if(letra == ' '|| letra=='\n' || letra == '\t' || letra == '\r')
                    break;
                else{
                    palavra[i] = letra;
                    i++;
                }
            }
            if(i>0){
                palavra[i++]='\0';
                raiz = insere_arvore(raiz, palavra);
                quantas++;
            }
        }
        fechaArquivo(arquivo);
        
    }
    else{
        printf("Não abriu para leitura o arquivo \n");
        printf("Terminando o programa...\n");
        exit(1);

    }

    printf("\nLista das %d palavras lidas: \n\n", quantas);
    lista(raiz);
    printf("\nFim da lista das %d palavras lidas:\n\n", quantas);

    for(;;){
        printf("\nDigite a palavra que você quer localizar (Digite '*fim*' para terminar)");
        scanf("%s",palavra);
        if(strcmp(palavra,"*fim*")==0)
            break;
        if(ocorrencia =busca_arvore(raiz,palavra))
            printf("\n Ocorrencias : %d \n", ocorrencia);
        else
            printf("\nNenhuma ocorrencia encontrada \n");

    }
    
    return 0;
}

    

	

