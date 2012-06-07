#pragma once
#include "cinder/Color.h"
#include "MSAPhysics2D.h"

namespace Particles {
	
    class Particle {
	public:
		Particle();
		~Particle();
		
		// pass in a pointer to the particle
		void setup(MSA::Physics::Particle2D *p);
		void update();
		void draw();
		
	private:
		// store a pointer to the particle in the physics world from the main app
		MSA::Physics::Particle2D *physicsParticle;
		ci::Color color;
	};
	
}

