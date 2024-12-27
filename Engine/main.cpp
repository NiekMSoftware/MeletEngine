#include "precomp.h"

int main()
{
    MeletEngine::Apps::FirstApp app{};

    try
    {
        app.run();
    } catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}