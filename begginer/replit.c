#include <stdio.h>

int ehMAiuscula(char c)
{
  return c >= 'A' && c <= 'Z';
}

int ehMinuscula(char c)
{
  return c >= 'a' && c <= 'z';
}

int ehNumero(char c)
{
  return c >= '0' && c <= '9';
}

void encripta(char alg[], char msg[])
{
  int i, j;
  
  for(i = 0; alg[i] != '\0' && alg[i] != '\n'; i++)
  {
    for(j = 0; msg[j] != '\0' && msg[j] != '\n'; j++)
    {
      if(alg[i] == 's')
      {
        if(ehNumero(msg[j]))
        {
          if(msg[j] == '9') msg[j] = '0';
          else msg[j]++;
        }
        else if(ehMinuscula(msg[j]) || ehMAiuscula(msg[j]))
        {
          if(msg[j] == 'z') msg[j] = 'a';
          else if(msg[j] == 'Z') msg[j] = 'A';
          else msg[j]++;
        }
      }// fim comando s
      else if(alg[i] == 'd')
      {
        if(ehNumero(msg[j]))
        {
          if(msg[j] == '0') msg[j] = '9';
          else msg[j]--;
        }
        else if(ehMinuscula(msg[j]) || ehMAiuscula(msg[j]))
        {
          if(msg[j] == 'a') msg[j] = 'z';
          else if(msg[j] == 'A') msg[j] = 'Z';
          else msg[j]++;
        }
      }// fim comando d
      else if(alg[i] == 'M')
      {
        if(ehMinuscula(msg[j]))
        {
          msg[j] -= 32;
        }
      }//fim comando M
      else if(alg[i] == 'm')
      {
        if(ehMAiuscula(msg[j]))
        {
          msg[j] +=  32;
        }
      }
      
    }
  }
}

int main(void) {
  char alg[51], msg[101];
  fgets(alg, 51, stdin);
  fgets(msg, 101, stdin);
  
  encripta(alg, msg);
  
  printf("%d\n%s\n", 'b', msg);

  return 0;
}