#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>
#include <framework/World.h>
#include <framework/Core.h>

namespace ly {
	class World;
	class Application {
	public:
		Application();
		void Run();
		template<typename WorldType>
		weak<WorldType> loadWorld();
	private:
		sf::RenderWindow mWindow;
		float mTargetFrameRate;
		sf::Clock mTickClock;
		shared<World> currentWorld;

		void RenderInternal();
		virtual void Render();
		virtual void Tick(float deltaTime);
		void TickInternal(float deltaTime);
		void Display();
	};

	template<typename WorldType>
	weak<WorldType> Application::loadWorld() {
		shared<WorldType> newWorld{ new WorldType{this} };
		currentWorld = newWorld;
		currentWorld->BeginPlayInternal();
		return newWorld;
	}
}

#endif