#include<stdio.h>
#include<stdlib.h>
#include"matrice.h"
#include"vecteur.h"

// rôle : renvoie une vecteur initialisée à 0
vecteur vecteurNulle (const int m){
  for(int i=0;i<m;i++){
      m.vec[i];//索引i,j遍历矩阵并初始化
  }
  return m.vec;
}
// rôle : renvoie l’élément m(i)
T getV( const vecteur m , const int i ){
  T value=m.vec[i];
  return value;
}
// rôle : m(i) = x
void setV(vecteur *m , const int i , const T x){
  m->vec[i]=x;//给m(i,j)赋值x
}
// rôle : écrit la matrice m sur la sortie standard
void ecrireVecteur (const vecteur m){
  for(int i=0;i<m;i++){
    printf("%lf ",m.vec[i]);//逐元素打印出矩阵元素
  }
}
// rôle : initialise la matrice m à partir du fichier de nom f
void lireVecteur (vecteur *m , const char *f){
  FILE *fd;
  int num=0;
  int nb=0;
  if((fd=fopen(f,"r"))==NULL){
  perror(f);
  exit(errno);
  }
  fread(&nb,sizeof(int),1,fd);//读取向量的维度
  while(fread(&num,sizeof(T),1,fd)>0){
    for(int i=0;i<nb;i++){
        m->vec[i]=num;//在文件f中一个一个读取并遍历存入矩阵mat
    }
  }
}
