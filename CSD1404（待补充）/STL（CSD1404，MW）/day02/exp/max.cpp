#include "comp.h"
template<typename T>
T const& Comparator<T>::max (void) const {
	return m_x < m_y ? m_y : m_x;
}
template<typename T>
T const& max (T const& x, T const& y) {
	return x < y ? y : x;
}
