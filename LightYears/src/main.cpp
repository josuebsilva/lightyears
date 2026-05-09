#include <iostream>
#include <framework/Application.h>
#include <memory>

int main() {
	std::cout << "Light Years" << std::endl;
	
	std::unique_ptr<ly::Application> app = std::make_unique <ly::Application>();
	app->Run();

	return 0;
}