#include <cstdlib>

#include <QTextStream>
#include <QtGui>

int main (int argc, char* argv[])
{
    QApplication app(argc, argv);
    QTextStream cout(stdout);
    bool ok;

    int seed = QInputDialog::getInt(
                0,                          // Parent
                "Seed for random numbers",  // Title
                "Enter the seed:",          // Label
                0,                          // Current Value
                0,                          // Min Value
                5000,                       // Max Value
                1,                          // Step
                &ok                         // Result button
                );
    srand(seed);
    if (true == ok) {
        cout << rand() << endl;
    }

    return EXIT_SUCCESS;
}
