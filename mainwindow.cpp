#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Skillbox 39.3");
    this->resize(500, 300);
    connect(ui->lineEdit, &QLineEdit::textChanged, [this](QString currentText){
        QRegularExpression exp("^(\\+7|8)\\d{10}$");
        if(exp.match(currentText).hasMatch())
        {
            setOkLabel();
        }
        else
        {
            setNonOkLabel();
        }
    });
}

//-------------------------------------------------------------------

MainWindow::~MainWindow()
{
    delete ui;
}

//-------------------------------------------------------------------

void MainWindow::setOkLabel()
{
    ui->label->setText("OK");
    ui->label->setStyleSheet("color : green;");
}

//-------------------------------------------------------------------

void MainWindow::setNonOkLabel()
{
    ui->label->setText("FAIL");
    ui->label->setStyleSheet("color : red;");
}

