#include <stdint.h>

namespace atom
{

	class Window
	{
	public:
		Window(uint32_t width, uint32_t height, const char* title);
		~Window();

		virtual void OnUpdate() = 0;

		virtual bool ShouldClose() const = 0;

	protected:
		uint32_t m_Width;
		uint32_t m_Height;
		const char* m_Title;

	};

}