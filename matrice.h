#ifndef _MATRICEH
#define _MATRICEH

typedef double T;
typedef struct {
  int nbl;// le nombre de lignes
  int nbc;// le nombre de colonnes
  T *mat;// les éléments de la matrice
}matrice;

// rôle : renvoie une matrice m × n initialisée à 0
extern matrice matriceNulle (const int m , const int n);
// rôle : renvoie l’élément m(i,j)
extern T getM( const matrice m , const int i , const int j);
// rôle : m(i,j) = x
extern void setM(matrice *m , const int i , const int j , const T x);
// rôle : permute les lignes i et j de la matrice m
extern void echangerLignesM (matrice *m , const int i , const int j );
// rôle : écrit la matrice m sur la sortie standard
extern void ecrireMatrice (const matrice m);
// rôle : initialise la matrice m à partir du fichier de nom f
extern void lireMatrice ( matrice *m , const char *f);
// rôle : renvoie le nombre de lignes de la matrice m
extern int getNbLignes (const matrice m );
// rôle : renvoie le nombre de colonnes de la matrice m
extern int getNbCols (const matrice m );