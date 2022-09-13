#ifndef STATE
#define STATE

struct State{
	bool start = false;
	bool clear = true;
	bool step = false;
	bool reset_particles;

	void reset(){
		bool start = false;
		bool clear = true;
		bool step  = false;
		bool reset_particles = false;
	}
};

#endif
