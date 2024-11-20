#pragma once

#include "Esco/Core.h"
#include "Event.h"


namespace Esco {
	class ESCO_API MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y) {}
		
		inline float GetMouseX() const { return m_MouseX; }
		inline float GetMouseY() const { return m_MouseY; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MousePosition: [" << m_MouseX << ", " << m_MouseY << "]." << std::endl;
			return ss.str();
		}

		EVENT_CATEGORY(toUnderLying(EventCategory::EventCategoryMouse) | toUnderLying(EventCategory::EventCategoryInput))
		EVENT_TYPE(EventType::MouseMoved)

	private:
		float m_MouseX, m_MouseY;
	};

	class ESCO_API MouseScrolledEvent :public Event {
	public:
		MouseScrolledEvent(float xoffset, float yoffset) : m_XOffset(xoffset), m_YOffset(yoffset) {}

		inline float getXOffset() const { return m_XOffset; }
		inline float getYOffset() const { return m_YOffset; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "Offset: [" << m_XOffset << ", " << m_YOffset << "]." << std::endl;
			return ss.str();
		}

		EVENT_CATEGORY(toUnderLying(EventCategory::EventCategoryMouse) | toUnderLying(EventCategory::EventCategoryInput))
		EVENT_TYPE(EventType::MouseScrolled)

	private:
		float m_XOffset, m_YOffset;
	};

	class ESCO_API MouseButtonEvent :public Event {
	public:

		inline int getMouseButton() const { return m_Button; }

		EVENT_CATEGORY(toUnderLying(EventCategory::EventCategoryMouseButton) | toUnderLying(EventCategory::EventCategoryInput))
	protected:	
		// The base class does not need to be instantiated
		MouseButtonEvent(int button) : m_Button(button) {}
		int m_Button;
	};

	class ESCO_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button): MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button << std::endl;
			return ss.str();
		}

		EVENT_TYPE(EventType::MousePressed)
	private:

	};

	class ESCO_API MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button << std::endl;
			return ss.str();
		}

		EVENT_TYPE(EventType::MouseReleased)
	};
}
