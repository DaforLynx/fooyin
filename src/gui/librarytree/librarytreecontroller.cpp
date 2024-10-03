/*
 * Fooyin
 * Copyright © 2024, Luke Taylor <LukeT1@proton.me>
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

#include "librarytreecontroller.h"

#include "librarytreegroupregistry.h"

namespace Fooyin {
LibraryTreeController::LibraryTreeController(SettingsManager* settings, QObject* parent)
    : QObject{parent}
    , m_groupRegistry{new LibraryTreeGroupRegistry(settings, this)}
{ }

LibraryTreeGroupRegistry* LibraryTreeController::groupRegistry() const
{
    return m_groupRegistry;
}

QString LibraryTreeController::defaultPlaylistName()
{
    return tr("Library Selection");
}
} // namespace Fooyin
