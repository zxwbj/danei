#include "comp.h"
#include "max.cpp"
#include "min.cpp"
template class Comparator<int>;
template int const& max<int> (int const&,
	int const&);
template int const& min<int> (int const&,
	int const&);
template class Comparator<double>;
template double const& max<double> (
	double const&, double const&);
template double const& min<double> (
	double const&, double const&);
