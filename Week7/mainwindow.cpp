#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->N0, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->N1, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->N2, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->N3, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->N4, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->N5, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->N6, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->N7, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->N8, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->N9, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->add, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->sub, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->mul, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->div, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->clear, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->enter, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();

    if(name.at(0) == "N") {
        numberClickedHandler(name);
    }
    else if(name == "clear" || name == "enter") {
        clearAndEnterClickHandler(name);
    }
    else {
        addSubMulDivClickHandler(name);
    }
}

void MainWindow::numberClickedHandler(QString &name)
{
    name.remove(0, 1); // removes the N from digitbutton name
    if(state == 1) {
        number1.append(name);
        ui->num1->setText(number1);
    }
    else if(state == 2) {
        number2.append(name);
        ui->num2->setText(number2);
    }
}

void MainWindow::clearAndEnterClickHandler(QString &name)
{
    if(name == "clear") {
        state = 1;
        resetLineEdits();
    }

    else if(name == "enter") {
        float n1 = number1.toFloat();
        float n2 = number2.toFloat();

        switch(operand) {
            case 0:
                result = n1+n2;
                break;
            case 1:
                result = n1-n2;
                break;
            case 2:
                result = n1*n2;
                break;
            case 3:
                result = n1/n2;
                break;
            default:
                result = 0;
                break;
        }
        ui->result->setText(QString::number(result));
    }
}

void MainWindow::addSubMulDivClickHandler(QString &name)
{
    if(name == "add") operand = 0;
    else if(name == "sub") operand = 1;
    else if(name == "mul") operand = 2;
    else if(name == "div") operand = 3;
    else operand = 0;
    state = 2;
}

void MainWindow::resetLineEdits()
{
    number1 = "";
    number2 = "";
    result = 0;
    ui->num1->setText("");
    ui->num2->setText("");
    ui->result->setText("");
}
