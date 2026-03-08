/**
 * \file main-zigzag.c
 * \brief Programme principal
 * \author Benoit Donnet, Géraldine Brieven -- Université de Liège (ULiège)
 * \version 0.1
 * \date 11/12/2025
 *
 * Programme principal avec plusieurs exemples pour la recherche de zigzag
 */

#include <stdio.h>

#include "zigzag.h"

/*
 * Affiche le contenu d'un sous-tableau sur la sortie standard
 */
static void affiche_tableau(int *T, int start, int end){
  if (start > end) {
    printf("{}"); // segment vide
    return;
  }

  printf("{");
  for(int i = start; i <= end; ++i){
    if(i > start)
      printf(", ");
    printf("%d", T[i]);
  }//fin for -- i

  printf("}\n");
}//fin affiche_tableau()

/*
 * Affiche les résutlats de l'analyse du zigzag
 */
static void affiche_resultat(char *header, int*T, unsigned int N, unsigned int start, unsigned int end, unsigned int length, int sum){
  printf("%s", header);
  affiche_tableau(T, 0, N-1);

  printf("\tZigzag maximum: ");
  affiche_tableau(T, start, end);

  printf("\tDébut du zigzag: %u\n", start);
  printf("\tFin du zigzag: %u\n", end);
  printf("\tLongueur du zigzag: %u\n", length);
  printf("\tSomme du zigzag: %d\n", sum);

  printf("\n");
}//fin affiche résultat()

int main(){
  const unsigned int N1 = 7;
  const unsigned int N2 = 6;
  const unsigned int N3 = 7;
  const unsigned int N4 = 8;
  const unsigned int N5 = 7;
  const unsigned int N6 = 7;
  const unsigned int N7 = 5;

  int T1[7] = {1,3,2,4,3,5,1};
  int T2[6] = {9,4,7,2,8,3};
  int T3[7] = {5,1,4,2,3,0,6};
  int T4[8] = {2,2,3,1,4,4,0,5};
  int T5[7] = {-5,-2,-6,-1,-7,-3,-8};
  int T6[7] = {3,-1,4,-2,5,-3,6};
  int T7[5] = {4,4,4,4,4};

  unsigned int start, end, length;
  int sum;
  char *header;

  /*
   * Tableau T1: {1, 3, 2, 4, 3, 5, 1}
   *  - zigzag maximum: {1,3,2,4,3,5,1}
   *  - start: 0
   *  - end: 5
   *  - length: 6
   *  - sum: 18
   */
  analyse_zigzag(T1, N1, &start, &end, &length, &sum);
  affiche_resultat("Tableau T1: ", T1, N1, start, end, length, sum);

  /*
   * Tableau T2: {9,4,7,2,8,3}
   *  - zigzag maximum: {9,4,7,2,8,3}
   *  - start: 0
   *  - end: 5
   *  - length: 6
   *  - sum: 33
   */
  analyse_zigzag(T2, N2, &start, &end, &length, &sum);
  affiche_resultat("Tableau T2: ", T2, N2, start, end, length, sum);

  /*
   * Tableau T3: {5,1,4,2,3,0,6}
   *  - zigzag maximum: {5,1,4,2,3}
   *  - start: 0
   *  - end: 4
   *  - length: 5
   *  - sum: 15
   */
  analyse_zigzag(T3, N3, &start, &end, &length, &sum);
  affiche_resultat("Tableau T3: ", T3, N3, start, end, length, sum);

  /*
   * Tableau T4: {2,2,3,1,4,4,0,5}
   *  - zigzag maximum: {3,1,4}
   *  - start: 2
   *  - end: 4
   *  - length: 3
   *  - sum: 8
   */
  analyse_zigzag(T4, N4, &start, &end, &length, &sum);
  affiche_resultat("Tableau T4: ", T4, N4, start, end, length, sum);

  /*
   * Tableau T5: {−5,−2,−6,−1,−7,−3,−8}
   *  - zigzag maximum: {−5,−2,−6,−1,−7,−3,−8}
   *  - start: 0
   *  - end: 6
   *  - length: 7
   *  - sum: 32
   */
  analyse_zigzag(T5, N5, &start, &end, &length, &sum);
  affiche_resultat("Tableau T5: ", T5, N5, start, end, length, sum);

  /*
   * Tableau T6: {3,−1,4,−2,5,−3,6}
   *  - zigzag maximum: {3,−1,4,−2,5,−3,6}
   *  - start: 0
   *  - end: 6
   *  - length: 7
   *  - sum: 12
   */
  analyse_zigzag(T6, N6, &start, &end, &length, &sum);
  affiche_resultat("Tableau T6: ", T6, N6, start, end, length, sum);

  /*
   * Tableau T7: {4,4,4,4,4}
   *  - zigzag maximum: {4}
   *  - start: 0
   *  - end: 0
   *  - length: 1
   *  - sum: 4
   */
  analyse_zigzag(T7, N7, &start, &end, &length, &sum);
  affiche_resultat("Tableau T7: ", T7, N7, start, end, length, sum);

  return 0;
}//fin programme
