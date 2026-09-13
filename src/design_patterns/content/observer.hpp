#ifndef OBSERVER_HPP
# define OBSERVER_HPP

#include <functional>
#include <map>
#include <vector>

template <typename TEvent>
class Observer {
	private:
		std::map<TEvent, std::vector<std::function<void()> > > actions;
	public:

		void subscribe(const TEvent& event, const std::function<void()>& lambda) {
			actions[event].push_back(lambda);
		}

		void notify(const TEvent& event) {
			std::vector<std::function<void()> >& functions = actions[event];
			for (std::function<void()>& f: functions)
				f();
		}
};

#endif