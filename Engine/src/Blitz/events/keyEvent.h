#pragma once

#include "event.h"


/*
Events:
KeyPressedEvent
KeyReleasedEvent
*/

namespace blitz {

    class ENGINE_API KeyEvent : public Event {
        protected:
            int m_KeyCode;

            KeyEvent(int keycode) : m_KeyCode(keycode) {}
        
        public:
            int getKeyCode() const { return m_KeyCode; }

            EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
    };

    class ENGINE_API KeyPressedEvent : public KeyEvent {
        private:
            int m_RepeatCount;
        public:
            KeyPressedEvent(int keycode, int repeatCount) : KeyEvent(keycode), m_RepeatCount(repeatCount) {}

            int getReapeatCount() const { return m_RepeatCount; }

            std::string toString() const override {
                std::stringstream ss;
                ss << "KeyPressedEvent: " << m_KeyCode << " : (" << m_RepeatCount << " repeats)";
                return ss.str();
		    }

            EVENT_CLASS_TYPE(KeyPressed)
    };

    class ENGINE_API KeyReleasedEvent : public KeyEvent {
        public:
            KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

            std::string toString() const override {
                std::stringstream ss;
                ss << "KeyReleasedEvent: " << m_KeyCode;
                return ss.str();
		    }

            EVENT_CLASS_TYPE(KeyReleased)
    };
}