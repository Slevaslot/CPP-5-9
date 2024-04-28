#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <exception>
#include <stdexcept>
#include <string>
#include <vector>
#include <stack>
#include <list>
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T> {
public:
	MutantStack() : MutantStack<T, Container>::stack() {};
	MutantStack(const MutantStack<T, Container>& other) : MutantStack<T, Container>::stack(other) {};

    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;

    iterator begin() {
        return this->c.begin();
    }

    iterator end() {
        return this->c.end();
    }

    const_iterator begin() const {
        return this->c.begin();
    }

    const_iterator end() const {
        return this->c.end();
    }
};

#endif
