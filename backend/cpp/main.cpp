#include "crow.h"
#include "taxnow24/statecontroller.h"

int main() {
    const auto port = static_cast<std::uint16_t>(18080);

    crow::SimpleApp app;
    taxNow24::StateController stateController;
    stateController.setupRoutes(app);
    app.port(port).run();

    return 0;
}
