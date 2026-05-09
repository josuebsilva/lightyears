#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>

namespace ly {
	class Application {
	public:
		Application();
		void Run();
	private:
		sf::RenderWindow mWindow;
		float mTargetFrameRate;
		sf::Clock mTickClock;
		virtual void Render();
		virtual void Update(float deltaTime);
		void Tick(float deltaTime);
		void Display();
	};
}

#endif