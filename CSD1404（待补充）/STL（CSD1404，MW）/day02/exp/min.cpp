#include "comp.h"
template<typename T>
T const& Comparator<T>::min (void) const {
	return m_x < m_y ? m_x : m_y;
}
template<typename T>
T const& min (T const& x, T const& y) {
	return x < y ? x : y;
}
