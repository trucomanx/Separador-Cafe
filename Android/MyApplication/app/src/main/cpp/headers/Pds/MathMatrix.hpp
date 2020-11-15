/*
 * MathMatrix.hpp
 * 
 * Copyright 2018 Fernando Pujaico Rivera <fernando.pujaico.rivera@gmail.com>
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

/** \file MathMatrix.hpp
 *  \author Fernando Pujaico Rivera
 *  \brief Funciones que trabajan con matrices.
 *  
 *  <br>Estas funciones trabajan con una matriz de la forma.<br>
 *  \image html matrix.png "Matriz de NlinxNcol"
 *  \b Nlin es el número de lineas y \b Ncol es el número de columnas.
 */



#ifndef __PDS_MATRIXMATH_HPP__
#define __PDS_MATRIXMATH_HPP__


/** \defgroup MathMatrixGroup Funciones Pds::Matrix -- Math
 *  \brief Funciones que usan Pds::Matrix, Ejemplo: Pds::Sin(), Pds::Cos(), Pds::Exp(), Pds::Sqrt, etc 
 *  <div class="fragment"> \#include <Pds/MathMatrix> </div>
 *  
 *  <br>Estas funciones trabajan con una matriz de la forma.<br>
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
 *  \b nlin es el número de lineas y \b ncol es el número de columnas.
 *  
 * Informacion adicional puede ser encontrada en @cite tutorialmatvec
 * @{
 */


#include <Pds/Matrix>

namespace Pds{
    

/** @name Funciones trigonometricas
 *  Descripcion de algunas funciones matematicas que usan  Pds::Matrix.
 * @{
 */


    /** 
     *  \brief Retorna el resultado de evaluar elemento a elemento la funcion seno.  
     *
     *  \f[ sin(A) \f]
     *  \param[in] A La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \see Pds::Matrix::Apply()
     *  \ingroup MathMatrixGroup
     */
    Pds::Matrix Sin(const Pds::Matrix &A);
    
    /** 
     *  \brief Retorna el resultado de evaluar elemento a elemento la funcion coseno.  
     *
     *  \f[ cos(A) \f]
     *  \param[in] A La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \see Pds::Matrix::Apply()
     *  \ingroup MathMatrixGroup
     */
    Pds::Matrix Cos(const Pds::Matrix &A);
    
    /** 
     *  \brief Retorna el resultado de evaluar elemento a elemento la funcion tangente.  
     *
     *  \f[ tan(A) \f]
     *  \param[in] A La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \see Pds::Matrix::Apply()
     *  \ingroup MathMatrixGroup
     */
    Pds::Matrix Tan(const Pds::Matrix &A);
/**
 * @}
 */


/** @name Funciones exponencial
 *  Descripcion de algunas funciones matematicas que usan  Pds::Matrix.
 * @{
 */
    /** 
     *  \brief Retorna el resultado de evaluar elemento a elemento la funcion exponente.  
     *
     *  \f[ e^A \f]
     *  \param[in] A La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \see Pds::Matrix::Apply()
     *  \ingroup MathMatrixGroup
     */
    Pds::Matrix Exp(const Pds::Matrix &A);
    
    /** 
     *  \brief Retorna el resultado de evaluar elemento a elemento la funcion exponente de 2.  
     *
     *  \f[ 2^A \f]
     *  \param[in] A La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \see Pds::Matrix::Apply()
     *  \ingroup MathMatrixGroup
     */
    Pds::Matrix TwoExp(const Pds::Matrix &A);
    
    /** 
     *  \brief Retorna el resultado de evaluar elemento a elemento la funcion logaritmo natural.
     *
     *  \f[ ln(A) \f]
     *  \param[in] A La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \see Pds::Matrix::Apply()
     *  \see Pds::Ln()
     *  \ingroup MathMatrixGroup
     */
    Pds::Matrix Log(const Pds::Matrix &A);

    /** 
     *  \brief Retorna el resultado de evaluar elemento a elemento la funcion logaritmo natural.
     *
     *  \f[ ln(A) \f]
     *  \param[in] A La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \see Pds::Matrix::Apply()
     *  \see Pds::Log()
     *  \ingroup MathMatrixGroup
     */
    Pds::Matrix Ln(const Pds::Matrix &A);
    
    /** 
     *  \brief Retorna el resultado de evaluar elemento a elemento la funcion logaritmo de base 2.
     *
     *  \f[ log_2(A) \f]
     *  \param[in] A La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \see Pds::Matrix::Apply()
     *  \ingroup MathMatrixGroup
     */
    Pds::Matrix Log2(const Pds::Matrix &A);

    /** 
     *  \brief Retorna el resultado de evaluar elemento a elemento la funcion logaritmo de base 10.
     *
     *  \f[ log_{10}(A) \f]
     *  \param[in] A La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \see Pds::Matrix::Apply()
     *  \ingroup MathMatrixGroup
     */
    Pds::Matrix Log10(const Pds::Matrix &A);

/**
 * @}
 */


/** @name Funciones de potencia
 *  Descripcion de algunas funciones matematicas que usan  Pds::Matrix.
 * @{
 */
 
    /** 
     *  \brief Retorna el resultado de evaluar elemento a elemento la funcion raiz cuadrada.
     *
     *  \f[ \sqrt{A} \f]
     *  \param[in] A La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \see Pds::Matrix::Apply()
     *  \ingroup MathMatrixGroup
     */
    Pds::Matrix Sqrt(const Pds::Matrix &A);
 
    /** 
     *  \brief Retorna el resultado de evaluar elemento a elemento la funcion pow.
     *
     *  \f[ A^{var} \equiv pow(A,var) \f]
     *  \param[in] A La matriz a evaluar
     *  \param[in] var La variable a evaluar
     *  \return Retorna la matriz evaluada.
     *  \see Pds::Matrix::Apply()
     *  \ingroup MathMatrixGroup
     */
    Pds::Matrix Pow(const Pds::Matrix &A,double var);
 
    /** 
     *  \brief Retorna el resultado de evaluar elemento a elemento la funcion pow.
     *
     *  \f[ A^B \equiv pow(A,B) \f]
     *  \param[in] A La matriz a evaluar
     *  \param[in] B La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \see Pds::Matrix::Apply()
     *  \ingroup MathMatrixGroup
     */
    Pds::Matrix Pow(const Pds::Matrix &A,const Pds::Matrix &B);
 
    /** 
     *  \brief Retorna el resultado de evaluar elemento a elemento la funcion atan2.
     *
     *  \f[ atan2(A,B) \f]
     *  \param[in] A La matriz a evaluar
     *  \param[in] B La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \see Pds::Matrix::Apply()
     *  \ingroup MathMatrixGroup
     */
    Pds::Matrix Atan2(const Pds::Matrix &A,const Pds::Matrix &B);
/**
 * @}
 */


/** @name Funciones Estadisticas
 *  Descripcion de algunas funciones matematicas que usan  Pds::Matrix.
 * @{
 */

    /** 
     *  \brief Calcula el valor de la varianza de la matriz A.
     *
     *  \param[in] A Matriz a procesar.
     *  \param[in] mean Valor medio de los elelento de la Matriz A.
     *  \return Retorna el valor de la varianza de la matriz. En caso de que la matriz sea vacía
     *  se retorna Pds::Ra::Nan.
     *  \ingroup MathMatrixGroup
     */
    double Var(const Pds::Matrix &A, double *mean);

    /** 
     *  \brief Calcula el valor de la varianza de la matriz A.
     *
     *  \param[in] A Matriz a procesar.
     *  \return Retorna el valor de la varianza de la matriz. En caso de que la matriz sea vacía
     *  se retorna Pds::Ra::Nan.
     *  \ingroup MathMatrixGroup
     */
    double Var(const Pds::Matrix &A);

    /** 
     *  \brief Calcula el valor medio de los elementos de la matriz A.
     *
     *  \param[in] A Matriz a procesar.
     *  \return Retorna el valor medio de los elementos de la matriz. En caso de que la matriz sea vacía
     *  se retorna Pds::Ra::Nan.
     *  \ingroup MathMatrixGroup
     */
    double Mean(const Pds::Matrix &A);

    /** 
     *  \brief Calcula el valor de la suma de los elementos de la matriz A.
     *
     *  \param[in] A Matriz a procesar.
     *  \return Retorna el valor de la suma de los elementos de la matriz. En caso de que la matriz sea vacía
     *  se retorna Pds::Ra::Nan.
     *  \ingroup MathMatrixGroup
     */
    double Sum(const Pds::Matrix &A);

/**
 * @}
 */


/** @name Funciones de álgebra lineal
 *  Descripcion de algunas funciones matematicas que usan  Pds::Matrix.
 * @{
 */

    /** 
     *  \brief Calcula el valor de la detrminante de una matriz.
     *
     *  \f[ Pds::Det(A)=|A| \f]
     *  \return Retorna el valor de la determinante. En caso de que la matriz sea vacía
     *  se retorna Pds::Ra::Nan.
     *  \ingroup MathMatrixGroup
     */
    double Det(const Pds::Matrix &A);

    /** 
     *  \brief Calcula el valor raiz quadrático medio de una matriz.
     *
     *  \f[ Pds::Rms(A)=\sqrt{\frac{1}{Nlin~Ncol}\sum \limits_{i}^{Nlin} \sum \limits_{j}^{Ncol} {|a_{ij}|}^2} \f]
     *  \return Retorna el valor raiz cuadrático medio. En caso de que la matriz sea vacía
     *  se retorna Pds::Ra::Nan.
     *  \ingroup MathMatrixGroup
     */
    double Rms(const Pds::Matrix &A);

    /** 
     *  \brief Calcula el valor absoluto medio de una matriz.
     *
     *  \f[ Pds::MeanSquare(A)=\frac{1}{Nlin~Ncol}\sum \limits_{i}^{Nlin} \sum \limits_{j}^{Ncol} {|a_{ij}|} \f]
     *  \return Retorna el valor absoluto medio. En caso de que la matriz sea vacía
     *  se retorna Pds::Ra::Nan.
     *  \ingroup MathMatrixGroup
     */
    double MeanAbsolute(const Pds::Matrix &A);

    /** 
     *  \brief Calcula el valor quadrático medio de una matriz.
     *
     *  \f[ Pds::MeanSquare(A)=\frac{1}{Nlin~Ncol}\sum \limits_{i}^{Nlin} \sum \limits_{j}^{Ncol} {|a_{ij}|}^2 \f]
     *  \return Retorna el valor cuadrático medio. En caso de que la matriz sea vacía
     *  se retorna Pds::Ra::Nan.
     *  \ingroup MathMatrixGroup
     */
    double MeanSquare(const Pds::Matrix &A);


    /** 
     *  \brief Calcula el valor  de la suma quadrática de una matriz.
     *
     *  \f[ Pds::SumSquare(A)=\sum \limits_{i}^{Nlin} \sum \limits_{j}^{Ncol} {|a_{ij}|}^2 \f]
     *  \return Retorna el valor de la suma cuadrática. En caso de que la matriz sea vacía
     *  se retorna Pds::Ra::Nan.
     *  \ingroup MathMatrixGroup
     */
    double SumSquare(const Pds::Matrix &A);

    /** 
     *  \brief Calcula el valor dela norma (Frobenius) de una matriz.
     *
     *  \f[ Pds::Norm(A)=\sqrt{\sum \limits_{i}^{Nlin} \sum \limits_{j}^{Ncol} {|a_{ij}|}^2} \f]
     *  \return Retorna el valor de la norma de Frobenius. En caso de que la matriz sea vacía
     *  se retorna Pds::Ra::Nan.
     *  \ingroup MathMatrixGroup
     */
    double Norm(const Pds::Matrix &A);
    
/**
 * @}
 */


/** @name Funciones de activación
 *  Descripcion de algunas funciones matematicas que usan  Pds::Matrix.
 * @{
 */
    /** 
     *  \brief Retorna el resultado de evaluar la funcion
     *  <a href="https://www.doi.org/10.1109/IJCNN.2018.8489043">SQNL</a>.
     *
     *  \f[ sqnl(x)=+1 \quad if(2<x)\f]
     *  \f[ sqnl(x)=x-\frac{x^2}{4} \quad if(0\leq x\leq 2)\f]
     *  \f[ sqnl(x)=x+\frac{x^2}{4} \quad if(-2 \leq x< 0)\f]
     *  \f[ sqnl(x)=-1 \quad if(x<-2)\f]
     *  \param[in] x La variable a evaluar
     *  \return Retorna la varaible evaluada.
     *  \ingroup MathMatrixGroup
     */
    double SQNL(double x);

    /** 
     *  \brief Retorna el resultado de evaluar elemento a elemento la funcion
     *  <a href="https://www.doi.org/10.1109/IJCNN.2018.8489043">SQNL</a>.
     *
     *  \f[ sqnl(x)=+1 \quad if(2<x)\f]
     *  \f[ sqnl(x)=x-\frac{x^2}{4} \quad if(0\leq x\leq 2)\f]
     *  \f[ sqnl(x)=x+\frac{x^2}{4} \quad if(-2 \leq x< 0)\f]
     *  \f[ sqnl(x)=-1 \quad if(x<-2)\f]
     *  \f[ sqnl(A)\f]
     *  \param[in] A La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \see Pds::Matrix::Apply()
     *  \ingroup MathMatrixGroup
     */
    Pds::Matrix SQNL(const Pds::Matrix &A);
    

    /** 
     *  \brief Retorna el resultado de evaluar la funcion gaussiana.
     *
     *  \f[ gaussian(x)=e^{-x^2} \f]
     *  \param[in] x La variable a evaluar
     *  \return Retorna la variable evaluada.
     *  \ingroup MathMatrixGroup
     */
    double Gaussian(double x);

    /** 
     *  \brief Retorna el resultado de evaluar elemento a elemento la funcion gaussiana.
     *
     *  \f[ gaussian(A)=e^{-A^2} \f]
     *  \param[in] A La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \see Pds::Matrix::Apply()
     *  \ingroup MathMatrixGroup
     */
    Pds::Matrix Gaussian(const Pds::Matrix &A);
 
    /** 
     *  \brief Retorna el resultado de evaluar elemento a elemento la funcion tangente hiperbólico.
     *
     *  \f[ tanh{A}=\frac{e^{2A}-1}{e^{2A}+1} \f]
     *  \param[in] A La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \see Pds::Matrix::Apply()
     *  \ingroup MathMatrixGroup
     */
    Pds::Matrix Tanh(const Pds::Matrix &A);

     /** 
     *  \brief Retorna el resultado de evaluar elemento a elemento la funcion sigmoid.
     *
     *  \f[ \frac{1}{1+e^{-x}} \f]
     *  \param[in] x La varaible a evaluar
     *  \return Retorna la variable evaluada.
     *  \ingroup MathMatrixGroup
     */
    double Sigmoid(double x);
    
     /** 
     *  \brief Retorna el resultado de evaluar elemento a elemento la funcion sigmoid.
     *
     *  \f[ \frac{1}{1+e^{-A}} \f]
     *  \param[in] A La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \see Pds::Matrix::Apply()
     *  \ingroup MathMatrixGroup
     */
    Pds::Matrix Sigmoid(const Pds::Matrix &A);

/**
 * @}
 */


/** @name Funcione de analisis combinatorio
 *  Descripcion de algunas funciones matematicas que usan  Pds::Matrix.
 * @{
 */
    /** 
     *  \brief Evalúa  factorial de n, igual a n!.
     *  
     *  \f[ y=n!\equiv n(n-1)(n-2)(n-3)...1 \f]
     *  
     *  Tiene problemas de presición, cuando n es muy grande.
     *  \param[in] n Valor de entrada.
     *  \return El valor de n!.
     *  \ingroup MathMatrixGroup
     */
    unsigned int Factorial(unsigned int n);


    /** 
     *  \brief Retorna el combinatorio (n,k)
     *  
     *  \f[ {n \choose k}=\frac{n!}{k!(n-k)!} \f] 
     *  \param[in] n Valor superior del combinatorio.
     *  \param[in] k Valor inferior del combinatorio.
     *  \return El valor del combinatorio (n,k). Si k>n retorna 0.
     *  \ingroup MathMatrixGroup
     */
    unsigned int NchooseK(unsigned int n,unsigned int k);

    /** 
     *  \brief Retorna el combinatorio (n,k)
     *  
     *  \f[ \left({n \choose k}\right)={{n+k-1} \choose k} \f] 
     *  \param[in] n Valor superior del combinatorio.
     *  \param[in] k Valor inferior del combinatorio.
     *  \return El valor del combinatorio (n,k).
     *  \ingroup MathMatrixGroup
     */
    unsigned int NmultichooseK(unsigned int n,unsigned int k);

/**
 * @}
 */


/** @name Funciones de aredondamento a enteros
 *  Descripcion de algunas funciones matematicas que usan  Pds::Matrix.
 * @{
 */
     /** 
     *  \brief Retorna el resultado de evaluar la funcion UnitStep().
     *
     *  \f[ if(x\geq 0)\quad return\quad 1 \f]
     *  \f[ else \quad return\quad 0 \f]
     *  \param[in] x La varaible a evaluar
     *  \return Retorna la varaible evaluada.
     *  \ingroup MathMatrixGroup
     */
    double UnitStep(double x);

     /** 
     *  \brief Retorna el resultado de evaluar la funcion UnitStep().
     *
     *  \f[ if(x\geq 0)\quad return\quad 1 \f]
     *  \f[ else \quad return\quad 0 \f]
     *  \f[ UnitStep(A) \f]
     *  \param[in] A La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \ingroup MathMatrixGroup
     */
    Pds::Matrix UnitStep(const Pds::Matrix &A);

     /** 
     *  \brief Retorna el resultado de evaluar la funcion UnitRamp().
     *
     *  \f[ if(x\geq 0)\quad return\quad x \f]
     *  \f[ else \quad return\quad 0 \f]
     *  \param[in] x La varaible a evaluar
     *  \return Retorna la varaible evaluada.
     *  \ingroup MathMatrixGroup
     */
    double UnitRamp(double x);

     /** 
     *  \brief Retorna el resultado de evaluar la funcion UnitRamp().
     *
     *  \f[ if(x\geq 0)\quad return\quad x \f]
     *  \f[ else \quad return\quad 0 \f]
     *  \f[ UnitRamp(A) \f]
     *  \param[in] A La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \ingroup MathMatrixGroup
     */
    Pds::Matrix UnitRamp(const Pds::Matrix &A);

    
     /** 
     *  \brief Retorna el resultado de evaluar la funcion Sign.
     *
     *  \f[ if(x>0)\quad return\quad+1 \f]
     *  \f[ if(x=0)\quad return\quad~0 \f]
     *  \f[ if(x<0)\quad return\quad-1 \f]
     *  \param[in] x La varaible a evaluar
     *  \return Retorna la varaible evaluada.
     *  \ingroup MathMatrixGroup
     */
    double Sign(double x);



     /** 
     *  \brief Retorna el resultado de evaluar elemento a elemento la funcion Sign.
     *
     *  \f[ if(x>0)\quad sign(x)\quad return\quad+1 \f]
     *  \f[ if(x=0)\quad sign(x)\quad return\quad~0 \f]
     *  \f[ if(x<0)\quad sign(x)\quad return\quad-1 \f]
     *  \f[ sign(A) \f]
     *  \param[in] A La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \ingroup MathMatrixGroup
     */
    Pds::Matrix Sign(const Pds::Matrix &A);
    
    /** 
     *  \brief Retorna el resultado de evaluar elemento a elemento la funcion round.  
     *
     *  \f[ round(A) \f]
     *  \param[in] A La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \see Pds::Matrix::Apply()
     *  \ingroup MathMatrixGroup
     */
    Pds::Matrix Round(const Pds::Matrix &A);


/**
 * @}
 */


/** @name Funciones de teoria de la informacion
 *  Descripcion de algunas funciones matematicas que usan  Pds::Matrix.
 * @{
 */
     /** 
     *  \brief Retorna el resultado de evaluar la funcion Entropia binária.
     *
     *  \f[ h_b(x)=-x~log_2(x)-(1-x) log_2(1-x) \f]
     *  \param[in] x La varaible a evaluar
     *  \return Retorna lavaraible evaluada.
     *  \ingroup MathMatrixGroup
     */
    double Hb(double x);

     /** 
     *  \brief Retorna el resultado de evaluar elemento a elemento la funcion Entropia binária.
     *
     *  \f[ h_b(x)=-x~log_2(x)-(1-x) log_2(1-x) \f]
     *  \f[ h_b(A) \f]
     *  \param[in] A La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \see Pds::Matrix::Apply()
     *  \ingroup MathMatrixGroup
     */
    Pds::Matrix Hb(const Pds::Matrix &A);

    /** 
     *  \brief Retorna el valor \f$p\f$ de la función de entropía binaria para un
     *  valor de \f$h\approx h_b(p)\f$.
     *  
     *  \f[h_b(p)\equiv -p~log_2(p)-(1-p)~log_2(1-p)\f] 
     *  \param[in] h Valor de entrada.
     *  \return El valor de \f$p\f$ en \f$h\approx h_b(p)\f$. La busqueeda finaliza quando \f$|h-H_b(p)|<|\frac{E(h)}{1000000}|\f$,
     *  \f$ E(h)=h +(1-2 h) u(h-0.5)\f$ .
     *  \ingroup MathMatrixGroup
     */
    double HbInv(double h);

    /** 
     *  \brief Retorna el resultado de evaluar elemento a elemento la funcion inversa de la Entropia binária.
     *  
     *  \f[h_b(p)\equiv -p~log_2(p)-(1-p)~log_2(1-p)\f] 
     *  \param[in] A La matriz a evaluar
     *  \return El valor de \f$p\f$ en \f$h\approx h_b(p)\f$. La busqueeda finaliza quando \f$|h-H_b(p)|<|\frac{E(h)}{1000000}|\f$,
     *  \f$ E(h)=h +(1-2 h) u(h-0.5)\f$ .
     *  \see Pds::Matrix::Apply()
     *  \ingroup MathMatrixGroup
     */
    Pds::Matrix HbInv(const Pds::Matrix &A);

/**
 * @}
 */



/** @name Funciones varias
 *  Descripcion de algunas funciones matematicas que usan  Pds::Matrix.
 * @{
 */
    
    /** 
     *  \brief Retorna el resultado de evaluar elemento a elemento la funcion valor absoluto.  
     *
     *  \f[ |A| \f]
     *  \param[in] A La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \see Pds::Matrix::Apply()
     *  \ingroup MathMatrixGroup
     */
    Pds::Matrix Abs(const Pds::Matrix &A);
    
     /** 
     *  \brief Retorna el resultado de evaluar la funcion logit.
     *
     *  \f[ log\left(\frac{x}{1-x}\right) \f]
     *  \param[in] x La variable a evaluar
     *  \return Retorna la variable evaluada.
     *  \ingroup MathMatrixGroup
     */
    double Logit(double x);

     /** 
     *  \brief Retorna el resultado de evaluar elemento a elemento la funcion logit.
     *
     *  \f[ log\left(\frac{A}{1-A}\right) \f]
     *  \param[in] A La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \see Pds::Matrix::Apply()
     *  \ingroup MathMatrixGroup
     */
    Pds::Matrix Logit(const Pds::Matrix &A);

     /** 
     *  \brief Retorna el resultado de evaluar la funcion sinc.
     *
     *  \f[ sinc(x)=\frac{sin(x)}{x} \f]
     *  \param[in] x La variable a evaluar
     *  \return Retorna la variable evaluada.
     *  \ingroup MathMatrixGroup
     */
    double Sinc(double x);

     /** 
     *  \brief Retorna el resultado de evaluar elemento a elemento la funcion sinc.
     *
     *  \f[ sinc(x)=\frac{sin(x)}{x} \f]
     *  \f[ sinc(A) \f]
     *  \param[in] A La matriz a evaluar
     *  \return Retorna la matriz evaluada.
     *  \see Pds::Matrix::Apply()
     *  \ingroup MathMatrixGroup
     */
    Pds::Matrix Sinc(const Pds::Matrix &A);
/**
 * @}
 */



/** @name Funciones de integración
 *  Descripcion de algunas funciones matematicas que usan  Pds::Matrix.
 * @{
 */

    /** 
     *  \brief Evalúa la integral de a-->b de la función f(x), aplicando la regla de 
     *  Simpson con n divisiones, si n no es par internamente la función hace n=n+1.
     *  
     *  \f[S_n=\int_{a}^{b}f(x)dx\f] 
     *  \f[h=\frac{b-a}{n}\f] 
     *  \f[x_i=a+h~i\f] 
     *  \f[S_n=\frac{h}{3}(f(x_0)+f(x_n)+4\left [ f(x_1)+f(x_3)+\cdots +f(x_{n-1}) \right ]+2\left [ f(x_2)+f(x_4)+\cdots +f(x_{n-2}) \right ])\f] 
     *  \param[in] f La función a integrar.
     *  \param[in] a Límite inferior de la integral.
     *  \param[in] b Límite superior de la integral.
     *  \param[in] n Es el número de divisiones.
     *  \return El valor de la integral o cero si hubo un error, ejemplo b<a o n==0.
     *  \ingroup MathMatrixGroup
     */
    double SimpsonIntegration(double (*f)(double), double a,double b,unsigned int n);
    
    /** 
     *  \brief Evalúa la integral de a-->b de la función f(x,r), aplicando la regla de 
     *  Simpson con n divisiones, si n no es par internamente la función hace n=n+1.
     *  
     *  \f[S_n=\int_{a}^{b}f(x,r)dx\f] 
     *  \f[h=\frac{b-a}{n}\f] 
     *  \f[x_i=a+h~i\f] 
     *  \f[S_n=\frac{h}{3}(f(x_0,r)+f(x_n,r)+4\left [ f(x_1,r)+f(x_3,r)+\cdots +f(x_{n-1},r) \right ]+2\left [ f(x_2,r)+f(x_4,r)+\cdots +f(x_{n-2},r) \right ])\f] 
     *  \param[in] f La función a integrar.
     *  \param[in] r Parámetro de la función.
     *  \param[in] a Límite inferior de la integral.
     *  \param[in] b Límite superior de la integral.
     *  \param[in] n Es el número de divisiones.
     *  \return El valor de la integral o cero si hubo un error, ejemplo b<a o n==0.
     *  \ingroup MathMatrixGroup
     */
    double SimpsonIntegration(double (*f)(double,double),double r, double a,double b,unsigned int n);
    
    /** 
     *  \brief Evalúa la integral de a-->infinito de la función f(x), aplicando el 
     *  cambio de variable u<--1/(x+1) para integrar de 0-->1/(a+1) y ejecutar luego 
     *  la regla de Simpson con n divisiones, si n no es par internamente la 
     *  función hace n=n+1. Además es necesario que el limite de f(1/u-1)/u^2-->0 cuando u-->0.
     *  
     *  \f[S_t=\left \{ \begin{matrix}
                ~&~&\int_{x_{0}=a}^{ \infty }f(x)dx &  a \geq 0 \\
                \int_{a}^{0}f(x)dx &+ &\int_{x_{0}=0}^{ \infty }f(x)dx &  a < 0 
           \end{matrix}\right.\f] 
     *  
     *  \f[\int_{x_{0}}^{ \infty }f(x)dx \xrightarrow{u=\frac{1}{x+1}} \int_{0}^{ \frac{1}{x_{0}+1} }\frac{f(\frac{1}{u}-1)}{u^2}du\f] 
     *  Se asume que
     *  \f[ \lim_{u \rightarrow 0+}\frac{f(\frac{1}{u}-1)}{u^2}=0 \f] 
     *
     *  \param[in] f La función a integrar.
     *  \param[in] a Límite inferior de la integral.
     *  \param[in] n Es el número de divisiones.
     *  \return El valor de la integral o cero si hubo un error, ejemplo b<a o n<=0.
     *  \ingroup MathMatrixGroup
     */
    double ImproperIntegration(double (*f)(double), double a,unsigned int n);


    /** 
     *  \brief Evalúa la integral de a-->infinito de la función f(x,r) en x, aplicando el 
     *  cambio de variable u<--1/(x+1) para integrar de 0-->1/(a+1) y ejecutar luego 
     *  la regla de Simpson con n divisiones, si n no es par internamente la 
     *  función hace n=n+1. Además es necesario que el limite de f(1/u-1,r)/u^2-->0 cuando u-->0.
     *  
     *  \f[S_t=\left \{ \begin{matrix}
                ~&~&\int_{x_{0}=a}^{ \infty }f(x,r)dx &  a \geq 0 \\
                \int_{a}^{0}f(x,r)dx &+ &\int_{x_{0}=0}^{ \infty }f(x,r)dx &  a < 0 
           \end{matrix}\right.\f] 
     *  
     *  \f[\int_{x_{0}}^{ \infty }f(x,r)dx \xrightarrow{u=\frac{1}{x+1}} \int_{0}^{ \frac{1}{x_{0}+1} }\frac{f(\frac{1}{u}-1,r)}{u^2}du\f] 
     *  Se asume que
     *  \f[ \lim_{u \rightarrow 0+}\frac{f(\frac{1}{u}-1,r)}{u^2}=0 \f] 
     *
     *  \param[in] f La función a integrar.
     *  \param[in] r Valor del parámetro .
     *  \param[in] a Límite inferior de la integral.
     *  \param[in] n Es el número de divisiones.
     *  \return El valor de la integral o cero si hubo un error, ejemplo b<a o n<=0.
     *  \ingroup MathMatrixGroup
     */
    double ImproperIntegration(double (*f)(double,double),double r, double a,unsigned int n);
/**
 * @}
 */

} //namespace Pds
/**
 * @}
 */

#endif

