#include "./ingredientes.h"
#include <stdbool.h>
#include <windows.h>

#define CAPING1 5000 // Capacidade da vasilha 1 (em gramas)

typedef struct {
  int capacidade;
  int quantidade_Atual;
  Ingrediente *ingrediente;
} Vasilha;

Vasilha *criaVasilha(Ingrediente *ingrediente);

bool RemoveQtdeVasilha(Vasilha *vasilha, int qtdeARemover);

bool TrocaDeVasilha(Vasilha *vasilha);
