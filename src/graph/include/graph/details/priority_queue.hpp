/* 
 * priority_queue.hpp
 * 
 * Created on: Nov 30, 2017 11:41
 * Description: 
 * 
 * Copyright (c) 2017 Ruixiang Du (rdu)
 */

#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

#include <utility>
#include <queue>

namespace librav
{

/// A simple priority queue implementation.
// Source: http://www.redblobgames.com/pathfinding/a-star/implementation.html
template <typename T, typename Number = double>
struct PriorityQueue
{
	typedef std::pair<Number, T> PQElement;

	std::priority_queue<PQElement, std::vector<PQElement>,
						std::greater<PQElement>>
		elements;

	inline bool empty() const { return elements.empty(); }

	inline size_t size() const { return elements.size(); }

	inline void put(T item, Number priority)
	{
		elements.emplace(priority, item);
	}

	inline T get()
	{
		T best_item = elements.top().second;
		elements.pop();
		return best_item;
	}
};

/// A priority queue implementation that supports element priority update.
// Reference:
// [1] https://github.com/csbence/DynamicPriorityQueue
template <typename ElmentType, typename PriorityType = double>
struct DynamicPriorityQueue
{
	typedef std::pair<ElmentType, PriorityType> PQElement;

	std::priority_queue<PQElement, std::vector<PQElement>,
						std::greater<PQElement>>
		elements;

	inline bool empty() const { return elements.empty(); }

	inline void put(ElmentType item, PriorityType priority)
	{
		elements.emplace(priority, item);
	}

	inline ElmentType get()
	{
		ElmentType best_item = elements.top().second;
		elements.pop();
		return best_item;
	}
};
} // namespace librav

#endif /* PRIORITY_QUEUE_HPP */
