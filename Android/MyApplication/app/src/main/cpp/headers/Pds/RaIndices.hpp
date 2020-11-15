/*
 * RaIndices.hpp
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

/** \file RaIndices.hpp
 *  \author Fernando Pujaico Rivera
 *  \brief Archivo de definición herramientas para a biblioteca Ra.
 *  
 */
    
    
#ifndef __PDS_RAINDICES_HPP__
#define __PDS_RAINDICES_HPP__
    
#include <string>
#include <list>

/** \defgroup PdsRaIndicesGroup Extras Pds::Ra -- Indices
 *  \brief Funciones con indices: Pds::Ra::IndicesRand(), etc
 *  <div class="fragment"> \#include <Pds/RaIndices> </div>
 *  
 *  
 * @{
 */

//! Nombre de espacion para PDS (Procesamiento Digital de Senales)
namespace Pds{
/**
 *  \brief Nombre de espacio para RA (Real Arrays)
 *  \ingroup PdsRaIndicesGroup
 */
namespace Ra{


/** @name Indices
 *  Funciones interesantes
 * @{
 */

    /**
     *  \brief Retorna una lista aleatoria de indices
     *  
     *  \warning La función usa internamente la función rand(), 
     *  si se desea esta puede ser aleatoriamente inicializada usando la funcíón Pds::Ra::Randomize(),
     *  de lo contrario los números pseudo aleatórios siempre seguirán la misma secuencia.
     *  \param[in] Init Menor posible valor de los indices en la lista.
     *  \param[in] End Maior posible valor de los indices en la lista.
     *  \param[in] N Numero de elementos de la lista
     *  \return Retorna una std::list con datos aleatórios con indices.
     *  Si N>(End-Init+1) los elementos en la lista no se repetiran, caso contrario si.
     *  \ingroup PdsRaIndicesGroup
     */
    std::list<unsigned int> IndicesRand(unsigned int Init,unsigned int End, unsigned int N);

    /**
     *  \brief Convierte una lista de indices a un std::string.
     *  
     *  \param[in] IDs Lista de indices.
     *  \param[in] separator Separador de elementos.
     *  \ingroup PdsRaIndicesGroup
     */
    std::string IndicesToString(std::list<unsigned int> IDs, std::string separator="");

/**
 * @}
 */


    
} // namespace Ra
} // namespace Pds


/**
 * @}
 */
    
#endif /* __PDS_RAINDICES_HPP__ */
