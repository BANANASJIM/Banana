#pragma once

#include "Banana/Layer.h"

#include "Banana/Events/ApplicationEvent.h"
#include "Banana/Events/KeyEvent.h"
#include "Banana/Events/MouseEvent.h"

namespace Banana {

	class BANANA_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}