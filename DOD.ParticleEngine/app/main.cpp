
#include <glm/glm.hpp>
#include <Texture.h>

struct Emitter {
	glm::vec2 position;
	float rate;
};

struct Particle {
	float life;

	glm::vec2 position;
	float rotation;

	Texture texture;
	glm::vec4 color;

	glm::vec2 velocity;
	float angularVelocity;
};

void CreateParticle() {
	//if current time > last + rate => spawn new particle at position
}

void UpdateParticleHealth() {
	//life -= deltatime
}

void UpdateParticlePosition() {
	//position += velocity * deltatime
}

void UpdateParticleRotation() {
	//rotation += angularVelocity * deltatime
}

void RenderParticle() {
	// render texture with color at position with rotation
}

int main() {

	while (true) {

	}

	return 1;
}