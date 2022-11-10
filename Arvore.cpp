#include "Arvore.h"
#include <cstddef>
#include <iostream>


struct noh* criar_noh(int dado)
{
    struct noh* nohh
        = (struct noh*)malloc(sizeof(struct noh));

    nohh->dado = dado;

    nohh->esquerda = NULL;
    nohh->direita = NULL;
    return (nohh);
}

struct noh* inserir(noh* nohzito, int dado)
{
    if (nohzito == NULL)
        return criar_noh(dado);

    if (dado < nohzito->dado)
        nohzito->esquerda = inserir(nohzito->esquerda, dado);
    else if (dado > nohzito->dado)
        nohzito->direita = inserir(nohzito->direita, dado);

    return nohzito;
}


// se a raiz não for nula, soma 1 a cada nó que passa tanto na esquerda quanto na direita, contando o total de nós.
int contarNos(noh* raiz) {
    if (raiz == NULL)
        return 0;
    return 1 + contarNos(raiz->esquerda) + contarNos(raiz->direita);
}
//se a raiz não for nula, percorre a árvore somando os dados de cada nó, obtendo a soma total.
int somarNos(noh* raiz) {
    if (raiz == NULL)
        return 0;
    return raiz->dado + somarNos(raiz->esquerda) + somarNos(raiz->direita);
}
//se a raiz não for nula, é contado a altura de cada lado da árvore, retornando no final o maior lado.
int altura(noh* raiz) {
    if (raiz == NULL)
        return 0;
    else {
        int esq = 1 + altura(raiz->esquerda);
        int dir = 1 + altura(raiz->direita);
        if (esq > dir)
          return esq;
        else 
          return dir;
    }


}

void arvore() {
    struct noh* raiz_de_todos_os_males = NULL;
    raiz_de_todos_os_males = inserir(raiz_de_todos_os_males, 50);
    inserir(raiz_de_todos_os_males, 30);
    inserir(raiz_de_todos_os_males, 20);
    inserir(raiz_de_todos_os_males, 40);
    inserir(raiz_de_todos_os_males, 25);
    inserir(raiz_de_todos_os_males, 10);
    inserir(raiz_de_todos_os_males, 2);
    inserir(raiz_de_todos_os_males, 70);
    inserir(raiz_de_todos_os_males, 60);
    inserir(raiz_de_todos_os_males, 80);
    inserir(raiz_de_todos_os_males, 45);
    inserir(raiz_de_todos_os_males, 90);
    inserir(raiz_de_todos_os_males, 100);
    inserir(raiz_de_todos_os_males, 120);
    

    int totalNos = contarNos(raiz_de_todos_os_males);
    std::cout << "o total de nós é " << totalNos;

    int totalSoma = somarNos(raiz_de_todos_os_males);
    std::cout << "\no total da soma é " << totalSoma;

    int profundidade = altura(raiz_de_todos_os_males);
    std::cout << "\na profundidade da árvore é " << profundidade -1;
}


