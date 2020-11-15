/*
 * FuncVector.hpp
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

/** \file FuncVector.hpp
 *  \author Fernando Pujaico Rivera
 *  \brief Funciones que trabajan con vectores.
 *  
 *  <br>Estas funciones trabajan con una vector de la forma.<br>
 *  \image html vecto.png "Matriz de NlinxNcol"
 *  \b Nlin es el número de lineas y \b Ncol es el número de columnas.
 */



#ifndef __PDS_VECTORFUNC_HPP__
#define __PDS_VECTORFUNC_HPP__


/** \defgroup FuncVectorGroup Funciones Pds::Vector -- Básicos
 *  \brief Funciones que usan Pds::Vector, Ejemplo:  Pds::LinSpace(), Pds::GeomSpace(), Pds::X2D(), Pds::Y2D(), Pds::X3D(), etc 
 *  <div class="fragment"> \#include <Pds/FuncVector> </div>
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


namespace Pds{

/** @name funciones con vectores especiales
 *  Descripción de algunas funciones que usan  Pds::Vector.
 * @{
 */

    /** 
     *  \brief Retorna un vector con elementos desde start hasta end con
     * N elementos.
     *
   \f[
\left(\begin{matrix}
a_{0} \\ 
a_{1} \\
... \\
a_{N-1} 
\end{matrix}\right)
   \f]
    *
   \f[
\alpha \leftarrow \frac{end-start}{N-1}
   \f]
    *
   \f[
a_{i} \leftarrow i \alpha +start
   \f]
     *  \param[in] start Inicio del espacio linear.
     *  \param[in] end Final del espacio linear.
     *  \param[in] N Numero de elementos del vetor.
     *  \return Retorna la matriz diagonal.
     *  \ingroup FuncVectorGroup
     */
    Vector LinSpace(double start,double end,unsigned int N);


    /** 
     *  \brief Retorna un vector con elementos desde start hasta end con
     * N elementos.
     *
   \f[
\left(\begin{matrix}
a_{0} \\ 
a_{1} \\
a_{2} \\
... \\
a_{N-1} 
\end{matrix}\right) \equiv
\left(\begin{matrix}
a_{0} \\ 
\alpha^1 a_{0} \\
\alpha^2 a_{0} \\
... \\
\alpha^{N-1} a_{0} 
\end{matrix}\right)
   \f]
    *
   \f[
\alpha \leftarrow  {\left(\frac{end}{start}\right)}^{\frac{1.0}{N-1}} 
   \f]
    *
   \f[
a_{i} \leftarrow  {\alpha}^{i} start
   \f]
     *  \param[in] start Inicio del espacio linear.
     *  \param[in] end Final del espacio linear.
     *  \param[in] N Numero de elementos del vetor.
     *  \return Retorna la matriz diagonal.
     *  \ingroup FuncVectorGroup
     */
    Vector GeomSpace(double start,double end,unsigned int N);

/**
 * @}
 */

/** @name funciones para crear vectores eje en 2 dimensiones
 *  Descripción de algunas funciones que usan  Pds::Vector.
 * @{
 */
    
    /** 
     *  \brief Retorna una matriz vector columna eje X en 2 dimensiones.
     *
   \f[
\left(\begin{matrix}
1 \\ 
0
\end{matrix}\right)
   \f]
     *  \return Retorna una matriz vector columna eje X en 2 dimensiones.
     *  \ingroup FuncVectorGroup
     */
    Vector X2D(void);
    
    /** 
     *  \brief Retorna una matriz vector columna eje Y en 2 dimensiones.
     *
   \f[
\left(\begin{matrix}
0 \\ 
1
\end{matrix}\right)
   \f]
     *  \return Retorna una matriz vector columna eje Y en 2 dimensiones.
     *  \ingroup FuncVectorGroup
     */
    Vector Y2D(void);
/**
 * @}
 */

/** @name funciones para crear vectores eje en 3 dimensiones
 *  Descripción de algunas funciones que usan  Pds::Vector.
 * @{
 */
    
    /** 
     *  \brief Retorna una matriz vector columna eje X en 3 dimensiones.
     *
   \f[
\left(\begin{matrix}
1 \\ 
0 \\
0
\end{matrix}\right)
   \f]
     *  \return Retorna una matriz vector columna eje X en 3 dimensiones.
     *  \ingroup FuncVectorGroup
     */
    Vector X3D(void);
    
    /** 
     *  \brief Retorna una matriz vector columna eje Y en 3 dimensiones.
     *
   \f[
\left(\begin{matrix}
0 \\ 
1 \\
0
\end{matrix}\right)
   \f]
     *  \return Retorna una matriz vector columna eje Y en 3 dimensiones.
     *  \ingroup FuncVectorGroup
     */
    Vector Y3D(void);
    
    /** 
     *  \brief Retorna una matriz vector columna eje Z en 3 dimensiones.
     *
   \f[
\left(\begin{matrix}
0 \\ 
0 \\
1
\end{matrix}\right)
   \f]
     *  \return Retorna una matriz vector columna eje Z en 3 dimensiones.
     *  \ingroup FuncVectorGroup
     */
    Vector Z3D(void);
/**
 * @}
 */


}
/**
 * @}
 */

#endif

