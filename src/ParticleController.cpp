#pragma once
#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/Vector.h"
#include "ParticleController.h"
#include "Globals.h"

using namespace ci;
using std::list;

namespace Particles {

ParticleController::ParticleController()
{
}

void ParticleController::setup(MSA::Physics::World2D &p)
{
	physics = &p;
}

void ParticleController::update()
{
	for( list<Particle>::iterator p = particles.begin(); p != particles.end(); p++) {
		p->update();
	}
}

void ParticleController::draw()
{
	for( list<Particle>::iterator p = particles.begin(); p != particles.end(); p++ ){
		p->draw();
	}
}

void ParticleController::addParticle(const Vec2i &mousePos)
{
	float mass		= Rand::randFloat(global::MIN_MASS, global::MAX_MASS);
	float bounce	= Rand::randFloat(global::MIN_BOUNCE, global::MAX_BOUNCE);
	float radius	= mapRange(mass, global::MIN_MASS, global::MAX_MASS, global::MIN_RADIUS, global::MAX_RADIUS);

	Physics::Particle2D* p = physics->makeParticle(mousePos);
	p->setMass(mass)->setBounce(bounce)->setRadius(radius)->enableCollision()->makeFree();

	Particle part = Particle();
	// initialize the particle by passing the pointer to the Particle2D
	part.setup(p);
	particles.push_back(part);

}

void ParticleController::removeAll()
{
	physics->clear();
	particles.clear();
	if (global::COLOR_SCHEME == 0)
		global::COLOR_SCHEME++;
	else
		global::COLOR_SCHEME--;
}

}