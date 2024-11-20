#pragma once


#include "Esco/Core.h"


#include <string>
#include <functional>
#include <sstream>

namespace Esco {


	enum class EventType {
		None = 0, 
		// Window events
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		// mouse events
		MousePressed, MouseReleased, MouseMoved, MouseScrolled,
		// application events
		AppTick, AppUpdate, AppRender,
		// keyboard events
		KeyPressed, KeyReleased
	};


	enum class EventCategory {
		None = 0,
		EventCategoryApplication		= BIT(1),
		EventCategoryInput				= BIT(2),
		EventCategoryMouse				= BIT(3),
		EventCategoryKeyboard			= BIT(4),
		EventCategoryMouseButton		= BIT(5)
	};

	// Getting category type, to use the logical oprations.
	// We can use static_cast<T> to get the same result.
	template<typename T>
	constexpr auto toUnderLying(T t) noexcept {
		return static_cast<std::underlying_type_t<T>>(t);
	}

#define EVENT_TYPE(type) static EventType GetStaticEventType() {return type;} \
						 virtual EventType GetEventType() const override {return GetStaticEventType();} \
						 virtual const char* GetName() const override {return #type;}

#define EVENT_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}

	class ESCO_API Event {
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;

		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category) {
			return GetCategoryFlags() & static_cast<int>(category);
		}

	protected:
		bool m_Handled = false;
	};

	class EventDispatcher {
		template <typename T>
		using EventFunction = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event):m_Event(event) {

		}

		template<typename T>
		bool Dispatch(EventFunction<T> func) {
			if (m_Event.GetEventType() == T::GetEventType()) {
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};


	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.ToString(); 
	}

}



/*



*/