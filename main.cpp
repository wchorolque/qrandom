#include <cstdlib>

#include <QTextStream>
#include <QtGui>

int main (int argc, char* argv[])
{
    QApplication app(argc, argv);
    QTextStream cout(stdout);
    bool ok;
    int seed;
    int answer;
    seed = QInputDialog::getInt(
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
        do {
            qint64 nextRandomValue = rand();
            QString response = QString("The next random value is: %1\n%2")
                    .arg(nextRandomValue)
                    .arg("Do you want to generate another value?");
            answer = QMessageBox::question(
                        0,                  // Parent
                        "New random value", // Title
                        response,           // Label
                        QMessageBox::Yes | QMessageBox::No
                        );
        } while (QMessageBox::Yes == answer);
    }

    return EXIT_SUCCESS;
}
