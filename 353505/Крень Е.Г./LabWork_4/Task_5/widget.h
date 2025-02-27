#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "vector.h"
#include "pair.h"


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

private:
    Ui::Widget *ui;
    Vector<pair<Vector<int>, Vector<pair<int, double>>>> data;
    void refreshTable();
    void refreshMatrix();
};
#endif // WIDGET_H
