#pragma once

#include "Blitz/layers/layer.h"

namespace blitz {
    class ENGINE_API ImGuiLayer : public Layer {
        private:
            float m_time = 0.0f;
        public:
            ImGuiLayer();
            ~ImGuiLayer();

            void onAttach();
            void onDeattach();

            void onUpdate();
            void onEvent(Event& event);
    };
}