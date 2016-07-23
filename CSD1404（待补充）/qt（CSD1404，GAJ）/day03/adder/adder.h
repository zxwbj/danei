#ifndef ADDER_H
#define ADDER_H

#include <QDialog>

namespace Ui {
class Adder;
}

class Adder : public QDialog
{
    Q_OBJECT
    
public:
    explicit Adder(QWidget *parent = 0);
    ~Adder();
    
private:
    Ui::Adder *ui;
public slots:
    void   jisuan();
};

#endif // ADDER_H
