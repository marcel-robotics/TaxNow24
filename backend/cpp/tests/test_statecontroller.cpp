#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../external/doctest/doctest.h"
#include "../taxnow24/statecontroller.h"

TEST_SUITE("StateController") {
    TEST_CASE("Route - GET /states") {
        crow::SimpleApp app;
        taxNow24::StateController stateController;
        stateController.setupRoutes(app);
        app.validate();

        crow::request request;
        request.method = crow::HTTPMethod::GET;
        request.url = "/states";

        crow::response response;
        app.handle_full(request, response);

        CHECK(response.code == 200);
    }

    TEST_CASE("Route - POST /states/<string>/tax") {
        crow::SimpleApp app;
        taxNow24::StateController stateController;
        stateController.setupRoutes(app);
        app.validate();

        crow::request request;
        request.method = crow::HTTPMethod::POST;
        request.url = "/states/some_state/tax";
        request.body = "5.0";

        crow::response response;
        app.handle_full(request, response);

        CHECK(response.code == 204);
    }
}