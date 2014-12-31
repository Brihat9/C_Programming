C       PROGRAM TO PRINT BIGGEST NO
        DIMENSION L(100)
        WRITE(*,*) 'ENTER 5 NUMBERS'
        READ(*,1) (L(I),I=1,5)
1       FORMAT(I5)
        M = L(1)
        DO 10 I=2,5
            IF(M .LT. L(I)) M=L(I)
10      CONTINUE
        WRITE(*,4) M
4       FORMAT(1X,'BIGGEST NUMBER = ',I10)
        STOP
        END
