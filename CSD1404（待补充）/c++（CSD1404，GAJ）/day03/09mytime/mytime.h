#ifndef  MYTIME_H
#define  MYTIME_H
    extern  int  x;
		void  show();
		class MyTime{
		    int  hour;
				int  min;
				int  sec;
				public:
				MyTime(int hour=0,int min=0,
								int sec=0);
        void run();
				private:
				void show();
				void dida();
		};
#endif 

