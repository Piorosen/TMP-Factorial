#include <iostream>
#include <array>

using namespace std;

template <int N>
struct Factorial
{
	static const int64_t result = N * Factorial<N - 1>::result;
};

template <>
struct Factorial<1>
{
	static const int64_t result = 1;
};

template<int N>
struct list
{
	static const array<int64_t, N> getvalue()
	{
		static array<int64_t, N> value;
		static const array<int64_t, N -1> p = list<N - 1>::getvalue();
		copy(p.begin(), p.end(), value.begin());
		value[N - 1] = Factorial<N>::result;
		return value;
	}
};

template <>
struct list<1>
{
	static const array<int64_t, 1> getvalue()
	{
		return { Factorial<1>::result };
	}
};

int main()
{
	auto p = list<10>::getvalue();
	for (auto l : p) {
		cout << l << endl;
	}
}