#pragma once


#include "Event.h"


namespace Esco {

	class ESCO_API KeyEvent : public Event {
	public:
		inline int getKeyCode() const { return m_KeyCode; }

		EVENT_CATEGORY(toUnderLying(EventCategory::EventCategoryInput) | toUnderLying(EventCategory::EventCategoryKeyboard))
	protected:
		KeyEvent(int code) : m_KeyCode(code) {

		}

	protected:
		int m_KeyCode;
	};

	class ESCO_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int keyCode, int repeatCount) : KeyEvent(keyCode), m_repeatCount(repeatCount) {

		}

		inline int getRepeatCount() const { return m_repeatCount; }

		std::string ToString() const override{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << "(" << m_repeatCount << " repeats.)" << std::endl;
			return ss.str();
		}
		
		EVENT_TYPE(EventType::KeyPressed)

	private:
		int m_repeatCount;
	};

	class ESCO_API KeyReleasedEvent :public KeyEvent {
	public:
		KeyReleasedEvent(int keycode): KeyEvent(keycode) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << std::endl;
			return ss.str();
		}

		EVENT_TYPE(Esco::EventType::KeyReleased)
		

	};

}