#ifndef FOODSTORAGEWIDGET_H
#define FOODSTORAGEWIDGET_H

#include <QWidget>
#include <vector>
#include <fooditem.h>

class FoodStorageWidget : public QWidget
{
    Q_OBJECT
public:
    virtual void paintEvent(QPaintEvent *event) override =0;
    virtual QSize sizeHint() const override =0;
    virtual void mousePressEvent(QMouseEvent *event) override =0;
    virtual QSize minimumSizeHint() const override =0;
    void add_item (const FoodItem& f);
    FoodItem get_item (const QString& search_name);
private:
    double scale;
    std::vector <FoodItem> contents;

signals:
    void clicked();

public slots:

friend class AddItemWindow;
};

#endif // FOODSTORAGEWIDGET_H
