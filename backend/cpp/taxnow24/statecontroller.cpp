#include "statecontroller.h"

taxNow24::StateController::StateController() = default;


void taxNow24::StateController::setupRoutes(crow::SimpleApp &app) {
    CROW_ROUTE(app, "/")
            ([]() {
                return "Hello, TaxNow24!";
            });

    CROW_ROUTE(app, "/states")
            ([this]() {
                crow::json::wvalue jsonObj;
                jsonObj["states"] = states;

                auto response = crow::response(jsonObj);
                response.add_header("Content-Type", "application/json");
                response.code = 200;
                return response;
            });

    CROW_ROUTE(app, "/states/<string>/tax").methods("POST"_method)
            ([this](const crow::request &req, crow::response &res, const std::string &state) {
                double tax = std::stod(req.body);
                taxes[state] = tax;
                res.code = 204;
                res.end();
            });
}
