#include <unistd.h>
#define MACRO(x) ((x +2) / 2)

struct	s_leaf
{
  int nbr_espace;
  int nbr_stars;
  int ligne;
  int indice;
};
int     max(int size);
void    print(int n, char c);
void	leaf(int size, struct s_leaf* sleaf);
void    trunk(int size);
void    sapin(int size);

void	leaf(int size, struct s_leaf* sleaf)
{
  while (sleaf->indice <= sleaf->ligne) 
    {
      print(sleaf->nbr_espace,' '); 
      print(sleaf->nbr_stars, '*'); 
      write(1, "\n", 1); 
      sleaf->indice++; 
      if (sleaf->indice <= sleaf->ligne) 
	{
	  sleaf->nbr_espace = sleaf->nbr_espace - 1; 
	  sleaf->nbr_stars = sleaf->nbr_stars + 2; 
	}
    }
}
void	trunk(int size)
{
  int indice;
  int nbr_espace;
  int nbr_pipe;
  
  if (size == 1) 
    {
      print(3, ' ');
      print(1, '|');
      write(1, "\n", 1);
    }
  else
    {
      indice = 1;
      nbr_espace = ((max(size))/ 2) - (1 * MACRO(size - 2)); 
      nbr_pipe = 1 + (2 * MACRO(size - 2)); 
      while (indice <= size)
	{
	  print(nbr_espace, ' '); 
	  print(nbr_pipe, '|'); 
	  write(1, "\n", 1); 
	  indice++; 
	}
    }
}
int    max(int size) 
{
  int id;
  int stars;
  int lvl;

  id = 2; 
  lvl = 0; 
  stars = 0;  
  if (size >=3) 
    {
      stars = 13;  
      while (id < size) 
	{
	  stars = stars + (6 + (2 * MACRO(lvl))); 
	  id++; 
	  lvl++; 
	}
    }
  else if (size == 2)   
    stars = 13;   
  else
    stars = 7;   
  return (stars);
}
void    print(int n, char c) 
{
  int i;
 
  i = 0;
  while (i != n)
    {
      write(1, &c, 1);
      i++;
    }
}
void	sapin(int size)
{
  int etage;
  int lvl;
  struct s_leaf sleaf; 

  if (size == 0) 
    return;
  etage = 1;
  lvl = 0; 
  sleaf.indice = 1; 
  sleaf.ligne = 4; 
  sleaf.nbr_espace = ((max(size))/ 2);   
  sleaf.nbr_stars = 1; 
  while (etage <= size)  
    {
      leaf(size, &sleaf); 
      sleaf.nbr_stars = sleaf.nbr_stars - (2 * MACRO(lvl));  
      sleaf.nbr_espace = sleaf.nbr_espace + MACRO(lvl);  
      sleaf.ligne = sleaf.ligne + 1; 
      sleaf.indice = 1; 
      etage++; 
      lvl++; 
    }
  trunk(size); 
}
int	main(int argc, char **argv) 
{ 
   sapin(atoi(argv[1])); 
   return(0); 
} 
