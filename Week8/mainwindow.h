#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_player1_clicked();
    void on_player2_clicked();
    void on_time120_clicked();
    void on_time360_clicked();
    void on_start_clicked();
    void on_stop_clicked();
    void updateProgressbar();

private:
    Ui::MainWindow *ui;
    void setGameInfoText(QString);
    void reset();
    short player1Time;
    short player2Time;
    short currentPlayer;
    short gameTime = 120;
    QTimer *pQTimer = nullptr;
};
#endif // MAINWINDOW_H
