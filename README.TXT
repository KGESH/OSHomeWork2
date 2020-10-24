IF NOT EXIST "A.dat" "B.dat" THEN
	EXCUTE ./main

IF EXIST "A.dat" "B.dat" THEN
	EXCUTE ./main A.dat B.dat
