#include <QApplication>
#include "mytime.h"
int main(int argc,char** argv){
    QApplication  app(argc,argv);
    MyTime  mytime;
		mytime.show();
		return  app.exec();
}

