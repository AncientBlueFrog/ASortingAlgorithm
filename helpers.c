/**************************************************************************** 
 * helpers.c
 *
 * CC50
 * Pset 3
 *
 * Helper functions for Problem Set 3.
 ***************************************************************************/

#include <cs50.h>
#include <stdio.h>
#include "helpers.h"


/*
 * Returns true if value is in array of n values, else false.
 */

bool 
search(int value, int array[], int n)
{
  int menor = 0;
  int maior = n - 1;
  int range;
  int meio;
  
  do 
  {
    range = maior - menor;  
    meio = menor + ((range) / 2);

    if(value < array[meio])
    {
      maior = meio;
    }
    else if(value > array[meio])
    {
      menor = meio + 1;
    }
    else
    {
      return true;
    }
  }
  while(range);

  return false; 
}


/*
 * Sorts array of n values.  Returns true if
 * successful, else false.
 */

bool
sort(int values[], int n)
{
  int arrayL[n];//Vetor que separa valores a esquerda.
  int arrayR[n];//Vetor que separa valores a dierita.

  int cL = 0, cR = 0;//Ponteiros.

  //Definem o maior e o menor valor do array.
  int menor = values[0];
  int maior = values[0];

  //Analiza o vetor a fim de encontrar o menor e o maior valor. 
  for(int i = 1; i < n; i++)
  {
      if(values[i] < menor)
      {
        menor = values[i];
      } 
      else
      {
        maior = values[i];
      }

  }

  int range = maior - menor;

  //Separar

  //Separar: Analizar o vetor a fim de separar os valores pelo range.
  if(range > 0)
  {

    for(int i = 0; i < n; i++)
    {
        if(values[i] <= menor + (range/2))
        {
          arrayL[cL] = values[i];
          cL++;
        }else
        {    
          arrayR[cR] = values[i];
          cR++;
        }
    }

    //Recursão.
    if(cL > 1)
      sort(arrayL, cL);
    if(cR > 1)
      sort(arrayR, cR);
  }
  
  
  //Unir
  for(int i = 0; i < cL; i++)
  {
    values[i] = arrayL[i];  
  }

  for(int i = cL; i < cL + cR; i++)
  {
    values[i] = arrayR[i - cL];
  }

  return true; 
}
