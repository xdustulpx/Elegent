#ifndef _VECTEURH
#define _VECTEURH

typedef struct {
  //int nbl;// le nombre de lignes
  int nb;// les nombre de éléments de la vecteur
  T *vec;// les éléments de la vecteur
}vecteur;

// rôle : renvoie une vecteur initialisée à 0
extern vecteur vecteurNulle (const int m);
// rôle : renvoie l’élément m(i)
extern T getV( const vecteur m , const int i );
// rôle : m(i) = x
extern void setV(vecteur *m , const int i , const T x);
// rôle : écrit la matrice m sur la sortie standard
extern void ecrireVecteur (const vecteur m);
// rôle : initialise la matrice m à partir du fichier de nom f
extern void lireVecteur (vecteur *m , const char *f);