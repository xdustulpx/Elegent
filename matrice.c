#include<stdio.h>
#include<stdlib.h>
#include"matrice.h"
#include"vecteur.h"
// rôle : renvoie une matrice m × n initialisée à 0
matrice matriceNulle (const int m , const int n){
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      m.mat[i*n+j];//索引i,j遍历矩阵并初始化
    }
  }
  return m.mat;
}
// rôle : renvoie l’élément m(i,j)
T getM( const matrice m , const int i , const int j){
  T value=m.mat[i*m.nbc+j];
  return value;
}
// rôle : m(i,j) = x
void setM(matrice *m , const int i , const int j , const T x){
  m->mat[i*m.nbc+j]=x;//给m(i,j)赋值x
}
// rôle : permute les lignes i et j de la matrice m
void echangerLignesM (matrice *m , const int i , const int j ){
  if (i == j) {
    // 如果要交换的行相同，无需操作
    return;//直接结束函数，不返回值
  }
  // 获取i,j行的指针
  T *ligne_i = m->mat + i * m->nbc;
  T *ligne_j = m->mat + j * m->nbc;

  // 逐元素交换两行的值
  for (int k = 0; k < m->nbl; k++) {
    T temp = ligne_i[k];
    ligne_i[k] = ligne_j[k];
    ligne_j[k] = temp;
  }
}
// rôle : écrit la matrice m sur la sortie standard
void ecrireMatrice (const matrice m){
  for(int i=0;i<m.nbl;i++){
    for(int j=0;i<m.nbc;j++){
      printf("%lf ",m.mat[i*m.nbc+j]);//逐元素打印出矩阵元素
    }
    printf("\n");//换行
  }
}
// rôle : initialise la matrice m à partir du fichier de nom f
void lireMatrice (matrice *m , const char *f){
  FILE *fd;
  int num=0;
  int nbl,nbc=0;
  if((fd=fopen(f,"r"))==NULL){
  perror(f);
  exit(errno);
  }
  fread(&nbl,sizeof(int),1,fd);//读取矩阵的行列
  fread(&nbc,sizeof(int),1,fd);
  while(fread(&num,sizeof(T),1,fd)>0){
    for(int i=0;i<m.nbl;i++){
      for(int j=0;j<m.nbc;j++){
        m->mat[i*mat.nbc+j]=num;//在文件f中一个一个读取并遍历存入矩阵mat
      }
    }
  }
  fclose(fd);
}
// rôle : renvoie le nombre de lignes de la matrice m
int getNbLignes (const matrice m ){
  return m.nbl;
}
// rôle : renvoie le nombre de colonnes de la matrice m
int getNbCols (const matrice m ){
  return m.nbc;
}