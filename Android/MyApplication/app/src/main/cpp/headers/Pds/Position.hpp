/*
 * Position.hpp
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

/** \file Position.hpp
 *  \author Fernando Pujaico Rivera
 *  \date 01-04-2011
 *  \brief Funciones que trabajan con matrices columna.
 *  
 *  <br>Estas funciones trabajan con una matriz de la forma.<br>
 *  \image html matrix.png "Matriz de Nlinx1"
 *  \b Nlin es el número de lineas.
 */



#ifndef __PDS_POSITION_HPP__
#define __PDS_POSITION_HPP__


/** \defgroup PositionGroup Métodos Pds::Position
 *  \brief Metodos de la clase Pds::Position
 *  <div class="fragment"> \#include <Pds/Position> </div>
 *  
 * Informacion adicional puede ser encontrada en @cite tutorialmatvec
 * @{
 */


#include <sstream>      // std::ostringstream

namespace Pds{

class Matrix;

/*! 
 *  \brief La estructura tipo  Pds::Position .
 *  Esta estructura genera una posicion.
 *  Para usar incluir <Pds/Position>.
 *  \ingroup PositionGroup
 *  \author Fernando Pujaico Rivera
 */
class Position
{
public:
	int Lin;
	/*! Numero de Columnas */
	int Col;
public:

/** @name Varios tipos de constructores
 *  Crean una objeto Pds::Position
 * @{
 */

    /** 
     *  \brief Crea un objeto de tipo Pds::Position
     *  \return un objeto de tipo Pds::Position.
     *  \ingroup PositionGroup
     */
    Position(void);
    

    /** 
     *  \brief Crea la variable Pds::Position.
     *  \param[in] Lin Lineas.
     *  \param[in] Col Columnas.
     *  \return La variable Pds::Position.
     *  \ingroup PositionGroup
     */
    Position(int Lin,int Col);
    
    ~Position();

/**
 * @}
 */
    

}; // Class Position

} // namespace Pds


/*!
 * @}
 */

#endif

