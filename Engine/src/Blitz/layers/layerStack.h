#pragma once

#include "Blitz/core/core.h"
#include "layer.h"

#include <vector>

namespace blitz {
    class ENGINE_API LayerStack {
        private:
            std::vector<Layer*> m_Layers;
            std::vector<Layer*>::iterator m_LayerInsert;
        public:
            LayerStack();
            ~LayerStack();

            void pushLayer(Layer* layer);
            void pushOverlay(Layer* layer);
            void popLayer(Layer* layer);
            void popOverlay(Layer* layer);

            std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
            std::vector<Layer*>::iterator end() { return m_Layers.end(); }
    };
}
