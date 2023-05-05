/**
 * DISCLAIMER
 * não está funcionando até o momento
 */

#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "dequef.h"


/**
   Create an empty deque of floats.

   capacity is both the initial and minimum capacity.
   factor is the resizing factor, larger than 1.0.

   On success it returns the address of a new dequef.
   On failure it returns NULL.
**/
dequef* df_alloc(long capacity, double factor)
{
   dequef *D = malloc(sizeof(dequef));
   if(D == NULL)
      return NULL; // Alocação da deque falhou
   
   D->data = malloc(capacity * sizeof(float));
   if(D->data == NULL)
   {
      free(D); // Libera D
      return NULL; // Alocação da data falhou
   }

   D->first = 0;
   D->size = 0;
   D->cap = capacity;
   D->mincap = capacity;
   D->factor = factor;

   return D;
}



/**
  Release a dequef and its data.
**/
void df_free(dequef* D)
{
   free(D->data);
   free(D);
}



/**
   The size of the deque.
**/
long df_size(dequef* D)
{
   return D->size;
}

/**
   Add x to the end of D.

   If the array is full, it first tries to increase the array size to
   capacity*factor.

   On success it returns 1.
   If attempting to resize the array fails then it returns 0 and D remains unchanged.
**/
int df_push(dequef* D, float x)
{
   if(D->size == D->cap)
   {
      // Deque cheia
      float *newData = malloc((D->size*D->factor) * sizeof(float));
      if(!newData)
         return 0; // Alocação de mais data falhou

      // Cópia dos dados
      float *p = D->data, *q = newData; // P aponta pro dado antigo, Q pro dado novo (vazio)
      p += D->first; // P avança até first
      for(int i = 0; i < D->size; i++)
      {
         if(p == D->data + D->cap)
         {
            // Chegou no fim, volta ao começo
            p = D->data;
         }
         *q = *p; // Copia valor de P para Q
         q++;
         p++;
      }
      *p = x; // Adiciona x no fim
      D->size++;
      D->cap *= D->factor;
      return 1;
   }
   else
   {
      // Deque com espaço suficiente
      if(D->first + D->size > D->cap)
      {
         // Vetor circular
         float *p = D->data; // P aponta pro dado antigo, Q pro dado novo (vazio)
         p += D->first; // P avança até first
         for(int i = 0; i < D->size; i++)
         {
            if(p == D->data + D->cap)
            {
               // Chegou no fim, volta ao começo
               p = D->data;
            }
            p++;
         }
         p++;
         // Chegou no lugar para adicionar
         *p = x;
         D->size++;
      }
      else
      {
         // Vetor simples
         float *p = D->data; // P aponta pro dado
         for(int i = 0; i < D->size; i++)
            p++;
         // Chegou no endereço vazio
         *p = x;
         D->size++;
      }
      return 1;
   }
}


/**
   Remove a float from the end of D.

   If the deque has capacity/(factor^2) it tries to reduce the array size to
   capacity/factor.  If capacity/factor is smaller than the minimum capacity,
   the minimum capacity is used instead.  If it is not possible to resize, then
   the array size remains unchanged.

   This function returns the float removed from D.
   If D was empty prior to invocation, it returns 0.0 and D remains unchanged.
**/
float df_pop(dequef* D)
{
   if(D->size == 0)
      return (0.0);

   if((D->size - 1) == (D->cap / (D->factor * D->factor)))
   {
      if((D->cap / D->factor) >= D->mincap)
      {
         // Reduzir tamanho da deque
         float *newData = malloc((D->size/D->factor) * sizeof(float));
         if(!newData)
            return 0; // Alocação de data falhou

         // Cópia dos dados
         float *p = D->data, *q = newData; // P aponta pro dado antigo, Q pro dado novo (vazio)
         p += D->first; // P avança até first
         for(int i = 0; i < D->size; i++)
         {
            if(p == D->data + D->cap)
            {
               // Chegou no fim, volta ao começo
               p = D->data;
            }
            *q = *p; // Copia valor de P para Q
            q++;
            p++;
         }
         D->cap /= D->factor;
      }
      else
      {
         // Tamanho minimo

      }
   }

   float *p = D->data;
   for(int i = 0; i < D->size; i++)
      p++;
   D->size--;

   return (*p);
}



/**
   Add x to the beginning of D.

   If the array is full, it first tries to increase the array size to
   capacity*factor.

   On success it returns 1.
   If attempting to resize the array fails then it returns 0 and D remains unchanged.
**/
int df_inject(dequef* D, float x)
{
   if(D->size == D->cap)
   {
      // Deque cheia
      float *newData = malloc((D->size*D->factor) * sizeof(float));
      if(!newData)
         return 0; // Alocação de mais data falhou

      // Cópia dos dados
      float *p = D->data, *q = newData; // P aponta pro dado antigo, Q pro dado novo (vazio)
      p += D->first; // P avança até first
      *q = x; // Adiciona 'x' no inicio
      q++;
      for(int i = 0; i < D->size; i++)
      {
         if(p == D->data + D->cap)
         {
            // Chegou no fim, volta ao começo
            p = D->data;
         }
         *q = *p; // Copia valor de P para Q
         q++;
         p++;
      }
      D->first--;
      D->size++;
      return 1;
   }
   else
   {
      // Deque com espaço suficiente
      if(D->first + D->size > D->cap)
      {
         // Vetor circular
         float *p = D->data; // P aponta pro dado antigo, Q pro dado novo (vazio)
         p += D->first - 1; // P avança até o anterior de first
         *p = x;
         D->first--;
         D->size++;
      }
      else
      {
         // Vetor simples
         if(!D->first)
         {
            // Começa em 0
            float *p = D->data;
            for(int i = 0; i < D->size; i++)
               p++;
            *p = x;
            D->first = D->size;
            D->size++;
         }
         else
         {
            // Não começa em 0
            float *p = D->data + D->first - 1; // Vai pra 1 antes do inicio
            *p = x; // Insere 'x'
            D->first--;
            D->size++;
         }
      }
      return 1;
   }
}



/**
   Remove a float from the beginning of D.

   If the deque has capacity/(factor^2) elements, this function tries to reduce
   the array size to capacity/factor.  If capacity/factor is smaller than the
   minimum capacity, the minimum capacity is used instead.

   If it is not possible to resize, then the array size remains unchanged.

   This function returns the float removed from D.
   If D was empty prior to invocation, it returns 0.0 and D remains unchanged.
**/
float df_eject(dequef* D)
{
   if(D->size == 0)
      return (0.0);

   if((D->size - 1) == (D->cap / (D->factor * D->factor)))
   {
      if((D->cap / D->factor) >= D->mincap)
      {
         // Reduzir tamanho da deque
         float *newData = malloc((D->size/D->factor) * sizeof(float));
         if(!newData)
            return 0; // Alocação de data falhou

         // Cópia dos dados
         float *p = D->data, *q = newData; // P aponta pro dado antigo, Q pro dado novo (vazio)
         p += D->first; // P avança até first
         float aux = *p; // Armazena o float que vai ser retirado
         p++; // Pula o primeiro
         for(int i = 0; i < D->size; i++)
         {
            if(p == D->data + D->cap)
            {
               // Chegou no fim, volta ao começo
               p = D->data;
            }
            *q = *p; // Copia valor de P para Q
            q++;
            p++;
         }

         D->cap /= D->factor;
         D->first++;
         return aux;
      }
      else
      {
         // Tamanho minimo

      }
   }

   float *p = D->data + D->first;
   D->first++;
   return (*p);
}



/**
   Set D[i] to x.

   If i is not in [0,|D|-1]] then D remains unchanged.
**/
void df_set(dequef* D, long i, float x)
{
   if(!(i > D->size + 1))
   {
      // i está no intervalo
      float *p = D->data;
      for(int i = 0; i < D->size; i++)
      {
         if(p == D->data + D->cap)
         {
            // Chegou no fim, volta ao começo
            p = D->data;
         }
         p++;
      }
      *p = x; // Seta 'x'
   }
}



/**
   Return D[i].

   If i is not in [0,|D|-1]] it returns 0.0.
**/
float df_get(dequef* D, long i)
{
   if(i > D->size + 1)
   {
      return (0.0);
   }
   else
   {
      // i está no intervalo
      float *p = D->data;
      for(int i = 0; i < D->size; i++)
      {
         if(p == D->data + D->cap)
         {
            // Chegou no fim, volta ao começo
            p = D->data;
         }
         p++;
      }
      return(*p);
   }
}



/**
   Print the elements of D in a line.
**/
void df_print(dequef* D)
{
   printf("deque(%ld): ", D->size);
   float *p = D->data + D->first;
   for(int i = 0; i < D->size; i++)
   {
      if(p == D->data + D->cap - 1)
      {
         // Chegou no fim, volta ao começo
         p = D->data;
      }
      printf("%.1f ", *p);
      p++;
   }
   printf("\n");
}