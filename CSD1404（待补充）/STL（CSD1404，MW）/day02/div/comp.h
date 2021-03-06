#ifndef __COMP_H__
#define __COMP_H__
template<typename T>
class Comparator {
public:
	Comparator (T const& x, T const& y) :
		m_x (x), m_y (y) {}
	T const& max (void) const;
	T const& min (void) const;
private:
	T const& m_x;
	T const& m_y;
};
template<typename T>
T const& max (T const& x, T const& y);
template<typename T>
T const& min (T const& x, T const& y);
#include "max.cpp"
#include "min.cpp"
#endif // __COMP_H__
