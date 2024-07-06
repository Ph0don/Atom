#include <memory>

namespace atom
{
	class Window;

	class Application
	{
	public:
		struct Properties
		{
			const char* name;
			int width;
			int height;
		};

	public:
		~Application() = default;

		Application(const Application&) = delete;
		void operator=(const Application&) = delete;

		Application(Application&&) = delete;
		Application& operator=(Application&&) = delete;

	public:
		static Application& GetInstance();

		void Init(const Properties& props);
		void Run();
	private:
		Application() = default;

	private:
		std::unique_ptr<Window> m_Window;
	};
}