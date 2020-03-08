#include "Aircraft.h"

class AircraftList {
	public:
		Aircraft *head;

		Aircraft *find(uint32_t addr);
		void update();

		AircraftList();
		~AircraftList();
};
