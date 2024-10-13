/*
 * Fooyin
 * Copyright © 2023, Luke Taylor <LukeT1@proton.me>
 *
 * Fooyin is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Fooyin is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Fooyin.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#pragma once

#include <core/track.h>

#include <utils/crypto.h>
#include <utils/treeitem.h>

#include <QObject>
#include <QString>
#include <QStyleOptionViewItem>

namespace Fooyin {
class LibraryTreeItem : public TreeItem<LibraryTreeItem>
{
public:
    enum Role
    {
        Title = Qt::UserRole,
        Level,
        Key,
        Tracks,
        TrackCount,
        DecorationPosition,
    };

    LibraryTreeItem();
    explicit LibraryTreeItem(QString title, LibraryTreeItem* parent, int level);

    [[nodiscard]] bool pending() const;
    [[nodiscard]] int level() const;
    [[nodiscard]] QString title() const;
    [[nodiscard]] TrackList tracks() const;
    [[nodiscard]] int trackCount() const;
    [[nodiscard]] Md5Hash key() const;
    [[nodiscard]] std::optional<Track::Cover> coverType() const;
    [[nodiscard]] QStyleOptionViewItem::Position coverPosition() const;

    void setPending(bool pending);
    void setTitle(const QString& title);
    void setKey(const Md5Hash& key);

    void addTrack(const Track& track);
    void addTracks(const TrackList& tracks);
    void removeTrack(const Track& track);
    void replaceTrack(const Track& track);
    void sortTracks();

private:
    bool m_pending;
    int m_level;
    Md5Hash m_key;
    QString m_title;
    std::optional<Track::Cover> m_coverType;
    QStyleOptionViewItem::Position m_coverPosition;
    TrackList m_tracks;
};
} // namespace Fooyin
