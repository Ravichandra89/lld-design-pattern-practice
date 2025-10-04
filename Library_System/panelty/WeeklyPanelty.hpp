#ifndef WEEKLY_PANELTY_HPP
#define WEEKLY_PANELTY_HPP

#include "PaneltyStrategy.hpp"
using namespace std;

class WeeklyPanelty : public PaneltyStrategy {
    public: 
        double calculatePanelty(Borrowing* b) override {
            if (!b->isReturned()) return 0;
            double days = difftime(b->getRetunredDate(), b->getBorrowedDate()) / (60*60*24*7);
            return days * 5.0;
        }
};

#endif