#ifndef GameEngine_H
#define GameEngine_H

#include <vector>
#include "Component.h"

namespace cwing {

	class GameEngine
	{
public:
	void add(Component* comp);
	void remove(Component* comp);
	void run();
private:
	std::vector<Component*> comps;
	std::vector<Component*> added, removed;
};

}
#endif
