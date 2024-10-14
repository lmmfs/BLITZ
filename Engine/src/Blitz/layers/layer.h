#pragma once

#include "Blitz/core/core.h"
#include "Blitz/events/event.h"


namespace blitz {


    class ENGINE_API Layer {
        protected:
            std::string m_LayerName;
        public:
            Layer(const std::string& name = "Layer");
            virtual ~Layer();

            virtual void onAttach() {}
            virtual void onDeattach() {}
            virtual void onUpdate() {}
            virtual void onEvent(Event& event) {}

            inline const std::string& getName() const { return m_LayerName; }
    };

}