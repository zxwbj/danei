       /* create  mydept1404 and myemp1404 */
       drop    table  mydept1404 cascade constraints;
       create  table  mydept1404(
           id  number  constraint 
	      mydept1404_id_pk  primary  key,
	   name  varchar2(30)
       );
       insert into mydept1404 values(1,'test1');
       insert into mydept1404 values(2,'test2');
       commit; 
       drop    table  myemp1404 cascade constraints;
       create  table  myemp1404(
           id  number  constraint 
	      myemp1404_id_pk  primary  key,
	   name  varchar2(30),
	   salary number,
	   dept_id number constraint  
              myemp1404_dept_id_fk  references
	      mydept1404(id)
       );
       insert  into myemp1404 values(1,'ea',
          1000,1);
       insert  into myemp1404 values(2,'eb',
          1001,1);
       insert  into myemp1404 values(3,'ec',
          1002,1);
       insert  into myemp1404 values(4,'ed',
          2001,2);
       insert  into myemp1404 values(5,'ee',
          2002,2);
       commit;
