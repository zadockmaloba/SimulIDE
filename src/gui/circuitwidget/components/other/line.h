/***************************************************************************
 *   Copyright (C) 2018 by santiago González                               *
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

#ifndef LINE_H
#define LINE_H

#include "itemlibrary.h"
#include "shape.h"

class  Line : public Shape
{
    Q_OBJECT

    public:

        Line( QObject* parent, QString type, QString id );
        ~Line();

 static Component* construct( QObject* parent, QString type, QString id );
 static LibraryItem *libraryItem();

        virtual QPainterPath shape() const;
        virtual void paint( QPainter *p, const QStyleOptionGraphicsItem *option, QWidget *widget );

};

#endif
