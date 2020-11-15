/*
 * FuncMatrixRotation.hpp
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

/** \file FuncMatrixRotation.hpp
 *  \author Fernando Pujaico Rivera
 *  \brief Funciones que trabajan con matrices.
 *  
 *  <br>Estas funciones trabajan con una matriz de la forma.<br>
 *  \image html matrix.png "Matriz de NlinxNcol"
 *  \b Nlin es el número de lineas y \b Ncol es el número de columnas.
 */



#ifndef __PDS_MATRIXROTATION_HPP__
#define __PDS_MATRIXROTATION_HPP__


/** \defgroup FuncMatrixRotationGroup Funciones Pds::Matrix -- Rotación
 *  \brief Funciones que usan Pds::Matrix, Ejemplo: Pds::Rot2D(), Pds::RotX(), Pds::RotY(), Pds::RotZ(), etc
 *  <div class="fragment"> \#include <Pds/FuncMatrixRotation> </div>
 *  
 *  <br>Estas funciones trabajan con una matriz de la forma.<br>
   \f[
\mathbf{A}=\left(\begin{matrix}
a_{00} & a_{01} & \hdots & a_{0(Ncol-1)}\\ 
a_{10} & a_{11} & \hdots & a_{1(Ncol-1)}\\
\vdots & \vdots & \vdots & \vdots \\
a_{(Nlin-2)0} & a_{(Nlin-2)1} & \hdots & a_{(Nlin-2)(Ncol-1)}\\ 
a_{(Nlin-1)0} & a_{(Nlin-1)1} & \hdots & a_{(Nlin-1)(Ncol-1)}\\
\end{matrix}\right)\equiv A_{(Nlin-1),(Ncol-1)}
   \f]
   \f[
A_{(Nlin-1),(Ncol-1)}\equiv [a_{i,j}]_{(Nlin-1),(Ncol-1)}
   \f]
 *  \b nlin es el número de lineas y \b ncol es el número de columnas.
 *  
 * Informacion adicional puede ser encontrada en @cite tutorialmatvec
 * @{
 */


#include <Pds/Matrix>


namespace Pds{

/** @name funciones para rotar coordenadas en 2 dimensines
 *  Descripción de algunas funciones que usan  Pds::Matrix.
 * @{
 */
    
    /** 
     *  \brief Retorna una matriz de rotación anti-horaria en 2 dimensiones.
     *
   \f[
R_{\theta}=\left(\begin{matrix}
cos(\theta)&-sin(\theta) \\ 
sin(\theta)&cos(\theta)
\end{matrix}\right)=\left( \begin{matrix} e_{1}(\theta) & e_{2}(\theta) \end{matrix} \right)
   \f]
     * El punto \f$P\f$ rotacionado puede ser encontrado ahora en \f$P_R\f$
   \f[ P_R = R_{\theta} P \f]
     *
     *  \param[in] theta Ángulo de rotación anti-horaria en radianes.
     *  \return Retorna una matriz de rotación anti-horaria en 2 dimensiones.
     *  \ingroup FuncMatrixRotationGroup
     */
    Matrix Rot2D(double theta);
    
    /** 
     *  \brief Retorna una matriz de rotación anti-horaria al rededor
     *  del eje X en 3 dimensiones.
     *
   \f[
R_{X}=\left(\begin{matrix}
1&0&0\\
0&cos(\theta)&-sin(\theta) \\ 
0&sin(\theta)&cos(\theta)
\end{matrix}\right)=\left( \begin{matrix} e_{1} & e_{2}(\theta) & e_{3}(\theta) \end{matrix} \right)
   \f]
     * El punto \f$P\f$ rotacionado puede ser encontrado ahora en \f$P_R\f$
   \f[ P_R = R_{X} P \f]
     *
     *  \param[in] RadAngle Ángulo de rotación horaria en radianes.
     *  \return Retorna una matriz de rotación anti-horaria al rededor
     *  del eje X en 3 dimensiones.
     *  \ingroup FuncMatrixRotationGroup
     */
    Matrix RotX(double RadAngle);
    
    /** 
     *  \brief Retorna una matriz de rotación anti-horaria al rededor
     *  del eje Y en 3 dimensiones.
     *
   \f[
R_{Y}=\left(\begin{matrix}
cos(\theta)&0&sin(\theta)\\
0&1&0 \\ 
-sin(\theta)&0&cos(\theta)
\end{matrix}\right)=\left(\begin{matrix} e_{1}(\theta) & e_{2} & e_{3}(\theta) \end{matrix}\right)
   \f]
     * El punto \f$P\f$ rotacionado puede ser encontrado ahora en \f$P_R\f$
   \f[ P_R = R_{Y} P \f]
     *
     *  \param[in] RadAngle Ángulo de rotación horaria en radianes.
     *  \return Retorna una matriz de rotación anti-horaria al rededor
     *  del eje Y en 3 dimensiones.
     *  \ingroup FuncMatrixRotationGroup
     */
    Matrix RotY(double RadAngle);
    
    /** 
     *  \brief Retorna una matriz de rotación anti-horaria al rededor
     *  del eje Z en 3 dimensiones.
     *
   \f[
R_{Z}=\left(\begin{matrix}
cos(\theta)&-sin(\theta)&0\\
sin(\theta)&cos(\theta)&0 \\ 
0&0&1
\end{matrix}\right)=\left( \begin{matrix}e_{1}(\theta) &e_{2}(\theta) &e_{3} \end{matrix}\right)
   \f]
     * El punto \f$P\f$ rotacionado puede ser encontrado ahora en \f$P_R\f$
   \f[ P_R = R_{Z} P \f]
     *
     *  \param[in] RadAngle Ángulo de rotación horaria en radianes.
     *  \return Retorna una matriz de rotación anti-horaria al rededor
     *  del eje Z en 3 dimensiones.
     *  \ingroup FuncMatrixRotationGroup
     */
    Matrix RotZ(double RadAngle);
/**
 * @}
 */

}
/**
 * @}
 */

#endif

