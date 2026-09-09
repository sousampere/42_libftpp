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
			cout << "Subscribed";
		}
		void notify(const TEvent& event) {
			
		}
};


#endif // !OBSERVER_HPP