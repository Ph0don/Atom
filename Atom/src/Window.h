#include <stdint.h>

struct GLFWwindow;

namespace atom
{

	class Window
	{
	public:
		Window(uint32_t width, uint32_t height, const char* title);
		~Window();

		void OnUpdate();

		bool ShouldClose() const;

	protected:
		uint32_t m_Width;
		uint32_t m_Height;
		const char* m_Title;

		GLFWwindow* m_Window;
	};

}