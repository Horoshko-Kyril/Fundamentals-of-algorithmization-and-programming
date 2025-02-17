#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QStandardItemModel(this);
    ui->treeView->setModel(model);
    ui->treeView->header()->hide();
    ui->treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Widg(QStandardItem* parentItem, Node* node) {
    if (node == nullptr) return;
    QStandardItem * ch = new QStandardItem(QString::number(node->key) + ": " + node->str);
    parentItem->appendRow(ch);
    Widg(ch, node->left);
    Widg(ch, node->right);
}

void MainWindow::on_pushButton_add_clicked()
{
    tree.insert(qMakePair(ui->spinBox->value(), ui->lineEdit->text()));
    model->clear();
    Widg(model->invisibleRootItem(), tree.getRoot());
    ui->treeView->expandAll();
}


void MainWindow::on_pushButton_del_clicked()
{
    tree.remove(ui->spinBox->value());
    model->clear();
    Widg(model->invisibleRootItem(), tree.getRoot());
    ui->treeView->expandAll();
}


void MainWindow::on_pushButton_InOrder_clicked()
{
    auto vec = tree.inOrderToVec();
    QString ans;
    for (auto & i : vec) {
        ans += QString::number(i.first) + ". " + i.second + "\n";
    }
    ui->textEdit_ans->setText(ans);
}


void MainWindow::on_pushButton_PreOrder_clicked()
{
    auto vec = tree.preOrderToVec();
    QString ans;
    for (auto & i : vec) {
        ans += QString::number(i.first) + ". " + i.second + "\n";
    }
    ui->textEdit_ans->setText(ans);
}


void MainWindow::on_pushButton_PostOrder_clicked()
{
    auto vec = tree.postOrderToVec();
    QString ans;
    for (auto & i : vec) {
        ans += QString::number(i.first) + ". " + i.second + "\n";
    }
    ui->textEdit_ans->setText(ans);
}

void MainWindow::on_pushButton_balanse_clicked()
{
    tree.balanceTree();
    model->clear();
    Widg(model->invisibleRootItem(), tree.getRoot());
    ui->treeView->expandAll();
}


void MainWindow::on_pushButton_2_clicked()
{
    close();
}


void MainWindow::on_pushButton_clicked()
{
    ui->label_2->setText(QString::number(tree.searchKeyByString(ui->lineEdit->text())));
}



void MainWindow::on_pushButton_3_clicked()
{
    tree.deleteLeftSubtree(ui->spinBox_2->value());
    model->clear();
    Widg(model->invisibleRootItem(), tree.getRoot());
    ui->treeView->expandAll();
}


void MainWindow::on_pushButton_4_clicked()
{
    tree.deleteRightSubtree(ui->spinBox_3->value());
    model->clear();
    Widg(model->invisibleRootItem(), tree.getRoot());
    ui->treeView->expandAll();
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->label_3->setText(QString::number(tree.find(ui->spinBox_4->value(), ui->spinBox_5->value())));
}

