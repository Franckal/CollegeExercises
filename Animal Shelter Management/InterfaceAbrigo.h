#ifndef INTERFACEABRIGO_H
#define INTERFACEABRIGO_H
/* Programa Feito Por: Franck Allyson da Silva Rocha  */


/* Funções para Entrar e exibir Animal/Abrigo*/
#include <stdio.h>
#include "Animal.h"
#include "Abrigo.h"

void clear();

void entraAbrigo(Abrigo * endAbrigo);
void entraAnimais(Animal * endAnimal);

void exibeAbrigo(Abrigo * endAbrigo);
void exibeAnimal(Animal * endAnimal);
#endif