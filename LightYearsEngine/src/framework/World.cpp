#include <framework/World.h>
#include <framework/Core.h>

namespace ly {
	World::World(Application* app) : mApp{ app }, mBeginPlay{false} {
	}

	void World::TickInternal(float deltaTime) {
		Tick(deltaTime);
	}

	void World::Tick(float deltaTime) {
		LOG("Tick at fram rate %f", 1.f / deltaTime);
	}

	void World::BeginPlayInternal() {
		if (!mBeginPlay) {
			mBeginPlay = true;
			BeginPlay();
		}
	}

	void World::BeginPlay() {
		LOG("Begin Play");
	}

	World::~World() {

	}
}