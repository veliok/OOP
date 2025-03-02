#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setGameInfoText(QString("Select time and press start"));
    /*
        Made the logic easy to understand with
        enabling/disabling buttons for every step
    */
    ui->player1->setEnabled(false);
    ui->player2->setEnabled(false);
    ui->stop->setEnabled(false);
}

MainWindow::~MainWindow()
{
    if(pQTimer) {
        pQTimer->stop();
        delete pQTimer;
        pQTimer = nullptr;
    }
    delete ui;
}

void MainWindow::reset()
{
    if(pQTimer) {
        pQTimer->stop();
        delete pQTimer;
        pQTimer = nullptr;
    }
    ui->player1->setEnabled(false);
    ui->player2->setEnabled(false);
    ui->start->setEnabled(true);
    ui->stop->setEnabled(false);
    ui->time120->setEnabled(true);
    ui->time360->setEnabled(true);
}

void MainWindow::on_player1_clicked()
{
    currentPlayer = 2;
    ui->player1->setEnabled(false);
    ui->player2->setEnabled(true);
}

void MainWindow::on_player2_clicked()
{
    currentPlayer = 1;
    ui->player1->setEnabled(true);
    ui->player2->setEnabled(false);
}

void MainWindow::on_time120_clicked()
{
    gameTime = 120;
    ui->time360->setEnabled(true);
    ui->time120->setEnabled(false);
}

void MainWindow::on_time360_clicked()
{
    gameTime = 360;
    ui->time120->setEnabled(true);
    ui->time360->setEnabled(false);
}

void MainWindow::on_start_clicked()
{
    currentPlayer = 1;
    player1Time = gameTime;
    player2Time = gameTime;

    ui->player1_bar->setRange(0, gameTime);
    ui->player1_bar->setValue(gameTime);
    ui->player2_bar->setRange(0, gameTime);
    ui->player2_bar->setValue(gameTime);
    ui->player1->setEnabled(true);
    ui->player2->setEnabled(false);
    ui->start->setEnabled(false);
    ui->stop->setEnabled(true);
    ui->time120->setEnabled(false);
    ui->time360->setEnabled(false);

    setGameInfoText(QString("Game ongoing"));

    pQTimer = new QTimer(this);
    connect(pQTimer, &QTimer::timeout, this, &MainWindow::updateProgressbar);
    pQTimer->setInterval(1000);
    pQTimer->start();
}

void MainWindow::on_stop_clicked()
{
    setGameInfoText(QString("Select time and press start"));
    reset();
}

void MainWindow::updateProgressbar()
{
    if(currentPlayer == 1) {
        --player1Time;
        ui->player1_bar->setValue(player1Time);
        if(player1Time == 0) {
            setGameInfoText(QString("Player 2 Won"));
            reset();
        }
    }
    else {
        --player2Time;
        ui->player2_bar->setValue(player2Time);
        if(player2Time == 0) {
            setGameInfoText(QString("Player 1 Won"));
            reset();
        }
    }
}

void MainWindow::setGameInfoText(QString s)
{
    ui->prompt->setText(s);
}

