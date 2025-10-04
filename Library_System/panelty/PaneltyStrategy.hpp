#ifndef PANELTY_STRATEGY_HPP
#define PANELTY_STRATEGY_HPP

#include "../books/Borrowing.hpp"

class PaneltyStrategy {
    public: 
        virtual ~PaneltyStrategy() = 0;
        virtual double calculatePanelty(Borrowing* b) = 0;
};

#endif