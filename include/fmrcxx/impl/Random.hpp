#ifndef FMRCXX_IMPL_RANDOM_H_
#define FMRCXX_IMPL_RANDOM_H_

#include <utility>
#include <random>

#include <fmrcxx/Random.h>

namespace fmrcxx {

template <>
class default_distribution<bool> {
public:
	using type = std::bernoulli_distribution;
};

template <>
class default_distribution<float> {
public:
	using type = std::uniform_real_distribution<float>;
};

template <>
class default_distribution<double> {
public:
	using type = std::uniform_real_distribution<double>;
};

template <>
class default_distribution<long double> {
public:
	using type = std::uniform_real_distribution<long double>;
};

template <typename T, typename SeedType, typename RandomNumberEngine, typename RandomNumberDistribution> template <typename... Args>
Random<T, SeedType, RandomNumberEngine, RandomNumberDistribution>::Random(SeedType seed, Args&&... args) :
	Iterator<T, std::nullptr_t>(),
	engine(seed),
	distribution(std::forward<Args>(args)...) {
}

template <typename T, typename SeedType, typename RandomNumberEngine, typename RandomNumberDistribution>
Random<T, SeedType, RandomNumberEngine, RandomNumberDistribution>::Random(Random<T, SeedType, RandomNumberEngine, RandomNumberDistribution>&& rhs) :
	Iterator<T, std::nullptr_t>(std::move(rhs)),
	engine(rhs.engine),
	distribution(rhs.distribution.param()) {
}

template <typename T, typename SeedType, typename RandomNumberEngine, typename RandomNumberDistribution>
const RandomNumberEngine& Random<T, SeedType, RandomNumberEngine, RandomNumberDistribution>::getEngine() const noexcept {
	return this->engine;
}

template <typename T, typename SeedType, typename RandomNumberEngine, typename RandomNumberDistribution>
const RandomNumberDistribution& Random<T, SeedType, RandomNumberEngine, RandomNumberDistribution>::getDistribution() const noexcept {
	return this->distribution;
}

template <typename T, typename SeedType, typename RandomNumberEngine, typename RandomNumberDistribution>
bool Random<T, SeedType, RandomNumberEngine, RandomNumberDistribution>::fullyConsumed() {
	return false;
}

template <typename T, typename SeedType, typename RandomNumberEngine, typename RandomNumberDistribution>
T& Random<T, SeedType, RandomNumberEngine, RandomNumberDistribution>::next() {
	current = distribution(engine);
	return current;
}

template <typename T, typename SeedType, typename RandomNumberEngine, typename RandomNumberDistribution>
bool Random<T, SeedType, RandomNumberEngine, RandomNumberDistribution>::ownItem() {
	return true;
}

}

#endif
