#include "Particle.h"
#include "Globals.h"

namespace Particles {
	
	Particle::Particle() {
	}
	
	Particle::~Particle() {
	}
	
	
	void Particle::setup(MSA::Physics::Particle2D *p) {
		physicsParticle = p;

		if (global::COLOR_SCHEME == 0)
			color = ci::ColorA(1, ci::Rand::randFloat(0,.8), 0, 1);  // red to yellow
		else
			color = ci::ColorA(ci::Rand::randFloat(0,.8), 0, 1, 1);  // blue to violet
	}
	
	void Particle::update() {

	}

	void Particle::draw() {
		glColor4f(color);
		ci::gl::drawSolidCircle(physicsParticle->getPosition(), physicsParticle->getRadius());
	}

}

