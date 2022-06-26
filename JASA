int
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

  return 0; 
}
