#include <core/application.h>
#include "chess.h"

int main(int argc, char **argv)
{
    Application application(argc, argv);

    application.AddScene(new Chess);

    return application.Exec();
}
