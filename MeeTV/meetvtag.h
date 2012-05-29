/*
 *  Copyright (C) 2012 Robert Meijers
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MEETVTAG_H
#define MEETVTAG_H

#include <QObject>

#include "meetvchannelmodel.h"
#include "meetvhtsp.h"
#include "../QHtsp/qhtsptag.h"

class MeeTvTag : public QHtspTag
{
    Q_OBJECT
    Q_PROPERTY(MeeTvChannelModel *channelsModel READ channelsModel)
    Q_PROPERTY(QObject *parent READ parent WRITE setParent)

public:
    explicit MeeTvTag(QObject *parent = 0);
    MeeTvTag(const QHtspTag &tag, QObject *parent = 0);

    MeeTvChannelModel *channelsModel();

private:
    MeeTvChannelModel *m_channelsModel;
};

#endif // MEETVTAG_H
