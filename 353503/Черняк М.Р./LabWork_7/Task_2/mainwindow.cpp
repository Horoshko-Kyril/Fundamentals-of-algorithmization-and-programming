#include "mainwindow.h"
#include "Solver.h"
#include "ui_mainwindow.h"
#include <qpushbutton.h>

MainWindow::MainWindow() : ui(new Ui::MainWindow), solver(new Solver) {
  ui->setupUi(this);

  connect(ui->clearBtn, &QPushButton::clicked, this, &MainWindow::clearClicked);
  connect(ui->randBtn, &QPushButton::clicked, this, &MainWindow::randClicked);
  connect(ui->getBtn, &QPushButton::clicked, this, &MainWindow::getClicked);
  connect(ui->setBtn, &QPushButton::clicked, this, &MainWindow::setClicked);
  connect(ui->delBtn, &QPushButton::clicked, this, &MainWindow::delClicked);
  connect(ui->balanceBtn, &QPushButton::clicked, this, &MainWindow::balanceClicked);
  connect(ui->enter, &QPushButton::clicked, this, &MainWindow::enterClicked);
  update();
}

void MainWindow::update() {
  solver->fillEnties(ui->tree);
}

void MainWindow::enterClicked(){
    QString letter = ui->valStart->text();
    int count = solver->countStartingWithLetter(letter);
    QString c = QString::number(count);
    if(letter.length() > 1 || letter.length() < 1){
        ui->count->setText("Error");
    }
    else ui->count->setText(c);
    update();
}

void MainWindow::clearClicked() {
  solver->clear();
  update();
}

void MainWindow::randClicked() {
  solver->randomize();
  update();
}

void MainWindow::getClicked() {
  int key = ui->key->value();
  QString val = "NOT_FOUND";
  if (solver->contains(key))
    val = solver->get(key);
  ui->value->setText(val);
}

void MainWindow::setClicked() {
  int key = ui->key->value();
  QString val = ui->value->text();
  solver->insert(key, val);
  update();
}

void MainWindow::delClicked() {
  int key = ui->key->value();
  QString val = "NOT_FOUND";
  if (solver->contains(key))
    val = solver->get(key);
  ui->value->setText(val);
  solver->remove(key);
  update();
}

void MainWindow::balanceClicked() {
  solver->balance();
  update();
}
