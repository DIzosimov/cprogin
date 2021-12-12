#ifndef GameEngine_H
#define GameEngine_H

#include <vector>
#include "Component.h"

namespace cwing {

	class GameEngine
	{
	public:
		void add(Component* c);
		void run();
		~GameEngine();
	private:
		std::vector<Component*> comps;
	};
}
#endif
