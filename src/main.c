#include "../include/TADs/bancadas.h"
#include "../include/TADs/filas.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  system("clear");
  iniciaAleatoriedade();
  printf("\033[1;32mTESTE MANUAL DO SOFTWARE\033[0m\n");

  Usuario *usuario1 = criarUsuario(1);
  Usuario *usuario2 = criarUsuario(2);
  Usuario *usuario3 = criarUsuario(3);
  Usuario *usuario4 = criarUsuario(4);
  Usuario *usuario5 = criarUsuario(5);
  Usuario *usuario6 = criarUsuario(6);
  Usuario *usuario7 = criarUsuario(7);
  Usuario *usuario8 = criarUsuario(8);
  Usuario *usuario9 = criarUsuario(9);

  Fila *fila1 = criarFila(1);

  Bancada *bancada1 = criaBancada(1, 0);

  Servente *servente1 = criarServente(1);
  Servente *servente2 = criarServente(2);
  Servente *servente3 = criarServente(3);
  Servente *servente4 = criarServente(4);
  Servente *servente5 = criarServente(5);
  Servente *servente6 = criarServente(6);

  Usuario *usuarios[] = {usuario1, usuario2, usuario3, usuario4, usuario5, usuario6, usuario7, usuario8, usuario9};
  for (int i = 0; i < 9; i++) {
    if (usuarios[i] != NULL) {
      addFila(fila1, usuarios[i]);
    }
  }

  printf("\033[1;34mUSUARIOS NA FILA:\033[0m\n");
  exibeFila(fila1);

  printf("\033[1;34mBANCADA ANTES DE CHAMAR USUARIO:\033[0m\n");
  exibeBancada(bancada1);

  if (bancada1->estaVazia == 1)
    chamarParaBancada(bancada1, fila1);

  printf("\033[1;33mCheckpoint 0\033[0m\n\n");

  exibeFila(fila1);

  printf("\033[1;34mBANCADA DEPOIS DE CHAMAR USUARIO:\033[0m\n");
  exibeBancada(bancada1);

  Servente *serventes[] = {servente1, servente2, servente3, servente4, servente5, servente6};
  for (int i = 0; i < 6; i++) {
    addServenteBancada(bancada1, serventes[i]);
  }

  printf("\033[1;34mBANCADA DEPOIS DE ADICIONAR SERVENTES:\033[0m\n");
  exibeBancada(bancada1);

  if (bancada1->estaVazia == 0) {
    servirUsuario(bancada1);
    // TODO (caio): Aqui ta dando segmentation fault as vezes
  }

  printf("\033[1;33mCheckpoint 1\033[0m\n\n");

  printf("\033[1;34mBANCADA DEPOIS DE SERVIR USUARIO:\033[0m\n");
  exibeBancada(bancada1);

  // teste automatico
  // int i = 0;
  // while (1) {
  //   Usuario *usuario = criarUsuario(i);

  //   if (usuario != NULL) {
  //     addFila(fila1, usuario);
  //     i++;
  //   } else {
  //     free(usuario);
  //   }

  //   exibeFila(fila1);

  //   if (bancada1->estaVazia == 1)
  //     chamarParaBancada(bancada1, fila1);

  //   exibeBancada(bancada1);
  //   sleep(1); // Pausa de 1 segundo
  // }

  return 0;
}
