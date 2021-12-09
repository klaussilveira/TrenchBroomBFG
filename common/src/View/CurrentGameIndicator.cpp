/*
 Copyright (C) 2010-2017 Kristian Duske

 This file is part of TrenchBroom.

 TrenchBroom is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 TrenchBroom is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with TrenchBroom. If not, see <http://www.gnu.org/licenses/>.
 */

#include "CurrentGameIndicator.h"

#include "IO/Path.h"
#include "IO/ResourceUtils.h"
#include "Model/GameFactory.h"
#include "View/ViewConstants.h"

#include <QPixmap>
#include <QString>

namespace TrenchBroom {
namespace View {
CurrentGameIndicator::CurrentGameIndicator(const std::string& gameName, QWidget* parent)
  : DialogHeader{parent} {
  auto& gameFactory = Model::GameFactory::instance();

  const auto gamePath = gameFactory.gamePath(gameName);
  auto iconPath = gameFactory.iconPath(gameName);
  if (iconPath.isEmpty()) {
    iconPath = IO::Path("DefaultGameIcon.svg");
  }

  const auto gameIcon = IO::loadPixmapResource(iconPath);
  set(QString::fromStdString(gameName), gameIcon);
    LayoutConstants::WideHMargin, LayoutConstants::MediumVMargin, LayoutConstants::WideHMargin,
    LayoutConstants::MediumVMargin);
} // namespace TrenchBroom
} // namespace View
} // namespace TrenchBroom
