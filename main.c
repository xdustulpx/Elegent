#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"matrice.h"
#include"vecteur.h"
void GaussRSL(matrice A,vecteur B,vecteur *X);
int main(){
  int m,n=0;
  char *f1="data_matrice";
  char *f2="data_vecteur";
  FILE *fd=fopen(f1,"r");
  FILE *fp=fopen(f2,"r");
  fscanf(fd,"%d %d",m,n);
  fclose(fd);
  fclose(fp);
  matrice A=matriceNulle(m,n);//初始化系数矩阵
  vecteur B=vecteurNulle(m);//初始化右边矩阵
  vecteur *X;
  lireMatrice(A,f1);
  lireVecteur(B,f2);
  GaussRSL(A,B,X);
  ecrieVecteur(*X);
  return EXIT_SUCCESS;
}
void GaussRSL(matrice A,vecteur B,vecteur *X){
  int max_index=0;
  int top_linge=0;
  T max_value=0;
  T times=0;
  int nbl=getNbLignes (A);//获取矩阵A的行数
  int nbc=getNbCols (A)+1;//获取矩阵A的列数
  
  //将矩阵A,B合并变为增广矩阵，并赋值
  matrice M=matriceNulle(nbl,nbc);
  matrice *m=M;
  for(int i=0;i<nbl;i++){
    for(int j=0;j<nbc-1;j++){
      setM(m,i,j,mat[i*(nbc-1)+j]);//给增广矩阵每行0到nbc-1列赋值
    }
    setM(m,i,nbc,B.vec[i]);//给增广矩阵第nbc列赋值
  }
  
  //高斯消元法进行矩阵对角化
  for(int j=0;j<nbc-1;j++){//找到第j列的最大数作为主元，并记录索引和值
    for(int i=0;i<nbl;i++){
      T abs_value=fabs(getM(A,i,j));
      if(abs_value>max_value){
        max_value=abs_value;//记录最大值
        max_index=i;//记录索引
      }
    }
    for(int j=0;j<nbc;j++){
      m->mat[max_index*nbc+j]/=max_value;//主元所在行的主元归一化，并交换到最上面
      echangerLingesM(top_ligne,max_index);//交换行
    }
    
    for(int i=top_ligne+1;i<nbl;i++){//主元所在行同乘一个合适的数，再减去其余各行的所有元素，来消去每行第一列未知数，变为0
      times=m->mat[i*nbc+top_ligne]/m->mat[top_ligne*nbc+top_ligne];
      for(int j=0;j<nbc;j++){
      m->mat[i*nbc+j]-=times*(m->mat)[top_ligne*nbc+j];
      }
    }
    top_ligne++;
    
  }
  
  //对角化后在从下往上消元，把所有行的未知数都变成1
  for(int j=nbc-2;j>=0;j--){
    bottom_ligne=i;
    for(int i=nbl-1;i>=0;i--){
      times=m->mat[(i-1)*nbc+j]/mat[bottom_ligne*nbc+j];
      mat[(i-1)*nbc+j]-=times*mat[bottom_ligne*nbc+j];
      mat[(i-1)*nbc+nbc-1]-=times*mat[bottom_ligne*nbc+nbc-1];
    }
  }
  
  //获取对角消元后矩阵的最后一列元素，其为所求解向量X的元素
  for(int i=0;i<nbl;i++){
    value=getM(m,i,nbc);
    setV(X,i,value);
  }
  
}