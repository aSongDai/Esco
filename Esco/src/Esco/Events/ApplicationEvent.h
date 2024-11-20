#pragma once
#include "Esco/Core.h"
#include "Event.h"


namespace Esco {
	class ESCO_API WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(unsigned width, unsigned height) : m_Width(width), m_Height(height) {}

		inline unsigned GetWidth() const { return m_Width; }
		inline unsigned GetHeight() const { return m_Height; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "Application: [" << m_Width << " X " << m_Height << "]." << std::endl;
			return ss.str();
		}

		EVENT_CATEGORY(toUnderLying(EventCategory::EventCategoryApplication))
		EVENT_TYPE(EventType::WindowResize)

	private:
		unsigned int m_Width, m_Height;
	};

	class ESCO_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() {}

		EVENT_CATEGORY(toUnderLying(EventCategory::EventCategoryApplication))
		EVENT_TYPE(EventType::WindowClose)

	};

	class ESCO_API AppTickEvent : public Event {
	public:
		AppTickEvent() {}

		EVENT_CATEGORY(toUnderLying(EventCategory::EventCategoryApplication))
		EVENT_TYPE(EventType::AppTick)

	};

	class ESCO_API AppUpdateEvent : public Event {
	public:
		AppUpdateEvent() {}

		EVENT_CATEGORY(toUnderLying(EventCategory::EventCategoryApplication))
		EVENT_TYPE(EventType::AppUpdate)

	};

	class ESCO_API AppRenderEvent : public Event {
	public:
		AppRenderEvent() {}

		EVENT_CATEGORY(toUnderLying(EventCategory::EventCategoryApplication))
		EVENT_TYPE(EventType::AppRender)

	};


}