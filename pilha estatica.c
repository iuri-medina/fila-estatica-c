#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 100

typedef struct {
    int Item[MAXTAM];
    int Topo;
  } TPilha;

void TPilha_Inicia(TPilha *p) {
  p->Topo = -1;
};

int TPilha_Vazia(TPilha *p) {
  if(p->Topo == -1) {
    return 1;
  } else {return 0;}
};

int TPilha_Cheia (TPilha *p) {
  if(p->Topo == MAXTAM - 1) {
    return 1;
  } else {return 0;}
};

void TPilha_Insere(TPilha *p, int x) {
  if(TPilha_Cheia(p) == 1) {
    printf("Erro: Pilha cheia.");
  } else {
      p->Topo++;
      p->Item[p->Topo] = x;
  }
};

int TPilha_Remove(TPilha *p) {
  int aux;
  if(TPilha_Vazia(p) == 1) {
    printf("Erro: Pilha vazia.");
  } else {
      aux = p->Item[p->Topo];
      p->Topo--;
      return aux;
  }
};

void exibirVetor(TPilha *p) {
  int i;
  printf("\nExibindo itens da pilha.");
  for(i=0;i<=p->Topo;i++) {
    printf("\nElemento: [%d] -> %d", i, p->Item[i]);
  };
  printf("\n\n");
};

int main() {
  int op = -1;
  int dado;
  int aux;
  TPilha *p = (TPilha*)malloc(sizeof(TPilha));
  TPilha_Inicia(p);

  while(op != 0) {
    printf("\n\nMenu\n1 - Inserir\n2 - Excluir\n3 - Exibir Vetor\n0 - Fim\n Opcao: ");
    scanf("%d", &op);
    if(op == 1) {
      printf("Digite um numero: ");
      scanf("%d", &dado);
      TPilha_Insere(p, dado);
    } 
    else if(op == 2) {
      aux = TPilha_Remove(p);
      printf("Item removido: %d", aux);
    }
    else if(op == 3) {
      exibirVetor(p);
    }
  };

  
  return 0;
}