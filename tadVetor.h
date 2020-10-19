#include <stdlib.h>
#include <string.h>
#include <stdio.h>



/**************************************
* DADOS
**************************************/

typedef struct{
	int* array;
	int tamVetor;
	int qtdeElementos;
}Vetor;


typedef enum boolean{false=0, true=1} Boolean;

typedef int TipoElemento;




/**************************************
* PROTÓTIPOS
**************************************/

Vetor* vet_criar();
void verifica_aumenta(Vetor* v);
void verifica_diminui(Vetor* v);
Boolean verifica_vetor(Vetor* v);
Boolean vet_inserirFim(Vetor* v, TipoElemento elemento);
Boolean vet_inserir(Vetor* v, TipoElemento elemento, int posicao);
Boolean vet_substituir(Vetor* v, int posicao, TipoElemento novoElemento);
Boolean vet_removerPosicao(Vetor* v, int posicao, TipoElemento* endereco);
Boolean vet_removerElemento(Vetor* v, TipoElemento elemento);
int vet_tamanho(Vetor* v);
Boolean vet_elemento(Vetor* v, int posicao, TipoElemento* saida);
int vet_posicao(Vetor* v, TipoElemento elemento);
void vet_imprimir(Vetor* v);
void vet_destruir(Vetor* v);
Boolean vet_toString(Vetor* v, char* enderecoString);
Vetor* vet_clone(Vetor* v);
void vet_ordenarBuble(Vetor* v);
void vet_ordenarSelection(Vetor* v);
void vet_ordenarInsertion(Vetor* v);




Vetor* vet_importar(char* nomeArquivo);
Boolean vet_exportar(Vetor* v, char* nomeArquivo);
Vetor* vet_criarAleatorio(int tam);

/**************************************
* IMPLEMENTAÇÃO
**************************************/

Vetor* vet_criar(){
    Vetor* v = (Vetor*) malloc(sizeof(Vetor*));

    v->tamVetor = 5;
    v->qtdeElementos = 0;
    v->array = (TipoElemento*) calloc(5, sizeof(TipoElemento));
    return v;
}




void verifica_aumenta(Vetor* v){
  float percentual;

  percentual = (float) v->qtdeElementos / v->tamVetor;

  if(percentual == 1){
    v->tamVetor *= 2;
    v->array = (TipoElemento*) realloc(v->array, v->tamVetor*sizeof(TipoElemento));
  }
}



void verifica_diminui(Vetor* v){
  float percentual;

  percentual = (float) v->qtdeElementos / v->tamVetor;

    if(percentual < 0.25){
        v->tamVetor /= 2;
        v->array = (TipoElemento*) realloc(v->array, v->tamVetor*sizeof(TipoElemento));
      }
}



Boolean verifica_vetor(Vetor* v){
    if(v == NULL)
        return false;
    else
        return true;
}



Boolean vet_inserirFim(Vetor* v, TipoElemento elemento){
    Boolean verdadeiro = verifica_vetor(v);
    verifica_aumenta(v);

    v->array[v->qtdeElementos] = elemento;
    v->qtdeElementos++;

    return verdadeiro;
}



Boolean vet_inserir(Vetor* v, TipoElemento elemento, int posicao){
    Boolean verdadeiro = verifica_vetor(v);
    if(posicao<0)
        posicao = posicao + v->qtdeElementos;

    if(posicao>v->tamVetor)
        return false;

    verifica_aumenta(v);

    for(int i=v->tamVetor; i>=posicao; i--)
        v->array[i + 1] = v->array[i];

    v->array[posicao] = elemento;
    v->qtdeElementos++;
    return verdadeiro;
}



Boolean vet_substituir(Vetor* v, int posicao, TipoElemento novoElemento){
    Boolean verdadeiro = verifica_vetor(v);

    if(posicao>=v->tamVetor)
        return false;
    if(posicao>0)
        posicao += v->tamVetor;
    v->array[posicao] = novoElemento;

    return verdadeiro;
}



Boolean vet_removerPosicao(Vetor* v, int posicao, TipoElemento* endereco){
    Boolean verdadeiro = verifica_vetor(v);

    if(posicao > v->tamVetor)
        return false;
    else if(posicao < 0)
        posicao = posicao + v->tamVetor;

    *endereco = v->array[posicao];
    for(int i=posicao; i<v->qtdeElementos; i++)
        v->array[i] = v->array[i + 1];

    v->qtdeElementos--;

    verifica_diminui(v);

    return verdadeiro;

}



Boolean vet_removerElemento(Vetor* v, TipoElemento elemento){
    Boolean verdadeiro = verifica_vetor(v);

    for(int i=0; i<v->qtdeElementos; i++)
        if(elemento == v->array[i]){
            for(int j=elemento; i<v->qtdeElementos; i++)
                if(elemento == v->array[i])
                    v->array[i] = v->array[i + 1];

            v->qtdeElementos--;

        }
    verifica_diminui(v);
    return true;
}



int vet_tamanho(Vetor* v){
    return v->qtdeElementos;
}


Boolean vet_elemento(Vetor* v, int posicao, TipoElemento* saida){
    Boolean verdadeiro = verifica_vetor(v);
    if(posicao > v->tamVetor)
        return false;
    else if(posicao < 0)
        posicao += v->tamVetor;

    for(int i=0; i<v->qtdeElementos; i++)
        if(*saida == v->array[i])
            *saida = v->array[i];
    return verdadeiro;
}



int vet_posicao(Vetor* v, TipoElemento elemento){
    for(int i=0; i<v->qtdeElementos; i++)
        if(elemento == v->array[i])
            return v->array[i];
    return -1;
}



void vet_imprimir(Vetor* v){
    for(int i=0; i<v->qtdeElementos; i++)
        printf("%u ", v->array[i]);
}



void vet_destruir(Vetor* v){
    free(v);
}



/*Boolean vet_toString(Vetor* v, char* enderecoString){
  Boolean verdadeiro = verifica_vetor(v);

  char string = (char*) malloc(sizeof(char));

  strcat (string, "\n[");
  for(int i=0; i<v->qtdeElementos; i++){
    char valor;

  }

}*/





Vetor* vet_clone(Vetor* v){
    Vetor* vclone = (Vetor*) malloc(sizeof(v));
    memcpy(vclone, v, sizeof(Vetor));

    return vclone;
}



void vet_ordenarBuble(Vetor* v){
    int aux = 0;
    int indice = v->qtdeElementos - 1;
    for(int i=0; i < indice; i++){
        for(int j=0; j<indice-i; j++){
            if(v->array[j] > v->array[j + 1]){
                aux = v->array[j];
                v->array[j] = v->array[j + 1];
                v->array[j + 1] = aux;
            }
        }
    }
}




void vet_ordenarSelection(Vetor* v){
    int aux = 0;
    int menor = 0;
    int indice = v->qtdeElementos - 1;
    for(int i = 0; i < indice; i++){
        menor = i;
        for(int j = i + 1; j <= indice; j++)
            if(v->array[j] < v->array[menor])
                menor = j;

        if(v->array[i] != v->array[menor]){
            aux = v->array[i];
            v->array[i] = v->array[menor];
            v->array[menor] = aux;
        }
    }
}


void vet_ordenarInsertion(Vetor* v){
  for(int i = 1; i < v->qtdeElementos; i++){
      int key = v->array[i];
      int j = i - 1;
      while(j >= 0 && v->array[j] > key){
          v->array[j + 1] = v->array[j];
          j--;
      }
      v->array[j + 1] = key;
  }
}



int vet_buscaBinaria(Vetor* v, TipoElemento elemento){
  int maior = v->qtdeElementos - 1;
  int menor = 0;

  while(menor <= maior){
      int meio = (maior + menor) / 2;
      if(elemento == v->array[meio])
          return meio;
      else if(elemento < v->array[meio])
          maior = meio - 1;
      else
          menor = meio + 1;
  }
  return -1;
}




Vetor* vet_importar(char* nomeArquivo){
  Vetor* importar = vet_criar();

  FILE *arquivo;
  arquivo = fopen(nomeArquivo, "r");
  if(arquivo == NULL){
    return NULL;
  }

  int a;
  do{
    verifica_aumenta(importar);
    a = fscanf(arquivo, "%d", &importar->array[importar->qtdeElementos]);
    importar->qtdeElementos++;
  }while(a != EOF);

  importar->qtdeElementos--;


return importar;
}



Boolean vet_exportar(Vetor* v, char* nomeArquivo){
    FILE* arquivo;
    int exporta;

    arquivo = fopen(nomeArquivo, "w");

    if(arquivo != NULL){
        for(int i=0; i<v->qtdeElementos;i++)
            exporta = fprintf(arquivo,"%d\n",v->array[i]);

        return true;
    }

    return false;
}



Vetor* vet_criarAleatorio(int tam){
  printf("vetor aleatorio\n");
  Vetor* random = (Vetor*) malloc (sizeof(Vetor*));
  random->tamVetor = tam;
  random->qtdeElementos = tam;
  random->array = (TipoElemento *) calloc (random->tamVetor,sizeof(TipoElemento));

  for(int i=0; i<random->qtdeElementos;i++){
      random->array[i] = rand();
  }

    return random;
}



Vetor* vet_criarAscendente(int tam){
  printf("vetor ascendente\n");
  Vetor* novo = (Vetor *) malloc (sizeof(Vetor));
  novo->tamVetor = tam;
  novo->qtdeElementos = tam;
  novo->array = (TipoElemento *) calloc (novo->tamVetor,sizeof(TipoElemento));

  for(int i = 0; i < novo->tamVetor;i++){
      novo->array[i] = i+1;
  }

  return novo;
}



Vetor* vet_criarDescendente(int tam){
  printf("vetor descendente\n");
  Vetor* desc = (Vetor *) malloc (sizeof(Vetor));
  desc->tamVetor = tam;
  desc->qtdeElementos = tam;
  desc->array = (TipoElemento *) calloc (desc->tamVetor,sizeof(TipoElemento));

  for(int i=0; i<desc->tamVetor;i++){
      desc->array[i] = desc->tamVetor - i;
  }

  return desc;
}



Vetor* vet_criarAscendenteParcial(int tam, int percentual){
  printf("vetor ascendente parcial\n");

  float porcentagem = percentual / 100.00;
  int PercentInt = porcentagem * tam;

  Vetor* novo = (Vetor *) malloc (sizeof(Vetor));
  novo->tamVetor = tam;
  novo->qtdeElementos = tam;
  novo->array = (TipoElemento *) calloc (novo->tamVetor,sizeof(TipoElemento));

  for(int i = 0; i < novo->tamVetor;i++){

      if(i<PercentInt){
          novo->array[i] = i+1;
      }

      else
          novo->array[i] = rand();
  }


  return novo;

}

