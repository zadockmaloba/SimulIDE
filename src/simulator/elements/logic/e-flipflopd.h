/***************************************************************************
 *   Copyright (C) 2016 by santiago González                               *
 *   santigoro@gmail.com                                                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, see <http://www.gnu.org/licenses/>.  *
 *                                                                         *
 ***************************************************************************/

#ifndef EFLIPFLOPD_H
#define EFLIPFLOPD_H

#include "e-logic_device.h"

class  eFlipFlopD : public eLogicDevice
{
    public:

        eFlipFlopD( std::string id );
        ~eFlipFlopD();
        
        void stamp();

        void createPins();
        virtual void setVChanged();

        bool srInv() { return m_srInv; }
        void setSrInv( bool inv );

    protected:
        bool m_srInv;
};


#endif
