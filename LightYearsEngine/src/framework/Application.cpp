#include "framework/Application.h"
#include <iostream>

namespace ly {
	Application::Application() 
		: mWindow{ sf::VideoMode({1024, 800}), "Light Years" },
		mTargetFrameRate {60.0f},
		mTickClock {},
		currentWorld {nullptr}
	{

	}

	void Application::Run() {
		mTickClock.restart();
		float accumulatedTime = 0.f;
		float targetDeltaTime = 1.f / mTargetFrameRate;
		while (mWindow.isOpen()) {
			while (const std::optional event = mWindow.pollEvent())
			{
				if (event->is<sf::Event::Closed>())
				{
					mWindow.close();
				}
			}
			float frameDeltaTime = mTickClock.restart().asSeconds();
			accumulatedTime += frameDeltaTime;
			while (accumulatedTime > targetDeltaTime) {
				accumulatedTime -= targetDeltaTime;
				TickInternal(targetDeltaTime);
				RenderInternal();
			}
		}
	}

	void Application::RenderInternal() {
		mWindow.clear();
		Render();
		mWindow.display();
	}
	void Application::Render() {
		

		sf::RectangleShape rect{ sf::Vector2f{100, 100} };
		rect.setFillColor(sf::Color::Green);
		rect.setOrigin(sf::Vector2f { 50, 50 });
		rect.setPosition(sf::Vector2f(mWindow.getSize().x / 2, mWindow.getSize().y / 2));
		
		mWindow.draw(rect);

	}

	void Application::Tick(float deltaTime) {

	}

	void Application::TickInternal(float deltaTime) {
		Tick(deltaTime);
		if (currentWorld) {
			currentWorld->TickInternal(deltaTime);
		}
	}
}