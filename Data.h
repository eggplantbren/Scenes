#ifndef Data_h
#define Data_h

#include "Scene.h"

class Data
{
	private:
		Scene scene;

	public:
		Data();
		void load(const char* filename);

	// Static global instance
	private:
		static Data instance;

	public:
		static Data& get_instance() { return instance; }

};

#endif

