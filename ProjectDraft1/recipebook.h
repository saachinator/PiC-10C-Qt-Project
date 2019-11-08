#ifndef RECIPEBOOK_H
#define RECIPEBOOK_H

#include <QWidget>

class RecipeBook : public QWidget
{
    Q_OBJECT
public:
    RecipeBook (const double &s): scale(s){}
    void mousePressEvent ( QMouseEvent * event ) override;
    void paintEvent(QPaintEvent *event) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
private:
    double scale;

public slots:
    void is_clicked();
signals:
    void clicked();

public slots:
};

#endif // RECIPEBOOK_H