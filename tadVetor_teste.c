#include <stdio.h>
#include <stdlib.h>
#include "tadVetor.h"

Vetor* v;

void teste1(){



  /********PARTE 2*********/

  int n, quantidade, saida, pos;
  Vetor* v = vet_criar();
  vet_inserirFim(v, 4);
  vet_inserirFim(v, 3);
  vet_inserirFim(v, 7);
  vet_inserirFim(v, 1);
  vet_inserirFim(v, 2);
  vet_imprimir(v);
  printf("\n");
  vet_inserir(v, 30, 3);
  vet_imprimir(v);
  printf("\n");
  vet_substituir(v, 2, 65);
  vet_imprimir(v);
  printf("\n");
  vet_removerPosicao(v, 3, &n);
  printf("valor removido %d\n", n);
  vet_imprimir(v);
  printf("\n");
  vet_removerElemento(v, 4);
  vet_imprimir(v);
  printf("\n");
  quantidade = vet_tamanho(v);
  printf("quantidade = %d\n", quantidade);
  vet_elemento(v, 1, &saida);
  printf("elemento = %d\n", saida);
  pos = vet_posicao(v, 1);
  printf("posicao = %d\n", pos);
  vet_destruir(v);
  printf("\n\n");



/********PARTE 2*********/

  Vetor* clone = vet_clone(v);
  int binario;
  printf("clone = %u\n", clone->tamVetor);
  vet_ordenarBuble(v);
  vet_imprimir(v);
  printf("\n");
  vet_ordenarSelection(clone);
  vet_imprimir(v);
  printf("\n");
  vet_ordenarInsertion(clone);
  vet_imprimir(v);
  printf("\n");
  binario = vet_buscaBinaria(clone, 1);
  printf("binario = %u\n", binario);
  printf("\n\n");



  /********PARTE 3*********/

  Vetor* importado;
  importado = vet_importar("arquivo_entrada.txt");
  vet_imprimir(importado);
  printf("\n");
  vet_exportar(importado, "arquivo_exportado");
  printf("\n\n");




  /********PARTE 2*********/

  Vetor* aleatorio;
  aleatorio = vet_criarAleatorio(6);
  vet_imprimir(aleatorio);
  printf("\n\n");
  Vetor* ascendente;
  ascendente = vet_criarAscendente(4);
  vet_imprimir(ascendente);
  printf("\n\n");
  Vetor* descendente;
  descendente = vet_criarDescendente(15);
  vet_imprimir(descendente);
  printf("\n\n");
  Vetor* ascendenteParcial;
  ascendenteParcial = vet_criarAscendenteParcial(12, 50);
  vet_imprimir(ascendenteParcial);
}




int main(){

  teste1();

}
