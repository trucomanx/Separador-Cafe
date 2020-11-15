/*
 * Matrix.hpp
 * 
 * Copyright 2011 Fernando Pujaico Rivera <fernando.pujaico.rivera@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */

/** \file Matrix.hpp
 *  \author Fernando Pujaico Rivera
 *  \brief Funciones que trabajan con matrices.
 *  
 *  <br>Estas funciones trabajan con una matriz de la forma.<br>
 *  \image html matrix.png "Matriz de NlinxNcol"
 *  \b Nlin es el número de lineas y \b Ncol es el número de columnas.
 */


#ifndef __PDS_MATRIX_HPP__
#define __PDS_MATRIX_HPP__


/** \defgroup MatrixGroup Métodos Pds::Matrix
 *  \brief Métodos de la clase Pds::Matrix, una matriz 
 *  <div class="fragment"> \#include <Pds/Matrix> </div>
 *  
 *  <br>Estas funciones trabajan con una matriz de la forma.<br>
 * 
   \f[
\mathbf{A}=\left(\begin{matrix}
a_{00} & a_{01} & \hdots & a_{0(Ncol-1)}\\ 
a_{10} & a_{11} & \hdots & a_{1(Ncol-1)}\\
\vdots & \vdots & \vdots & \vdots \\
a_{(Nlin-2)0} & a_{(Nlin-2)1} & \hdots & a_{(Nlin-2)(Ncol-1)}\\ 
a_{(Nlin-1)0} & a_{(Nlin-1)1} & \hdots & a_{(Nlin-1)(Ncol-1)}\\
\end{matrix}\right)
   \f]
   \f[
A\equiv [a_{i,j}]
   \f]
 *  
 *  \b Nlin es el número de lineas y \b Ncol es el número de columnas.
 *  
 * Información adicional puede ser encontrada en @cite tutorialmatvec
 * @{
 */


#include <string>
#include <list>
#include <Pds/Size>
#include <Pds/RaDefines>
#include <Pds/RegionRect>
#include <Pds/Array>

namespace Pds{

class Vector;

/*! \class Matrix
 *  \brief La clase tipo  Pds::Matrix .
 *  Esta clase genera una matriz de Nlin lineas y Ncol columnas.
 *  Para usar incluir Pds/Matrix.
 *  \ingroup MatrixGroup
 *  \author Fernando Pujaico Rivera
 */
class Matrix
{
protected:
    /*! Un arreglo de Nlin lineas y Ncol elementos por linea. */
    double **array;
    /*! Número de lineas. */
    unsigned int nlin;
    /*! Número de columnas. */
    unsigned int ncol;
    
    friend class CMatrix; 
public:

/** @name Constructores
 *  Crean una objeto Pds::Matrix
 * @{
 */

    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix vacio.
     * 
   \f[
\mathbf{A}\equiv []
   \f]
   Para crear una matriz vacia:
\code{.cpp}
    Pds::Matrix A;
    
    if(A.IsEmpty()) std::cout<<"Yes,always\n";
\endcode
     *  \ingroup MatrixGroup
     */
    Matrix(void);
    
    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix de N lineas y N columnas,
     *  con elementos inicializados con cero.
     * 
   \f[
\mathbf{A}=\left(\begin{matrix}
0 & 0 & \hdots & 0\\ 
0 & 0 & \hdots & 0\\
\vdots & \vdots & \vdots & \vdots \\
0 & 0 & \hdots & 0\\ 
0 & 0 & \hdots & 0\\
\end{matrix}\right)
   \f]
   \f[
A_{N,N}\equiv [0]
   \f]
   Para crear una matriz A de 4 filas y 4 columnas:
\code{.cpp}
    Pds::Matrix A(4);
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] N El numero de lineas y columnas de la matriz.
     *  \ingroup MatrixGroup
     */
    Matrix(unsigned int N);
    
    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix con elementos inicializados con cero.
     * 
   \f[
\mathbf{A}=\left(\begin{matrix}
0 & 0 & \hdots & 0\\ 
0 & 0 & \hdots & 0\\
\vdots & \vdots & \vdots & \vdots \\
0 & 0 & \hdots & 0\\ 
0 & 0 & \hdots & 0\\
\end{matrix}\right)
   \f]
   \f[
A\equiv [0]
   \f]
   Para crear una matriz A de 4 filas y 3 columnas:
\code{.cpp}
    Pds::Matrix B(4,3);
    Pds::Matrix A(B.Size);
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] S El tamaño de la matriz.
     *  \ingroup MatrixGroup
     */
    Matrix(const Pds::Size &S);

    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix copiando datos desde 
     *  otra matriz. Este es un Copy assignment constructor.
     * 
   \f[
B\equiv [b_{i,j}]
   \f]
   \f[
\mathbf{A} \leftarrow \mathbf{B}
   \f]
   Para crear una matriz A con copia de datos de una matriz B:
\code{.cpp}
    Pds::Matrix B(4,3,-1.0);
    Pds::Matrix A(B);
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] B Matriz a copiar.
     *  \ingroup MatrixGroup
     */
    Matrix(const Pds::Matrix &B);
    

    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix copiando datos desde 
     *  un arreglo
     * 
   \f[
B\equiv [b_{i,j}]
   \f]
   \f[
\mathbf{A} \leftarrow \mathbf{B}
   \f]
     *  \param[in] B Array a copiar.
     *  \ingroup MatrixGroup
     */
    Matrix(const Pds::Array<unsigned int> &B);

    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix copiando datos desde 
     *  un arreglo
     * 
   \f[
B\equiv [b_{i,j}]
   \f]
   \f[
\mathbf{A} \leftarrow \mathbf{B}
   \f]
     *  \param[in] B Array a copiar.
     *  \ingroup MatrixGroup
     */
    Matrix(const Pds::Array<unsigned char> &B);
    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix copiando datos desde 
     *  un arreglo
     * 
   \f[
B\equiv [b_{i,j}]
   \f]
   \f[
\mathbf{A} \leftarrow \mathbf{B}
   \f]
     *  \param[in] B Array a copiar.
     *  \ingroup MatrixGroup
     */
    Matrix(const Pds::Array<double> &B);

    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix copiando datos desde 
     *  una cadena.
     * 
   Para crear una matriz A con los datos de una cadena:
\code{.cpp}
    Pds::Matrix A="1 2 3\n4 5 6\n";
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] str Cadena a leer.
     *  \ingroup MatrixGroup
     */
    Matrix(const char *str);
    
    
    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix con elementos inicializados con cero.
     * 
   \f[
\mathbf{A}=\left(\begin{matrix}
0 & 0 & \hdots & 0\\ 
0 & 0 & \hdots & 0\\
\vdots & \vdots & \vdots & \vdots \\
0 & 0 & \hdots & 0\\ 
0 & 0 & \hdots & 0\\
\end{matrix}\right)
   \f]
   \f[
A\equiv [0]
   \f]
   Para crear una matriz A de 4 filas y 3 columnas:
\code{.cpp}
    Pds::Matrix A(4,3);
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] Nlin El numero de lineas de la matriz.
     *  \param[in] Ncol El numero de columnas de la matriz.
     *  \ingroup MatrixGroup
     */
    Matrix(unsigned int Nlin,unsigned int Ncol);
    
    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix con elementos inicializados con val.
     * 
   \f[
\mathbf{A}=\left(\begin{matrix}
val & val & \hdots & val\\ 
val & val & \hdots & val\\
\vdots & \vdots & \vdots & \vdots \\
val & val & \hdots & val\\ 
val & val & \hdots & val\\
\end{matrix}\right)
   \f]
   \f[
A\equiv [val]
   \f]
   Para crear una matriz A de 4 filas y 3 columnas inicializado con -1:
\code{.cpp}
    Pds::Matrix A(4,3,-1.0);
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] Nlin El numero de lineas de la matriz.
     *  \param[in] Ncol El numero de columnas de la matriz.
     *  \param[in] val El valor a usar.
     *  \ingroup MatrixGroup
     */
    Matrix(unsigned int Nlin,unsigned int Ncol,double val);
    
    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix, evaluando mediante una función, 
     *  los datos de otra matriz.
     * 
   \f[
B\equiv [b_{i,j}]
   \f]
   \f[
\mathbf{A} \leftarrow func(\mathbf{B})
   \f]
   Para crear una matriz A , copia de sin(B):
\code{.cpp}
    Pds::Matrix B(4,3,1.0);
    Pds::Matrix A(sin,B);
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] func Función a aplicar, esta debe tener a forma double func(double).
     *  \param[in] B Matriz a evaluar para copiar los resultados.
     *  \ingroup MatrixGroup
     */
    Matrix(double (*func)(double),const Pds::Matrix &B );
    
    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix, evaluando mediante una función, 
     *  los datos de otra matriz.
     * 
   \f[
B\equiv [b_{i,j}]
   \f]
   \f[
\mathbf{A} \leftarrow func(\mathbf{B},var)
   \f]
   Para crear una matriz A , copia de pow(B,3):
\code{.cpp}
    Pds::Matrix B(4,3,2.0);
    Pds::Matrix A(pow,B,3);
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] func Función a aplicar, esta debe tener a forma double func(double,double).
     *  \param[in] B Matriz a evaluar para copiar los resultados.
     *  \param[in] var Segunda variable de la función.
     *  \ingroup MatrixGroup
     */
    Matrix(double (*func)(double,double),const Pds::Matrix &B , double var);

    
    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix, evaluando mediante una función, 
     *  los datos de otra matriz.
     * 
   \f[
B\equiv [b_{ij}], \qquad C\equiv [c_{ij}] 
   \f]
   \f[
\mathbf{A} \leftarrow func(\mathbf{B},\mathbf{C})
   \f]
   \f[
\mathbf{a}_{ij} \leftarrow func(\mathbf{b}_{ij},\mathbf{c}_{ij})
   \f]
   Para crear una matriz A , copia de pow(B,C):
\code{.cpp}
    Pds::Matrix B(2,3,2.0);
    Pds::Matrix C(2,3,3.0);
    Pds::Matrix A(pow,B,C);
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] func Función a aplicar elemento a elemento en las matrices, 
     *  esta debe tener a forma double func(double,double).
     *  \param[in] B Matriz a evaluar para copiar los resultados.
     *  \param[in] C Matriz a evaluar para copiar los resultados.
     *  \ingroup MatrixGroup
     */
    Matrix(double (*func)(double,double),const Pds::Matrix &B ,const Pds::Matrix &C);

    
    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix, evaluando mediante una función, 
     *  los datos de otra matriz.
     * 
   \f[
B\equiv [b_{ij}], \qquad C\equiv [c_{ij}] 
   \f]
   \f[
\mathbf{A} \leftarrow func(\mathbf{B},\mathbf{C},var)
   \f]
   \f[
\mathbf{a}_{ij} \leftarrow func(\mathbf{b}_{ij},\mathbf{c}_{ij},var)
   \f]
   Para crear una matriz A , copia de func(B,C,var):
\code{.cpp}
    Pds::Matrix B(2,3,2.0);
    Pds::Matrix C(2,3,3.0);
    double var=2;
    Pds::Matrix A(func,B,C,var);
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] func Función a aplicar elemento a elemento en las matrices, 
     *  esta debe tener a forma double func(double,double,double).
     *  \param[in] B Matriz a evaluar para copiar los resultados.
     *  \param[in] C Matriz a evaluar para copiar los resultados.
     *  \param[in] var Tercera variable de la función.
     *  \ingroup MatrixGroup
     */
    Matrix(double (*func)(double,double,double),const Pds::Matrix &B ,const Pds::Matrix &C, double var);
    
    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix, evaluando mediante una función, 
     *  los datos de otra matriz.
     * 
   \f[
X\equiv [x_{ij}], \qquad Y\equiv [y_{ij}], \qquad Z\equiv [z_{ij}] 
   \f]
   \f[
\mathbf{A} \leftarrow func(\mathbf{X},\mathbf{Y},\mathbf{Z})
   \f]
   \f[
\mathbf{a}_{ij} \leftarrow func(\mathbf{x}_{ij},\mathbf{y}_{ij},\mathbf{z}_{ij})
   \f]
   Para crear una matriz A , copia de func(X,Y,Z):
\code{.cpp}
    Pds::Matrix X(2,3,2.0);
    Pds::Matrix Y(2,3,3.0);
    Pds::Matrix Z(2,3,1.0);
    Pds::Matrix A(func,X,Y,Z);
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] func Función a aplicar elemento a elemento en las matrices, 
     *  esta debe tener a forma double func(double,double,double).
     *  \param[in] X Matriz a evaluar para copiar los resultados.
     *  \param[in] Y Matriz a evaluar para copiar los resultados.
     *  \param[in] Z Matriz a evaluar para copiar los resultados.
     *  \ingroup MatrixGroup
     */
    Matrix(double (*func)(double,double,double),
            const Pds::Matrix &X, 
            const Pds::Matrix &Y, 
            const Pds::Matrix &Z);

    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix, evaluando mediante una función, 
     *  los datos de otra matriz.
     * 
   \f[
X\equiv [x_{ij}], \qquad Y\equiv [y_{ij}], \qquad Z\equiv [z_{ij}] 
   \f]
   \f[
\mathbf{A} \leftarrow func(\mathbf{X},\mathbf{Y},\mathbf{Z},var)
   \f]
   \f[
\mathbf{a}_{ij} \leftarrow func(\mathbf{x}_{ij},\mathbf{y}_{ij},\mathbf{z}_{ij},var)
   \f]
   Para crear una matriz A , copia de func(X,Y,Z,var):
\code{.cpp}
    Pds::Matrix X(2,3,2.0);
    Pds::Matrix Y(2,3,3.0);
    Pds::Matrix Z(2,3,1.0);
    double var=2;
    Pds::Matrix A(func,X,Y,Z,var);
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] func Función a aplicar elemento a elemento en las matrices, 
     *  esta debe tener a forma double func(double,double,double,double).
     *  \param[in] X Matriz a evaluar para copiar los resultados.
     *  \param[in] Y Matriz a evaluar para copiar los resultados.
     *  \param[in] Z Matriz a evaluar para copiar los resultados.
     *  \param[in] var Cuarto valor a evaluar.
     *  \ingroup MatrixGroup
     */
    Matrix(double (*func)(double,double,double,double),
            const Pds::Matrix &X, 
            const Pds::Matrix &Y, 
            const Pds::Matrix &Z,
            double var);

    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix, evaluando mediante una función, 
     *  los datos de otra matriz.
     * 
   \f[
X\equiv [x_{ij}], \qquad Y\equiv [y_{ij}], \qquad Z\equiv [z_{ij}], \qquad W\equiv [w_{ij}] 
   \f]
   \f[
\mathbf{A} \leftarrow func(\mathbf{X},\mathbf{Y},\mathbf{Z},\mathbf{W})
   \f]
   \f[
\mathbf{a}_{ij} \leftarrow func(\mathbf{x}_{ij},\mathbf{y}_{ij},\mathbf{z}_{ij},\mathbf{w}_{ij})
   \f]
   Para crear una matriz A , copia de func(X,Y,Z,W):
\code{.cpp}
    Pds::Matrix X(2,3,2.0);
    Pds::Matrix Y(2,3,3.0);
    Pds::Matrix Z(2,3,1.0);
    Pds::Matrix W(2,3,1.0);
    Pds::Matrix A(func,X,Y,Z,W);
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] func Función a aplicar elemento a elemento en las matrices, 
     *  esta debe tener a forma double func(double,double,double,double).
     *  \param[in] X Matriz a evaluar para copiar los resultados.
     *  \param[in] Y Matriz a evaluar para copiar los resultados.
     *  \param[in] Z Matriz a evaluar para copiar los resultados.
     *  \param[in] W Matriz a evaluar para copiar los resultados.
     *  \ingroup MatrixGroup
     */
    Matrix(double (*func)(double,double,double,double),
            const Pds::Matrix &X, 
            const Pds::Matrix &Y, 
            const Pds::Matrix &Z,
            const Pds::Matrix &W);

    /** 
     *  \brief Crea un objeto de tipo Pds::Matrix copiando datos desde 
     *  un archivo.
     * 
\code{.cpp}
    Pds::Matrix A(Pds::Ra::TextFormat,"textfile.txt");
    
    if(A.IsEmpty()) std::cout<<"Yes,possible memory allocation problem\n";
    else            std::cout<<"No,all fine\n";
\endcode
     *  \param[in] Type Tipo de archivo de fuente de datos. Los tipos aceptados son:
     *  <table>
     *  <tr><td> Pds::Ra::TextFormat    <td> Lee en formato de texto.
     *  </table>
     *  \param[in] filepath Path del archivo cargado.
     *  \ingroup MatrixGroup
     */
    Matrix(Pds::Ra::FormatType Type,std::string filepath);
    
    ~Matrix(); 
    
/**
 * @}
 */

public:

/** @name Métodos de estado
 *  Indican o establecen el estado de una matriz.
 * @{
 */

    /** 
     *  \brief Verifica si la matriz es nula es decir con lineas o columnas cero o arreglo NULL.
     *  
     *  Una matriz\f$\mathbf{A}\f$ está vacía si  \f$ \mathbf{A}=[]\f$.
     *  \return Retorna true si es nula e false si no.
     *  \ingroup MatrixGroup
     */
    bool IsEmpty(void) const;

    /** 
     *  \brief Verifica si la matriz NO es nula, es decir con lineas y columnas diferentes cero y arreglo diferente de NULL.
     * 
     *  Una matriz \f$\mathbf{A}\f$ está vacía si  \f$ \mathbf{A}=[]\f$.
     *  \return Retorna true si NO es nula e false si lo es.
     *  \ingroup MatrixGroup
     */
    bool IsNotEmpty(void) const;


    /** 
     *  \brief Verifica si las matrices son similares en tamaño.
     * 
     *  Una matriz\f$A_{M,N}\f$ es similar a \f$B_{P,Q}\f$ 
     *  si  \f$M=P\f$ y \f$N=Q\f$.
     *  \param[in] B Matriz en consulta.
     *  \return Retorna true si son similares y false si no.
     *  \ingroup MatrixGroup
     */
    bool IsSimilarTo(const Pds::Matrix &B) const;

    /** 
     *  \brief Verifica si las matrices son similares en tamaño.
     * 
     *  Una matriz\f$A_{M,N}\f$ es similar a \f$B_{P,Q}\f$ 
     *  si  \f$M=P\f$ y \f$N=Q\f$.
     *  \param[in] B Matriz en consulta.
     *  \return Retorna false si son similares y true si no.
     *  \ingroup MatrixGroup
     */
    bool IsNotSimilarTo(const Pds::Matrix &B) const;
    
    /** 
     *  \brief Verifica si las matrices son multiplicables.
     * 
     *  Una matriz\f$A_{M,N}\f$ es multiplicable por \f$B_{P,Q}\f$ 
     *  si  \f$N=P\f$ y ambas son no vacías.
     *  \param[in] B Matriz en consulta.
     *  \return Retorna true si son multiplicables y false si no.
     *  \ingroup MatrixGroup
     */
    bool IsMulBy(const Pds::Matrix &B) const;

    /** 
     *  \brief Verifica si las matrices son multiplicables.
     * 
     *  Una matriz\f$A_{M,N}\f$ es multiplicable por \f$B_{P,Q}\f$ 
     *  si  \f$N= P\f$ y ambas son no vacías.
     *  \param[in] B Matriz en consulta.
     *  \return Retorna false si son multiplicables y true si no.
     *  \ingroup MatrixGroup
     */
    bool IsNotMulBy(const Pds::Matrix &B) const;

    /** 
     *  \brief Verifica si la posición pertenece a la matriz.
     * 
     *  Dada una matriz\f$A_{M,N}\f$; la posición \f$(lin,col)\f$ 
     *  está en rango de \f$\mathbf{A}\f$ si cualquier valor entero de \f$0\leq lin \leq M-1\f$
     *  y  cualquier valor entero de \f$0\leq col \leq N-1\f$.
     *  \param[in] lin Linea en consulta.
     *  \param[in] col columna en consulta.
     *  \return Retorna true si pertenece y false si no.
     *  \ingroup MatrixGroup
     */
    bool IsInRange(unsigned int lin,unsigned int col) const;
    
    /** 
     *  \brief Verifica si la posición NO pertenece a la matriz.
     * 
     *  Dada una matriz\f$A_{M,N}\f$; la posición \f$(lin,col)\f$ 
     *  está en rango de \f$\mathbf{A}\f$ si cualquier valor entero de \f$0\leq lin \leq M-1\f$
     *  y  cualquier valor entero de \f$0\leq col \leq N-1\f$.
     *  \param[in] lin Linea en consulta.
     *  \param[in] col columna en consulta.
     *  \return Retorna false si pertenece y true si no.
     *  \ingroup MatrixGroup
     */
    bool IsNotInRange(unsigned int lin,unsigned int col) const;
    
    /** 
     *  \brief Verifica si la posición (lin,col) pertenece al rango de la matriz.
     * 
     *  Dada una matriz\f$A_{M,N}\f$; la posición \f$(lin,col)\f$ 
     *  está en rango de \f$\mathbf{A}\f$ si cualquier valor real de \f$0\leq lin \leq M-1\f$
     *  y  cualquier valor real de \f$0\leq col \leq N-1\f$.
     *  \param[in] lin Linea en consulta.
     *  \param[in] col columna en consulta.
     *  \return Retorna true si pertenece y false si no.
     *  \ingroup MatrixGroup
     */
    bool IsInSizeRange(double lin,double col) const;
    

    /** 
     *  \brief Verifica si la matriz tiene solo una linea.
     * 
     *  
     *  \return Retorna true si la matriz tiene solo una linea o false si no.
     *  Si la matriz está vacia se retorna false.
     *  \ingroup MatrixGroup
     */
    bool IsRowMatrix(void) const;


    /** 
     *  \brief Verifica si la matriz tiene solo una columna.
     * 
     *  
     *  \return Retorna true si la matriz tiene solo una columna o false si no.
     *  Si la matriz está vacia se retorna false.
     *  \ingroup MatrixGroup
     */
    bool IsColMatrix(void) const;

    /** 
     *  \brief Verifica si la matriz está llena de zeros.
     * 
   \f[
true \overleftarrow{IsZero} 
\left(\begin{matrix}
0 & 0 & \hdots & 0\\ 
0 & 0 & \hdots & 0\\
\vdots & \vdots & \vdots & \vdots \\
0 & 0 & \hdots & 0\\ 
0 & 0 & \hdots & 0\\
\end{matrix}\right)
   \f]
     *  \return Retorna true si la matriz está llena de zeros o false si no.
     *  Si la matriz está vacia se retorna false.
     *  \ingroup MatrixGroup
     */
    bool IsZero(void) const;

    /** 
     *  \brief Verifica si cada elemento de la matriz es menor a el valor val.
     * 
   \f[
\mathbf{A}~<=~val
   \f]
     *  \param[in] val El valor a comparar.
     *  \return Retorna true si todos los elementos son menores que val y false si no.
     *  \ingroup MatrixGroup
     */
    bool IsLeq(double val) const;

    /** 
     *  \brief Verifica si cada elemento de la matriz es menor igual a cada elemento de la matriz B.
     * 
   \f[
\mathbf{A}~<=~\mathbf{B}
   \f]
     *  \param[in] B Matriz a comparar.
     *  \return Retorna true si todos los elementos son menores y false si no.
     *  \ingroup MatrixGroup
     */
    bool IsLeq(const Pds::Matrix &B) const;

    /** 
     *  \brief Verifica si cada elemento de la matriz es mayor a el valor val.
     * 
   \f[
\mathbf{A}~>=~val
   \f]
     *  \param[in] val El valor a comparar.
     *  \return Retorna true si todos los elementos son mayores que val y false si no.
     *  \ingroup MatrixGroup
     */
    bool IsGeq(double val) const;
    
    /** 
     *  \brief Verifica si cada elemento de la matriz es mayor igual a cada elemento de la matriz B.
     * 
   \f[
\mathbf{A}~>=~\mathbf{B}
   \f]
     *  \param[in] B Matriz a comparar.
     *  \return Retorna true si todos los elementos son mayores y false si no.
     *  \ingroup MatrixGroup
     */
    bool IsGeq(const Pds::Matrix &B) const;

    /** 
     *  \brief Verifica si cada elemento de la matriz es igual a el valor val.
     * 
   \f[
\mathbf{A}~==~val
   \f]
     *  \param[in] val El valor a comparar.
     *  \return Retorna true si todos los elementos son iguale a val y false si no.
     *  \ingroup MatrixGroup
     */
    bool IsEqualTo(double val) const;
    
    /** 
     *  \brief Verifica si cada elemento de la matriz es igual a cada elemento de la matriz B.
     * 
   \f[
\mathbf{A}~==~\mathbf{B}
   \f]
     *  \param[in] B Matriz a comparar.
     *  \return Retorna true si todos los elementos son iguales y false si no.
     *  \ingroup MatrixGroup
     */
    bool IsEqualTo(const Pds::Matrix &B) const;

    /** 
     *  \brief Verifica si la matriz tiene algun valor infinito.
     * 
     * Los valores infinitos pueden producirse con \f$+\frac{1}{0},-\frac{1}{0} y \frac{1}{0}\f$.
   \f[
true\qquad \overleftarrow{HasInf()}\qquad \left(\begin{matrix}
1 & NaN & NaN\\ 
0 & 2 & -\infty\\
\infty & 0 & 0\\ 
3 & -\infty & NaN\\
\end{matrix}\right)
   \f]
     *  \return Retorna true si tiene algun elemento infinito y false si no lo tiene.
     *  \ingroup MatrixGroup
     */
    bool HasInf(void) const;
    
    /** 
     *  \brief Verifica si la matriz tiene algun valor NAN (Not A Number).
     * 
     *  Los valores NAN pueden producirse con \f$\frac{0}{0}\f$.
   \f[
true\qquad \overleftarrow{EqualToNan()}\qquad \left(\begin{matrix}
1 & NaN & NaN\\ 
0 & 2 &  -\infty\\
\infty & 0 & 0\\ 
3 & -\infty & NaN\\
\end{matrix}\right)
   \f]
     *  \return Retorna true si tiene NAN y false si no lo tiene.
     *  \ingroup MatrixGroup
     */
    bool HasNan(void) const;
    

    /** 
     *  \brief Verifica si la matriz tiene elementos no finitos (+inf, -inf y  NAN).
     * 
   \f[
true\qquad \overleftarrow{EqualToFinite()}\qquad \left(\begin{matrix}
1 & NaN & NaN\\ 
0 & 2 & -\infty\\
\infty & 0 & 0\\ 
3 & -\infty & NaN\\
\end{matrix}\right)
   \f]
     *  \return Retorna true si tiene un valor no finito y false si no lo tiene.
     *  \ingroup MatrixGroup
     */
    bool HasNotFinite(void) const;


/**
 * @}
 */

public:

/** @name Métodos de inicialización
 *  Establecen los valores de las matrices.
 * @{
 */
    /** 
     *  \brief Inicializa la matriz con números aleatórios, distribuidos usando una distribución
     * Gaussiana normalizada con media 0 y desvío padrón 1.0.
     *  \warning La función usa internamente la función rand(), 
     *  si se desea esta puede ser aleatoriamente inicializada usando la funcíón Pds::Ra::Randomize(),
     *  de lo contrario los números pseudo aleatórios siempre seguirán la misma secuencia.
     * 
   \f[ f_{X}(x)=\frac {1}{\sqrt {2\pi }} e^{-{\frac {1}{2}}x^{2}},~~x \in R \f]
   \f[ \mathbf{A}\equiv [a_{i,j}]_{M,N} \f]
   \f[ a_{i,j}\leftarrow X_{l} \in X \f]
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool FillRandN(void);
    
    /** 
     *  \brief Inicializa la matriz con números aleatórios, distribuidos uniformemente,
     *  desde 0 a 1.0, incluyendo 0 y excluyendo 1.0.
     *  \warning La función usa internamente la función rand(), 
     *  si se desea esta puede ser aleatoriamente inicializada usando la funcíón Pds::Ra::Randomize(),
     *  de lo contrario los números pseudo aleatórios siempre seguirán la misma secuencia.
     * 
   \f[ f_{X}(x)= 1,~~0\leq x<1, x \in R \f]
   \f[ \mathbf{A}\equiv [a_{i,j}]_{M,N} \f]
   \f[ a_{i,j}\leftarrow X_{l} \in X \f]
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool FillRandU(void);

    
    /** 
     *  \brief Inicializa la matriz con números aleatórios unos y ceros,
     *  la probabilidad de 1 es p1.
     *  \warning La función usa internamente la función rand(), 
     *  si se desea esta puede ser aleatoriamente inicializada usando la funcíón Pds::Ra::Randomize(),
     *  de lo contrario los números pseudo aleatórios siempre seguirán la misma secuencia.
     * 
     *  \param[in] p1 Probabilidad de acontecer un 1.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool FillRandC(double p1);
    
    /** 
     *  \brief Inicializa la matriz con números aleatórios, distribuidos uniformemente,
     *  desde a a b, incluyendo a y b.
     *  \warning La función usa internamente la función rand(), 
     *  si se desea esta puede ser aleatoriamente inicializada usando la funcíón Pds::Ra::Randomize(),
     *  de lo contrario los números pseudo aleatórios siempre seguirán la misma secuencia.
     * 
   \f[ f_{X}(x)= 1,~~min(a,b)\leq x\leq max(a,b), x \in R \f]
   \f[ \mathbf{A}\equiv [a_{i,j}]_{M,N} \f]
   \f[ a_{i,j}\leftarrow X_{l} \in X \f]
     *  \param[in] a Valor mínimo posible.
     *  \param[in] b Valor máximo posible.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool FillRandU(int a, int b);
    
    /** 
     *  \brief Inicializa la matriz con números aleatórios, distribuidos uniformemente,
     *  desde a a b, incluyendo a y b.
     *  \warning La función usa internamente la función rand(), 
     *  si se desea esta puede ser aleatoriamente inicializada usando la funcíón Pds::Ra::Randomize(),
     *  de lo contrario los números pseudo aleatórios siempre seguirán la misma secuencia.
     * 
   \f[ f_{X}(x)= 1,~~min(a,b)\leq x\leq max(a,b), x \in R \f]
   \f[ \mathbf{A}\equiv [a_{i,j}]_{M,N} \f]
   \f[ a_{i,j}\leftarrow X_{l} \in X \f]
     *  \param[in] a Valor mínimo posible.
     *  \param[in] b Valor máximo posible.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool FillRandU(double a, double b);
    
    /** 
     *  \brief Inicializa la matriz con el valor de la posición de cada elemento.
     * 
     * En el caso de una matriz A de 4 lineas y 3 columnas:
   \f[
\mathbf{A} \leftarrow \left(\begin{matrix}
0 & 4 & 8\\ 
1 & 5 & 9\\
2 & 6 & 10\\ 
3 & 7 & 11\\
\end{matrix}\right)
   \f]
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool FillId(void );

    /** 
     *  \brief Inicializa la matriz con un valor constante.
     * 
   \f[
\mathbf{A} \leftarrow \left(\begin{matrix}
val & val & \hdots & val\\ 
val & val & \hdots & val\\
\vdots & \vdots & \vdots & \vdots \\
val & val & \hdots & val\\ 
val & val & \hdots & val\\
\end{matrix}\right)
   \f]
     *  \param[in] val El valor a ser usado.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool Fill(double val);

    /** 
     *  \brief Inicializa la matriz con un espacio linear entre begin y end.
     *  Se inicializa primero una columna ante de pasar ala siguiente.
     * 
     * En el caso de una matriz A de Nlin=4 lineas y Ncol=3 columnas:
   \f[\alpha= \frac{b-a}{Nlin~Ncol- 1}\f]
   \f[
\mathbf{A} \leftarrow \left(\begin{matrix}
a         & 4\alpha+a & 8\alpha+a\\ 
\alpha+a  & 5\alpha+a & 9\alpha+a\\
2\alpha+a & 6\alpha+a & 10\alpha+a\\ 
3\alpha+a & 7\alpha+a & 11\alpha+a\\
\end{matrix}\right)
   \f]
     *  \param[in] a El valor inicial.
     *  \param[in] b El valor final.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool FillLinSpace(double a,double b);
/**
 * @}
 */

public:

/** @name Métodos de tamaño
 *  Herramientas genéricas para lectura y escritura de datos.
 * @{
 */
    
    /** 
     *  \brief Retorna el numero de lineas de la matriz.
     *  \return Retorna el numero de lineas de la matriz.
     *  \ingroup MatrixGroup
     */
    unsigned int Nlin(void) const;
    
    /** 
     *  \brief Retorna el numero de columnas de la matriz.
     *  \return Retorna el numero de columnas de la matriz.
     *  \ingroup MatrixGroup
     */
    unsigned int Ncol(void) const;
    
    /** 
     *  \brief Retorna el numero de elementos de la matriz (Nlin x Ncol).
     *  \return Retorna el numero de elementos de la matriz.
     *  \ingroup MatrixGroup
     */
    unsigned int Nel(void) const;
    
    /** 
     *  \brief Retorna un objeto de tipo Pds::Size con el numero de lineas y columans.
     *  \return Retorna el tamano de la matriz.
     *  \ingroup MatrixGroup
     */
    Pds::Size Size(void) const;
    
    /** 
     *  \brief Retorna el identificador de la ultima linea de la matriz.
     *  \return Retorna Nlin-1.
     *  \ingroup MatrixGroup
     */
    unsigned int LinEnd(void) const;
    
    /** 
     *  \brief Retorna el identificador de la ultima columna  de la matriz.
     *  \return Retorna Ncol-1.
     *  \ingroup MatrixGroup
     */
    unsigned int ColEnd(void) const;
    
    /** 
     *  \brief Retorna el identificador del ultimo elemento de la matriz.
     *  \return Retorna ((Nlin x Ncol)-1).
     *  \ingroup MatrixGroup
     */
    unsigned int End(void) const;


/**
 * @}
 */

public:

/** @name Métodos get y set de elementos
 *  Herramientas genéricas para lectura y escritura de datos.
 * @{
 */
    

    
    /** 
     *  \brief Retorna el valor en la posición del índice id, hace una verificación
     *  si la posición existe. 
     *  \param[in] id índice de un elemento de la matriz.
     *  \return Retorna el valor en la posición (id\%Nlin,id/Nlin) o cero si la 
     *  posición no existe.
     *  \ingroup MatrixGroup
     */
    double Get(unsigned int id) const;
    
    /** 
     *  \brief Retorna el valor en la posición (lin,col), hace una verificación
     *  si la posición existe. 
     *  \param[in] lin La linea en consulta.
     *  \param[in] col La columna en consulta.
     *  \return Retorna el valor en la posición (lin,col) o cero si la 
     *  posición no existe.
     *  \ingroup MatrixGroup
     */
    double Get(unsigned int lin,unsigned int col) const;
    
    /** 
     *  \brief Escribe el valor en la posición del índice id, hace una verificación
     *  si la posición existe. 
     *  \param[in] val valor a escribir.
     *  \param[in] id índice de un elemento de la matriz.
     *  \return Retorna true si consiguió escribir el valor en la 
     *  posición (id\%Nlin,id/Nlin) o false si no.
     *  \ingroup MatrixGroup
     */
    bool Set(unsigned int id,double val);
    
    /** 
     *  \brief Escribe el valor en la posición (lin,col), hace una verificación
     *  si la posición existe. 
     *  \param[in] val valor a escribir.
     *  \param[in] lin La linea en consulta.
     *  \param[in] col La columna en consulta.
     *  \return Retorna true si consiguió escribir el valor en la 
     *  posicion (lin,col) o false si no.
     *  \ingroup MatrixGroup
     */
    bool Set(unsigned int lin,unsigned int col,double val);
    
    /** 
     *  \brief Retorna una variable double en la posición (lin,col) de la matriz. 
     *  Hace una verificación para evitar leer o escribir fuera de la memoria, 
     *  con este fin hace lin=lin%Nlin y col=col%Ncol. 
     *  \param[in] lin La linea en consulta.
     *  \param[in] col La columna en consulta.
     *  \return Retorna una variable double en la posición (lin,col). 
     *  \ingroup MatrixGroup
     */
    double &At(unsigned int lin,unsigned int col);

    /** 
     *  \brief Retorna una variable double en la posición (id) de la matriz. 
     *  Hace una verificación para evitar leer o escribir fuera de la memoria, 
     *  con este fin hace id=id%(Nlin*Ncol). 
     *  \param[in] id La posicion en consulta.
     *  \return Retorna una variable double en la posición (id). 
     *  \ingroup MatrixGroup
     */
    double &At(unsigned int id);
    
    
    /** 
     *  \brief Retorna el valor en la posición (lin,col),  usando una
     *  interpolación bilinear, valores fuera del rango de la matriz retornan cero.
     *  \image html Bilinear.png "Matrix A"
     *
     *  \f[ A(P) \leftarrow (1-\beta)(1-\alpha)A(P_1)+(1-\beta)\alpha A(P_2)+\beta(1-\alpha)A(P_3)+ \beta \alpha A(P_4)\f]
     *  \param[in] lin La linea en consulta.
     *  \param[in] col La columna en consulta.
     *  \return Retorna el valor en la posición P=(lin,col) o cero si lin<0
     *  o col<0 o lin>(Nlin-1) o col>(Ncol-1).
     *  \ingroup MatrixGroup
     */
    double Bilinear(double lin,double col) const;
    
/**
 * @}
 */

public:

/** @name Métodos get y set de matrices y vectores
 *  Herramientas genericas para lectura y escritura de datos.
 * @{
 */
 
    /** 
     *  \brief Retorna un vector columna copia de los valores de la diagonal de la matriz. 
     *  \return Retorna el vector columna en la posición (col) o un vector vacío
     *  en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Vector GetDiagonal(void) const;
    
    /** 
     *  \brief Copia un vector columna en una diagonal de la matriz. Si los 
     *  tamaños son diferentes, se interceptan las matrices y se copia 
     *  solamente en la intersección.
     *  \param[in] V El vector a copiar.
     *  \return Retorna true si la copia fue hecha 
     *  o false si hubo algún problema. En caso de retornar false no se modifica la matriz.
     *  \ingroup MatrixGroup
     */
    bool SetDiagonal(const Pds::Vector V);


    /** 
     *  \brief Retorna una sub matriz desde la posición (lin_init,col_init) hasta (lin_end,col_end), inclusive. 
     *  Hace una verificación si la posición existe, si no existe llena con ceros. 
     *  \param[in] lin_init La linea inicial en consulta.
     *  \param[in] col_init La columna inicial en consulta.
     *  \param[in] lin_end La linea final en consulta.
     *  \param[in] col_end La columna final en consulta.
     *  \return Retorna una sub matriz. Si no existe interseccion entre 
     * la matriz y las cordenadas pedidas, entonces se retorna una matriz vacia.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix GetMatrix(unsigned int lin_init,unsigned int col_init,unsigned int lin_end,unsigned int col_end) const;
    
    /** 
     *  \brief Retorna una sub matriz desde la posición (lin_init,col_init) hasta (lin_end,col_end), inclusive. 
     *  Hace una verificación si la posición existe, si no existe llena con ceros. 
     *  \param[in] lin_init La linea inicial en consulta.
     *  \param[in] col_init La columna inicial en consulta.
     *  \param[in] size Tamaño de la matriz a recibir.
     *  \return Retorna una sub matriz. Si no existe interseccion entre 
     * la matriz y las cordenadas pedidas, entonces se retorna una matriz vacia.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix GetMatrix(unsigned int lin_init,unsigned int col_init,Pds::Size size) const;
    
    /** 
     *  \brief Copia en si mismo (A) en la posicion (lin,col), el contenido de una matriz B.
     * Si a matriz B no cabe em A se retorna false.
     * 
     *  \param[in] lin Linea donde se inicia a copia.
     *  \param[in] col Columna donde se inicia a copia.
     *  \param[in] B la matriz a copiar
     *  \return Retorna true si todo fue bien o false si no. Si se retorna false
     *  no se copia nada. Si IsEmpty() iguala true retorna false.
     *  \ingroup MatrixGroup
     */
    bool SetMatrix(unsigned int lin,unsigned int col,const Pds::Matrix &B);

    
    /** 
     *  \brief Retorna una matriz linea escojida en la linea lin. 
     *  Hace una verificación si la linea existe, si no existe devuelve una matriz vacia. 
     *  \param[in] lin La linea en consulta.
     *  \return Retorna una matriz linea. Si no existe la linea, entonces se retorna una matriz vacia.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix GetRow(unsigned int lin) const;
    
    /** 
     *  \brief Retorna una matriz columna escojida en la columna col. 
     *  Hace una verificación si la columna existe, si no existe devuelve una matriz vacia. 
     *  \param[in] col La columna en consulta.
     *  \return Retorna una matriz columna. Si no existe la columna, entonces se retorna una matriz vacia.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix GetCol(unsigned int col) const;
    
    /** 
     *  \brief Retorna una sub matriz escojida desde la linea lin_init hasta lin_end, inclusive. 
     *  Hace una verificación si la linea existe, si no existe llena esta con ceros. 
     *  \param[in] lin_init La linea inicial en consulta.
     *  \param[in] lin_end  La linea final en consulta.
     *  \return Retorna una sub matriz. Si no existe interseccion entre 
     *  la matriz y las lineas pedidas, entonces se retorna una matriz vacia.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix GetRows(unsigned int lin_init,unsigned int lin_end) const;
    
    /** 
     *  \brief Retorna una sub matriz escojida desde la columna col_init hasta col_end, inclusive. 
     *  Hace una verificación si la columna existe, si no existe llena esta con ceros. 
     *  \param[in] col_init La columna inicial en consulta.
     *  \param[in] col_end  La columna final en consulta.
     *  \return Retorna una sub matriz. Si no existe interseccion entre 
     *  la matriz y las columnas pedidas, entonces se retorna una matriz vacia.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix GetCols(unsigned int col_init,unsigned int col_end) const;
    
    /** 
     *  \brief Retorna una sub matriz escojida desde una lista de indices de lineas. 
     *  Hace una verificación si los indices existen, si alguno no existe devuelve una matriz vacia. 
     *  \param[in] List La lista de indices de lineas.
     *  \return Retorna una sub matriz. Si no existe algun elemento en la lista se devuelve una matriz vacia.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix GetRows(std::list<unsigned int> List) const;
    
    /** 
     *  \brief Retorna una sub matriz escojida desde una lista de indices de columnas. 
     *  Hace una verificación si los indices existen, si alguno no existe devuelve una matriz vacia. 
     *  \param[in] List La lista de indices de columnas.
     *  \return Retorna una sub matriz. Si no existe algun elemento en la lista se devuelve una matriz vacia.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix GetCols(std::list<unsigned int> List) const;
    
    /** 
     *  \brief Retorna una sub matriz escojiendo N lineas aleatoriamente (sin repetición). 
     *  \warning La función usa internamente la función rand(), 
     *  si se desea esta puede ser aleatoriamente inicializada usando la funcíón Pds::Ra::Randomize(),
     *  de lo contrario los números pseudo aleatórios siempre seguirán la misma secuencia.
     *  \param[in] N El número de lineas a escojer.
     *  \return Retorna una sub matriz. Si N=0 o N>Nlin entonces se retorna una matriz vacia.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix GetRowsRand(unsigned int N) const;
    
    /** 
     *  \brief Retorna una sub matriz escojiendo N columnas aleatoriamente (sin repetición).
     *  \warning La función usa internamente la función rand(), 
     *  si se desea esta puede ser aleatoriamente inicializada usando la funcíón Pds::Ra::Randomize(),
     *  de lo contrario los números pseudo aleatórios siempre seguirán la misma secuencia. 
     *  \param[in] N El número de columnas a escojer.
     *  \return Retorna una sub matriz. Si N=0 o N>Ncol entonces se retorna una matriz vacia.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix GetColsRand(unsigned int N) const;
    
    /** 
     *  \brief Copia un valor en una linea de la matriz.
     *  \param[in] value El valor a copiar.
     *  \param[in] lin La linea en consulta.
     *  \return Retorna true si la copia fue hecha y la posición (lin) existe
     *  o false si hubo algún problema. En caso de retornar false no se modifica la matriz.
     *  \ingroup MatrixGroup
     */
    bool SetRowValue(unsigned int lin,double value);
    
    /** 
     *  \brief Copia un valor en una columna de la matriz.
     *  \param[in] value El valor a copiar.
     *  \param[in] col La columna en consulta.
     *  \return Retorna true si la copia fue hecha y la posición (col) existe
     *  o false si hubo algún problema. En caso de retornar false no se modifica la matriz.
     *  \ingroup MatrixGroup
     */
    bool SetColValue(unsigned int col,double value);
    
    /** 
     *  \brief Retorna un vector columna copia de una linea de la matriz. 
     *  \param[in] lin La linea en consulta.
     *  \return Retorna un vector columna correspondiente a la linea (lin) o un vector vacío si la 
     *  posición no existe.
     *  \ingroup MatrixGroup
     */
    Pds::Vector GetRowAsColVector(unsigned int lin) const;

    
    /** 
     *  \brief Retorna un vector columna copia de una columna de la matriz. 
     *  \param[in] col La columna en consulta.
     *  \return Retorna el vector columna en la posición (col) o un vector vacío si la 
     *  posición no existe.
     *  \ingroup MatrixGroup
     */
    Pds::Vector GetColVector(unsigned int col) const;
    
    /** 
     *  \brief Copia un vector columna en una columna de la matriz. Si los 
     *  tamaños son diferentes, se interceptan las matrices y se copia 
     *  solamente en la intersección.
     *  \param[in] V El vector a copiar.
     *  \param[in] col La columna en consulta.
     *  \return Retorna true si la copia fue hecha y la posición (col) existe
     *  o false si hubo algún problema. En caso de retornar false no se modifica la matriz.
     *  \ingroup MatrixGroup
     */
    bool SetColVector(unsigned int col,const Pds::Vector V);
    
    /** 
     *  \brief Copia un vector columna en una columna de la matriz, despues
     *  de evaluar el vector en una funcion. Si los 
     *  tamaños son diferentes, se interceptan las matrices y se copia 
     *  solamente en la intersección.
     *  \param[in] func funcion a evaluar.
     *  \param[in] V El vector a evaluar y copiar.
     *  \param[in] col La columna en consulta.
     *  \return Retorna true si la copia fue hecha y la posición (col) existe
     *  o false si hubo algún problema. En caso de retornar false no se modifica la matriz.
     *  \ingroup MatrixGroup
     */
    bool SetColVector(unsigned int col,double (*func)(double),const Pds::Vector V);
    
    /** 
     *  \brief Copia un vector columna en una columna de la matriz, despues
     *  de evaluar el vector en una funcion. Si los 
     *  tamaños son diferentes, se interceptan las matrices y se copia 
     *  solamente en la intersección.
     *  \param[in] func funcion a evaluar.
     *  \param[in] V El vector a evaluar y copiar.
     *  \param[in] var Segunda variable a evaluar.
     *  \param[in] col La columna en consulta.
     *  \return Retorna true si la copia fue hecha y la posición (col) existe
     *  o false si hubo algún problema. En caso de retornar false no se modifica la matriz.
     *  \ingroup MatrixGroup
     */
    bool SetColVector(unsigned int col,double (*func)(double,double),const Pds::Vector V,double var);

/**
 * @}
 */


public:

/** @name Métodos de opreaciones sobre las lineas de la matriz
 *  operaciones con lineas
 * @{
 */

    /** 
     *  \brief Multiplica los valores de la linea lin2 por alfa y el 
     *  resultado es sumado a los valores de la linea lin1.
     * 
     *  \f[ row[lin1] \leftarrow row[lin1]+\alpha ~ row[lin2] \f]
     *  \param[in] lin1 Lineas a intercambiar.
     *  \param[in] lin2 Lineas a intercambiar.
     *  \param[in] alpha Factor multiplicador.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool RowAddAssig(unsigned int lin1,unsigned int lin2,double alpha);
    
    /** 
     *  \brief Multiplica la linea lin por alpha
     * 
     *  \f[ row[lin] \leftarrow \alpha ~ row[lin] \f]
     *  \param[in] lin Linea a multiplicar.
     *  \param[in] alpha Factor multiplicador.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool RowMulAssig(unsigned int lin,double alpha);
    
    /** 
     *  \brief Divide la linea lin por alpha
     * 
     *  \f[ row[lin] \leftarrow  row[lin]/\alpha \f]
     *  \param[in] lin Linea a dividir.
     *  \param[in] alpha Factor multiplicador.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool RowDivAssig(unsigned int lin,double alpha);
    
    /** 
     *  \brief Intercambia los valores de las lineas de una matriz.
     *  \param[in] lin1 Lineas a intercambiar.
     *  \param[in] lin2 Lineas a intercambiar.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool RowSwap(unsigned int lin1,unsigned int lin2);
    
    /** 
     *  \brief Si el n-avo elemento de la diagonal es cero entonces intercambia 
     *  la linea n de la matriz con cualquier linea inferior con elemento 
     *  diferente de cero en la columna n.
     *  \param[in] n Linea a intercambiar.
     *  \return Retorna el numero de la fila con quien intercambio o -1
     *  en caso de error. Si el n-avo 
     *  elemento de la diagonal ja es diferente de cero no se hace nada y
     *  se retorna n.
     *  \ingroup MatrixGroup
     */
    int RowSwapBelow(unsigned int n);
    
    /** 
     *  \brief Convierte la matriz en una matriz reducida.
     * 
     *  \return Retorna true si todo fue bien o false si no.
     * Si retorna false la matriz es modificada hasta donde consiguió 
     * avanzar el proceso de reducción.
     *  \ingroup MatrixGroup
     */
    bool RowReduction(void);
/**
 * @}
 */


public:

/** @name Métodos estadísticos
 *  Herramientas genéricas
 * @{
 */
    /** 
     *  \brief Calcula el valor de la suma de elementos de la matriz.
     *
     *  \return Retorna el valor de la suma de elementos de la matriz. En caso de que la matriz sea vacía
     *  se retorna Pds::Ra::Nan.
     *  \ingroup MatrixGroup
     */
    double Sum(void) const;
      
    /** 
     *  \brief Calcula el valor medio de la matriz.
     *
     *  \return Retorna el valor medio de la matriz. En caso de que la matriz sea vacía
     *  se retorna Pds::Ra::Nan.
     *  \ingroup MatrixGroup
     */
    double Mean(void) const;
    
    /** 
     *  \brief Calcula el valor de la varianza de la matriz.
     *
     *  \return Retorna el valor de la varianza de la matriz. En caso de que la matriz sea vacía
     *  se retorna Pds::Ra::Nan.
     *  \ingroup MatrixGroup
     */
    double Var(double *mean=NULL) const;
    
    /** 
     *  \brief Calcula el valor del desvío padrón de la matriz.
     *
     *  \return Retorna el valor del desvío padrón de la matriz. En caso de que la matriz sea vacía
     *  se retorna Pds::Ra::Nan.
     *  \ingroup MatrixGroup
     */
    double Std(double *mean=NULL) const;

    
    /** 
     *  \brief Calcula el máximo valor del valor absoluto de la matriz.
     *
     *  \param[in] id Se retorna el id do valor máximo.
     *  \return Retorna el máximo valor del valor absoluto de la matriz. En caso de que la matriz sea vacía
     *  se retorna Pds::Ra::Nan.
     *  \ingroup MatrixGroup
     */
    double MaxAbs(unsigned int *id=NULL) const;
    
    /** 
     *  \brief Calcula el mínimo valor del valor absoluto de la matriz.
     *
     *  \param[in] id Se retorna el id do valor mínimo.
     *  \return Retorna el mínimo valor del valor absoluto de la matriz. En caso de que la matriz sea vacía
     *  se retorna Pds::Ra::Nan.
     *  \ingroup MatrixGroup
     */
    double MinAbs(unsigned int *id=NULL) const;
    
    /** 
     *  \brief Calcula el máximo valor de la matriz.
     *
     *  \param[in] id Se retorna el id do valor máximo.
     *  \return Retorna el máximo valor de la matriz. En caso de que la matriz sea vacía
     *  se retorna Pds::Ra::Nan.
     *  \ingroup MatrixGroup
     */
    double Max(unsigned int *id=NULL) const;
    
    /** 
     *  \brief Calcula el mínimo valor de la matriz.
     *
     *  \param[in] id Se retorna el id do valor mínimo.
     *  \return Retorna el mínimo valor de la matriz. En caso de que la matriz sea vacía
     *  se retorna Pds::Ra::Nan.
     *  \ingroup MatrixGroup
     */
    double Min(unsigned int *id=NULL) const;
    
    /** 
     *  \brief Calcula el coeficiente de determinación o \f$R^2\f$.
     *
     *  \f[ R^2\equiv A.R2(Y)\quad =\quad 1-\frac{\sigma_r^2}{\sigma^2}\quad =\quad 1-\frac{\frac{1}{L}|| \mathbf{A}_{ij}-\mathbf{Y}_{ij}||^2}{Var(\mathbf{A})}\f]
     *  \f[-\infty < R^2 < 1\f]
     *  Varianza \f$\sigma^2\f$, varianza residual \f$\sigma_r^2\f$.
     *  \return Retorna el coeficiente de determinación entre A e Y. En caso de que la matriz sea vacía
     *  se retorna Pds::Ra::Nan.
     *  \ingroup MatrixGroup
     */
    double R2(const Pds::Matrix &Y) const;

    /** 
     *  \brief Calcula o \f$RF\f$.
     *
     *  \f[ Rf\equiv A.Rf(Y)\quad =\quad \frac{\sigma_r}{\sigma}\f]
     *  \f[ Rf\equiv A.Rf(Y)\quad =\quad \frac{\sqrt{\frac{1}{L}|| \mathbf{A}_{ij}-\mathbf{Y}_{ij}||^2}}{Std(\mathbf{A})}\f]
     *  \f[0 < Rf < \infty\f]
     *  Varianza \f$\sigma^2\f$, varianza residual \f$\sigma_r^2\f$.
     *  \return RetornaRF entre A e Y. En caso de que la matriz sea vacía
     *  se retorna Pds::Ra::Nan.
     *  \ingroup MatrixGroup
     */
    double Rf(const Pds::Matrix &Y) const;
    
    /** 
     *  \brief Calcula el error absoluto medio porcentual (Mean Absolute Percentage Error) de una matriz.
     *
     *  \f[ A.Mape()=\frac{100}{N_{total}}\sum \limits_{i} \sum \limits_{j} \left|\frac{a_{ij}-b_{ij}}{a_{ij}}\right| \f]
     *  \f$N_{total}\f$ es el número de elementos no cero en \f$\mathbf{A}\f$.
     *  Solo son sumados elementos no cero en \f$\mathbf{A}\f$.
     *  \return Retorna el error absoluto medio porcentual. En caso de que la matriz sea vacía
     *  se retorna Pds::Ra::Nan.
     *  \ingroup MatrixGroup
     */
    double Mape(const Pds::Matrix &B) const;
/**
 * @}
 */


public:

/** @name Métodos Digital Signal Processing
 *  Herramientas genéricas
 * @{
 */
    /** 
     *  \brief Calcula la correlación de Pearson con la matriz.
     *
     *  \return Retorna el valor de la correlación. En caso de que la matriz sea vacía
     *  se retorna Pds::Ra::Nan.
     *  \ingroup MatrixGroup
     */
    double Corr(const Pds::Matrix &B) const;
    
    /** 
     *  \brief Calcula la correlacion cruzada entre A y B. 
     * 
     * \f[ \mathbf{A}\equiv [a_{i,j}]  \overset{func}{\equiv} a(i,j),\qquad 0 \leq i< Nlin,\qquad 0 \leq j< Ncol \f]
     * \f[ \mathbf{B}\equiv [b_{i,j}]  \overset{func}{\equiv} b(i,j),\qquad 0 \leq i< Mlin,\qquad 0 \leq j< Mcol \f]
     * \f[ \mathbf{C}\equiv [c_{i,j}]  \overset{func}{\equiv} c(i-(Mlin-1),j-(Mcol-1)),\qquad 0 \leq i < Mlin+Nlin-1 ,\qquad  0 \leq j < Mcol+Ncol-1\f]
   \f[
\mathbf{C}=\left(\begin{matrix}
c(1-Mlin,1-Mcol)     & c(1-Mlin,2-Mcol)  & \hdots & c(1-Mlin,0)  & \hdots & c(1-Mlin,Ncol-1)\\ 
c(2-Mlin,1-Mcol)     & c(2-Mlin,2-Mcol)  & \hdots & c(2-Mlin,0)  & \hdots & c(2-Mlin,Ncol-1)\\
\vdots               & \vdots            & \vdots & \vdots       & \vdots & \vdots \\
c(0,1-Mcol)          & c(0,2-Mcol)       & \hdots & c(0,0)       & \hdots & c(0,Ncol-1)\\
\vdots               & \vdots            & \vdots & \vdots       & \vdots & \vdots \\
c(Nlin-2,1-Mcol)     & c(Nlin-2,2-Mcol)  & \hdots & c(Nlin-2,0)  & \hdots & c(Nlin-2,Ncol-1) \\ 
c(Nlin-1,1-Mcol)     & c(Nlin-1,2-Mcol)  & \hdots & c(Nlin-1,0)  & \hdots & c(Nlin-1,Ncol-1) \\
\end{matrix}\right) 
   \f] 
     *  De modo que
     * \f[ c(k,l) \leftarrow \sum \limits_{q=-\infty}^{+\infty} \sum \limits_{r=-\infty}^{+\infty} a(q,r) b(q-k,r-l) \f]
     * \f[ c(k,l) \leftarrow \sum \limits_{q=max(0,k)}^{min(Nlin-1,Mlin-1+k)}~~ \sum \limits_{r=max(0,l)}^{min(Ncol-1,Mcol-1+l)} a(q,r) b(q-k,r-l) \f]
     *  Esta funcion no usa FFT para economizar el tiempo.
     * 
     *  \param[in] B Matriz a aplicar la correlacion cruzada.
     *  \param[in] Same indica si la correlación cruzada tendrá el mismo 
     *  tamaño que A, si Same es igual a true entonces,\f$[c_{i,j}]  \overset{func}{\equiv} c(i,j), ~0 \leq i \leq Nlin-1, ~0 \leq j \leq Ncol-1\f$.
     *  Por defecto Same es igual a false.
     * \return retorna la correlacion cruzada.
     *  \ingroup VectorGroup
     */
    Pds::Matrix XCorr(const Pds::Matrix &B, bool Same=false) const;
/**
 * @}
 */


public:

/** @name Métodos de álgebra lineal
 *  Herramientas genéricas
 * @{
 */
    
    /** 
     *  \brief Calcula la determinante.
     *
     *  \f[ A.Det() = |A| \f]
     *  \return Retorna la determinante de un vector. En caso de que la matriz sea vacía
     *  se retorna Pds::Ra::Nan.
     *  \ingroup MatrixGroup
     */
    double Det(void) const;
    
    /** 
     *  \brief Calcula el producto punto entre dos matrices.
     *
     *  \f[ A.Dot(B) = \sum \limits_{i,j} a_{i,j}b_{i,j} \f]
     *  \param[in] B Matriz a multiplicar.
     *  \return Retorna el producto punto. En caso de que la matriz sea vacía
     *  se retorna Pds::Ra::Nan.
     *  \ingroup MatrixGroup
     */
    double Dot(const Pds::Matrix &B) const;
   
    /** 
     *  \brief Calcula valor raiz quadrático medio de una matriz.
     *
     *  \f[ A.Rms()=\sqrt{\frac{1}{Nlin~Ncol}\sum \limits_{i}^{Nlin} \sum \limits_{j}^{Ncol} {|a_{ij}|}^2} \f]
     *  \return Retorna el valor raiz cuadrático medio. En caso de que la matriz sea vacía
     *  se retorna Pds::Ra::Nan.
     *  \ingroup MatrixGroup
     */
    double Rms(void) const;


    /** 
     *  \brief Calcula valor absoluto medio de una matriz.
     *
     *  \f[ A.MeanAbsolute()=\frac{1}{Nlin~Ncol}\sum \limits_{i}^{Nlin} \sum \limits_{j}^{Ncol} {|a_{ij}|} \f]
     *  \return Retorna el valor absoluto medio. En caso de que la matriz sea vacía
     *  se retorna Pds::Ra::Nan.
     *  \ingroup MatrixGroup
     */
    double MeanAbsolute(void) const;
 
    /** 
     *  \brief Calcula valor quadrático medio de una matriz.
     *
     *  \f[ A.MeanSquare()=\frac{1}{Nlin~Ncol}\sum \limits_{i}^{Nlin} \sum \limits_{j}^{Ncol} {|a_{ij}|}^2 \f]
     *  \return Retorna el valor cuadrático medio. En caso de que la matriz sea vacía
     *  se retorna Pds::Ra::Nan.
     *  \ingroup MatrixGroup
     */
    double MeanSquare(void) const;

    /** 
     *  \brief Calcula valor de la suma quadrática de una matriz.
     *
     *  \f[ A.SumSquare()=\sum \limits_{i} \sum \limits_{j} {|a_{ij}|}^2 \f]
     *  \return Retorna la suma cuadrática. En caso de que la matriz sea vacía
     *  se retorna Pds::Ra::Nan.
     *  \ingroup MatrixGroup
     */
    double SumSquare(void) const;

    /** 
     *  \brief Calcula la 2-norm de una matriz (Frobenius norm).
     *
     *  \f[ ||A||_2=\sqrt{\sum \limits_{i} \sum \limits_{j} {|a_{ij}|}^2} \f]
     *  \return Retorna la norma de un vector. En caso de que la matriz sea vacía
     *  se retorna Pds::Ra::Nan.
     *  \ingroup MatrixGroup
     */
    double Norm(void) const;

    
    /** 
     *  \brief Calcula la 1-norm de un vector.
     *
     *  \f[ ||A||_1=\max \limits_{j} \sum \limits_{i} {|a_{ij}|} \f]
     *  \return Retorna la norma de un vector. En caso de que la matriz sea vacía
     *  se retorna Pds::Ra::Nan.
     *  \ingroup MatrixGroup
     */
    double PNorm1(void) const;

    
    /** 
     *  \brief Calcula la inf-norm de una matriz.
     *
     *  \f[ ||A||_{\infty}=\max \limits_{i} \sum \limits_{j} {|a_{ij}|} \f]
     *  \return Retorna la norma de un vector. En caso de que la matriz sea vacía
     *  se retorna Pds::Ra::Nan.
     *  \ingroup MatrixGroup
     */
    double PNormInf(void) const;

    /** 
     *  \brief Dada una matriz 
     *  \f$\mathbf{X}=\left[\mathbf{x}_1,\quad \mathbf{x}_2,\quad ...,\quad \mathbf{x}_n,\quad ...,\quad \mathbf{x}_N\right]\f$
     *  es calculado el vector 
     *  \f$\mathbf{\overline{X}}^{\mathbf{d}}\f$.
\f[\mathbf{\overline{X}}^{\mathbf{d}}\equiv \mathbf{x}_1^{d_1} \mathbf{x}_2^{d_2} \mathbf{x}_3^{d_3} ... \mathbf{x}_N^{d_N}\f]
     *  \param[in] d Vector de indices \f$\mathbf{d}=\left[d_1,\quad d_2,\quad ...,\quad d_n,\quad ...,\quad d_N\right]\f$.
     *  \return Retorna el vector \f$\mathbf{\overline{X}}^{\mathbf{d}}\f$. En caso de error
     *  se retorna una matriz vazia.
     *  \ingroup MatrixGroup
     */
    Pds::Vector Multiindex(const Pds::Vector &d) const;
/**
 * @}
 */


public:

/** @name Métodos para find
 *  Herramientas genéricas
 * @{
 */


    /** 
     *  \brief Retorna una lista de indices donde existe un 1 en la matriz A.
     *
     *  \return Retorna  una lista de indices donde existe un 1 en la matriz A.
     *  \ingroup MatrixGroup
     */
    std::list<unsigned int> Find(void) const;


/**
 * @}
 */


public:

/** @name Métodos para aplicar operaciones
 *  Herramientas genéricas
 * @{
 */


    /** 
     *  \brief Aplica la función func a cada elemento de la matriz.
     * \param[in] func Función a aplicar, esta debe tener a forma double func(double).
     * \return true si todo fue bien o false si la matriz era vacia.
     *  \ingroup MatrixGroup
     */
    bool Apply( double (*func)(double) );

    /** 
     *  \brief Aplica la función func a cada elemento de la matriz.
     * \param[in] func Función a aplicar, esta debe tener a forma double func(double,double).
     * \param[in] var Variable a usar em func(double,var).
     * \return true si todo fue bien o false si la matriz era vacia.
     *  \ingroup MatrixGroup
     */
    bool Apply( double (*func)(double,double), double var);

    /** 
     *  \brief Aplica la función func a cada elemento de la columna col  de la matriz.
     * \param[in] col Columna a aplicar la función.
     * \param[in] func Función a aplicar, esta debe tener a forma double func(double).
     * \return true si todo fue bien o false si la matriz era vacia.
     *  \ingroup MatrixGroup
     */
    bool ApplyInCol(unsigned int col, double (*func)(double) );

    /** 
     *  \brief Aplica la función func a cada elemento de la columna col  de la matriz.
     * \param[in] col Columna a aplicar la función.
     * \param[in] func Función a aplicar, esta debe tener a forma double func(double,double).
     * \param[in] var Variable a usar em func(double,var).
     * \return true si todo fue bien o false si la matriz era vacia.
     *  \ingroup MatrixGroup
     */
    bool ApplyInCol(unsigned int col, double (*func)(double,double), double var);

    /** 
     *  \brief Opera la función func usando como entrada cada fila de la matriz.
     * \param[in] func Función a aplicar, esta debe tener a forma double func(const Pds::Matrix &Row).
     * \return Una matriz columna si todo fue bien o una vacia en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix OperateRows(double (*func)(const Pds::Matrix &Row)) const;

    /** 
     *  \brief Opera la función func usando como entrada cada columna de la matriz.
     * \param[in] func Función a aplicar, esta debe tener a forma double func(const Pds::Matrix &Col).
     * \return Una matriz linea si todo fue bien o una vacia en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix OperateCols(double (*func)(const Pds::Matrix &Col)) const;

/**
 * @}
 */

public:

/** @name Métodos con regiones
 *  Herramientas genéricas
 * @{
 */

    /** 
     *  \brief Copia la región Rin de la matriz a la región Rout de la matriz Mout.
     *  
     *  Ambas regiones deben estar dentro de las matrices y tener el mismo tamaño
     *  para que la copia sea realizada. 
     *
     *  \param[in] Rin Región en donde se leerán los datos.
     *  \param[in] Rout Región en donde se escribirá.
     *  \param[out] Mout La matriz donde se escribirá.
     *  \return true si las matrices existen y son copiables o false si no.
     *  \ingroup MatrixGroup
     */
    bool CopyRegion(const Pds::RegionRect &Rin,const Pds::RegionRect &Rout,Pds::Matrix &Mout) const;

    /** 
     *  \brief Inicializa la región R de la matriz con el valor val. 
     *  \param[in] R La region a inicializar.
     *  \param[in] val valor a ser usado en la inicialización.
     *  \return true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool InitRegion(Pds::RegionRect R,double val);

    /** 
     *  \brief Retorna una variable Pds::RegionRect desde la posicion (0,0), con ancho y alto (Mat.Nlin(),Mat.Ncol()).
     *  \return La region si todo fue bien, sino se retorna una region donde IsEmpty() == true.
     *  \ingroup MatrixGroup
     */
    Pds::RegionRect GetRegion(void) const;

    /** 
     *  \brief Calcula la media de los elementos en la region, pero para que sea
     *  calculado debe existir una interseccion diferente de zero con la matriz.
     *  Los valores fuera de la matriz son considerados cero.
     *
\f[ 
R=Rin\cap R_{A}
\f] 
\f[  
mean=\mu_{R}=
\frac{\sum \limits_{i\in R} Mat\{i\}}{card(R)}
\f]
     *  \param[in] Rin La region a calcular.
     *  \param[out] mean Media.
     *  \return true si todo fue bien o false si no (ej: mean==NULL). 
     *  \ingroup MatrixGroup
     */
    bool MeanOfRegion(const Pds::RegionRect &Rin, double *mean) const;

    /** 
     *  \brief Calcula la media de los elementos en la region, pero para que sea
     *  calculado debe existir una interseccion diferente de zero con la matriz.
     *  Los valores fuera de la matriz son considerados cero.
     *
\f[ 
R=Rin\cap R_{A}
\f] 
\f[  
mean=\mu_{R}=
\frac{\sum \limits_{i\in R} Mat\{i\}}{card(R)}
\f]
     *  \param[in] Rin La region a calcular.
     *  \return la media o Pds::Ra::Nan si hubo un error (ej: IsEmpty()==true). 
     *  \ingroup MatrixGroup
     */
    double MeanOfRegion(const Pds::RegionRect &Rin) const;

    /** 
     *  \brief Calcula la media del cuadrado de los elementos en la region, pero para que sea
     *  calculado debe existir una interseccion diferente de zero con la matriz.
     *  Los valores fuera de la matriz son considerados cero.
     *
\f[ 
R=Rin\cap R_{A}
\f] 
\f[  
mean=\mu_{R}=
\frac{\sum \limits_{i\in R} Mat\{i\}^2}{card(R)}
\f]
     *  \param[in] Rin La region a calcular.
     *  \param[out] mean Media.
     *  \return true si todo fue bien o false si no (ej: mean==NULL). 
     *  \ingroup MatrixGroup
     */
    bool MeanSquareOfRegion(const Pds::RegionRect &Rin, double *mean) const;

    /** 
     *  \brief Calcula la media del cuadrado de los elementos en la region, pero para que sea
     *  calculado debe existir una interseccion diferente de zero con la matriz.
     *  Los valores fuera de la matriz son considerados cero.
     *
\f[ 
R=Rin\cap R_{A}
\f] 
\f[  
mean=\mu_{R}=
\frac{\sum \limits_{i\in R} Mat\{i\}^2}{card(R)}
\f]
     *  \param[in] Rin La region a calcular.
     *  \return la media o Pds::Ra::Nan si hubo un error (ej: IsEmpty()==true). 
     *  \ingroup MatrixGroup
     */
    double MeanSquareOfRegion(const Pds::RegionRect &Rin) const;

    /** 
     *  \brief Calcula el desvío padrón y la media de los elementos de la intersección de la región con la matriz.
     *
\f[ 
R=Rin\cap R_{A}
\f] 
\f[  
mean=\mu_{R}=
\frac{\sum \limits_{i\in R} Mat\{i\}}{card(R)}, \quad 
std=\sigma_{R}=
\sqrt{\frac{\sum \limits_{i\in R} \left(Mat\{i\}-\mu_{R}\right)^2}{card(R)}}
\f]
     *  \param[in] Rin La región a calcular.
     *  \param[out] std Desvío padrón.
     *  \param[out] mean Media.
     *  \return true si todo fue bien o false si no (ej: IsEmpty()==true). 
     *  \ingroup MatrixGroup
     */
    bool StdAndMeanOfRegion(const Pds::RegionRect &Rin, double *std, double *mean) const;


    /** 
     *  \brief Calcula correlación normalizada entre los
     *  elementos de la intersección de la regiones con sus matrices. 
     *
     *  Para que la correlacion sea ejecutada se debe cumplir que \f$ Size(R_0)==Size(R_1)\f$
     *  ademas que \f$ R_0 \subset M_0 \f$ y \f$R_1 \subset M_1\f$. Con estas 
     *  condiciones obtenemos las submatrices \f$S_0\f$ y \f$S_1\f$.
\f[
S_0 \equiv {M_0}_{R_0}, \qquad S_1 \equiv {M_1}_{R_1}
\f]
\f[  CORR=\frac{E[S_0~S_1]}{\sqrt{MS\{S_0\}~MS\{S_1\}}} \f]
     *  \param[in] M1 Una matriz de la correlación.
     *  \param[in] R0 La región a analizar en la matriz M0, el tamaño de R0 debe ser igual al tamaño de R1.
     *  \param[in] R1 La región a analizar en la matriz M1, el tamaño de R0 debe ser igual al tamaño de R1.
     *  \param[out] corrn Correlación normalizada.
     *  \return true si todo fue bien o false si no (ej: pcc==NULL).
     *  Retorna false cuando algún lado de las regiones a analizar son cero.
     *  \ingroup MatrixGroup
     */
    bool CorrNormRegions(   const Pds::Matrix &M1,
                            const Pds::RegionRect &R0,
                            const Pds::RegionRect &R1, 
                            double *corrn) const;

    /** 
     *  \brief Calcula correlación normalizada entre los
     *  elementos de la intersección de la regiones con sus matrices. 
     *
     *  Para que la correlacion sea ejecutada se debe cumplir que \f$ Size(R_0)==Size(R_1)\f$
     *  ademas que \f$ R_0 \subset M_0 \f$ y \f$R_1 \subset M_1\f$. Con estas 
     *  condiciones obtenemos las submatrices \f$S_0\f$ y \f$S_1\f$.
\f[
S_0 \equiv {M_0}_{R_0}, \qquad S_1 \equiv {M_1}_{R_1}
\f]
\f[  CORR=\frac{E[S_0~S_1]}{\sqrt{MS\{S_0\}~MS\{S_1\}}} \f]
     *  \param[in] M1 Una matriz de la correlación.
     *  \param[in] R0 La región a analizar en la matriz M0, el tamaño de R0 debe ser igual al tamaño de R1.
     *  \param[in] R1 La región a analizar en la matriz M1, el tamaño de R0 debe ser igual al tamaño de R1.
     *  \param[in] means0 Valor cuadrático medio de la region R0, \f$MS\{S_0\}\f$.
     *  \param[in] means1 Valor cuadrático medio de la region R1, \f$MS\{S_1\}\f$.
     *  \param[out] corrn Correlación normalizada.
     *  \return true si todo fue bien o false si no (ej: pcc==NULL).
     *  Retorna false cuando algún lado de las regiones a analizar son cero.
     *  \ingroup MatrixGroup
     */
    bool CorrNormRegions(   const Pds::Matrix &M1,
                            const Pds::RegionRect &R0,
                            const Pds::RegionRect &R1, 
                            double means0,
                            double means1,
                            double *corrn) const;

    /** 
     *  \brief Calcula el coeficiente de correlación de Pearson (PCC) entre los
     *  elementos de la intersección de la regiones con sus matrices. 
     *
     *  Para que la correlacion sea ejecutada se debe cumplir que \f$ Size(R_0)==Size(R_1)\f$
     *  ademas que \f$ R_0 \subset M_0 \f$ y \f$R_1 \subset M_1\f$. Con estas 
     *  condiciones obtenemos las submatrices \f$S_0\f$ y \f$S_1\f$.
\f[
S_0 \equiv {M_0}_{R_0}, \qquad S_1 \equiv {M_1}_{R_1}
\f]
\f[  PCC=\frac{E[(S_0-\mu_{S_0})(S_1-\mu_{S_1})]}{\sigma_{S_0}\sigma_{S_1}} \f]
     *  Si algun desvío padrón es cero entonces existen casos especiales para el valor de PCC.
<table>
<caption id="multi_row_region1">Casos especiales para PCC</caption>
    <tr><td>PCC <td>sigma0 <td>sigma1 <td>mean0 <td>mean1
    <tr><td>0.0 <td>Zero   <td>NonZero<td>?     <td>?
    <tr><td>0.0 <td>NonZero<td>Zero   <td>?     <td>?
    <tr><td>1.0 <td>Zero   <td>Zero   <td>Positive<td>Positive
    <tr><td>1.0 <td>Zero   <td>Zero   <td>Negative<td>Negative
    <tr><td>-1.0<td>Zero   <td>Zero   <td>Positive<td>Negative
    <tr><td>-1.0<td>Zero   <td>Zero   <td>Negative<td>Positive
    <tr><td>0.0 <td>Zero   <td>Zero   <td>Zero    <td>NonZero
    <tr><td>0.0 <td>Zero   <td>Zero   <td>NonZero <td>Zero
    <tr><td>1.0 <td>Zero   <td>Zero   <td>Zero    <td>Zero
</table> 
     *  \param[in] M1 Una matriz de la correlación.
     *  \param[in] R0 La región a analizar en la matriz M0, el tamaño de R0 debe ser igual al tamaño de R1.
     *  \param[in] R1 La región a analizar en la matriz M1, el tamaño de R0 debe ser igual al tamaño de R1.
     *  \param[out] pcc Coeficiente de correlación de Pearson.
     *  \return true si todo fue bien o false si no (ej: pcc==NULL).
     *  Retorna false cuando algún lado de las regiones a analizar son cero.
     *  \ingroup MatrixGroup
     */
    bool CorrPearsonRegions(const Pds::Matrix &M1,
                            const Pds::RegionRect &R0,
                            const Pds::RegionRect &R1, 
                            double *pcc) const;

    /** 
     *  \brief Calcula el coeficiente de correlación de Pearson (PCC) entre los
     *  elementos de la intersección de la regiones con sus matrices. 
     *
     *  Para que la correlacion sea ejecutada se debe cumplir que \f$ Size(R_0)==Size(R_1)\f$
     *  ademas que \f$ R_0 \subset M_0 \f$ y \f$R_1 \subset M_1\f$. Con estas 
     *  condiciones obtenemos las submatrices \f$S_0\f$ y \f$S_1\f$.
\f[
S_0 \equiv {M_0}_{R_0}, \qquad S_1 \equiv {M_1}_{R_1}
\f]
\f[  PCC=\frac{E[(S_0-\mu_{S_0})(S_1-\mu_{S_1})]}{\sigma_{S_0}\sigma_{S_1}} \f]
     *  Si algun desvío padrón es cero entonces existen casos especiales para el valor de PCC.
<table>
<caption id="multi_row_region1b">Casos especiales para PCC</caption>
    <tr><td>PCC <td>sigma0 <td>sigma1 <td>mean0 <td>mean1
    <tr><td>0.0 <td>Zero   <td>NonZero<td>?     <td>?
    <tr><td>0.0 <td>NonZero<td>Zero   <td>?     <td>?
    <tr><td>1.0 <td>Zero   <td>Zero   <td>Positive<td>Positive
    <tr><td>1.0 <td>Zero   <td>Zero   <td>Negative<td>Negative
    <tr><td>-1.0<td>Zero   <td>Zero   <td>Positive<td>Negative
    <tr><td>-1.0<td>Zero   <td>Zero   <td>Negative<td>Positive
    <tr><td>0.0 <td>Zero   <td>Zero   <td>Zero    <td>NonZero
    <tr><td>0.0 <td>Zero   <td>Zero   <td>NonZero <td>Zero
    <tr><td>1.0 <td>Zero   <td>Zero   <td>Zero    <td>Zero
</table> 
     *  \param[in] M1 Una matriz de la correlación.
     *  \param[in] R0 La región a analizar en la matriz M0, el tamaño de R0 debe ser igual al tamaño de R1.
     *  \param[in] R1 La región a analizar en la matriz M1, el tamaño de R0 debe ser igual al tamaño de R1.
     *  \param[in] mean0 La media de la region R0.
     *  \param[in] mean1 La media de la region R1.
     *  \param[in] std0 El desvio padron de la region R0.
     *  \param[in] std1 El desvio padron de la region R1.
     *  \param[out] pcc Coeficiente de correlación de Pearson.
     *  \return true si todo fue bien o false si no (ej: pcc==NULL).
     *  Retorna false cuando algún lado de las regiones a analizar son cero.
     *  \ingroup MatrixGroup
     */
    bool CorrPearsonRegions(   const Pds::Matrix &M1,
                        const Pds::RegionRect &R0,
                        const Pds::RegionRect &R1,
                        double mean0,
                        double mean1,
                        double std0,
                        double std1,
                        double *pcc) const;
/**
 * @}
 */

public:

/** @name Métodos variados
 *  Herramientas genéricas
 * @{
 */
    /** 
     *  \brief Rescala linearmente los datos desde minval a maxval.
     * 
     *  \param[in] minval Valor menor de la escala.
     *  \param[in] maxval Valor maior de la escala.
     *  \return Retorna la matriz escalada si todo fue bien o una vacia si no.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix Scale(double minval,double maxval) const;

    /** 
     *  \brief libera los datos internos de la matriz y la convierte en una matriz nula.
     *  es decir con lineas y columnas cero.
     * 
     *  Una matriz\f$\mathbf{A}\f$ está vacía si  \f$ \mathbf{A}=[]_{0,0}\f$.
     *  \ingroup MatrixGroup
     */
    void MakeEmpty(void);
    
    /** 
     *  \brief Convierte los datos de la matriz en un std::string.
     *  \return Retorna un std::string. Si la matriz es nula retorna un string sin caracteres.
     *  \ingroup MatrixGroup
     */
    std::string ToString(void) const;


    /** 
     *  \brief Imprime en pantalla el contenido de la matriz después del
     * texto indicado en str.
     * \param str Texto a mostrar antes de imprimir.
     *  \ingroup MatrixGroup
     */
    void Print(std::string str) const;

    /** 
     *  \brief Imprime en pantalla el contenido de la matriz.
     *  \ingroup MatrixGroup
     */
    void Print(void) const;


/**
 * @}
 */


public:

/** @name Métodos para exportar e importar datos
 *  Herramientas genéricas que pueden ser usadas desde Pds::Matrix
 * @{
 */
    
    
   /** 
     *  \brief Escribe en un archivo de texto el contenido de la matriz.
     *  \param[in] filepath El archivo donde se escribirán los datos.
     *  \return Retorna true si todo fue bien o false en caso de error.
     *  \ingroup MatrixGroup
     */
    bool Save(const char* filepath) const;

   /** 
     *  \brief Lee de un archivo una matriz de Nlin lineas y Ncol columnas.
     *  Si la lectura es satisfactoria el contenido actual de la matriz es liberado,
     *  en caso de error la matriz queda vacia, esdecir .IsEmpty() retorna true.
     *  \param[in] filepath El archivo donde se leerán los datos.
     *  \return Retorna true si todo fue bien o false en caso de error.
     *  \ingroup MatrixGroup
     */
    bool Load(const char* filepath);
    
   /** 
     *  \brief Escribe en un archivo de texto el contenido de la matriz usando
     *  un formato Csv (Comma Separated Values).
     *  \param[in] filepath El archivo donde se escribirán los datos.
     *  \param[in] delimitador Delimitador separador de elementos, ',' por defecto.
     *  \return Retorna true si todo fue bien o false en caso de error.
     *  \ingroup MatrixGroup
     */
    bool ExportCsvFile(const char* filepath,char delimitador=',') const;
    
    
   /** 
     *  \brief Escribe en un archivo binario en formato de octave la matriz.
     *  Es necesario dar un nombre como identificador de matriz.
     * 
Para cargar los datos en OCTAVE se puede usar el siguiente código
\verbatim
% Load all the variables in "matfile.mat" in the workspace.
load("-v4","matfile.mat");

% Load the B variable in a STRUCTURE
STRUCTURE=load("-v4","matfile.mat","B");
\endverbatim
     *  Version 4 MAT-File Format:[Documento externo](https://www.eiscat.se/wp-content/uploads/2016/03/Version-4-MAT-File-Format.pdf)
     *  [Documento oficial](https://www.mathworks.com/help/pdf_doc/matlab/matfile_format.pdf)
     *  \param[in] pname El nombre de la matriz.
     *  \param[in] filepath El archivo donde se escribirán los datos.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool ExportMatFile(const char* pname,const char* filepath) const;

   /** 
     *  \brief Escribe en una matriz en un archivo binario en formato BMP.
     *  Losdatos deben ir de 0 a 255, valores superiores o inferiores serán truncados.
     * 
     *  \param[in] colormap Mapa de colores. Ejemplo: Pds::Colormap::Jet, Pds::Colormap::Bone,
     *  \param[in] filepath Nombre del archivo donde se escribirán los datos 
     *  Pds::Colormap::Hot,Pds::Colormap::Jolly.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    bool ExportBmpFile(const unsigned char colormap[256][3],const char* filepath) const;
/**
 * @}
 */


public:

/** @name Métodos Static con Matrices
 *  Herramientas genéricas que pueden ser usadas desde Pds::Matrix
 * @{
 */
    

    /** 
     *  \brief Convierte un sdt::string a una Matriz de Nlin lineas y Ncol columnas.
     *  \param[in] str Cadena a leer.
     *  \return Retorna una matriz. en caso de error se retorna una matriz vacía.
     *  \ingroup MatrixGroup
     */
    static Pds::Matrix FromString(const std::string &str);

   /** 
     *  \brief Escribe en una matriz en un archivo binario en formato BMP.
     *  Losdatos deben ir de 0 a 255, valores superiores o inferiores serán truncados.
     * 
     *  \param[in] R Matriz con colores red 0<=r<=255.
     *  \param[in] G Matriz con colores green 0<=r<=255.
     *  \param[in] B Matriz con colores blue 0<=r<=255.
     *  \param[in] bmpfilename Nombre del archivo donde se escribirán los datos.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    static bool ExportBmpFile(  const Pds::Matrix &R,
                                const Pds::Matrix &G,
                                const Pds::Matrix &B,
                                const char* bmpfilename);
/**
 * @}
 */


public:

/** @name Métodos Static con arrays
 *  Herramientas genéricas que pueden ser usadas desde Pds::Matrix
 * @{
 */
    /** 
     *  \brief crea dinámicamente un arreglo de A.Nlin() lineas y A.Ncol() columnas,
     *  con los datos copiados de aplicar func(A).
     *  \param[in] func Función a aplicar, esta debe tener a forma double func(double).
     *  \param[in] A Matriz de donde se copiaran datos.
     *  \return Retorna un puntero al arreglo, o NULL si no consiguió reservar
     * la memoria. Esta memoria debe ser liberada siempre com ArrayRelease
     *  \ingroup MatrixGroup
     */
    static double** ArrayAllocate(double (*func)(double),const Pds::Matrix &A);

    /** 
     *  \brief crea dinámicamente un arreglo de A.Nlin() lineas y A.Ncol() columnas,
     *  con los datos copiados de aplicar func(A,var).
     *  \param[in] func Función a aplicar, esta debe tener a forma double func(double).
     *  \param[in] A Matriz de donde se copiaran datos.
     *  \param[in] var Variable a evaluar.
     *  \return Retorna un puntero al arreglo, o NULL si no consiguió reservar
     * la memoria. Esta memoria debe ser liberada siempre com ArrayRelease
     *  \ingroup MatrixGroup
     */
    static double** ArrayAllocate(double (*func)(double,double),const Pds::Matrix &A,double var);

    /** 
     *  \brief crea dinámicamente un arreglo de A.Nlin() lineas y A.Ncol() columnas,
     *  con los datos copiados de aplicar func(A,B).
     *  Los tamaño de A y B son similares.
     *  \param[in] func Función a aplicar, esta debe tener a forma double func(double,double).
     *  \param[in] A Matriz de donde se copiaran datos.
     *  \param[in] B Matriz de donde se copiaran datos.
     *  \return Retorna un puntero al arreglo, o NULL si no consiguió reservar
     * la memoria. Esta memoria debe ser liberada siempre com ArrayRelease
     *  \ingroup MatrixGroup
     */
    static double** ArrayAllocate(double (*func)(double,double),const Pds::Matrix &A,const Pds::Matrix &B);

    /** 
     *  \brief crea dinámicamente un arreglo de A.Nlin() lineas y A.Ncol() columnas,
     *  con los datos copiados de aplicar func(A,B,var).
     *  Los tamaño de A y B son similares.
     *  \param[in] func Función a aplicar, esta debe tener a forma double func(double,double,double).
     *  \param[in] A Matriz de donde se copiaran datos.
     *  \param[in] B Matriz de donde se copiaran datos.
     *  \param[in] var Tercer valor a evaluar.
     *  \return Retorna un puntero al arreglo, o NULL si no consiguió reservar
     * la memoria. Esta memoria debe ser liberada siempre com ArrayRelease
     *  \ingroup MatrixGroup
     */
    static double** ArrayAllocate(double (*func)(double,double,double),const Pds::Matrix &A,const Pds::Matrix &B,double var);
    
    /** 
     *  \brief crea dinámicamente un arreglo de A.Nlin() lineas y A.Ncol() columnas,
     *  con los datos copiados de aplicar func(A,B,C).
     *  Los tamaño de A, B y C son similares.
     *  \param[in] func Función a aplicar, esta debe tener a forma double func(double,double,double).
     *  \param[in] A Matriz de donde se copiaran datos.
     *  \param[in] B Matriz de donde se copiaran datos.
     *  \param[in] C Matriz de donde se copiaran datos.
     *  \return Retorna un puntero al arreglo, o NULL si no consiguió reservar
     * la memoria. Esta memoria debe ser liberada siempre com ArrayRelease
     *  \ingroup MatrixGroup
     */
    static double** ArrayAllocate(double (*func)(double,double,double),
                                    const Pds::Matrix &A,
                                    const Pds::Matrix &B,
                                    const Pds::Matrix &C);
    
    /** 
     *  \brief crea dinámicamente un arreglo de A.Nlin() lineas y A.Ncol() columnas,
     *  con los datos copiados de aplicar func(A,B,C,var).
     *  Los tamaño de A, B y C son similares.
     *  \param[in] func Función a aplicar, esta debe tener a forma double func(double,double,double,double).
     *  \param[in] A Matriz de donde se copiaran datos.
     *  \param[in] B Matriz de donde se copiaran datos.
     *  \param[in] C Matriz de donde se copiaran datos.
     *  \param[in] var Cuarto valor a evaluar.
     *  \return Retorna un puntero al arreglo, o NULL si no consiguió reservar
     * la memoria. Esta memoria debe ser liberada siempre com ArrayRelease
     *  \ingroup MatrixGroup
     */
    static double** ArrayAllocate(double (*func)(double,double,double,double),
                                    const Pds::Matrix &A,
                                    const Pds::Matrix &B,
                                    const Pds::Matrix &C,
                                    double var);
    
    /** 
     *  \brief crea dinámicamente un arreglo de A.Nlin() lineas y A.Ncol() columnas,
     *  con los datos copiados de aplicar func(A,B,C,D).
     *  Los tamaño de A, B, C y D son similares.
     *  \param[in] func Función a aplicar, esta debe tener a forma double func(double,double,double,double).
     *  \param[in] A Matriz de donde se copiaran datos.
     *  \param[in] B Matriz de donde se copiaran datos.
     *  \param[in] C Matriz de donde se copiaran datos.
     *  \param[in] D Matriz de donde se copiaran datos.
     *  \return Retorna un puntero al arreglo, o NULL si no consiguió reservar
     * la memoria. Esta memoria debe ser liberada siempre com ArrayRelease
     *  \ingroup MatrixGroup
     */
    static double** ArrayAllocate(double (*func)(double,double,double,double),
                                    const Pds::Matrix &A,
                                    const Pds::Matrix &B,
                                    const Pds::Matrix &C,
                                    const Pds::Matrix &D);
    
    /** 
     *  \brief crea dinámicamente un arreglo de A.Nlin() lineas y A.Ncol() columnas,
     *  con los datos copiados de una matriz A.
     *  \param[in] A Matriz de donde se copiaran datos.
     *  \return Retorna un puntero al arreglo, o NULL si no consiguió reservar
     * la memoria. Esta memoria debe ser liberada siempre com ArrayRelease
     *  \ingroup MatrixGroup
     */
    static double** ArrayAllocate(const Pds::Matrix &A);
    
    /** 
     *  \brief crea dinámicamente un arreglo de Nlin lineas y Ncol columnas,
     *  con elementos inicializado con un valor.
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \param[in] Ncol El numero de columnas en el arreglo.
     *  \param[in] val El valor a usar.
     *  \return Retorna un puntero al arreglo, o NULL si no consiguió reservar
     * la memoria. Esta memoria debe ser liberada siempre com ArrayRelease
     *  \ingroup MatrixGroup
     */
    static double** ArrayAllocate(unsigned int Nlin,unsigned int Ncol,double val);
    
    /** 
     *  \brief crea dinámicamente un arreglo de Nlin lineas y Ncol columnas
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \param[in] Ncol El numero de columnas en el arreglo.
     *  \return Retorna un puntero al arreglo, o NULL si no consiguió reservar
     * la memoria. Esta memoria debe ser liberada siempre com ArrayRelease
     *  \ingroup MatrixGroup
     */
    static double** ArrayAllocate(unsigned int Nlin,unsigned int Ncol);

   /** 
     *  \brief Libera un arreglo de Nlin lineas y Ncol columnas (arreglo de arreglos)
     * Adicionalmente carga con NULL al arreglo a liberar.
     *  \param[in] array El arreglo de arreglos de de Nlin lineas y Ncol columnas
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \ingroup MatrixGroup
     */
    static void ArrayRelease(double** &array,unsigned int Nlin);

   /** 
     *  \brief Convierte a un arreglo unidimensional un arreglo de Nlin
     *  lineas y Ncol columnas (arreglo de arreglos). Lee primero una columna entera.
     *  \param[in] array El arreglo de arreglos de de Nlin lineas y Ncol columnas
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \param[in] Ncol El numero de columnas en el arreglo.
     *  \return Retorna un double *. Si la matriz es nula retorna NULL.
     *  \ingroup MatrixGroup
     */
    static double *ArrayToArray(double **array,unsigned int Nlin,unsigned int Ncol);

   /** 
     *  \brief Convierte a un sdt::string un arreglo de Nlin lineas y Ncol columnas (arreglo de arreglos).
     *  \param[in] array El arreglo de arreglos de de Nlin lineas y Ncol columnas
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \param[in] Ncol El numero de columnas en el arreglo.
     *  \return Retorna un std::string. Si la matriz es nula retorna un string sin caracteres.
     *  \ingroup MatrixGroup
     */
    static std::string ArrayToString(double **array,unsigned int Nlin,unsigned int Ncol);

   /** 
     *  \brief Convierte un sdt::string con arreglo de Nlin lineas y Ncol columnas a un arreglo.
     *  \param[in] str Cadena a leer.
     *  \param[out] Nlin El numero de lineas en el arreglo.
     *  \param[out] Ncol El numero de columnas en el arreglo.
     *  \return Retorna un arreglo. en caso de error se retorna NULL.
     *  \ingroup MatrixGroup
     */
    static double **ArrayFromString(const std::string &str,unsigned int &Nlin,unsigned int &Ncol);

   /** 
     *  \brief Convierte un sdt::string con arreglo de Nlin lineas y 1 columna a un arreglo.
     *  \param[in] str Cadena a leer.
     *  \param[out] Nlin El numero de lineas en el arreglo.
     *  \param[out]  Ncol El numero de columnas en el arreglo. En caso de exito 
     *  este valor sera 1 en otro caso el valor original no es alterado.
     *  \return Retorna un arreglo. en caso de error se retorna NULL.
     *  \ingroup MatrixGroup
     */
    static double **ArrayColFromString(const std::string &str,unsigned int &Nlin,unsigned int &Ncol);
    
   /** 
     *  \brief Salva en un archivo un arreglo de Nlin lineas y Ncol columnas (arreglo de arreglos).
     *  \param[in] filepath El archivo donde se guardaran los datos.
     *  \param[in] array El arreglo de arreglos de de Nlin lineas y Ncol columnas
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \param[in] Ncol El numero de columnas en el arreglo.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    static bool ArraySave(const char* filepath,double **array,unsigned int Nlin,unsigned int Ncol);

   /** 
     *  \brief Lee de un archivo un arreglo de Nlin lineas y Ncol columnas (arreglo de arreglos).
     *  \param[in] filepath El archivo donde se leerán los datos.
     *  \param[out] Nlin Donde se escribirá el numero de lineas en el arreglo.
     *  \param[out] Ncol Donde se escribirá el numero de columnas en el arreglo.
     *  \return El arreglo de arreglos de de Nlin lineas y Ncol columnas. Si el numero de columnas 
     *  no es constante se retorna NULL. Si la función retorna NULL entonces los valores
     *  de entrada Nlin e Ncol no son alterados.
     *  \ingroup MatrixGroup
     */
    static double** ArrayLoad(const char* filepath,unsigned int& Nlin,unsigned int& Ncol);

   /** 
     *  \brief Lee de un archivo un arreglo de Nlin lineas y Ncol=1 columna (arreglo de arreglos).
     *  \param[in] filepath El archivo donde se leerán los datos.
     *  \param[out] Nlin Donde se escribirá el numero de lineas en el arreglo.
     *  \param[out] Ncol Donde se escribirá el numero de columnas en el arreglo.
     *  \return El arreglo de arreglos de de Nlin lineas y Ncol=1 columnas.
     *  No importa si el numero de columnas en el archivo no es constante,
     *  la funcion so se interesa por la cantidad de elementos no vacios. 
     *  Si la función retorna NULL entonces los valores
     *  de entrada Nlin e Ncol no son alterados. En caso de acierto Ncol 
     *  siempre es cargado con 1.
     *  \ingroup MatrixGroup
     */
    static double** ArrayColLoad(const char* filepath,unsigned int& Nlin,unsigned int& Ncol);

   /** 
     *  \brief Escribe en un archivo binario en formato de octave un
     *  arreglo de Nlin lineas y Ncol columnas (arreglo de arreglos).
     *  Es usado el nombre MAT0 como identificador de matriz.
     * 
Para cargar los datos en OCTAVE se puede usar el siguiente código
\verbatim
% Load all the variables in "matfile.mat" in the workspace.
load("-v4","matfile.mat");

% Load the B variable in a STRUCTURE
STRUCTURE=load("-v4","matfile.mat","B");
\endverbatim
     *  Version 4 MAT-File Format:[Documento externo](https://www.eiscat.se/wp-content/uploads/2016/03/Version-4-MAT-File-Format.pdf)
     *  [Documento oficial](https://www.mathworks.com/help/pdf_doc/matlab/matfile_format.pdf)
     *  \param[in] fp El descriptor de fichero que apunta a donde se guardaran los datos.
     *  \param[in] array El arreglo de arreglos de de Nlin lineas y Ncol columnas
     *  \param[in] pname El nombre de la matriz.
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \param[in] Ncol El numero de columnas en el arreglo.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    static bool ArrayWriteMatFile(FILE *fp,const char *pname,double **array,unsigned int Nlin,unsigned int Ncol);

   /** 
     *  \brief Escribe en un archivo binario en formato de octave un
     *  arreglo de Nlin lineas y Ncol columnas (arreglo de arreglos).
     *  Es usado el nombre MAT0 como identificador de matriz.
     * 
Para cargar los datos en OCTAVE se puede usar el siguiente código
\verbatim
% Load all the variables in "matfile.mat" in the workspace.
load("-v4","matfile.mat");

% Load the B variable in a STRUCTURE
STRUCTURE=load("-v4","matfile.mat","B");
\endverbatim
     *  Version 4 MAT-File Format:[Documento externo](https://www.eiscat.se/wp-content/uploads/2016/03/Version-4-MAT-File-Format.pdf)
     *  [Documento oficial](https://www.mathworks.com/help/pdf_doc/matlab/matfile_format.pdf)
     *  \param[in] fp El descriptor de fichero que apunta a donde se guardaran los datos.
     *  \param[in] arrayr El arreglo real de arreglos de de Nlin lineas y Ncol columnas.
     *  \param[in] arrayi El arreglo imag de arreglos de de Nlin lineas y Ncol columnas.
     *  \param[in] pname El nombre de la matriz.
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \param[in] Ncol El numero de columnas en el arreglo.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    static bool ArrayWriteMatFile(FILE *fp,const char *pname,double **arrayr,double **arrayi,unsigned int Nlin,unsigned int Ncol);

    
   /** 
     *  \brief Salva en un archivo de texto un arreglo de Nlin lineas y Ncol columnas, 
     *  usando el formato Csv (Comma Separated Values).
     *  \param[in] filepath El archivo donde se guardaran los datos.
     *  \param[in] array El arreglo de arreglos de de Nlin lineas y Ncol columnas
     *  \param[in] Nlin El numero de lineas en el arreglo.
     *  \param[in] Ncol El numero de columnas en el arreglo.
     *  \param[in] delimitador delimitador de elementos por defecto es ','.
     *  \return Retorna true si todo fue bien o false si no.
     *  \ingroup MatrixGroup
     */
    static bool ArrayWriteCsvFile(const char* filepath,double **array,unsigned int Nlin,unsigned int Ncol,char delimitador=',');

    /** 
     *  \brief Escribe los datos de una matriz en un archivo de en formato BMP.
     *
     *  <center>
     *  \image html pds_matrix_save_bmp_with_colormap_jet.bmp "grafico usando el colormap Pds::Colormap::Jet."
     *  </center>
     *  \param[in] array Arreglo donde se leerán los datos de escala de gris. \f$0\leq a_{ij} \leq 255\f$
     *  \param[in] Nlin Número de lineas del arreglo, equivalente a la altura de la imagen.
     *  \param[in] Ncol Número de columnas del arreglo, equivalente al ancho de la imagen.
     *  \param[in] colormap Mapa de colores. Ejemplo: Pds::Colormap::Jet, Pds::Colormap::Bone,
     *  \param[in] bmpfilename Nombre del archivo donde se escribirán los datos 
     *  Pds::Colormap::Hot,Pds::Colormap::Jolly.
     *  \return true si todo fue bien o false si no. (ej. array,bmpfilename==NULL)
     *  \ingroup MatrixGroup
     */
    static bool ArrayWriteBmpWithColormap(  double **array,
                                            unsigned int Nlin,
                                            unsigned int Ncol,
                                            const unsigned char colormap[256][3],
                                            const char *bmpfilename);

    /** 
     *  \brief Escribe los datos de una matriz en un archivo de en formato BMP.
     *
     *  \param[in] arrayr Arreglo donde se leerán los datos de escala de gris. \f$0\leq r_{ij} \leq 255\f$
     *  \param[in] arrayg Arreglo donde se leerán los datos de escala de gris. \f$0\leq g_{ij} \leq 255\f$
     *  \param[in] arrayb Arreglo donde se leerán los datos de escala de gris. \f$0\leq b_{ij} \leq 255\f$
     *  \param[in] Nlin Número de lineas del arreglo, equivalente a la altura de la imagen.
     *  \param[in] Ncol Número de columnas del arreglo, equivalente al ancho de la imagen.
     *  \param[in] bmpfilename Nombre del archivo donde se escribirán los datos.
     *  \return true si todo fue bien o false si no. (ej. array,bmpfilename==NULL)
     *  \ingroup MatrixGroup
     */
    static bool ArrayWriteBmp(  double **arrayr,
                                double **arrayg,
                                double **arrayb,
                                unsigned int Nlin,
                                unsigned int Ncol,
                                const char *bmpfilename);
/**
 * @}
 */

public:

/** @name Operadores unarios y sus métodos equivalentes
 *  Descripción de algunos operadores habilitados a trabajar con Pds::Matrix.
 * @{
 */
    
    /** 
     *  \brief Transpuesta de si mismo (A), el resultado es
     * cargado en B. 
     *
     *  \f[ B \leftarrow transpose(A) \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B;
    
    A.FillRandU();
    
    B=A.T();
    
    std::cout<<B;
\endcode
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix T(void) const;
    
    /** 
     *  \brief Retorna A.T()*A cargado en B. 
     *
     *  \f[ B \leftarrow A^{T}A \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B;
    
    A.FillRandU();
    
    B=A.MtM();
    
    std::cout<<B;
\endcode
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix MtM(void) const;
    
    
    /** 
     *  \brief Retorna la matriz inversa.
     *
     * rcond es:
     *  \f[ rcond \leftarrow \frac{1.0}{||A||_1 ||A^{-1}||_1} \f]
     *
     *  \param[out] rcond Esta variable es cargada con el valor del
     *  reciproco del condicional de la matriz. Si esta es la matriz A.
     * Si la matriz esta bien condicionada entonces rcond es próximo a 1.0 y si la matriz
     * esta pobremente condicionada este valor estará proximo a 0.0.
     * Si la variable rcond no es entregada entonces sera mostrado un mensaje
     * de advertencia por consola si el valor de rcond es menor a Pds::Ra::WarningRCond.
     *  \return Retorna la matriz inversa si todo fue bien o una matriz vacia (.IsEmpty()==true) 
     *  si no es posible calcular la inversa.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix Inv(double *rcond=NULL) const;
    
    /** 
     *  \brief Procesa esta matriz A y retorna B la matriz pseudo 
     *  inversa de Moore Penrose.
     *
     *  \f[ B \leftarrow (A^T A)^{-1}A^T \f]
     *  \f[ rcond \leftarrow \frac{1.0}{||A^T A||_1 ||(A^T A)^{-1}||_1} \f]
     *
     *  \param[out] rcond Esta variable es cargada con el valor del
     *  reciproco del condicional de la matriz \f$A^T A\f$.
     * Si la matriz está bien condicionada entonces rcond es próximo a 1.0 y si la matriz
     * esta pobremente condicionada este valor estará proximo a 0.0.
     * Si la variable rcond no es entregada entonces sera mostrado un mensaje
     * de advertencia por consola si el valor de rcond es menor a Pds::Ra::WarningRCond.
     *  \return Retorna la matriz inversa si todo fue bien o una matriz vacia (.IsEmpty()==true) 
     *  si no es posible calcular la inversa.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix PInv(double *rcond=NULL) const;
    
    
    /** 
     *  \brief Cambia de signo a si mismo (A), el resultado es
     * cargado en B. Este operador es similar al método unario Minus 
     *
     *  \f[ B \leftarrow -A \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B;
    
    A.Fill(2.0);
    
    B=-A;
    
    std::cout<<B;
\endcode
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vazia (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix operator -(void) const;
    
    /** 
     *  \brief Cambia de signo a si mismo (A), el resultado es
     * cargado en B. Este método es similar al operador unario - 
     *
     *  \f[ B \leftarrow -A \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B;
    
    A.Fill(2.0);
    
    B=A.Minus();
    
    std::cout<<B;
\endcode
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix Minus(void) const;
    
    /** 
     *  \brief Asigna el signo + a si mismo (A), el resultado es
     * cargado en B. Este operador es similar al método unario Plus 
     *
     *  \f[ B \leftarrow +A \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B;
    
    A.Fill(2.0);
    
    B=+A;
    
    std::cout<<B;
\endcode
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix operator +(void) const;
    
    /** 
     *  \brief Asigna el signo + a si mismo (A), el resultado es
     * cargado en B. Este método es similar al operador unario + 
     *
     *  \f[ B \leftarrow +A \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B;
    
    A.Fill(2.0);
    
    B=A.Plus();
    
    std::cout<<B;
\endcode
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vazia (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix Plus(void) const;
/**
 * @}
 */
    
    
/** @name Operadores binarios y sus métodos equivalentes
 *  Descripción de algunos operadores habilitados a trabajar con Pds::Matrix.
 * @{
 */
    

    /** 
     *  \brief Multiplica con sigo mismo (A), un valor b y el resultado es
     * cargado en C. Este operador es similar al método Mul() 
     *
     *  \f[ C \leftarrow A*b \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    
    C=A*2.0;
    
    std::cout<<C;
\endcode
     *  \param[in] b el valor a multiplicar
     *  \return Retorna C con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \see Mul
     *  \ingroup MatrixGroup
     */
    Pds::Matrix operator * (double b) const;
    
    /** 
     *  \brief Multiplica con sigo mismo (A), una matriz B y el resultado es
     * cargado en C. Este operador es similar al método Mul() 
     *
     *  \f[ C \leftarrow A*B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    B.Fill(1.0);
    
    C=A*B;
    
    std::cout<<C;
\endcode
     *  \param[in] B la matriz a multiplicar
     *  \return Retorna C con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \see Mul
     *  \ingroup MatrixGroup
     */
    Pds::Matrix operator * (const Pds::Matrix &B) const;
    
    /** 
     *  \brief Multiplica con sigo mismo (A), un valor b y el resultado es
     * cargado en C. Este método  es similar al operador * 
     *
     *  \f[ C \leftarrow A*b \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    
    C=A.Mul(2.0);
    
    std::cout<<C;
\endcode
     *  \param[in] b el valor a multiplicar
     *  \return Retorna C con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix Mul(double b) const;
    
    /** 
     *  \brief Multiplica con sigo mismo (A), una matriz B y el resultado es
     * cargado en C. Este método  es similar al operador * 
     *
     *  \f[ C \leftarrow A*B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    B.Fill(1.0);
    
    C=A.Mul(B);
    
    std::cout<<C;
\endcode
     *  \param[in] B la matriz a multiplicar
     *  \return Retorna C con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix Mul(const Pds::Matrix &B) const;
    
    /** 
     *  \brief Multiplica con sigo mismo (A), la transpuesta de una matriz B y el resultado es
     * cargado en C. Este método  es similar al operador * 
     *
     *  \f[ C \leftarrow A*B^T \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    B.Fill(1.0);
    
    C=A.MulT(B);
    
    std::cout<<C;
\endcode
     *  \param[in] B la matriz a multiplicar
     *  \return Retorna C con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix MulT(const Pds::Matrix &B) const;

    /** 
     *  \brief <b>[Elemento a elemento]</b> Suma con sigo mismo (A), un valor b y el resultado es
     * cargado en C. Este operador 
     *  es similar al método Add() 
     *
     *  \f[ C \leftarrow A+b \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    
    C=A+2.0;
    
    std::cout<<C;
\endcode
     *  \param[in] b El valor a sumar
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vazia (this->IsEmpty() igual a true) en caso de error.
     *  \see Add
     *  \ingroup MatrixGroup
     */
    Pds::Matrix operator + (double b) const;
    
    /** 
     *  \brief <b>[Elemento a elemento]</b> Suma con sigo mismo (A), una matriz B y el resultado es
     * cargado en C. Este operador 
     *  es similar al método Add() 
     *
     *  \f[ C \leftarrow A+B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    B.Fill(1.0);
    
    C=A+B;
    
    std::cout<<C;
\endcode
     *  \param[in] B la matriz a sumar
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vazia (this->IsEmpty() igual a true) en caso de error.
     *  \see Add
     *  \ingroup MatrixGroup
     */
    Pds::Matrix operator + (const Pds::Matrix &B) const;
    
    /** 
     *  \brief <b>[Elemento a elemento]</b> Suma con sigo mismo (A), una valor b y el resultado es
     * cargado en C. Este método 
     *  es similar al operador + 
     *
     *  \f[ C \leftarrow A+b \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    
    C=A.Add(2.0);
    
    std::cout<<C;
\endcode
     *  \param[in] b El valor a sumar
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vazia (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix Add(double b) const;
    
    /** 
     *  \brief <b>[Elemento a elemento]</b> Suma con sigo mismo (A), una matriz B y el resultado es
     * cargado en C. Este metodo 
     *  es similar al operador + 
     *
     *  \f[ C \leftarrow A+B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    B.Fill(1.0);
    
    C=A.Add(B);
    
    std::cout<<C;
\endcode
     *  \param[in] B la matriz a sumar
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vazia (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix Add(const Pds::Matrix &B) const;
    
    
    /** 
     *  \brief <b>[Elemento a elemento]</b> Resta con sigo mismo (A), un valor b y el resultado es
     * cargado en C. Este operador 
     *  es similar al método Sub() 
     *
     *  \f[ C \leftarrow A-b \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    
    C=A-2.0;
    
    std::cout<<C;
\endcode
     *  \param[in] b El valor a restar
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \see Add
     *  \ingroup MatrixGroup
     */
    Pds::Matrix operator - (double b) const;
    
    /** 
     *  \brief <b>[Elemento a elemento]</b> Resta con sigo mismo (A), una matriz B y el resultado es
     * cargado en C. Este operador es similar al método Sub
     *
     *  \f[ C \leftarrow A-B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    B.Fill(1.0);
    
    C=A-B;
    
    std::cout<<C;
\endcode
     *  \param[in] B la matriz que resta
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix operator -(const Pds::Matrix &B) const;
    
    /** 
     *  \brief <b>[Elemento a elemento]</b> Resta con sigo mismo (A), una valor b y el resultado es
     * cargado en C. Este método 
     *  es similar al operador - 
     *
     *  \f[ C \leftarrow A-b \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    
    C=A.Sub(2.0);
    
    std::cout<<C;
\endcode
     *  \param[in] b El valor a restar
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix Sub(double b) const;
    
    /** 
     *  \brief <b>[Elemento a elemento]</b> Resta con sigo mismo (A), una matriz B y el resultado es
     * cargado en C. Este método es similar al operador - 
     *
     *  \f[ C \leftarrow A-B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    B.Fill(1.0);
    
    C=A.Sub(B);
    
    std::cout<<C;
\endcode
     *  \param[in] B la matriz que resta
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix Sub(const Pds::Matrix &B) const;
    

    /** 
     *  \brief Suma con sigo mismo (A), una matriz B linea y el resultado es
     * cargado en C. La unica linea de B es sumada a cada linea de A
     *
     *  \f[ C \leftarrow A+B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(1,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    B.Fill(1.0);
    
    C=A.AddRowMatrix(B);
    
    std::cout<<C;
\endcode
     *  \param[in] B la matriz que suma
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  Existe error si B esta vacio o si B no es una matri linea.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix AddRowMatrix(const Pds::Matrix &B) const;
    
    /** 
     *  \brief Resta con sigo mismo (A), una matriz B linea y el resultado es
     * cargado en C. La unica linea de B es restada a cada linea de A
     *
     *  \f[ C \leftarrow A-B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(1,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    B.Fill(1.0);
    
    C=A.SubRowMatrix(B);
    
    std::cout<<C;
\endcode
     *  \param[in] B la matriz que resta
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  Existe error si B esta vacio o si B no es una matri linea.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix SubRowMatrix(const Pds::Matrix &B) const;

    /** 
     *  \brief <b>[Elemento a elemento]</b> Divide con sigo mismo (A), un valor b y el resultado es
     * cargado en C. Este operador es similar al método Div() 
     *
     *  \f[ C \leftarrow A/b \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    
    C=A/2.0;
    
    std::cout<<C;
\endcode
     *  \param[in] b el valor a dividir
     *  \return Retorna C con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \see Mul
     *  \ingroup MatrixGroup
     */
    Pds::Matrix operator / (double b) const;


    /** 
     *  \brief <b>[Elemento a elemento]</b> Divide con sigo mismo (A), elemento a elemento, una matriz B y el resultado es
     * cargado en C. Este método  es similar al método .Div()
     *
     *  \f[ C \leftarrow A / B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(4,4);
    Pds::Matrix C;
    
    A.Fill(1.0);
    B.Fill(2.0);
    
    C=A/B;
    
    std::cout<<C;
\endcode
     *  \param[in] B la matriz a dividir
     *  \return Retorna C con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix operator/(const Pds::Matrix &B) const;

    /** 
     *  \brief <b>[Elemento a elemento]</b> Divide con sigo mismo (A), un valor b y el resultado es
     * cargado en C. Este método  es similar al operador / 
     *
     *  \f[ C \leftarrow A/b \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    
    C=A.Div(2.0);
    
    std::cout<<C;
\endcode
     *  \param[in] b el valor a dividir
     *  \return Retorna C con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix Div(double b) const;

    /** 
     *  \brief <b>[Elemento a elemento]</b> Divide con sigo mismo (A), elemento a elemento, una matriz B y el resultado es
     * cargado en C. Este método  es similar al operador /
     *
     *  \f[ C \leftarrow A / B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(4,4);
    Pds::Matrix C;
    
    A.Fill(1.0);
    B.Fill(2.0);
    
    C=A.Div(B);
    
    std::cout<<C;
\endcode
     *  \param[in] B la matriz a dividir
     *  \return Retorna C con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix Div(const Pds::Matrix &B) const;  


    /** 
     *  \brief <b>[Elemento a elemento]</b> Divide con sigo mismo (A), un valor b y el resultado es
     * cargado en C. Este método  es similar al operador / 
     *
     *  \f[ C \leftarrow b/A \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    
    C=A.DivSelf(1.0);
    
    std::cout<<C;
\endcode
     *  \param[in] b El valor del numerador en la division
     *  \return Retorna C con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix DivSelf(double b) const;

    /** 
     *  \brief <b>[Elemento a elemento]</b> Multiplica con sigo mismo (A), elemento a elemento, una matriz B y el resultado es
     * cargado en C. Este método  es similar al método .Product()
     *
     *  \f[ C \leftarrow A \& B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    B.Fill(1.0);
    
    C=A&B;
    
    std::cout<<C;
\endcode
     *  \warning El operador & tiene baja precedencia, por lo que recomendamos usar parentesis (A&B).
<table>
<caption id="multi_row0">Operator Precedence</caption>
    <tr><td>Precedence <td>Operator
    <tr><td>5<td> a*b   a/b   a%b
    <tr><td>6<td> a+b   a-b
    <tr><td>7<td> <<   >>
    <tr><td>9<td> > < >= <=
    <tr><td>10<td> ==   !=
    <tr><td>11<td> &
    <tr><td>12<td> ^
</table> 
     *  \param[in] B la matriz a multiplicar
     *  \return Retorna C con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix operator&(const Pds::Matrix &B) const;

    /** 
     *  \brief <b>[Elemento a elemento]</b> Multiplica con sigo mismo (A), elemento a elemento, una matriz B y el resultado es
     * cargado en C. Este método  es similar al operador &
     *
     *  \f[ C \leftarrow A\&B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    B.Fill(1.0);
    
    C=A.Product(B);
    
    std::cout<<C;
\endcode
     *  \param[in] B la matriz a multiplicar
     *  \return Retorna C con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix Product(const Pds::Matrix &B) const;



    /** 
     *  \brief <b>[Elemento a elemento]</b>Potencia asi mismo (A), elemento a elemento, con una matriz B y el resultado es
     * cargado en C. Este método  es similar al operador
     *
     *  \f[ C \leftarrow A^B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    B.Fill(1.0);
    
    C=A.Pow(B);
    
    std::cout<<C;
\endcode
     *  \param[in] B La matriz a exponenciar
     *  \return Retorna C con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix Pow(const Pds::Matrix &B) const;


    /** 
     *  \brief <b>[Elemento a elemento]</b> Potencia asi mismo (A), elemento a elemento, con un valor val y el resultado es
     * cargado en C. Este método  es similar al operador 
     *
     *  \f[ C \leftarrow A^{val} \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix val=2;
    Pds::Matrix C;
    
    A.Fill(2.0);
    
    C=A.Pow(val);
    
    std::cout<<C;
\endcode
     *  \param[in] val Valor a exponenciar
     *  \return Retorna C con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix Pow(double val) const;

    /** 
     *  \brief <b>[Elemento a elemento]</b> Calcula con sigo mismo (A), si (A) es mayor que un valor b y el resultado es
     * cargado en C. Este método  es similar al operador >= 
     *
     *  \f[ C \leftarrow A>=b \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix C;
    
    A.FillId();
    
    C=A.Geq(4);
    
    std::cout<<C;
\endcode
     *  \param[in] b el valor a comparar
     *  \return Retorna C con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix Geq(double b) const;
    
    /** 
     *  \brief <b>[Elemento a elemento]</b> Calcula con sigo mismo (A), si (A) es mayor que un valor (B) y el resultado es
     * cargado en C. Este método  es similar al operador >= 
     *
     *  \f[ C \leftarrow A>=B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix C;
    
    A.FillId();
    
    C=A.Geq(B);
    
    std::cout<<C;
\endcode
     *  \param[in] B Matriz a comparar
     *  \return Retorna C con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix Geq(Pds::Matrix B) const;
    
    /** 
     *  \brief <b>[Elemento a elemento]</b> Calcula con sigo mismo (A), si (A) es menor que un valor b y el resultado es
     * cargado en C. Este método  es similar al operador <= 
     *
     *  \f[ C \leftarrow A<=b \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix C;
    
    A.FillId();
    
    C=A.Leq(4);
    
    std::cout<<C;
\endcode
     *  \param[in] b el valor a comparar
     *  \return Retorna C con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix Leq(double b) const;
    
    /** 
     *  \brief <b>[Elemento a elemento]</b> Calcula con sigo mismo (A), si (A) es menor que un valor B y el resultado es
     * cargado en C. Este método  es similar al operador <= 
     *
     *  \f[ C \leftarrow A<=B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix C;
    
    A.FillId();
    
    C=A.Leq(B);
    
    std::cout<<C;
\endcode
     *  \param[in] B Matriz a comparar
     *  \return Retorna C con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix Leq(const Pds::Matrix &B) const;
    

    /** 
     *  \brief <b>[Elemento a elemento]</b> Calcula con sigo mismo (A), si (A) es identico a un valor b y el resultado es
     * cargado en C. Este método  es similar al operador == 
     *
     *  \f[ C \leftarrow A==b \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix C;
    
    A.FillId();
    
    C=A.EqualTo(4);
    
    std::cout<<C;
\endcode
     *  \param[in] b el valor a comparar
     *  \return Retorna C con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix EqualTo(double b) const;
    
    /** 
     *  \brief <b>[Elemento a elemento]</b> Calcula con sigo mismo (A), si (A) es identico a un valor B y el resultado es
     * cargado en C. Este método  es similar al operador == 
     *
     *  \f[ C \leftarrow A==B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix C;
    
    A.FillId();
    
    C=A.EqualTo(B);
    
    std::cout<<C;
\endcode
     *  \param[in] B Matriz a comparar
     *  \return Retorna C con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix EqualTo(const Pds::Matrix &B) const;

    /** 
     *  \brief <b>[Elemento a elemento]</b> Calcula con sigo mismo (A), si (A) no es identico a un valor b y el resultado es
     * cargado en C. Este método  es similar al operador != 
     *
     *  \f[ C \leftarrow A!=b \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix C;
    
    A.FillId();
    
    C=A.NotEqualTo(4);
    
    std::cout<<C;
\endcode
     *  \param[in] b el valor a comparar
     *  \return Retorna C con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix NotEqualTo(double b) const;
    
    /** 
     *  \brief <b>[Elemento a elemento]</b> Calcula con sigo mismo (A), si (A) no es identico a un valor B y el resultado es
     * cargado en C. Este método  es similar al operador != 
     *
     *  \f[ C \leftarrow A!=B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix C;
    
    A.FillId();
    
    C=A.NotEqualTo(B);
    
    std::cout<<C;
\endcode
     *  \param[in] B Matriz a comparar
     *  \return Retorna C con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix NotEqualTo(const Pds::Matrix &B) const;

    
    /** 
     *  \brief Verifica si la matriz tiene elementos con valores infinitos.
     * 
     * Los valores infinitos pueden producirse con \f$+\frac{1}{0},-\frac{1}{0} y \frac{1}{0}\f$.
   \f[
\left(\begin{matrix}
0 & 0 & \hdots & 0\\ 
0 & 0 & \hdots & 1\\
\vdots & \vdots & \vdots & \vdots \\
1 & 0 & \hdots & 0\\ 
0 & 1 & \hdots & 0\\
\end{matrix}\right) \overleftarrow{EqualToInf} \left(\begin{matrix}
1 & NaN & \hdots & NaN\\ 
0 & 2 & \hdots & -\infty\\
\vdots & \vdots & \vdots & \vdots \\
\infty & 0 & \hdots & 0\\ 
3 & -\infty & \hdots & NaN\\
\end{matrix}\right)
   \f]
     *  \return Retorna una nueva matriz con 1 donde es infinito y 0 donde no lo es.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix EqualToInf(void) const;
    
    /** 
     *  \brief Verifica si la matriz tiene elementos con valores NAN (Not A Number).
     * 
     *  Los valores NAN pueden producirse con \f$\frac{0}{0}\f$.
   \f[
\left(\begin{matrix}
0 & 1 & \hdots & 1\\ 
0 & 0 & \hdots & 0\\
\vdots & \vdots & \vdots & \vdots \\
0 & 0 & \hdots & 0\\ 
0 & 0 & \hdots & 1\\
\end{matrix}\right) \overleftarrow{EqualToNan} \left(\begin{matrix}
1 & NaN & \hdots & NaN\\ 
0 & 2 & \hdots & -\infty\\
\vdots & \vdots & \vdots & \vdots \\
\infty & 0 & \hdots & 0\\ 
3 & -\infty & \hdots & NaN\\
\end{matrix}\right)
   \f]
     *  \return Retorna una nueva matriz con 1 donde es NAN y 0 donde no lo es.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix EqualToNan(void) const;
    
    /** 
     *  \brief Verifica si la matriz tiene elementos con valores finitos (no +inf, no -inf y no NAN).
     * 
   \f[
\left(\begin{matrix}
1 & 0 & \hdots & 0\\ 
1 & 1 & \hdots & 0\\
\vdots & \vdots & \vdots & \vdots \\
0 & 1 & \hdots & 1\\ 
1 & 0 & \hdots & 0\\
\end{matrix}\right) \overleftarrow{EqualToFinite} \left(\begin{matrix}
1 & NaN & \hdots & NaN\\ 
0 & 2 & \hdots & -\infty\\
\vdots & \vdots & \vdots & \vdots \\
\infty & 0 & \hdots & 0\\ 
3 & -\infty & \hdots & NaN\\
\end{matrix}\right)
   \f]
     *  \return Retorna una nueva matriz con 1 donde es finito y 0 donde no lo es.
     *  \ingroup MatrixGroup
     */
    Pds::Matrix EqualToFinite(void) const;

/**
 * @}
 */
    
    
/** @name Operadores binarios acumuladores y sus métodos equivalentes
 *  Descripción de algunos operadores habilitados a trabajar con Pds::Matrix.
 * @{
 */
    
    /** 
     *  \brief Resta y acumula en si mismo (A), un valor b. Este operador 
     *  es similar al método SubAssig() 
     *
     *  \f[ A \leftarrow A-b \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    double b=1.2;
    B.Fill(1.0);
    A-=b;
\endcode
     *  \param[in] b El valor a substraer
     *  \return Retorna el operador de la izquierda (acumulador) con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \see SubAssig
     *  \ingroup MatrixGroup
     */
    Pds::Matrix& operator -=(double b);
    
    /** 
     *  \brief Resta y acumula en si mismo (A), una matriz B. Este operador 
     *  es similar al método SubAssig() 
     *
     *  \f[ A \leftarrow A-B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(4,4);
    B.Fill(1.0);
    A-=B;
\endcode
     *  \param[in] B la matriz a substraer
     *  \return Retorna el operador de la izquierda (acumulador) con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \see SubAssig
     *  \ingroup MatrixGroup
     */
    Pds::Matrix& operator -=(const Pds::Matrix &B);
    
    /** 
     *  \brief Resta y acumula en si mismo (A), un valor b. Este es similar al
     *  operador -= 
     *
     *  \f[ A \leftarrow A-b \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    double b=1.2;
    A.SubAssig(b);
\endcode
     *  \param[in] b valor a substraer
     *  \return Retorna true si todo fue bien o false si no. Si se retorna false
     *  el acumulador no altera su contenido.
     *  \ingroup MatrixGroup
     */
    bool SubAssig(double b);
    
    /** 
     *  \brief Resta y acumula en si mismo (A), una matriz B. Este es similar al
     *  operador -= 
     *
     *  \f[ A \leftarrow A-B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(4,4);
    B.Fill(1.0);
    A.SubAssig(B);
\endcode
     *  \param[in] B la matriz que substrae
     *  \return Retorna true si todo fue bien o false si no. Si se retorna false
     *  el acumulador no altera su contenido.
     *  \ingroup MatrixGroup
     */
    bool SubAssig(const Pds::Matrix &B);
    
    /** 
     *  \brief Suma y acumula en si mismo (A), un valor b. Este operador 
     *  es similar al método AddAssig() 
     *
     *  \f[ A \leftarrow A+b \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    double b=1.2;
    A+=b;
\endcode
     *  \param[in] b El valor a acumular
     *  \return Retorna el operador de la izquierda (acumulador) con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \see AddAssig
     *  \ingroup MatrixGroup
     */
    Pds::Matrix& operator +=(double b);
    
    /** 
     *  \brief Suma y acumula en si mismo (A), una matriz B. Este operador 
     *  es similar al método AddAssig() 
     *
     *  \f[ A \leftarrow A+B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(4,4);
    B.Fill(1.0);
    A+=B;
\endcode
     *  \param[in] B la matriz a acumular
     *  \return Retorna el operador de la izquierda (acumulador) con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \see AddAssig
     *  \ingroup MatrixGroup
     */
    Pds::Matrix& operator +=(const Pds::Matrix &B);
    
    /** 
     *  \brief Suma y acumula en si mismo (A), un valor b. Este es similar al
     *  perador += 
     *
     *  \f[ A \leftarrow A+b \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    A.AddAssig(1.2);
\endcode
     *  \param[in] b Valor a acumular
     *  \return Retorna true si todo fue bien o false si no. Si se retorna false
     *  el acumulador no altera su contenido.
     *  \ingroup MatrixGroup
     */
    bool AddAssig(double b);

    /** 
     *  \brief Suma y acumula en si mismo (A), una matriz B. Este es similar al
     *  perador += 
     *
     *  \f[ A \leftarrow A+B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(4,4);
    B.Fill(1.0);
    A.AddAssig(B);
\endcode
     *  \param[in] B la matriz a acumular
     *  \return Retorna true si todo fue bien o false si no. Si se retorna false
     *  el acumulador no altera su contenido.
     *  \ingroup MatrixGroup
     */
    bool AddAssig(const Pds::Matrix &B);
    

    /** 
     *  \brief Suma y acumula en si mismo (A), una matriz B desde un punto (lin,col)
     *  haciendo una intersección.
     *
     *  \f[ A(lin:end,col:end) \leftarrow A(lin:end,col:end)+B(0:lin_end,0:col_end) \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(3,3);
    B.Fill(1.0);
    A.AddAssigAt(2,2,B);
\endcode
     *  \param[in] lin Suma desde esta linea
     *  \param[in] col Suma desde esta columna
     *  \param[in] B la matriz a acumular
     *  \return Retorna true si todo fue bien o false si no. Si se retorna false
     *  el acumulador no altera su contenido. Retorna false si la intersección
     *  no existe o si alguna de las matrices son nulas.
     *  \ingroup MatrixGroup
     */
    bool AddAssigAt(unsigned int lin,unsigned int col,const Pds::Matrix &B);
    
    /** 
     *  \brief Multiplica y acumula en si mismo (A), un valor b. Este operador 
     *  es similar al método MulAssig() 
     *
     *  \f[ A \leftarrow A*b \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    double b=1.2;
    A*=b;
\endcode
     *  \param[in] b El valor a acumular
     *  \return Retorna el operador de la izquierda (acumulador) con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \see AddAssig
     *  \ingroup MatrixGroup
     */
    Pds::Matrix& operator *=(double b);
    
    /** 
     *  \brief Multiplica y acumula en si mismo (A), una matriz B. Este operador 
     *  es similar al método MulAssig() 
     *
     *  \f[ A \leftarrow A*B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(4,4);
    A*=B;
\endcode
     *  \param[in] B El valor a acumular
     *  \return Retorna el operador de la izquierda (acumulador) con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \see AddAssig
     *  \ingroup MatrixGroup
     */
    Pds::Matrix& operator *=(const Pds::Matrix &B);
    
    /** 
     *  \brief Multiplica y acumula en si mismo (A), un valor b. Este es similar al
     *  operador *= 
     *
     *  \f[ A \leftarrow A*b \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    A.MulAssig(1.2);
\endcode
     *  \param[in] b Valor a acumular
     *  \return Retorna true si todo fue bien o false si no. Si se retorna false
     *  el acumulador no altera su contenido.
     *  \ingroup MatrixGroup
     */
    bool MulAssig(double b);
    
    /** 
     *  \brief Multiplica y acumula en si mismo (A), una matriz B. Este es similar al
     *  operador *= 
     *
     *  \f[ A \leftarrow A*B \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix B(4,4);
    A.MulAssig(B);
\endcode
     *  \param[in] B Valor a acumular
     *  \return Retorna true si todo fue bien o false si no. Si se retorna false
     *  el acumulador no altera su contenido.
     *  \ingroup MatrixGroup
     */
    bool MulAssig(const Pds::Matrix &B);
    
    
    
    /** 
     *  \brief Copia en si mismo (A), una matriz B. Este operador es 
     *  similar al método Copy().
     *  No importa  el tamaño de A, sus datos son liberados y un nuevo
     *  arreglo de datos es reservado.
     *
     *  \f[ A \leftarrow B \f]
     * Cuando acontece:
\code{.cpp}
    Pds::Matrix B(nlin,ncol);
    A=B;
\endcode
     * Cuando NO acontece:
\code{.cpp}
    Pds::Matrix A=Pds::Matrix(nlin,ncol);
\endcode
     *  \param[in] B la matriz a copiar
     *  \return Retorna el operador de la izquierda (acumulador) con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \see Copy
     *  \ingroup MatrixGroup
     */
    Pds::Matrix& operator = (const Pds::Matrix &B);
    
    /** 
     *  \brief Copia en si mismo (A), el contenido de una matriz B. Este 
     *  método es similar a usar el operador = .
     *  No importa  el tamaño de A, sus datos son liberados y un nuevo
     *  arreglo de datos es reservado.
     *
     *  \f[ A \leftarrow B \f]
     *  \param[in] B la matriz a copiar
     *  \return Retorna true si todo fue bien o false si no. Si se retorna false
     *  el receptor no altera su contenido.
     *  \see Copy
     *  \ingroup MatrixGroup
     */
    bool Copy(const Pds::Matrix &B);
    
    
    
    /** 
     *  \brief Copia en si mismo (A), el valor val. Este operador es 
     *  similar al método Copy().
     *  No importa  el tamaño de A, sus datos son liberados y un nuevo
     *  arreglo de datos de 1x1 es reservado.
     *
     *  \f[ A \leftarrow val \f]
     * Cuando acontece:
\code{.cpp}
    Pds::Matrix B(nlin,ncol);
    A=val;
\endcode
     * Cuando NO acontece:
\code{.cpp}
    Pds::Matrix A=Pds::Matrix(nlin,ncol);
\endcode
     *  \param[in] val El valor a copiar
     *  \return Retorna el operador de la izquierda (acumulador) con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \see Copy
     *  \ingroup MatrixGroup
     */
    Pds::Matrix& operator = (double val);
    
    /** 
     *  \brief Copia en si mismo (A), el valor val. Este 
     *  método es similar a usar el operador = .
     *  No importa  el tamaño de A, sus datos son liberados y un nuevo
     *  arreglo de datos de 1x1 es reservado.
     *
     *  \f[ A \leftarrow val \f]
     *  \param[in] val El valor a copiar
     *  \return Retorna true si todo fue bien o false si no. Si se retorna false
     *  el receptor no altera su contenido.
     *  \see Copy
     *  \ingroup MatrixGroup
     */
    bool Copy(double val);
/**
 * @}
 */


};// class Matrix

} // namespace Pds




/** @name Operadores no miembros
 *  Descripcion de algunos operadores habilitados a trabajar con Pds::Matrix.
 * @{
 */
    /** 
     *  \brief Retorna el contenido de la matriz por la salida estándar
     *
\code{.cpp}
    std::cout<<mat;
\endcode
     * es equivalente a :
\code{.cpp}
    std::cout<<mat.ToString();
\endcode
     *  \param[in] out La salida
     *  \param[in] mat La matriz a mostrar
     *  \return Retorna la misma salida estándar out.
     *  \see Pds::Matrix::ToString();
     *  \ingroup MatrixGroup
     */
std::ostream& operator<<(std::ostream &out,const Pds::Matrix &mat);

    /** 
     *  \brief Suma b con (A), el resultado es
     * cargado en C. Este operador 
     *  es similar al método Add() 
     *
     *  \f[ C \leftarrow b+A \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    
    C=2.0+A;
    
    std::cout<<C;
\endcode
     *  \param[in] b El valor a sumar
     *  \param[in] A matriz a sumar
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \see Add
     *  \ingroup MatrixGroup
     */
Pds::Matrix operator+(double b,const Pds::Matrix &A);

    /** 
     *  \brief Resta b con (A), el resultado es
     * cargado en C. Este operador 
     *  es similar al método Add() 
     *
     *  \f[ C \leftarrow b-A \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    
    C=2.0-A;
    
    std::cout<<C;
\endcode
     *  \param[in] b El valor a operar
     *  \param[in] A matriz a restar
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \see Sub
     *  \ingroup MatrixGroup
     */
Pds::Matrix operator-(double b,const Pds::Matrix &A);

    /** 
     *  \brief Multiplica b con (A), el resultado es
     * cargado en C. Este operador 
     *  es similar al método Mul() 
     *
     *  \f[ C \leftarrow b*A \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    
    C=2.0*A;
    
    std::cout<<C;
\endcode
     *  \param[in] b El valor a operar
     *  \param[in] A matriz a multiplicar
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \see Mul
     *  \ingroup MatrixGroup
     */
Pds::Matrix operator*(double b,const Pds::Matrix &A);

    /** 
     *  \brief Divide b con (A), elemento a elemento y el resultado es
     * cargado en C. Este operador 
     *  es similar al método DivSelf() 
     *
     *  \f[ C \leftarrow b/A \f]
\code{.cpp}
    Pds::Matrix A(4,4);
    Pds::Matrix C;
    
    A.Fill(2.0);
    
    C=2.0/A;
    
    std::cout<<C;
\endcode
     *  \param[in] b El valor a operar
     *  \param[in] A matriz a dividir
     *  \return Retorna un nuevo objeto con el
     *  resultado, o una matriz vacía (this->IsEmpty() igual a true) en caso de error.
     *  \see Mul
     *  \ingroup MatrixGroup
     */
Pds::Matrix operator/(double b,const Pds::Matrix &A);

/**
 * @}
 */

/**
 * @}
 */

#endif

