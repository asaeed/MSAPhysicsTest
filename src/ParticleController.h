#pragma once
#include "Particle.h"
#include "MSAPhysics2D.h"
#include <list>

namespace Particles {
	
	class ParticleController {
	public:
		ParticleController();
		// pass the physics world from the main app by reference
		void setup(MSA::Physics::World2D &p);
		void update();
		void draw();
		void addParticle(const ci::Vec2i &mousePos);
		void removeAll();
	
	private:
		// store a pointer to the physics world fro the main app
		MSA::Physics::World2D *physics;
		std::list<Particle>	particles;
};

}