#pragma once

#include "crow.h"

namespace taxNow24 {

    class StateController {
    private:
        std::vector<std::string> states = {"UT", "NV", "TX", "AL"};
        std::map<std::string, double> taxes;
    public:
        StateController();

        void setupRoutes(crow::SimpleApp &app);
    };
}
