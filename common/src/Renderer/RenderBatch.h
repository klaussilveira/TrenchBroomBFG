/*
 Copyright (C) 2010-2014 Kristian Duske
 
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

#ifndef __TrenchBroom__RenderBatch__
#define __TrenchBroom__RenderBatch__

#include "TrenchBroom.h"
#include "VecMath.h"
#include "Color.h"

#include <vector>

namespace TrenchBroom {
    namespace Renderer {
        class Renderable;
        class RenderContext;
        class RenderService;
        class Vbo;
        
        class RenderBatch {
        private:
            Vbo& m_vbo;

            typedef std::vector<Renderable*> RenderableList;
            RenderableList m_batch;
            RenderableList m_oneshots;
            
            RenderService& m_renderService;
        public:
            RenderBatch(Vbo& vbo, RenderService& renderService);
            ~RenderBatch();
            
            RenderService& renderService();
            
            void add(Renderable* renderable);
            void addOneShot(Renderable* renderable);
            
            void render(RenderContext& renderContext);
        private:
            void prepareRenderables();
            void renderRenderables(RenderContext& renderContext);
        };
    }
}

#endif /* defined(__TrenchBroom__RenderBatch__) */
