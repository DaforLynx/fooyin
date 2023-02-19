/*
 * Fooyin
 * Copyright 2022, Luke Taylor <LukeT1@proton.me>
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

#include <utils/settings/settingspage.h>

namespace Utils {
class SettingsDialogController;
}

namespace Core {
class SettingsManager;
}

namespace Gui::Settings {
class PlaylistGuiPageWidget : public Utils::SettingsPageWidget
{
public:
    explicit PlaylistGuiPageWidget(Core::SettingsManager* settings);
    ~PlaylistGuiPageWidget() override = default;

    void apply() override;

private:
    struct Private;
    std::unique_ptr<PlaylistGuiPageWidget::Private> p;
};

class PlaylistGuiPage : public Utils::SettingsPage
{
public:
    PlaylistGuiPage(Utils::SettingsDialogController* controller, Core::SettingsManager* settings);
};
} // namespace Gui::Settings
