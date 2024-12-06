#include <iostream>

#include <Application.h>

int main()
{
	atom::Application app({ "Atom App", 1280, 720 });
	app.Run();

	return 0;
}