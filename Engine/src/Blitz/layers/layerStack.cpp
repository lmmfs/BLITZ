#include "blpch.h"
#include "layerStack.h"

namespace blitz {

    LayerStack::LayerStack(){
        m_LayerInsert = m_Layers.begin();
    }

    LayerStack::~LayerStack(){
        for (Layer* layer : m_Layers){
            delete layer;
        }
    }

    void LayerStack::pushLayer(Layer* layer){
        m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
    }

    void LayerStack::pushOverlay(Layer* layer){
        m_Layers.emplace_back(layer);
    }

    void LayerStack::popLayer(Layer* layer){
        auto findLayer = std::find(m_Layers.begin(), m_Layers.end(), layer);

        if(findLayer != m_Layers.end()){
            m_Layers.erase(findLayer);
            m_LayerInsert--;
        }
    }

    void LayerStack::popOverlay(Layer* layer){
        auto findLayer = std::find(m_Layers.begin(), m_Layers.end(), layer);

        if(findLayer != m_Layers.end()){
            m_Layers.erase(findLayer);
        }
    }

}
