/*
 * RaTime.hpp
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

/** \file RaTime.hpp
 *  \author Fernando Pujaico Rivera
 *  \brief Archivo de definición herramientas para a biblioteca Ra.
 *  
 */
    
    
#ifndef __PDS_RATIME_HPP__
#define __PDS_RATIME_HPP__
    
#include <ctime>

/** \defgroup PdsRaTimeGroup Extras Pds::Ra -- Time
 *  \brief Funciones con archivos: Pds::Ra::Tic(), etc
 *  <div class="fragment"> \#include <Pds/RaTime> </div>
 *  
 *  
 * @{
 */

//! Nombre de espacion para PDS (Procesamiento Digital de Senales)
namespace Pds{
/**
 *  \brief Nombre de espacio para RA (Real Arrays)
 *  \ingroup PdsRaTimeGroup
 */
namespace Ra{


/** @name Trabajar con tiempo
 *  Salva datos de tiempo
 * @{
 */

/** 
 *  \brief Retorna el número de clocks actual. Este valor tambien es salvado internamente.
 *
 *  \return Retorna el número de clocks actual.
 *  \ingroup PdsRaTimeGroup
 */
clock_t Tic(void);

/** 
 *  \brief Retorna e imprime en pantalla el tiempo transcurrido desde Pds::Ra::Tic()
 *
 *  \return Retorna el tiempo transcurrido en segundos desde Pds::Ra::Tic()
 *  \ingroup PdsRaTimeGroup
 */
double Toc(void);


/** 
 *  \brief Retorna e imprime en pantalla el tiempo transcurrido desde start_time
 *
 *  \param[in] start_time Tiempo a comparar con el actual.
 *  \return Retorna el tiempo transcurrido en segundos desde start_time
 *  \ingroup PdsRaTimeGroup
 */
double Toc(clock_t start_time);

/**
 * @}
 */

    
} // namespace Ra
} // namespace Pds


/**
 * @}
 */
    
#endif /* __PDS_RATIME_HPP__ */
