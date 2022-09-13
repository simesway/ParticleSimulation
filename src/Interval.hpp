#ifndef INTERVAL_CLASS_HPP
#define INTERVAL_CLASS_HPP

template <typename T>
class Interval{
public:
	T start;
	T stop;

	Interval() : start(T()), stop(T()) {}
	Interval(T start, T stop) : start(start), stop(stop){}
	
	bool contains(const T &point){
		return ((point-stop) * (point-start) <= 0);
	}

	T max(){
		return (start < stop) ? stop : start;
	}

	T min(){
		return (start < stop) ? start : stop;
	}
};

#endif
