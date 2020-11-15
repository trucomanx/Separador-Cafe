/*
 * FuncVectorPoly.hpp
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

/** \file FuncVectorPoly.hpp
 *  \author Fernando Pujaico Rivera
 *  \brief Funciones que trabajan con Polinomios.
 *  
 *  <br>Estas funciones trabajan con una vector de la forma.<br>
 *  \image html vecto.png "Matriz de NlinxNcol"
 *  \b Nlin es el número de lineas y \b Ncol es el número de columnas.
 */



#ifndef __PDS_VECTORPOLY_HPP__
#define __PDS_VECTORPOLY_HPP__


/** \defgroup VectorAlgebraGroup Funciones Pds::Vector -- Polinómios
 *  \brief Funciones que usan Pds::Vector, Ejemplo: Pds::PolyMat(), Pds::PolyFit(), Pds::PolyVal(), etc 
 *  <div class="fragment"> \#include <Pds/FuncVectorPoly> </div>
 *  
 *  <br>Estas funciones trabajan con una matriz de la forma.<br>
   \f[
\left(\begin{matrix}
a_{0} \\ 
a_{1} \\
... \\
a_{Nlin-1} 
\end{matrix}\right)
   \f]
 *  
 * Informacion adicional puede ser encontrada en @cite tutorialmatvec
 * @{
 */


#include <Pds/Vector>
#include <Pds/Matrix>
#include <Pds/RaDefines>

namespace Pds{



/** @name funciones de fitting 
 *  Descripción de algunas funciones que usan  Pds::Vector.
 * @{
 */

    /** 
     *  \brief Retorna Un polinomio de grado N con el menor error
     *  cuadrático medio para el par X e Y.
     *
   \f[
A=\left(\begin{matrix}
X^0 &  X^1  & X^2  & ... & X^N \\
\end{matrix}\right)
   \f]
   \f[
P \leftarrow (A^T A )^{-1}A^T Y
   \f]
   \f[
p(x)= p_0 x^0 + p_1 x^1 + p_2 x^2 + ... + p_{N} x^N 
   \f]
     *  \param[in] X Vector a evaluar.
     *  \param[in] Y Vector a evaluar.
     *  \param[in] N Orden del polinomio.
     *  \return Retorna un vector \f$P=[p_0~p_1~p_2~...p_N]\f$ que representa um polinomio \f$p(x)\f$ de grado N con el menor error
     *  cuadrático medio para el par X e Y.
     *  \ingroup VectorAlgebraGroup
     */
    Pds::Vector PolyFit(Pds::Vector X, Pds::Vector Y, unsigned int N);

/**
 * @}
 */

/** @name funciones básicas
 *  Descripción de algunas funciones que usan  Pds::Vector.
 * @{
 */
    
    /** 
     *  \brief Retorna la Matriz de Vandermonde del vector X de M elementos.
     *
   \f[
\left(\begin{matrix}
1 & x_0^1 & x_0^2   & ... &  x_0^{N-1} & x_0^N \\
1 & x_1^1 & x_1^2   & ... &  x_1^{N-1} & x_1^N \\
\hdots & \hdots    & ... & \hdots & \hdots & \hdots \\ 
1 & x_{M-1}^1 & x_{M-1}^2   & ... &  x_{M-1}^{N-1} & x_{M-1}^N \\
\end{matrix}\right)
   \f]
     *  \param[in] X Vector a evaluar.
     *  \param[in] N Orden del polinomio.
     *  \return Retorna una matriz con el resultado.
     *  \ingroup VectorAlgebraGroup
     */
    Pds::Matrix PolyMat(Pds::Vector X, unsigned int N);
        
    /** 
     *  \brief Retorna la Matriz de Vandermonde del vector X de M elementos.
     *
   \f[
\left(\begin{matrix}
1 & x_0^1 & x_0^2   & ... &  x_0^{N-1} & x_0^N \\
\end{matrix}\right)
   \f]
     *  \param[in] x Valor a evaluar.
     *  \param[in] N Orden del polinomio.
     *  \return Retorna una matriz con el resultado.
     *  \ingroup VectorAlgebraGroup
     */
    Pds::Matrix PolyMat(double x, unsigned int N);
    
    /** 
     *  \brief Retorna El resultado de evaluar un polinomio P de grado N.
     *
   \f[
y= p_0 x^0 + p_1 x^1 + p_2 x^2 + ... + p_{N-1} x^{N-1} + p_{N} x^N 
   \f]
   \f[
Y= P(X)
   \f]
     *  \param[in] P Polinomio a evaluar.
     *  \param[in] X Vector a evaluar.
     *  \return Retorna Y=P(X).
     *  \ingroup VectorAlgebraGroup
     */
    Pds::Vector PolyVal(Pds::Vector P,Pds::Vector X);
    
    /** 
     *  \brief Retorna El resultado de evaluar un polinomio P de grado N.
     *
   \f[
y= p_0 x^0 + p_1 x^1 + p_2 x^2 + ... + p_{N-1} x^{N-1} + p_{N} x^N 
   \f]
   \f[
Y= P(X)
   \f]
     *  \param[in] P Polinomio a evaluar.
     *  \param[in] X Matriz a evaluar.
     *  \return Retorna Y=P(X).
     *  \ingroup VectorAlgebraGroup
     */
    Pds::Matrix PolyVal(Pds::Vector P,Pds::Matrix X);
    
    /** 
     *  \brief Retorna El resultado de evaluar un polinomio P de grado N.
     *
   \f[
y= p_0 x^0 + p_1 x^1 + p_2 x^2 + ... + p_{N-1} x^{N-1} + p_{N} x^N 
   \f]
   \f[
Y= P(X)
   \f]
     *  \param[in] P Polinomio a evaluar.
     *  \param[in] x Variable a avaliar.
     *  \return Retorna Y=P(x).
     *  \ingroup VectorAlgebraGroup
     */
    Pds::Vector PolyVal(Pds::Vector P,double x);

/**
 * @}
 */

/** @name funciones relativas al calculo
 *  Descripción de algunas funciones que usan  Pds::Vector.
 * @{
 */
    
    
    /** 
     *  \brief Retorna la derivada D del polinomio P(x).
     *
   \f[
P(x) = p_0 x^0 + p_1 x^1 + p_2 x^2 + ... + p_{N-1} x^{N-1} + p_{N} x^N 
   \f]
   \f[
D \leftarrow  \frac{ d^NP(x)}{dx^N} 
   \f]
     *  \param[in] P Polinomio a evaluar.
     *  \param[in] N Orden de la derivada, por defecto es la primera derivada.
     *  \return Retorna la N-esima derivada.
     *  \ingroup VectorAlgebraGroup
     */
    Pds::Vector PolyDer(Pds::Vector P,unsigned int N=1);


/**
 * @}
 */

/** @name funciones aritméticas
 *  Descripción de algunas funciones que usan  Pds::Vector.
 * @{
 */
    /** 
     *  \brief Retorna la multiplicación de los polinomio P(x) e Q(x).
     *
   \f[
P(x) = p_0 x^0 + p_1 x^1 + p_2 x^2 + ... + p_{N-1} x^{N-1} + p_{N} x^N 
   \f]
   \f[
Q(x) = q_0 x^0 + q_1 x^1 + q_2 x^2 + ... + q_{M-1} x^{M-1} + q_{M} x^M 
   \f]
   \f[
D \leftarrow  P(x)Q(x)
   \f]
     *  \param[in] P Polinomio a multiplicar.
     *  \param[in] Q Polinomio a multiplicar.
     *  \return La multiplicación de los polinomios, \f$ P(x)Q(x)\f$.
     *  \ingroup VectorAlgebraGroup
     */
    Pds::Vector PolyMul(Pds::Vector &P,Pds::Vector &Q);

    /** 
     *  \brief Retorna la suma de los polinomio P(x) e Q(x).
     *
   \f[
P(x) = p_0 x^0 + p_1 x^1 + p_2 x^2 + ... + p_{N-1} x^{N-1} + p_{N} x^N 
   \f]
   \f[
Q(x) = q_0 x^0 + q_1 x^1 + q_2 x^2 + ... + q_{M-1} x^{M-1} + q_{M} x^M 
   \f]
   \f[
D \leftarrow  P(x)+Q(x)
   \f]
     *  \param[in] P Polinomio a sumar.
     *  \param[in] Q Polinomio a sumar.
     *  \return La suma de los polinomios, \f$ P(x)+Q(x)\f$.
     *  \ingroup VectorAlgebraGroup
     */
    Pds::Vector PolyAdd(Pds::Vector &P,Pds::Vector &Q);
/**
 * @}
 */


}
/**
 * @}
 */

#endif

