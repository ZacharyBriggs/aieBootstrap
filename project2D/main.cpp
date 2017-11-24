#include "Application2D.h"
#include <Vector2.h>
#include <Vector3.h>
#include <Vector4.h>

int main()
{

	// allocation
	auto app = new Application2D();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}