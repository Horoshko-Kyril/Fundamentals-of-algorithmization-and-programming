#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void update();
    int interpolationSearch(const QVector<int>& A, int X);
    QVector<QVector<int>> interpolationSort(QVector<int>& vec);
    void shuffle(QVector<int>& vector);
    unsigned long long binpow(unsigned long long a, unsigned long long n, unsigned long long m);
    QVector<int> medians(QVector<int> arr);

private slots:
    void on_clearPushButton_clicked();

    void on_addPushButton_clicked();


    void on_shufflePushButton_clicked();



    void on_newPushButton_clicked();

    void on_mediansPushButton_clicked();

private:
    unsigned long long index = 0;
    Ui::Widget *ui;
    QVector<int> vector;
};
#endif // WIDGET_H
