#ifndef DAILY_PANELTY_HPP
#define DAILY_PANELTY_HPP

#include "PaneltyStrategy.hpp"
using namespace std;

class DailyPanelty : public PaneltyStrategy {
    public: 
        double calculatePanelty(Borrowing* b) override {
            if (!b->isReturned()) return 0;
            double days = difftime(b->getRetunredDate(), b->getBorrowedDate()) / (60*60*24);
            return days*1.0;
        }
};

#endif