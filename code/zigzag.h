/**
 * \file zigzag.h
 * \brief Header pour le calcul du plus grand zigzag dans un tableau
 * \author Benoit Donnet, Géraldine Brieven -- Université de Liège (ULiège)
 * \version 0.1
 * \date 11/12/2025
 */

#ifndef __zigzag__
#define __zigzag__

/*
 * @pre: ???
 * @post: ???
 */
void analyse_zigzag(int *T, unsigned int N,
                    unsigned int *start, unsigned int *end,
                    unsigned int *length, int *somme);

#endif
