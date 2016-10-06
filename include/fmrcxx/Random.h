#ifndef FMRCXX_RANDOM_H_
#define FMRCXX_RANDOM_H_

#include <random>

#include <fmrcxx/Iterator.h>

namespace fmrcxx {

/**
 * \internal
 * \brief Templatized structure providing the default distribution to use to generate number of type T.
 * \tparam T Type of number to generate: bool, short, int, float, double, etc.
 */
template <typename T>
class default_distribution {
public:
	/**
	 * \brief Type of the default distribution to use to generate number of type T.
	 */
	using type = std::uniform_int_distribution<T>;
};

template <typename T, typename SeedType = unsigned int, typename RandomNumberEngine = std::default_random_engine, typename RandomNumberDistribution = typename default_distribution<T>::type>
class Random :
		public Iterator<T>,
		public IteratorTransformingOperation<T, Iterator, Random<T>>,
		public IteratorTerminalOperation<T, Random<T>> {
public:
	/**
	 * \brief Construct an iterator that generates random numbers.
	 * \param seed Seed to use for the random number engine.
	 * \param args Arguments to forward to the constructor of the distribution.
	 */
	template <typename... Args>
	Random(SeedType seed, Args&&... args);

	/**
	 * \brief Move constructor
	 */
	Random(Random&& rhs);

	/**
	 * \brief Return the random number engine used to generate next number.
	 */
	const RandomNumberEngine& getEngine() const noexcept;

	/**
	 * \brief Return the random number distribution used to generate next number.
	 */
	const RandomNumberDistribution& getDistribution() const noexcept;

	bool fullyConsumed();

	T& next();

	bool ownItem();

private:
	RandomNumberEngine engine;
	RandomNumberDistribution distribution;
	T current;
};

}

#include <fmrcxx/impl/Random.hpp>

#endif
