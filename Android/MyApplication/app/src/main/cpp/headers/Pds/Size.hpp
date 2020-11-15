/*
 * Size.hpp
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

/** \file Size.hpp
 *  \author Fernando Pujaico Rivera
 *  \date 01-09-2018
 *  \brief Funciones que trabajan con objetos tipo Size.
 *  
 */



#ifndef __PDS_SIZE_HPP__
#define __PDS_SIZE_HPP__

#include <string>

/** \defgroup SizeGroup Métodos Pds::Size
 *  \brief Metodos de la clase Pds::Size, el tamaño de una matriz 
 *  <div class="fragment"> \#include <Pds/Size> </div>
 *  
 *  
 * Informacion adicional puede ser encontrada en @cite tutorialmatvec
 * @{
 */

namespace Pds{

class Matrix;

/*! \class Size
 *  \brief La clase tipo  Pds::Size .
 *  Esta clase genera un objeto con dos parametros Nlin y Ncol.
 *  Para usar incluir Pds/Size.
 *  \ingroup SizeGroup
 *  \author Fernando Pujaico Rivera
 */
class Size
{

public:

    unsigned int nlin;
    unsigned int ncol;

public:

/** @name Varios tipos de constructores
 *  Crean una objeto Pds::Size
 * @{
 */

    /** 
     *  \brief Crea un objeto de tipo Pds::Size
     *  \return un objeto de tipo Pds::Size.
     *  \ingroup SizeGroup
     */
    Size(void);
    
    /** 
     *  \brief Crea un objeto de tipo Pds::Size
     *  \param[in] Nlin El numero de lineas de la matriz.
     *  \param[in] Ncol El numero de columnas de la matriz.
     *  \return un objeto de tipo Pds::Size.
     *  \ingroup SizeGroup
     */
    Size(unsigned int Nlin,unsigned int Ncol);

    /** 
     *  \brief Crea un objeto de tipo Pds::Size copiando datos desde 
     *  otra.
     * 
     *  \param[in] B Size a copiar.
     *  \ingroup SizeGroup
     */
    Size(const Pds::Size &B);

    
    ~Size(); 
    
/**
 * @}
 */
    

/** @name Mostrando datos
 *   
 * @{
 */
 
    /** 
     *  \brief Muestra en pantalla el contenido de Pds::Size, elementos separados por tabulador.
     *  \param[in] str Texto a mostrar antes de imprimir el contenido.
     *  \ingroup SizeGroup
     */
    void Print(std::string str="");
 
    /** 
     *  \brief Muestra en pantalla el contenido de Pds::Size, en el formato [Nli,Ncol].
     *  \param[in] str Texto a mostrar antes de imprimir el contenido.
     *  \ingroup SizeGroup
     */
    void PrintStylized(std::string str="");
/**
 * @}
 */
}; // Class Size

} // namespace Pds


/*!
 * @}
 */

#endif

